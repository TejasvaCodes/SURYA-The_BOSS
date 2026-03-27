# Project Summary

# SURYA – Solar Utility for Real-time Yield and Automation

## Project Title

**Design and Development of SURYA – A Dual-Axis Solar Tracker with Automatic Night Lighting System**

---

## 1. Introduction

SURYA is a smart renewable-energy prototype designed to improve the efficiency of solar energy utilization by combining **dual-axis solar tracking** with an **automatic solar-powered lighting system**.

The project uses **Arduino UNO**, **LDR sensors**, and **servo motors** to orient a solar panel toward the direction of maximum sunlight. The same system also uses solar energy to charge a battery, which powers an LED panel during low-light or night conditions.

The prototype demonstrates the practical integration of:

- Renewable energy harvesting
- Sensor-based automation
- Embedded control systems
- Energy-efficient lighting

---

## 2. Problem Statement

Fixed solar panels do not always receive maximum sunlight throughout the day because the sun’s position changes continuously. This reduces the total energy that can be harvested.

Additionally, many small lighting systems depend on manual switching or external power sources, which reduces efficiency and sustainability.

There is a need for a system that can:

- Automatically track the sun in real time
- Improve solar energy collection
- Store energy efficiently
- Automatically provide lighting during low-light conditions

---

## 3. Proposed Solution

SURYA solves this problem by integrating two subsystems:

### A. Dual-Axis Solar Tracking
- Uses **3 LDR sensors** to detect sunlight intensity from different directions
- Uses **2 servo motors** to move the solar panel in horizontal and vertical directions
- Continuously aligns the panel toward the direction of highest light intensity

### B. Automatic Solar-Powered Lighting
- Uses a **6V solar panel** to charge a **3.7V 18650 Li-ion battery**
- Charging is handled by a **TP4056 charging module**
- The battery powers an **LED panel**
- The Arduino turns the LED ON automatically when ambient light falls below a threshold

---

## 4. Objectives

- Maximize solar energy capture using real-time tracking
- Build a dual-axis solar tracker using low-cost components
- Implement automatic lighting based on ambient light conditions
- Use solar energy for battery charging and night lighting
- Demonstrate an integrated renewable-energy automation prototype

---

## 5. Components Used

- Arduino UNO
- 2 × SG90 Servo Motors
- 3 × LDR Sensors
- 4 × 1kΩ Resistors
- 6V Solar Panel
- TP4056 Charging Module
- 1N4007 Diode
- 1 × 18650 Li-ion Battery
- LED Panel / LED Strip
- N-channel MOSFET
- 12V Adapter / USB Power
- Breadboard / Perfboard
- Jumper Wires

---

## 6. Working Principle

### Day Mode
- The three LDR sensors detect sunlight intensity.
- The Arduino compares light values and moves the solar panel toward the brightest direction.
- The solar panel charges the battery through the TP4056 charging module.
- The LED remains OFF during sufficient ambient light.

### Night / Low-Light Mode
- The Arduino calculates the average light intensity from the LDR sensors.
- If the light level falls below a threshold:
  - The LED turns ON automatically
  - Tracking can stop or reduce depending on the control logic

---

## 7. Innovation in the Project

The main innovation of SURYA is the integration of:

- **Real-time solar tracking**
- **Battery charging using solar energy**
- **Automatic lighting using the same sensing system**

The project uses a **3-LDR adaptive logic** instead of a standard 4-LDR design, making it practical under hardware constraints while still achieving dual-axis tracking.

---

## 8. Advantages

- Increases solar energy utilization compared to fixed panel orientation
- Low-cost and easy to build
- Demonstrates renewable energy and automation in one system
- Automatically provides lighting without manual intervention
- Educational and scalable for future smart energy applications

---

## 9. Applications

- Smart solar street lights
- Solar garden lighting
- Educational renewable-energy kits
- Small autonomous lighting systems
- Sustainable IoT energy platforms
- Renewable energy demonstration projects

---

## 10. Limitations

- Current design uses **3 LDRs** instead of 4
- Vertical tracking is less balanced than a full 4-LDR design
- SG90 servos are suitable only for lightweight panels
- Servo power from Arduino 5V is acceptable for prototype testing but not ideal for long-term deployment

---

## 11. Future Scope

- Upgrade to 4 LDR sensors
- Add battery voltage monitoring
- Use dedicated 5V power for servos
- Add IoT monitoring (ESP32/ESP8266)
- Improve night detection using adaptive thresholds
- Add weatherproof enclosure for outdoor deployment

---

## 12. Conclusion

SURYA is a practical and efficient renewable-energy prototype that combines **solar tracking**, **battery charging**, and **automatic lighting** into a single embedded system. It demonstrates how low-cost components and simple control logic can be used to build intelligent energy systems for sustainable applications.

The project serves as a strong foundation for future work in smart solar lighting, embedded renewable-energy systems, and automation-based energy optimization.
