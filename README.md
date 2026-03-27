# SURYA – The BOSS
## Solar Utility for Real-time Yield and Automation

> A smart renewable-energy project that combines **dual-axis solar tracking** with an **automatic solar-powered lighting system** using Arduino.

---

## 📌 Overview

**SURYA** is an embedded renewable-energy system designed to maximize solar energy utilization through **real-time sunlight tracking** and provide **automatic lighting during low-light/night conditions**.

The project consists of two integrated subsystems:

1. **Dual-Axis Solar Tracker**
   - Uses **3 LDR sensors** to detect sunlight intensity.
   - Controls **2 servo motors** to orient the solar panel toward the direction of maximum sunlight.

2. **Solar-Powered Automatic Light**
   - Uses a **6V solar panel**, **TP4056 charging module**, and **18650 Li-ion battery**.
   - Powers an **LED panel** automatically during night/low-light conditions using a **MOSFET switch** controlled by Arduino.

This project demonstrates practical implementation of **renewable energy harvesting**, **sensor-based control**, and **automation** in a compact prototype.

---

## 🎯 Objectives

- Maximize solar energy capture using **real-time dual-axis solar tracking**
- Build an **automatic night lighting system** powered by solar energy
- Use **Arduino-based control logic** for both tracking and lighting
- Create a low-cost and scalable prototype for renewable-energy applications

---

## ✨ Features

- 🌞 **Dual-axis solar tracking**
- 🔦 **Real-time sunlight detection using 3 LDR sensors**
- ⚙️ **2-servo panel movement (horizontal + vertical)**
- 🔋 **Solar charging using TP4056**
- 💡 **Automatic LED control during low-light conditions**
- 🧠 **Single-controller (Arduino) logic for tracking + lighting**
- 🛠️ **Simple, low-cost prototype architecture**
- 📈 **Serial Monitor output for live LDR debugging**

---

## 🧩 System Architecture

### 1. Solar Tracker Subsystem
- **Arduino UNO**
- **2 × SG90 Servo Motors**
- **3 × LDR Sensors**
- **3 × 1kΩ resistors** (used as LDR divider resistors)

### 2. Solar Light Subsystem
- **6V Solar Panel**
- **1N4007 Diode**
- **TP4056 Charging Module**
- **1 × 18650 Li-ion Battery**
- **LED Panel / LED Strip**
- **N-channel MOSFET**
- **1 × 1kΩ resistor** (MOSFET gate resistor)

---

## 🔌 Pin Configuration

| Arduino Pin | Connection |
|------------|------------|
| **D2** | Horizontal Servo Signal |
| **D13** | Vertical Servo Signal |
| **D4** | MOSFET Gate (LED control) |
| **A0** | Top Left LDR |
| **A1** | Top Right LDR |
| **A2** | Bottom Left LDR |
| **5V** | LDR divider supply + servo Vcc |
| **GND** | LDR divider ground + servo GND + common ground reference |

---

## ⚡ Power Architecture

### 🔵 Tracker System Power
- **Arduino powered initially via USB (recommended for testing)**
- Can also be powered through **12V adapter via barrel jack** for standalone operation

### 🟢 Solar Light System Power
- **6V solar panel** charges a **1S 18650 Li-ion battery** through **TP4056**
- The battery powers the **LED panel**
- Arduino controls the LED through a **MOSFET**

> **Important:**  
> If Arduino controls the MOSFET gate, then **Arduino GND must be connected to TP4056 OUT-** to provide a common reference ground.

---

## 🛠️ Circuit Summary

### 1. LDR Voltage Divider (for each LDR)
```text
5V ---- LDR ----●---- 1kΩ ---- GND
                |
               A0 / A1 / A2
