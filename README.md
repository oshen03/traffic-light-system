# Automated Traffic Light System

An Arduino-based traffic light system with pedestrian signals, using combinational logic and a 4-bit counter.

## Features
- 16-second cycle (7s green, 3s yellow, 6s pedestrian)
- Non-blocking timing with `millis()`
- Active-high LED control

## Wiring
| Arduino Pin | Component       | LED Color | Resistor |
|-------------|-----------------|-----------|----------|
| 2           | Traffic Red     | Red       | 470Ω     |
| 3           | Traffic Yellow  | Yellow    | 470Ω     |
| 4           | Traffic Green   | Green     | 470Ω     |
| 5           | Pedestrian Red  | Red       | 470Ω     |
| 6           | Pedestrian Green| Green     | 470Ω     |

## Usage
1. Upload `pedestrian.ino` to Arduino Uno.
2. LEDs will cycle automatically.

