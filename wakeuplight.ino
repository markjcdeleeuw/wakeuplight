#include <LiquidCrystal.h>



const int switchPin = 8; 
unsigned long previousTime = 000000; 
unsigned long Seconds = 0;
unsigned long TenSeconds = 0;
unsigned long Minutes = 0;
unsigned long Tenminutes = 0;
unsigned long Hours = 0;
unsigned long Tenhours = 0;
unsigned long Clocktime = 0;
int led = 2; 
long interval = 60000; 
long lastTimeReading = 0;
unsigned long currentTime = millis(); 
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
  for (int x = 2;x<8;x++){ 
  pinMode (x, OUTPUT);
} 
}
void loop() {
 unsigned long currentTime = millis();

if (millis() >0) 
{
Clocktime= millis(); 
 Tenhours = Clocktime /36000000, DEC;  
 Clocktime = Clocktime - (Tenhours * 36000000) ;
 Hours = Clocktime /3600000, DEC;
 Clocktime = Clocktime - (Hours * 3600000);
 Tenminutes = Clocktime /600000, DEC;
 Clocktime = Clocktime - (Tenminutes * 600000);
 Minutes = Clocktime  /60000, DEC;
 Clocktime = Clocktime - (Minutes * 60000);
  TenSeconds = Clocktime /10000, DEC;
  Clocktime = Clocktime - (TenSeconds * 10000) ;
  Seconds = Clocktime /1000, DEC;

  // above calculation makes it so that minutes won't exceed 60 etc. 
   
  lcd.setCursor(15, 1); 
  // print the number of seconds since reset:
  lcd.print(Seconds);  
     lcd.setCursor (14, 1); 
  lcd.print(TenSeconds);   
   lcd.setCursor(13, 1);
  // print the number of seconds since reset:
  lcd.print(Minutes);
   lcd.setCursor(12, 1);
  // print the number of seconds since reset:
  lcd.print(Tenminutes);
   lcd.setCursor(11, 1);
  // print the number of seconds since reset:
  lcd.print(Hours);
 lcd.setCursor(10, 1);
  // print the number of seconds since reset:
  lcd.print(Tenhours);
  delay (1000); } 
     
if ( currentTime / 12600000 > 1)
// this is where you insert the wake up time in milli seconds, if you turn on the arduino at 00:00, calculate the amount of milliseconds from 00:00 and divide that number by 2, insert above) 
{

if (currentTime - previousTime > interval){ 
 previousTime = currentTime; 
digitalWrite (led, HIGH);
led++;
}
}
}
