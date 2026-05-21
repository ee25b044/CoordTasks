#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.clear();

  mx.setPoint(1, 2, true);
  mx.setPoint(2, 2, true);

  mx.setPoint(1, 5, true);
  mx.setPoint(2, 5, true);

  mx.setPoint(4, 1, true);
  mx.setPoint(5, 1, true);
  mx.setPoint(4, 6, true);
  mx.setPoint(5, 6, true);

  mx.setPoint(6, 1, true);
  mx.setPoint(6, 2, true);
  mx.setPoint(6, 3, true);
  mx.setPoint(6, 4, true);
  mx.setPoint(6, 5, true);
  mx.setPoint(6, 6, true);

}

void loop() {
}