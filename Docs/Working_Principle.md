# Working Principle

## Overview

SURYA is composed of two major subsystems:

1. **Dual-Axis Solar Tracker**
2. **Solar-Powered Automatic Lighting System**

These two subsystems work together to maximize solar energy utilization and provide automatic lighting when ambient light becomes low.

---

## 1. Dual-Axis Solar Tracking System

The solar tracking subsystem uses:

- **Arduino UNO**
- **3 LDR sensors**
- **2 SG90 servo motors**

### Sensor Placement
The three LDRs are placed in partitioned sections so that each sensor receives light from a different direction:

- **Top Left (TL)**
- **Top Right (TR)**
- **Bottom Left (BL)**

### Horizontal Tracking
The Arduino compares the average light intensity on the left and right side:

- Left side = average of **Top Left + Bottom Left**
- Right side = **Top Right**

If the left side receives more light, the horizontal servo moves the panel toward the left.  
If the right side receives more light, the servo moves toward the right.

### Vertical Tracking
The Arduino compares:

- Top side = average of **Top Left + Top Right**
- Bottom side = **Bottom Left**

If the top side receives more light, the vertical servo moves upward.  
If the bottom side receives more light, the servo moves downward.

This process runs continuously, enabling the panel to align toward the direction of highest available sunlight in real time.

---

## 2. Solar-Powered Automatic Lighting System

The lighting subsystem uses:

- **6V solar panel**
- **1N4007 diode**
- **TP4056 charging module**
- **1 × 18650 Li-ion battery**
- **LED panel**
- **N-channel MOSFET**

### Solar Charging
During daylight:

- The solar panel generates electrical power.
- The **1N4007 diode** prevents reverse current from the battery back into the solar panel.
- The generated power is sent to the **TP4056 charging module**.
- The TP4056 safely charges the **1S 18650 Li-ion battery**.

### LED Lighting
The LED is powered from the battery through the TP4056 output terminals.

The Arduino controls the LED through a **MOSFET**:

- When ambient light is high → LED remains **OFF**
- When ambient light falls below a threshold → LED turns **ON**

This allows the same LDR sensors used for tracking to also provide night/light detection logic.

---

## 3. Night Detection Logic

The Arduino calculates the average light intensity from all three LDRs:

- **Average = (TL + TR + BL) / 3**

If the average light intensity falls below a predefined **night threshold**:

- The LED is turned **ON**
- Tracking movement can be stopped or reduced (depending on code logic)

This ensures energy is used efficiently and avoids unnecessary servo motion during darkness.

---

## 4. Overall Operation

### Day Mode
- Solar panel tracks sunlight using LDR feedback
- Solar panel charges the battery through TP4056
- LED remains OFF

### Night / Low-Light Mode
- LDR average drops below threshold
- LED turns ON automatically
- Tracking movement can be paused

---

## Conclusion

SURYA combines **renewable energy harvesting**, **real-time solar tracking**, and **automatic lighting control** into a single embedded prototype. The project demonstrates a practical and efficient way to use low-cost components for sustainable energy applications.
