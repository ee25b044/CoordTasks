#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <MPU6050.h>

const char* ssid = "F2-KDSK";
const char* password = "Kuruvi@0906";

MPU6050 mpu;
WebServer server(80);

int16_t ax, ay, az;
int16_t gx, gy, gz;

void handleRoot() {
  String html =
    "<!DOCTYPE html>"
    "<html>"
    "<head>"
    "<meta http-equiv='refresh' content='1'>"
    "<title>Please dont crash</title>"
    "</head>"
    "<body>"
    "<h1>Data for noobs</h1>"
    "<p>AX: " + String(ax) + "</p>"
    "<p>AY: " + String(ay) + "</p>"
    "<p>AZ: " + String(az) + "</p>"
    "<p>GX: " + String(gx) + "</p>"
    "<p>GY: " + String(gy) + "</p>"
    "<p>GZ: " + String(gz) + "</p>"
    "</body>"
    "</html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  mpu.initialize();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  
  mpu.getMotion6(
    &ax, &ay, &az,
    &gx, &gy, &gz
  );
  server.handleClient();
}