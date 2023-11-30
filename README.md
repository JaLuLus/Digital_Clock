# Digital_Clock
Arduino Digital clock using 
- 13 LEDS
- DS3231 RTC
Make sure to download and implement the provided library. 

Before running the 'Digital_clock.ino', make sure to run 'DS3231_Updater.ino' first. This is to ensure
that the RTC will be calibrated to your time based off your OS. You can then run Digital_Clock.ino.

Note that the RTC seems to be a couple (6-7) seconds off, may vary from module to module. 
Which could be fixed through hardcoding the fix. IE adding 6 to the seconds.

No Arduino schematics yet.
