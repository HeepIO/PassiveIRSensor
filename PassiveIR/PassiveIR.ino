
#include "HeepDeviceDefinitions.h"

#define IRSENSE_PIN 14

void InitializeControlHardware(){
  pinMode(IRSENSE_PIN,INPUT);
}

int ReadIRSense(){
  int currentSetting = digitalRead(IRSENSE_PIN);
  SetControlValueByName("IRSense",currentSetting);
  return currentSetting;
}

void setup()
{

  Serial.begin(115200);
  InitializeControlHardware();
  AddOnOffControl("IRSense",HEEP_OUTPUT,0);
  StartHeep(heepDeviceName, 7);

}

void loop()
{
  PerformHeepTasks();
  ReadIRSense();
}
