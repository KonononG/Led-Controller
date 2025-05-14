#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define numLight 50
#define numLeds 4

typedef struct {
  int id;
  bool isOn;
  bool autoControl;
  char name[20];
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
    printf("Qual o nome dado ao led? \n");
    scanf("%s",leds[i].name);
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
    printf("LED %s (%s): %s\n", leds[i].name, leds[i].autoControl ? "Auto":"Manual",leds[i].isOn ? "on":"off");
  }
}

void testSys(LED leds[]) {
  int lightLevel;
  while(1){
    printf("Insira o nivel de luz: \n");
    //scanf("%d",&lightLevel);

    if(scanf("%d",&lightLevel)){
      updateLED(lightLevel, leds);
      printLED(leds);
      printf("(Para sair, insira uma letra)\n");
    }
    else {
      break;
    }
  }
}


int main() {
  int lightLevel = 0;
  LED leds[numLeds];
  int menuChoice;

  configLED(leds);

  while(1) {
    printf("O que deseja fazer? \n");
    printf("1 - Mudar configuracao dos leds. \n");
    printf("2 - Testar sistema. \n");
    printf("3 - Sair. \n");
    scanf("%d",&menuChoice);

    switch (menuChoice) {
      case 1: 
        configLED(leds);
        break;
      case 2:  
        testSys(leds);
      case 3:
        return 0;
      default:
        printf("Essa opcao nao existe por favor digite outra. \n");
        break;
    }
  }
  return 0;
}
