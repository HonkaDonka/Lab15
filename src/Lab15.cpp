/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/vinso/Documents/CTDIoT2023/Lab15/src/Lab15.ino"
#include "oled-wing-adafruit.h"

void setup();
void loop();
void resetDisplay();
#line 3 "c:/Users/vinso/Documents/CTDIoT2023/Lab15/src/Lab15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#define BUTTONPIN D5

OledWingAdafruit display;

void setup()
{
  Serial.begin(9600);
  while (!Serial.isConnected())
  {
  }

  display.setup();
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  pinMode(BUTTONPIN, INPUT_PULLDOWN);

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    resetDisplay();
    display.println("WATCHDOG RESET");
    display.display();
  }
  else
  {
    resetDisplay();
    display.println("NORMAL RESET");
    display.display();
  }
  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();
}

void loop()
{
  if (digitalRead(BUTTONPIN) == HIGH)
  {
    Watchdog.refresh();
  }
}

void resetDisplay()
{
  display.clearDisplay();
  display.setCursor(0, 0);
}
