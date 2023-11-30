# Digital_Clock
Arduino Digital clock using 
- Arduino uno
- 13 LEDS
- DS3231 RTC
- Breadboard
- Wires (ofc)

!!! Make sure to download and implement the provided library !!! 

After downloading DS3231.zip go to your arduino IDE; Sketch > Include Library > ADD .ZIP Library


Before running the 'Digital_clock.ino', make sure to run 'DS3231_Updater.ino' first. This is to ensure
  that the RTC will be calibrated to your time based off your OS. You can then run Digital_Clock.ino.


!Note!
The RTC seems to be a couple (6-7) seconds off, may vary from module to module. 
Could be fixed through hardcoding the fix. For me that would be adding 6 to seconds.

No Arduino schematics yet.

