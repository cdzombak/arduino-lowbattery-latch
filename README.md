# arduino-lowbattery-latch

Control a relay based on a "low battery" comparator signal.

I wrote this to retrofit into my [Ego battery based 12 volt power supply](https://www.dzombak.com/blog/2024/04/The-12v-portable-power-supply-Ego-needs-to-make.html). Previously, the "low battery" comparator drove the main power relay directly, which (predictably) resulted in flapping when the battery level was marginal. This Ardunio code implements the following logic:

- Check the battery level comparator 5 times at start to be sure the battery is not too low before powering on the main relay
- Check the battery level comparator every second and shut off the main relay if the battery's voltage is low 5 seconds in a row
- Illuminate a LED when the battery is low
- Once in the "low battery" state, put the Arduino into low power mode
- Once in the "low battery" state, stay there; the main relay and Arduino remain off until power is reset

## Hardware

This runs on an [Arduino Nano Every](https://store.arduino.cc/products/arduino-nano-every). I chose this due to its combination of:

- 5V supply & GPIO
- small physical size
- low power consumption
- adequate GPIO pins
- ADC for possible future improved battery level monitoring

## Circuitry

TK

## License

MIT; see [`LICENSE` in this repo](LICENSE).

## Author

Chris Dzombak
- [dzombak.com](https://www.dzombak.com)
- [github @cdzombak](https://github.com/cdzombak)
