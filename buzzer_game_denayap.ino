#include "Adafruit_LiquidCrystal.h"

#define LED D8
#define DET D9
int sayac = 0;
Adafruit_LiquidCrystal lcd(D10, D13, D15, D12, D11, D14); 

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(DET, INPUT);
  lcd.begin(16, 2);
  lcd.clear();

}

void loop() {

  lcd.clear();
  
 int buttonState = digitalRead(DET);

  lcd.print("TEMAS SAYISI");
  if(buttonState == 1){ 
    sayac++;
    digitalWrite(LED, HIGH);
    delay(700);
    digitalWrite(LED, LOW);
      }
      else{
    digitalWrite(LED, LOW);
    lcd.setCursor(0,1); 
    lcd.print (sayac);
    }
    if(sayac>=10){
       lcd.clear();
       lcd.print("YANDINIZ");
       lcd.setCursor(0,1); 
       lcd.print ("-");
       digitalWrite(LED, HIGH);
       delay(3000);
       digitalWrite(LED, LOW);
       sayac=0;
    }
      
  Serial.println(buttonState);
}
