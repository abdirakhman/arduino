#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Init
int sec;
int mint =  7;
int hur = 8;
int dy = 23;
int mnth = 10;
int yer = 2018;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {

  for (sec = 0 ; sec < 60 ; sec++) {
    lcd.setCursor(6, 0); lcd.print(":");
    lcd.setCursor(9, 0); lcd.print(":");
    Serial.print(mint); Serial.print(":");
    Serial.println(sec);
    if (hur <= 9) {
      lcd.setCursor(4, 0); lcd.print("0");
      lcd.setCursor(5, 0); lcd.print(hur);
    }
    else if (hur > 9) {
      lcd.setCursor(4, 0); lcd.print(hur);
    }

    if (mint <= 9) {
      lcd.setCursor(7, 0); lcd.print("0");
      lcd.setCursor(8, 0); lcd.print(mint);
    }
    else if (mint > 9) {
      lcd.setCursor(7, 0); lcd.print(mint);
    }


    if (sec <= 9) {
      lcd.setCursor(10, 0); lcd.print("0");
      lcd.setCursor(11, 0); lcd.print(sec);
    }
    else if (hur > 9) {
      lcd.setCursor(10, 0); lcd.print(sec);
    }


lcd.setCursor(5, 1); lcd.print("/");
lcd.setCursor(8, 1); lcd.print("/");


if (dy <= 9) {
      lcd.setCursor(3, 1); lcd.print("0");
      lcd.setCursor(4, 1); lcd.print(dy);
    }
    else if (dy > 9) {
      lcd.setCursor(3, 1); lcd.print(dy);
    }

if (mnth <= 9) {
      lcd.setCursor(6, 1); lcd.print("0");
      lcd.setCursor(7, 1); lcd.print(mnth);
    }
    else if (mnth > 9) {
      lcd.setCursor(6, 1); lcd.print(mnth);
    }


      lcd.setCursor(9, 1); lcd.print(yer);
    
   
    
    delay(1000);
   // lcd.clear();
  }
  mint = mint + 1;
  if (mint == 60) {
    hur = hur + 1;
    mint = 0 ;
  }

  if (hur == 24) {
    hur = 0;
    dy = dy + 1;
  }

  if (dy == 31) {
    mnth = mnth + 1;
    dy = 0;
  }

  if (mnth == 13) {
    yer = yer + 1;
    mnth = 0;
  }


}
