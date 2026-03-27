# Code Explanation

This document explains the working of the Arduino program used in the **SURYA** project.

---

## 1. Purpose of the Code

The Arduino code performs the following tasks:

- Reads light intensity from **3 LDR sensors**
- Controls **2 servo motors** for real-time solar tracking
- Turns the **LED ON/OFF** based on ambient light threshold
- Displays LDR values in the **Serial Monitor** for debugging

---

## 2. Sensors Used

The system uses three LDR sensors:

- **A0 → Top Left (TL)**
- **A1 → Top Right (TR)**
- **A2 → Bottom Left (BL)**

These analog values are continuously read using `analogRead()`.

---

## 3. Servo Control

The two servos are used for:

- **Horizontal movement**
- **Vertical movement**

### Pin Mapping
- **D2 → Horizontal Servo**
- **D13 → Vertical Servo**

The servos are initialized with starting positions:

- Horizontal = 90°
- Vertical = 45°

Servo limits are used to prevent over-rotation and protect the mechanical structure.

---

## 4. Horizontal Tracking Logic

To decide left/right movement:

- Left side light = average of **Top Left + Bottom Left**
- Right side light = **Top Right**

### Logic
- If left side is brighter → move horizontal servo toward left
- If right side is brighter → move horizontal servo toward right

A tolerance value is used so that the servo does not jitter due to very small differences.

---

## 5. Vertical Tracking Logic

To decide up/down movement:

- Top side light = average of **Top Left + Top Right**
- Bottom side light = **Bottom Left**

### Logic
- If top side is brighter → move vertical servo upward
- If bottom side is brighter → move vertical servo downward

Since only one bottom sensor is used, the vertical axis may be slightly less sensitive than a 4-LDR design.

---

## 6. Night Detection Logic

The code calculates the average ambient light:

- **Average Light = (TL + TR + BL) / 3**

If the average light falls below a predefined threshold:

- LED is turned **ON**
- Tracking can be stopped or skipped

If the average is above the threshold:

- LED remains **OFF**
- Tracking continues

This allows the same LDR sensors to perform both:

- Solar tracking
- Night/light detection

---

## 7. LED Control Logic

The LED is not driven directly from the Arduino.

Instead:

- Arduino **D4** controls the **MOSFET gate**
- The MOSFET switches the LED using battery power from the solar-charged battery

### Pin Mapping
- **D4 → 1kΩ resistor → MOSFET Gate**

This protects the Arduino and allows the LED to be powered from the external battery system.

---

## 8. Serial Monitor Output

The code prints the LDR values continuously:

- TL
- TR
- BL
- Average Light

This helps in:

- Checking if sensors are working
- Calibrating the night threshold
- Debugging vertical and horizontal movement

---

## 9. Tuning Parameters

The following values can be adjusted in the code:

### Horizontal Tolerance
Controls sensitivity for left/right movement.

### Vertical Tolerance
Controls sensitivity for up/down movement.

### Night Threshold
Defines the light level below which the LED should turn ON.

### Servo Limits
Prevents the servo from rotating beyond safe mechanical angles.

---

## 10. Summary

The code provides a simple but effective real-time control system for:

- Sunlight tracking
- Automatic LED switching
- Sensor monitoring

It demonstrates the use of embedded logic for renewable-energy automation using low-cost components.
