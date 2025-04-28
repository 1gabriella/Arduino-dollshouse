# Arduino-dollshouse
# Where's My Phone? — Arduino OLED + Sensor Animation Project

## 📖 Overview
This project is a 2000's inspired  "Where's My Phone?" visual and sound alert system using an **Arduino**, a **1.5\" RGB OLED display**, an **ultrasonic distance sensor**, and a **buzzer**.

When the sensor detects a nearby object (like your hand searching around), it triggers a small "phone ringing" animation on the OLED screen and a buzzer sound to simulate a ringing phone.

---

## 🛠 Features
- 🎵 **Phone Ringtone Simulation** using a buzzer
- 📏 **Distance Detection** using an ultrasonic sensor
- 📺 **Animated OLED Display** showing a cute  cartoon girl worried because she lost her phone  + ringing phone animations
- 🚨 **LED Alert** lighting up when the phone is "found"


---

## 🧰 Hardware Used
- Arduino-compatible board (e.g., UNO, Nano)
- 1.5" RGB OLED Display (SPI)
- Ultrasonic Distance Sensor (HC-SR04)
- Buzzer
- LED (optional for visual indicator)
- Resistors, jumper wires, breadboard

---

## 🧑‍💻 Code Structure
| File | Description |
|:-----|:------------|
| `main.ino` | Main logic (setup/loop for OLED updates, sensor checks, and buzzer triggers) |
| `OLEDAnimations.h/cpp` | Functions to draw animations like lips, shocked face, speech bubbles |
| `SensorFunctions.h/cpp` | Distance reading function from ultrasonic sensor |
| `BuzzerFunctions.h/cpp` | Simple phone ringtone using tone() |
| `DEV_Config.h`, `OLED_Driver.h`, `GUI_Paint.h` | Driver and setup files for the OLED screen |

---

## 🖥️ Installation
1. Clone or download this repository.
2. Open the project in the Arduino IDE.
3. Install necessary libraries (OLED driver libraries if not already installed).
4. Wire your components according to the table below.


---

## 🔌 Wiring Summary
| Component | Arduino Pin |
|:----------|:------------|
| Ultrasonic Trig Pin | D9 |
| Ultrasonic Echo Pin | D4 |
| Buzzer | D12 |
| LED | D13 |
| OLED Display | I utilised a four wire OLED waveshare |
VCC	5V
GND	GND
DIN	SPI:D11/I2C:SDA
CLK	SPI:D13/I2C:SCL
CS	D10
DC	D7
RST	D8
---

## 📸 
<iframe src="https://player.vimeo.com/video/1079224852?title=0&amp;byline=0&amp;portrait=0&amp;badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" width="1080" height="1920" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media" title="518bf60886b04c8ca41044188ebb24ec"></iframe>
---
---
