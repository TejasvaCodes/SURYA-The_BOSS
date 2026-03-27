
# Bill of Materials (BOM)

This document lists the components used in the **SURYA** project.

---

## 1. Main Components BOM

| Sr. No. | Component | Qty | Specification / Notes | Used In |
|---|---:|---:|---|---|
| 1 | Arduino UNO | 1 | Main controller | Solar Tracker |
| 2 | SG90 Servo Motor | 2 | Micro servo | Solar Tracker |
| 3 | LDR (Photoresistor) | 3 | For sunlight sensing | Solar Tracker / night detection |
| 4 | Resistor | 3 | 1kΩ (used instead of 10k for LDR dividers) | Solar Tracker |
| 5 | Solar Panel | 1 | 6V, 250mA | Solar Light |
| 6 | TP4056 Charging Module | 1 | 1S Li-ion charger | Solar Light |
| 7 | 1N4007 Diode | 1 | Reverse current protection | Solar Light |
| 8 | 18650 Li-ion Cell | 1 | 3.7V nominal | Solar Light |
| 9 | 18650 Battery Holder | 1 | Single-cell holder (1S) | Solar Light |
| 10 | LED Panel / LED Strip | 1 | Rated up to 5V | Solar Light |
| 11 | N-channel MOSFET | 1 | For LED switching | Solar Light |
| 12 | Resistor | 1 | 1kΩ for MOSFET gate | Solar Light |
| 13 | 12V Adapter / USB Power | 1 | Arduino power source | Solar Tracker |
| 14 | Jumper Wires / Hookup Wires | 1 set | Male-male / male-female | Both |
| 15 | Breadboard / Perfboard | 1 | Prototyping or permanent build | Both |

---

## 2. Tracker Subsystem BOM

| Component | Qty | Notes |
|---|---:|---|
| Arduino UNO | 1 | Main controller |
| SG90 Servo | 2 | Horizontal + Vertical |
| LDR | 3 | Top-left, Top-right, Bottom-left |
| 1kΩ resistor | 3 | LDR voltage dividers |
| 12V adapter / USB | 1 | Initial testing via USB recommended |
| Jumper wires | As needed | Connections |
| Mount / bracket | 1 set | 3D-printed tracker structure |

---

## 3. Solar Light Subsystem BOM

| Component | Qty | Notes |
|---|---:|---|
| Solar Panel | 1 | 6V, 250mA |
| TP4056 Module | 1 | 1S Li-ion charging |
| 1N4007 Diode | 1 | Solar reverse current protection |
| 18650 Li-ion Cell | 1 | 3.7V |
| 18650 Holder | 1 | Single-cell preferred |
| LED Panel | 1 | Up to 5V rated |
| N-channel MOSFET | 1 | Low-side switching |
| 1kΩ resistor | 1 | MOSFET gate resistor |
| Wires | As needed | Connections |

---

## 4. Report-Friendly Short BOM

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| SG90 Servo Motor | 2 |
| LDR Sensor | 3 |
| 1kΩ Resistor | 4 |
| Solar Panel (6V, 250mA) | 1 |
| TP4056 Charging Module | 1 |
| 1N4007 Diode | 1 |
| 18650 Li-ion Battery | 1 |
| 18650 Battery Holder | 1 |
| LED Panel / Strip (5V max) | 1 |
| N-channel MOSFET | 1 |
| 12V Adapter / USB Power | 1 |
| Breadboard / Perfboard | 1 |
| Jumper Wires | As required |

---

## 5. Optional Recommended Components

| Component | Purpose |
|---|---|
| 470µF–1000µF Capacitor | Helps reduce servo current spikes |
| On/Off Switch | Manual power control |
| Fuse | Battery safety |
| Perfboard | More robust final assembly |
| Enclosure | Outdoor protection |

---

## 6. Notes

- A **logic-level N-channel MOSFET** is preferred for reliable switching with Arduino 5V gate drive.
- Standard tutorials often use **10kΩ** for LDR dividers, but this project currently uses **1kΩ** due to component availability.
- Initial testing is recommended through **USB power** for stable debugging.
