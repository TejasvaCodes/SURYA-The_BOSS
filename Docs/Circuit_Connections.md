# Circuit Connections

This document contains the complete wiring details for the **SURYA** project.

---

## 1. Arduino Pin Mapping

| Arduino Pin | Connection |
|------------|------------|
| **D2** | Horizontal Servo Signal |
| **D13** | Vertical Servo Signal |
| **D4** | MOSFET Gate (LED control through 1kΩ resistor) |
| **A0** | Top Left LDR |
| **A1** | Top Right LDR |
| **A2** | Bottom Left LDR |
| **5V** | Servo Vcc + LDR divider supply |
| **GND** | Servo GND + LDR divider ground + common reference |

---

## 2. LDR Connections (3 Sensors)

Each LDR is connected as a voltage divider.

### General LDR Divider Connection
```text
5V ---- LDR ----●---- 1kΩ ---- GND
                |
               A0 / A1 / A2
