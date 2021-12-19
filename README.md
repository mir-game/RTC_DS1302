# RTC_DS1302

Created by Andrej Mironov for Assignment in Module MCS40 on AKAD University Stuttgart.

Simple Library for Arduino to communicate with Real Time Clock module DS1302.

Note: currently only implemented for 0-23 hours.

Functions:

    byte readSecond();
    byte readMinutes();
    byte readHours();
    byte readDay();
    byte readDate();
    byte readMonth();
    byte readYear();

    void writeSecond(byte second);
    void writeMinutes(byte minutes);
    void writeHours(byte hours);
    void writeDay(byte day);
    void writeDate(byte date);
    void writeMonth(byte month);
    void writeYear(byte year);
    void setWriteProtection();
    void removeWriteProtection();
    
    void writeToRam(byte ADDRESS, byte data);
    byte readFromRam(byte ADDRESS);