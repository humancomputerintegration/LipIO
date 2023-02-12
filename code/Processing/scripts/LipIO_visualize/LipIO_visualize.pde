//----Params----
final String PORT_NAME = "/dev/cu.usbmodem14401";
final int BAUD_RATE = 115200;
final int NUM_LOC = 5;
final int SCREEN_WIDTH = 600;
final int SCREEN_HEIGHT = 450;
boolean isOnColocatedFb = false;
//--------

import processing.serial.*;
import processing.net.*; 
//Client reha;
Serial port;
int[] sensorVals = new int[NUM_LOC];
int[] stimIntensities = new int[NUM_LOC];

import java.util.*;
boolean isKeyReleased = false;
String idxStimStr = "-1";
int idxTouch = -1;

// GUI
import controlP5.*;
ControlP5 buttonCalibrate;
ControlP5 buttonTurnOffRelays;
ControlP5 sliderStimIntensities;
ControlP5 toggleColocatedFb;
Textarea textIdxTouch;


void settings()
{
  size(SCREEN_WIDTH, SCREEN_HEIGHT);
  //reha = new Client(this, "127.0.0.1", 50007); 
}

void setup()
{
  port = new Serial(this, PORT_NAME, 115200);
  surface.setResizable(true);
  
  // Initialize Sensor 
  calibrateSensors();
  
  
  // Initialize Stim
  for (int i=0; i<NUM_LOC; i++)
  {
    stimIntensities[i] = 2;
  }

  // GUI
  fill(0,0,0);
  textSize(40);
  
  sliderStimIntensities = new ControlP5(this);
  for(int i=0; i<NUM_LOC; i++)
  {
    sliderStimIntensities.addSlider("ch"+str(i), 2, 10)
      .setValue(stimIntensities[i])
      .setId(i)
      .setPosition(400, 20+i*10)
      .setColorCaptionLabel(color(0))
      .setNumberOfTickMarks(9);
  }
    
  buttonCalibrate = new ControlP5(this);
  buttonCalibrate.addButton("buttonCalibrate")
    .setPosition(400, 90)
    .setSize(80,60)
    .setLabel("Calibrate");
  
  buttonTurnOffRelays = new ControlP5(this);
  buttonTurnOffRelays.addButton("turnOffRelays")
    .setPosition(500, 90)
    .setSize(80,60)
    .setLabel("Turn off relays");
    
  toggleColocatedFb = new ControlP5(this);
  toggleColocatedFb.addToggle("toggleColocatedFb")
    .setPosition(400, 200)
    .setSize(30, 30)
    .setValue(isOnColocatedFb)
    .setLabel("ColocatedFb")
    .setColorLabel(color(0,0,0));
  
  textIdxTouch = (new ControlP5(this)).addTextarea("textIdxTouch")
    .setPosition(400, 250)
    .setFont(createFont("arial", 20))
    .setText("IdxTouch: -1")
    .setColor(color(0));
  
  turnOffRelays();
  delay(1000);
  turnOffColocatedFb();
}

void draw()
{
  // Read key
  if(!isOnColocatedFb && IsKeyReleased())
  {
    int idxStim = (int)key - 48;
    if(idxStim < 0 || idxStim >= NUM_LOC) return;
    String idxStimStr = str(idxStim);
    port.write(idxStimStr);
    println("Turn on channel " + idxStimStr);
  }
  
  // Draw Data
  background(255);
  fill(0,154,181);
  textSize(30);
  for (int i = 0; i < NUM_LOC; i++)
  {
    int val = sensorVals[i];
    int rect_x = 100+(NUM_LOC-i-1)*40;
    rect(rect_x, 400-3*val, 20, 3*val);
    text(str(i), rect_x+5, 400+25);
  }
  textIdxTouch.setText("IdxTouch: " + str(idxTouch));
}

void serialEvent(Serial p)
{
  String s = trim(p.readStringUntil('\n'));
  if(s == null) return;
  //println(s);
  int[] tokens = int(splitTokens(s, ","));
  idxTouch = tokens[5];
  sensorVals = Arrays.copyOf(tokens, NUM_LOC);
}

void keyReleased()
{
  isKeyReleased = true;
}

boolean IsKeyReleased()
{
  if (isKeyReleased)
  {
    isKeyReleased = false;
    return true;
  }
  else
  {
    return false;
  }
}

void calibrateSensors()
{
  port.write("-1");
  println("calibrateSensors");
}

void turnOnColocatedFb()
{
  port.write("-2");
  println("turnOnColocatedFb");
}

void turnOffColocatedFb()
{
  port.write("-3");
  println("turnOffColocatedFb");
}

void turnOffRelays()
{
  port.write("-4");
  println("turnOffRelays");
}


// GUIEvent
void controlEvent(CallbackEvent event)
{
  if(event.getAction() != ControlP5.ACTION_RELEASE) return;
  
  int sliderId = event.getController().getId();
  if((sliderId < 0) || (sliderId > NUM_LOC-1)) return;
  
  int value = (int) sliderStimIntensities.getController("ch"+str(sliderId)).getValue();
  stimIntensities[sliderId] = value;
  println("Slider "+ sliderId + ": changed to " + value);
}

void buttonCalibrate()
{
  calibrateSensors();
}

void toggleColocatedFb(boolean isOn)
{
  isOnColocatedFb = isOn;
  if (isOnColocatedFb)
  {
    turnOnColocatedFb();
  }
  else
  {
    turnOffColocatedFb();
  }
}

// reha
//void rehaOnePulse(int intensity)
//{
//  reha.write(100+intensity);
//}

//void reha2Sec(int intensity)
//{
//  reha.write(200+intensity);
//}
