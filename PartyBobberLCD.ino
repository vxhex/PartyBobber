/*********************
PartyBobber v2.0 LCD Shield

Uses the Adafruit RGB Character LCD Shield and Library
**********************/

#include <Wire.h>
#include <utility/Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define ARRAY_SIZE 5
char* strings[] = {"#TeamPedobear", "Pirate Box", "B33r H4x0rz", "DefCon XXI", "BSidesLV"};
char* credits[] = {"By: VxHex & RobP", "FingerGarden.org"};
char* pbob = "PartyBobber v2.0";
boolean randomMode = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print(credits[0]);
  lcd.setCursor(0, 1);
  lcd.print(credits[1]);
}

void loop() {
  if(randomMode && (((millis()/1000) % 5) == 0)) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(pbob);
    lcd.setCursor(0,0);
    lcd.print(strings[random(0, ARRAY_SIZE)]);
    delay(1000);
  }

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(pbob);
    lcd.setCursor(0,0);
    
    //B33r H4x
    if (buttons & BUTTON_UP) {
      lcd.print(strings[2]);
      randomMode = false;
    }
    //DC 21
    if (buttons & BUTTON_DOWN) {
      lcd.print(strings[3]);
      randomMode = false;
    }
    //Pirate Box
    if (buttons & BUTTON_LEFT) {
      lcd.print(strings[1]);
      randomMode = false;
    }
    //Team Pedobear
    if (buttons & BUTTON_RIGHT) {
      lcd.print(strings[0]);
      randomMode = false;
    }
    //Random mode
    if (buttons & BUTTON_SELECT) {
      lcd.print("Random mode!");
      randomMode = true;
    }
  }
}
