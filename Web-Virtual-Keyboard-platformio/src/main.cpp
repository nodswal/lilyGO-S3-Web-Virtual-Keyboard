#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "storage.h"
#include "globals.h"
#include "http_handlers.h"
#include "display.h"

bool connectWiFi()
{
    LogSerial.printf("[WiFi] Starting AP mode: \"%s\" ...\r\n", WIFI_SSID);

    WiFi.setHostname(HOSTNAME);
    WiFi.mode(WIFI_MODE_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASS);

    LogSerial.printf("[WiFi] AP Started! IP: %s\r\n", WiFi.softAPIP().toString().c_str());
    
#if ENABLE_DISPLAY
    display_write_word(COLOR_OK, Align::RIGHT, 5, WiFi.softAPIP().toString().c_str());
#endif

    return true;
}

// ---------- Setup / Loop ----------
void setup()
{
	// UART for logging over an external USB-UART adapter (not CDC)
	LogSerial.begin(UART_BAUD, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
	delay(100);
	LogSerial.print("\r\n=== Web Keyboard Server ===\r\n");

	USB.begin();
	Serial.begin(115200);
	delay(200);
	Keyboard.begin();
	LogSerial.print("[USB] HID Keyboard ready\r\n");
	delay(200);

#if ENABLE_DISPLAY
	display_init();

	if(connectWiFi())
	{
		display_write_word(COLOR_OK, Align::RIGHT, 5, WiFi.localIP().toString().c_str());
	}
	else
	{
		display_write_word(COLOR_ERROR, Align::RIGHT, 5, "Disconnected");
	}
#else
	(void)connectWiFi();
#endif

	// Initialize NVS key if absent
	prefs.begin(PREFS_NS, false);
	if (!prefs.isKey(PRESETS_K))
	{
		prefs.putString(PRESETS_K, "{}");
		LogSerial.println("[NVS] Initialized empty presets");
	}
	prefs.end();

	// HTTP routes
	server.on("/", HTTP_GET, handleRoot);
	server.on("/type", HTTP_POST, handleType);
	server.on("/presets", HTTP_GET, handleGetPresets);
	server.on("/presets", HTTP_POST, handlePostPreset);
	server.on("/presets", HTTP_DELETE, handleDeletePreset);

	server.on("/favicon.ico", HTTP_GET, []()
	{
		server.send(204);
	});

	server.begin();
	LogSerial.print("[HTTP] Server started on port ");
	LogSerial.println(SERVER_PORT);
}

void loop()
{
	server.handleClient();
}
