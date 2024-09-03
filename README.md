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

- 5V supply & GPIO (meaning it's trivially compatible with my original circuit)
- small physical size
- low power consumption
- adequate GPIO pins
- ADC for possible future improved battery level monitoring

## Circuitry

<img width="1617" alt="battery monitor circuit schematic revised august 2024" src="https://github.com/user-attachments/assets/f00ca25b-48b2-4b1e-a3ff-80336e05f6c2">

Notes:

- The odd comparator + microcontroller setup is simply because this was the easiest way to retrofit the Ardunio relay controller into [the original design](https://www.dzombak.com/blog/2024/04/The-12v-portable-power-supply-Ego-needs-to-make.html).
- The pull-up resistor marked `*` indicates I don't remember what value I used here; just pick something appropriate, maybe around 20 kΩ, based on your relay's datasheet and the desire to minimize power consumption.

## See Also

- [The 12v portable power supply Ego needs to make *(April 2024)*](https://www.dzombak.com/blog/2024/04/The-12v-portable-power-supply-Ego-needs-to-make.html)
- [Improved low-battery shutoff for my DIY Ego-powered 12V supply *(September 2024)*](https://www.dzombak.com/blog/2024/09/Improved-low-battery-shutoff-for-my-DIY-Ego-powered-12V-supply.html)

## License

MIT; see [`LICENSE` in this repo](LICENSE).

## Author

Chris Dzombak
- [dzombak.com](https://www.dzombak.com)
- [github @cdzombak](https://github.com/cdzombak)
