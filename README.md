# Digital_Clock
Arduino Digital clock using 
- Arduino uno
- 13 LEDS
- DS3231 RTC
- Breadboard
- Wires

!!! Make sure to download and implement the provided library !!! 

After downloading DS3231.zip go to your arduino IDE; Sketch > Include Library > ADD .ZIP Library

There is a .png schematic, as well as a .fzz. (Fritzing)

Mke sure to run 'DS3231_Updater.ino' first to update the RTC time. Depending on your development environment, or system, 
the time may or may not be set automatically based off your OS.
If it isn't automatically calibrated, there are instructions in 'DS3231_Updater.ino' to recalibrate.
You can then directly run Digital_Clock.ino 


!Note!
The RTC seems to be a couple (6-7) seconds off, may vary from module to module. 
