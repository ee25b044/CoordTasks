#include <cmath>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 5

#define XPot 34
#define YPot 35

int circle[12][2] = {
  {3,3},
  {3,4},
  {4,3},
  {4,4},
  {2,3},
  {2,4},
  {5,3},
  {5,4},
  {3,2},
  {4,2},
  {3,5},
  {4,5}
};

int arrowUP[22][2] = {
  {0,3},
  {0,4},
  {1,2},
  {1,3},
  {1,4},
  {1,5},
  {2,6},
  {2,1},
  {2,2},
  {2,3},
  {2,4},
  {2,5},
  {3,3},
  {3,4},
  {4,3},
  {4,4},
  {5,3},
  {5,4},
  {6,3},
  {6,4},
  {7,3},
  {7,4}
};

int arrowRIGHT[22][2] = {
  {3,0},
  {4,0},
  {2,1},
  {3,1},
  {4,1},
  {5,1},
  {1,2},
  {6,2},
  {2,2},
  {3,2},
  {4,2},
  {5,2},
  {3,3},
  {4,3},
  {3,4},
  {4,4},
  {3,5},
  {4,5},
  {3,6},
  {4,6},
  {3,7},
  {4,7}
};

int arrowLEFT[22][2] = {
  {3,7},
  {4,7},
  {2,6},
  {3,6},
  {4,6},
  {5,6},
  {1,5},
  {6,5},
  {2,5},
  {3,5},
  {4,5},
  {5,5},
  {3,4},
  {4,4},
  {3,3},
  {4,3},
  {3,2},
  {4,2},
  {3,1},
  {4,1},
  {3,0},
  {4,0}
};

int arrowDOWN[22][2] = {
  {7,3},
  {7,4},
  {6,2},
  {6,3},
  {6,4},
  {6,5},
  {5,1},
  {5,6},
  {5,2},
  {5,3},
  {5,4},
  {5,5},
  {4,3},
  {4,4},
  {3,3},
  {3,4},
  {2,3},
  {2,4},
  {1,3},
  {1,4},
  {0,3},
  {0,4}
};

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(115200);
  mx.begin();
  mx.clear();

}

void loop() {
  int xRaw = analogRead(XPot);
  int yRaw = analogRead(YPot);

  float xNorm = pow((xRaw - 2048.0) / 2048.0,3);
  float yNorm = pow((yRaw - 2048.0) / 2048.0,3);

  float deadzone = 0.1;

  if (abs(xNorm) < deadzone && abs(yNorm) < deadzone) {
      Serial.println("No direction");
      render(circle,12);
  }
  else if (abs(xNorm) > abs(yNorm)) {
    if (xNorm > 0){
        Serial.println("Down");
        render(arrowDOWN,22);
    }
    else{
        Serial.println("Up");
        render(arrowUP,22);
    }
  } 
  else {
    if (yNorm > 0){
        Serial.println("Left");
        render(arrowLEFT,22);
    }
    else{
        Serial.println("Right");
        render(arrowRIGHT,22);
    }
  }
  delay(100);
}

void render(int arr[][2], int rows){
  mx.clear();
  for (int i = 0; i < rows; i++) {
    mx.setPoint(arr[i][0], arr[i][1], true);
  }
}
