#include "oled-wing-adafruit.h"

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
  // Displays the reset reason
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
  // Initializes the watchdog timer
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
