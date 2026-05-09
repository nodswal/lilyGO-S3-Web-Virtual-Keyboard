#ifndef CONFIG_H
#define CONFIG_H

// ==================== USER CONFIGURATION ====================

#define MASTER_USER      "admin"               // ← Change this (web login username)
#define MASTER_PASS      "password"            // ← Change this (web login password)

#define WIFI_SSID        "VirtualKeyboard"     // ← Name of Wi-Fi this board will create
#define WIFI_PASS        "12345678"            // ← Password (must be at least 8 characters)

#define HOSTNAME         "web-virtual-keyboard"
#define SERVER_PORT      80

// ============================================================

#define TYPE_DELAY_MS    40

#define UART_RX_PIN      44
#define UART_TX_PIN      43
#define UART_BAUD        115200
#define UART_NUMBER      0

#define ENABLE_DISPLAY   true

#define MAX_PRESET_LENGTH   64
#define MAX_USER_LENGTH     128      
#define MAX_PASS_LENGTH     128
#define MAX_JSON_SIZE       16384

#endif
