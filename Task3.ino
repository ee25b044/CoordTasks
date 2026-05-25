#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/FreeMonoBold9pt7b.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
    Wire.begin(21,22);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();

    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0,20);
    display.println("Elecfest To Universe");
    display.println("Hello!");

    display.display();
}

void loop() {
}