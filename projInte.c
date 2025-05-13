#include <stdio.h>
#include <stdbool.h>

#define numLight 50
#define numLeds 4

typedef struct {
  int id;
  bool isOn;
  bool autoControl;
}LED;

void configLED(LED leds[]) {
  int choice;

  for(int i=0;i<numLeds;i++){
    leds[i].id = i;
    leds[i].isOn = false;
    leds[i].autoControl = false;

    printf("Deseja que o led %d seja controlado pelo sensor? \n",i+1);
    scanf("%d",&choice);
    leds[i].autoControl = (choice==1);
  }
}

void updateLED(int lightLevel,LED leds[]) {
  bool turnOn = lightLevel < numLight;

  for(int i = 0; i < numLeds; i++){
    if(leds[i].autoControl){
      leds[i].isOn = (turnOn);
    }
  }
}

void printLED(LED leds[]) {
  for(int i = 0; i < numLeds; i++) {
    printf("LED %d (%s): %s\n", leds[i].id + 1, leds[i].autoControl ? "Auto":"Manual",leds[i].isOn ? "on":"off");
  }
}

int main() {
  int lightLevel = 0;
  LED leds[numLeds];

  configLED(leds);

  while(1) {
    printf("Enter the light level: \n");
    scanf("%d",&lightLevel);

    updateLED(lightLevel, leds);
    printLED(leds);
  }

  return 0;
}
