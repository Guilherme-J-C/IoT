// C++ code
//
#include <Adafruit_LiquidCrystal.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd_1(10, 9, 8, 7, 6, 5);
int botao=0;
int carrovermelho=13;
int carroamarelo=12;
int carroverde=11;
int pedestrevermelho=2;
int pedestreverde=1;
int buzzer=4;
int sensor=3;

void setup()
{
  pinMode(carrovermelho, OUTPUT);
  pinMode(carroamarelo, OUTPUT);
  pinMode(carroverde, OUTPUT);
  lcd_1.begin(16, 2); 
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(pedestrevermelho, OUTPUT);
  pinMode(pedestreverde, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  digitalWrite(pedestrevermelho, HIGH);
  digitalWrite(carroverde, HIGH);
  
  if (digitalRead(botao) == 0) {
    digitalWrite(carroverde, LOW);
    digitalWrite(carroamarelo, HIGH);
    delay(6000); 
    
    digitalWrite(carroamarelo, LOW);
    digitalWrite(carrovermelho, HIGH);
    delay(1000); 
    
    for (int y=0; y<8; y++){
    digitalWrite(pedestrevermelho, LOW);
    digitalWrite(pedestreverde, HIGH);
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("     SEGURO,");
    lcd_1.setCursor(0, 1);
    lcd_1.print("PODE ATRAVESSAR!");
    tone(buzzer,440 ,100);
    delay(1000);
      
    }
    for (int y=0; y<4; y++){
    digitalWrite(pedestreverde, LOW);
    digitalWrite(pedestrevermelho, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.print("     SEGURO,");
    lcd_1.setCursor(0, 1);
    lcd_1.print("PODE ATRAVESSAR!");
    delay(500);
    
    digitalWrite(pedestrevermelho, LOW);
    lcd_1.clear();
    delay(500);
      
    }
    digitalWrite(pedestrevermelho, HIGH);
    delay(1000);
    
    digitalWrite(carrovermelho, LOW);
    digitalWrite(carroverde, HIGH);
    delay(10000);
    
  }
  if (digitalRead(sensor) == 1) {
    tone(buzzer, 440, 1000); 
    lcd_1.setCursor(0, 0);
    lcd_1.print("     PERIGO,");
    lcd_1.setCursor(0, 1);
    lcd_1.print(" SINAL VERMELHO!");
  }
}