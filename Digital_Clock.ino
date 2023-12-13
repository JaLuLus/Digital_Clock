#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

DS3231 rtc(SDA, SCL);

int bHour[4] = {1, 2, 4, 8};
int bMin[6] = {1, 2, 4, 8, 16, 32};

void setup() {
  Serial.begin(9600);
  rtc.begin();
  
  // minutes; pins 13 - 8
  for(int x = 8; x < 14; x++) 
  {
    pinMode (x, OUTPUT);
    digitalWrite(x, LOW);
  }

  // hour; pins 2 - 5
  for(int y = 2; y < 6; y++) 
 {
    pinMode (y, OUTPUT);
    digitalWrite(y, LOW);
  }

  // A.M & P.M; pins 7 and 6
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);


}

void loop() {
  // Hour and Minute
  String time_Str= rtc.getTimeStr(1);
  String com = String(time_Str[0]) + String(time_Str[1]);
  String com2 = String(time_Str[3]) + String(time_Str[4]);
  int hour = com.toInt();
  int minutes = com2.toInt();
  // int AP = 0;
  int mVal = minutes;
  int hVal;
  
  // if 
  if (hour > 12) {
    hVal = hour % 12;
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }

  for (int i = 3; i >= 0; i--) {
      if ((hVal - bHour[i]) >= 0) {
        hVal = hVal - bHour[i];
        digitalWrite(2 + i, HIGH);
      }
      else{
        digitalWrite (5 - i, LOW);
      }
  }

  for (int y = 5; y >= 0; y--) {
    if ((mVal - bMin[y]) >= 0) {
      mVal = mVal - bMin[y];
      digitalWrite(y + 8, HIGH);
    }
    else {
      digitalWrite(y + 8, LOW);
    }
  }
  
  // RTC Checker

  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  // Send date
  Serial.print(rtc.getDateStr(2, 3 , '/'));
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());

  // Wait one second before repeating
  delay(1000);
  // end of RTC Checker
}
