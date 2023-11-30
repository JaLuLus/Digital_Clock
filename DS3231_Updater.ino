#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

DS3231 rtc(SDA, SCL);

int getMonthNumber(const char* monthStr) {
  const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  for (int i = 0; i < 12; i++) {
    if (strcmp(monthStr, months[i]) == 0) {
      return i + 1;  // Months are 1-based in setDate function
    }
  }

  // Default to January if the month string is not recognized
  return 1;
}

void setup() {
  Serial.begin(9600);
  rtc.begin();

  // __TIME__ is coordinated with UTC time, but your environment is likely to adjust the time baesd off your OS
  int hours, minutes, seconds;
  sscanf(__TIME__, "%d:%d:%d", &hours, &minutes, &seconds);

  
  // Each variable could, and should, be hardcoded if the offbalanced time is constant.
  // For example, seconds constantly being 6 seconds off can be fixed by '..., seconds + 6)'
  rtc.setTime(hours, minutes, seconds);

  int day, month, year;
  char monthStr[4];
  // Parse the date string obtained from __DATE__ macro
  sscanf(__DATE__, "%s %d %d", monthStr, &day, &year);

  month = getMonthNumber(monthStr);
  // Set the date using the extracted components
  rtc.setDate(day, month, year);
  rtc.setDOW();
}

void loop() {
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr(1));
  Serial.print(": ");
  // Send date
  Serial.print(rtc.getDateStr(2, 3, '/'));
  Serial.print(" - ");
  Serial.println(rtc.getTimeStr(1)); // Send time, if parameter is set to 1, it will be hours and minutes only, 0 for seconds as well
  

  // Wait one second before repeating
  delay(1000);
}
