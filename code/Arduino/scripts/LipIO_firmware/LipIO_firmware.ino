#include <CommonParams.h>
#include <Sensor.h>
#include <Stimulator.h>

int idxTouch = -1;
boolean isOnColocatedFb = false;

Sensor sensor = Sensor(NUM_CHANNELS, THRESH_SENSOR);
Stimulator stimulator = Stimulator(NUM_CHANNELS);

void setup()
{
  Serial.begin(BAUD_RATE);

  sensor.Initialize();
  stimulator.TurnOffAllChannels();
}

void loop()
{
  if(Serial.available() > 0)
  {
    int idxInput = Serial.readStringUntil('\n').toInt();
    switch(idxInput)
    {
      case -1:
        sensor.Initialize();
        break;
      case -2:
        // turn on "co-located feedback"
        isOnColocatedFb = true;
        break;
        
      case -3:
        // turn off "co-located feedback"
        isOnColocatedFb = false;
        break;
        
      case -4:
        stimulator.TurnOffAllChannels();
        break;
        
      default:
        if ((idxInput >= 0) && (idxInput < NUM_CHANNELS))
        {
          stimulator.TurnOnSingleChannel(idxInput);
        }
        
        break;
    }
  }

  
  // Sensor
  idxTouch = sensor.CalculateIdxTouch();

  // Co-located feedback
  if (isOnColocatedFb)
  {
    stimulator.TurnOnSingleChannel(idxTouch);
  }

  // Serial send
  String s = "";
  s += sensor.GetAllDroppings() + ",";
  s += String(idxTouch);
  Serial.println(s);
}
