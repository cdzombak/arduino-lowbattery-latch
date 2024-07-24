#include <avr/sleep.h>
#include <avr/interrupt.h>

#define comparatorPin 9 // D9

#define comparatorBatteryOK LOW
#define comparatorBatteryLow HIGH

#define relayTransistorPin 7 // D7
#define lowBatteryLEDPin 8 // D8

#define ledPinOff HIGH
#define ledPinOn LOW

#define relayPinOff LOW
#define relayPinOn HIGH

int repeatedComparatorBatteryLowReadings = 0;

void setup() {
  pinMode(relayTransistorPin, OUTPUT);
  digitalWrite(relayTransistorPin, relayPinOff);
  pinMode(lowBatteryLEDPin, OUTPUT);
  digitalWrite(lowBatteryLEDPin, ledPinOff);
  pinMode(comparatorPin, INPUT);

  int repeatedComparatorOKReadings = 0;
  for (int i = 0; i < 5; i++) {
    delay(20);
    if (digitalRead(comparatorPin) == comparatorBatteryOK) {
      repeatedComparatorOKReadings++;
    }
  }

  if (repeatedComparatorOKReadings >= 4) {
    onBatteryOK();
  } else {
    onBatteryLow();
  }
}

void loop() {
  if (digitalRead(comparatorPin) == comparatorBatteryLow) {
    repeatedComparatorBatteryLowReadings++;
  } else {
    repeatedComparatorBatteryLowReadings = 0;
  }

  if (repeatedComparatorBatteryLowReadings >= 5) {
    onBatteryLow();
  }

  delay(1000);
}

// disable the relays output
// also set the "battery low" LED state to LOW (sinking to ground)
void onBatteryLow() {
  digitalWrite(relayTransistorPin, relayPinOff);
  digitalWrite(lowBatteryLEDPin, ledPinOn);
  goToSleep();
}

// enable the relays output
// also set the "battery low" LED state to HIGH (vcc == LED off)
void onBatteryOK() {
  digitalWrite(relayTransistorPin, relayPinOn);
  digitalWrite(lowBatteryLEDPin, ledPinOff);
}

void goToSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  noInterrupts();
  sleep_mode(); // calls sleep_enable(), then sleep_cpu()
  // per https://onlinedocs.microchip.com/pr/GUID-A834D554-5741-41A3-B5E1-35ED7CD8250A-en-US-5/index.html?GUID-825A28EE-C4E4-4C03-864F-92AA9BA41231
}
