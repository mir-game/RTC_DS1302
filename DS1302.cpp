#include "DS1302.h"


  DS1302::DS1302 (int CLK, int IO, int CE) {
    DS1302_CLK_PIN = CLK;
    DS1302_IO_PIN = IO;
    DS1302_CE_PIN = CE;
    
    pinMode(DS1302_IO_PIN, OUTPUT);
    pinMode(DS1302_CLK_PIN, OUTPUT);
    pinMode(DS1302_CE_PIN, OUTPUT);
    digitalWrite(DS1302_IO_PIN, LOW);
    digitalWrite(DS1302_CLK_PIN, LOW);
    digitalWrite(DS1302_CE_PIN, LOW);
    }

  void DS1302::readData (byte ADDRESS, byte &data){
    pinMode( DS1302_IO_PIN, OUTPUT);
    bitWrite( ADDRESS, 0, 1);             // address change to READ
    digitalWrite(DS1302_CE_PIN, HIGH);
    delayMicroseconds(4);                 // Tcc = 4us

    for(int i = 0; i<=7; ++i){  
     digitalWrite(DS1302_IO_PIN, bitRead(ADDRESS, i)); 
     delayMicroseconds(1); 
     digitalWrite(DS1302_CLK_PIN, HIGH);
     delayMicroseconds(1);
     if (i == 7){
      pinMode( DS1302_IO_PIN, INPUT);
      }   
      else {
        digitalWrite(DS1302_CLK_PIN, LOW);
        delayMicroseconds(1);
        }   
    }
   
      for(int i=0; i<=7; ++i){
     digitalWrite(DS1302_CLK_PIN, HIGH);
     delayMicroseconds(1);
     digitalWrite(DS1302_CLK_PIN, LOW);
     delayMicroseconds(1);
      bitWrite( data, i, digitalRead( DS1302_IO_PIN));
   
    }
   delayMicroseconds(1);
   digitalWrite(DS1302_CE_PIN, LOW);
}

  void DS1302::writeData(byte ADDRESS, byte &data){
    pinMode( DS1302_IO_PIN, OUTPUT);
    digitalWrite(DS1302_CE_PIN, HIGH);
    delayMicroseconds(4);                 // Tcc = 4us

    for(int i = 0; i<=7; ++i){  
     digitalWrite(DS1302_IO_PIN, bitRead(ADDRESS, i)); 
     delayMicroseconds(1); 
     digitalWrite(DS1302_CLK_PIN, HIGH);
     delayMicroseconds(1);
     digitalWrite(DS1302_CLK_PIN, LOW);
     delayMicroseconds(1);        
     }
   
    for(int i=0; i<=7; ++i){
     digitalWrite(DS1302_IO_PIN, bitRead(data, i));
     delayMicroseconds(1); 
     digitalWrite(DS1302_CLK_PIN, HIGH);
     delayMicroseconds(1);
     digitalWrite(DS1302_CLK_PIN, LOW);
     delayMicroseconds(1);        
    }
   digitalWrite(DS1302_CE_PIN, LOW);
    }
    
  byte DS1302::readSecond(){
    readData (DS1302_ADDRESS_SECONDS, secondsData);
    seconds = (secondsData & B00001111) + ((secondsData & B01110000)>>4)*10;
    return seconds;
    }
  byte DS1302::readMinutes(){
    readData (DS1302_ADDRESS_MINUTES, minutesData);
    minutes = (minutesData & B00001111) + ((minutesData & B01110000)>>4)*10;
    return minutes;
    }
  byte DS1302::readHours(){
    readData(DS1302_ADDRESS_HOURS, hoursData);
    hours = (hoursData & B00001111) + ((hoursData & B00110000)>>4)*10;
    return hours;
    }
  byte DS1302::readDate(){
    readData(DS1302_ADDRESS_DATE, dateData);
    date = (dateData & B00001111) + ((dateData & B00110000)>>4)*10;
    return date;
    }
  byte DS1302::readDay(){
    readData(DS1302_ADDRESS_DAY, dayData);
    day = (dayData & B00000111);
    return day;
    }
  byte DS1302::readMonth(){
    readData(DS1302_ADDRESS_MONTH, monthData);
    month = (monthData & B00001111) + ((monthData & B00010000)>>4)*10;
    return month;
    }
  byte DS1302::readYear(){
    readData(DS1302_ADDRESS_YEAR, yearData);
    year = (yearData & B00001111) + ((yearData & B11110000)>>4)*10;
    return year;
    }

  void DS1302::writeSecond(byte second){
    second = ( (second /10 ) << 4 ) | (second % 10);
    writeData(DS1302_ADDRESS_SECONDS, second);
    }
  void DS1302::writeMinutes(byte minutes){
    minutes = ( (minutes /10 ) << 4 ) | (minutes % 10);
    writeData(DS1302_ADDRESS_MINUTES, minutes);
    }
  void DS1302::writeHours(byte hours){
    hours = ( (hours /10 ) << 4 ) | (hours % 10);
    writeData(DS1302_ADDRESS_HOURS, hours);
    }
  void DS1302::writeDay(byte day){
    writeData(DS1302_ADDRESS_DAY, day);
    }
  void DS1302::writeDate(byte date){
    date = ( (date /10 ) << 4 ) | (date % 10);
    writeData(DS1302_ADDRESS_DATE, date);
    }
  void DS1302::writeMonth(byte month){
    month = ( (month /10 ) << 4 ) | (month % 10);
    writeData(DS1302_ADDRESS_MONTH, month);
    }
  void DS1302::writeYear(byte year){
    year = ( (year /10 ) << 4 ) | (year % 10);
    writeData(DS1302_ADDRESS_YEAR, year);
    }
  void DS1302::setWriteProtection(){
    byte data = B1000000;
    writeData(DS1302_ADDRESS_WP, data );
    }
  void DS1302::removeWriteProtection(){
    byte data = B0000000;
    writeData(DS1302_ADDRESS_WP, data );
    }
  void DS1302::writeToRam(byte ADDRESS, byte data){
    writeData(ADDRESS, data );
    }
  byte DS1302::readFromRam(byte ADDRESS){
    byte ramData;
    ++ADDRESS; 
    readData(ADDRESS, ramData);
    return ramData;
    }

  
