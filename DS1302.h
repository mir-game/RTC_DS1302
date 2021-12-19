#include <arduino.h>

#define DS1302_ADDRESS_SECONDS  0x80    // Address for write, for read add 1
#define DS1302_ADDRESS_MINUTES  0x82    // Address for write, for read add 1
#define DS1302_ADDRESS_HOURS    0x84    // Address for write, for read add 1
#define DS1302_ADDRESS_DATE     0x86    // Address for write, for read add 1
#define DS1302_ADDRESS_MONTH    0x88    // Address for write, for read add 1
#define DS1302_ADDRESS_DAY      0x8A    // Address for write, for read add 1
#define DS1302_ADDRESS_YEAR     0x8C    // Address for write, for read add 1
#define DS1302_ADDRESS_WP       0x8E    // Address for write protection

#define uint8_t byte

class DS1302 {
  private:
    byte secondsData, minutesData, hoursData, dateData, dayData, monthData, yearData;
    byte seconds, minutes, hours, date, day, month, year;
    
    int DS1302_CLK_PIN, DS1302_IO_PIN, DS1302_CE_PIN;
  
    void readData (byte ADDRESS, byte &data);
    void writeData(byte ADDRESS, byte &data);
    
  public:

    DS1302 (int CLK, int IO, int CE);   // Constructor with PINs
  
    byte readSecond();
    byte readMinutes();
    byte readHours();
    byte readDay();
    byte readDate();
    byte readMonth();
    byte readYear();
  
    void writeSecond(byte second);				// Values 0-59
    void writeMinutes(byte minutes);			// Values 0-59
    void writeHours(byte hours);				// Values 0-23
    void writeDay(byte day);					// Values 0-7
    void writeDate(byte date);					// Values 1-31
    void writeMonth(byte month);				// Values 1-12
    void writeYear(byte year);					// Values 0-99
    void setWriteProtection();
    void removeWriteProtection();
    void writeToRam(byte ADDRESS, byte data);	// Address  C0h - FCh
    byte readFromRam(byte ADDRESS);				// Address  C0h - FCh
  
  };
