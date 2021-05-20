#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int switch_pin = 6;
int switch_state = 0;
int prev_switch_state = 0;
int reply;


void setup() 
{
  lcd.begin(16,2);
  pinMode(switch_pin, INPUT);
  
  lcd.print("ask the");
  lcd.setCursor(0,1);
  lcd.print("Arduino");
}

void loop() 
{
  switch_state = digitalRead(switch_pin);
  if (switch_state != prev_switch_state)
  {
    if(switch_state == LOW)
    {
       reply = random(8); 

       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("the Arduino says: ");
       lcd.setCursor(0, 1);
         
       switch(reply)
       {
          case 0:
          lcd.print("No");
          break;
          case 1:
          lcd.print("Yes");
          break;
          case 2:
          lcd.print("Maybe one day");
          break;
          case 3:
          lcd.print("Ask again");
          break;
          case 4:
          lcd.print("Probably not");
          break;
          case 5:
          lcd.print("Ever or never");
          break;
          case 6:
          lcd.print("Most likely");
          break;
          case 7:
          lcd.print("The day will come");
          break;
       }
    }  
  }
  prev_switch_state = switch_state;
}
