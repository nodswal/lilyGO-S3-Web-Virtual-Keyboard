#ifndef CONFIG_H
#define CONFIG_H

#define MASTER_USER     "user"  // your master username here
#define MASTER_PASS     "password" // your master password here
#define WIFI_SSID       "ssid" // your wifi ssid here
#define WIFI_PASS       "password" // your wifi password here
#define TYPE_DELAY_MS   40
#define UART_RX_PIN     44
#define UART_TX_PIN     43
#define UART_BAUD       115200
#define HOSTNAME        "web-virtual-keyboard"

#define MAX_PRESET_LENGTH   64
#define MAX_USER_LENGTH     128      
#define MAX_PASS_LENGTH     128
#define MAX_JSON_SIZE       16384 // holds all the presets, adjust accordingly

#define SERVER_PORT     80
#define UART_NUMBER     0

#define ENABLE_DISPLAY  true

#endif