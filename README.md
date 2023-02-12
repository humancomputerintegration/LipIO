# LipIO: Enabling Lips as both Input and Output Surface
This repository includes software codes and an end-effector design file for the paper "LipIO: Enabling Lips as both Input and Output Surface" (ACM CHI2023).

## contents
### source codes
We share simple software codes to sense the tongue capacitive touch, calculate the centroid, stimulate a single channel, and visualize the capacitive sensing values.

- firmware: `code/Arduino/scripts/LipIO_firmware`  
    - Add `Seeed SAMD Boards` to Arduino IDE from Boards Manager.  
    - Upload `LipIO_firmware.ino` to [Seeeduino xiao](https://wiki.seeedstudio.com/Seeeduino-XIAO/).
    - Refer to [this link](https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/wiring) about the wiring of MPR121 (capacitive touch sensor).
    - Arduino IDE 1.8.19
- visualizer: `code/Processing/scripts/LipIO_visualize`  
    - Before running Processing, upload the firmware to Seeeduino xiao.
    - Change the `portName` constant to your correct port.
    - Type 0-4 to stimulate each electrode.
    - Processing 4.0b2

### end-effector design
`design` directory includes the path design of the LipIO device in Adobe Illustrator and pdf format. You can print the device with conductive ink or a craft cutter.

## schematics
![image](./schematics/schematics.jpg)

## stimulator 
Our software was tested with a medical-grade electrical stimulator, RehaMove. If you have RehaMove and want to learn more about how to control its stimulation output from your laptop (Unity, python), you should check the project page of our open-source library: https://github.com/humancomputerintegration/rehamove-integration-lib

## citing
<p>When using or building upon this device in an academic publication, please consider citing as follows:</p>

Arata Jingu, Yudai Tanaka, and Pedro Lopes. 2023. LipIO: Enabling Lips as both Input and Output Surface. In Proceedings of the 2023 CHI Conference on Human Factors in Computing Systems (CHI ’23), April 23–28, 2023, Hamburg, Germany. ACM, New York, NY, USA. https://doi.org/10.1145/3544548.3580775


## contact
For any questions about this repository, please contact jingu@cs.uni-saarland.de