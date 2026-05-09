This project is already set up perfectly for PlatformIO in VS Code, which is the easiest way to work with LilyGo boards.

Step-by-step guide for you:

1. Install PlatformIO in VS Code (if you haven't already)

Open VS Code.
Click on the Extensions icon (square blocks) on the left sidebar.
Search for "PlatformIO IDE" (official one by PlatformIO).
Click Install and wait for it to finish (it downloads quite a lot the first time).


2. Download the project

Go to: https://github.com/nodswal/Web-Virtual-Keyboard or https://github.com/DotaPie/Web-Virtual-Keyboard if you want the original (which connects to an existing WI-FI network, it does not create its own)
Click the green Code button → Download ZIP.
Extract the ZIP file somewhere convenient.

Inside the extracted folder you will see a subfolder called Web-Virtual-Keyboard-platformio.
This is the actual PlatformIO project.
3. Open the project in VS Code, if you opened the correct folder it will download components and give you a menu based on the project.

In VS Code, go to File → Open Folder and select the Web-Virtual-Keyboard-platformio folder.

You should now see the PlatformIO sidebar on the left (alien head icon in the side bar where you see Extensions and Explorer).


4. Edit config.h (use explorer to browse the files)

Open the file include/config.h.
Change these lines:

C++#define WIFI_SSID       "your_wifi_name"
#define WIFI_PASS       "your_wifi_password"

#define MASTER_USER     "admin"      // username for the web login
#define MASTER_PASS     "password"   // password for the web login

Tip: Use a strong password if the device will be on Wi-Fi.

If you're not using the exact LILYGO T-Dongle S3, you may also need to change the board in platformio.ini.


5. Build & Upload

Click the PlatformIO icon on the left (click the alien head in the side bar).
Under Project Tasks → your environment (probably lilygo_t_dongle_s3 or similar) → click Build.
If it builds without errors, click Upload.
First time it can take a few minutes (downloads ESP32 tools).


Tip: Put the board in bootloader mode if upload fails:

Hold the BOOT button while plugging in USB, then release it after a few seconds, the screen will be back light but blank.  This does require a firm press of the button to put it into programming mode.


6. Test it

After flashing, plug the native USB (the one on the dongle) into the target computer where you want the virtual keyboard.
The device should connect to Wi-Fi and show its IP address on the small display.
On any device on the same Wi-Fi, open browser and go to http://IP_SHOWN_ON_SCREEN

You should see the login page.

Common issues & fixes

Upload fails → Hold BOOT button while plugging USB.
Can't see IP → Connect a USB-to-UART adapter to the pins and open serial monitor (in PlatformIO: Monitor task) to see logs.
Board not recognized → Check platformio.ini and make sure the board is set correctly.
