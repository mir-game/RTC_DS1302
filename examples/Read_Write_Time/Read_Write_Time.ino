#include <DS1302.h>

#define DS1302_CLK_PIN        8
#define DS1302_IO_PIN         7
#define DS1302_CE_PIN         6

byte seconds, minutes, hours, date, day, month, year;

DS1302 rtc (DS1302_CLK_PIN, DS1302_IO_PIN, DS1302_CE_PIN);

void setup() {
   Serial.begin(9600);
  // Create new Time and Date
  seconds = 0;
  minutes = 30;
  hours = 12;
  date = 25;
  day = 6;
  month = 9;
  year = 21;
  
  // Write data to DS1302
  rtc.writeSecond(seconds);
  rtc.writeMinutes(minutes);
  rtc.writeHours(hours);
  rtc.writeDate(date);
  rtc.writeMonth(month);
  rtc.writeYear(year);
  rtc.writeDay(day);
}

void loop() {
  // Read data from DS1302
  seconds = rtc.readSecond();
  hours = rtc.readHours();
  minutes = rtc.readMinutes();
  day = rtc.readDay();
  date = rtc.readDate();
  month = rtc.readMonth();
  year = rtc.readYear();

  writeTimeToSerial();
  delay(1000);
}

void writeTimeToSerial(){
  Serial.print(hours); Serial.print(":"); 
  Serial.print(minutes); Serial.print(":"); 
  Serial.print(seconds); Serial.print("    "); 

  switch (day){
    case (1): Serial.print("Monday"); break;
    case (2): Serial.print("Tuesday"); break;
    case (3): Serial.print("Wednesday"); break;
    case (4): Serial.print("Thursday"); break;
    case (5): Serial.print("Friday"); break;
    case (6): Serial.print("Saturday"); break;
    case (7): Serial.print("Sunday"); break;
    }
  Serial.print("    "); 
  Serial.print(date); Serial.print(".");
  Serial.print(month); Serial.print(".");
  Serial.print(year); Serial.print("\n");
  }
