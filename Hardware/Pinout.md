# Hardware Pinout

This file contains the complete pin mapping for the **SURYA (Solar Utility for Real-time Yield and Automation)** project.

The system consists of:

1. **Solar Tracker Subsystem**
2. **Solar-Powered Automatic Light Subsystem**

---

# 1. Arduino UNO Pin Mapping

| Arduino Pin | Connected Component | Purpose |
|------------|---------------------|---------|
| **D2** | Horizontal Servo Signal | Controls left-right panel movement |
| **D13** | Vertical Servo Signal | Controls up-down panel movement |
| **D4** | MOSFET Gate (through 1kΩ resistor) | Controls LED ON/OFF |
| **A0** | Top Left LDR Junction | Reads top-left light intensity |
| **A1** | Top Right LDR Junction | Reads top-right light intensity |
| **A2** | Bottom Left LDR Junction | Reads bottom-left light intensity |
| **5V** | LDR supply + Servo Vcc | Powers sensors and servos |
| **GND** | LDR ground + Servo ground + TP4056 OUT- | Common reference ground |

---

# 2. LDR Pin Mapping

The project uses **3 LDRs** due to component availability.

| LDR Position | Arduino Pin | Description |
|-------------|-------------|-------------|
| **Top Left (TL)** | **A0** | Upper-left light sensor |
| **Top Right (TR)** | **A1** | Upper-right light sensor |
| **Bottom Left (BL)** | **A2** | Lower-left light sensor |

Each LDR is connected in a voltage divider configuration using a **1kΩ resistor**.

---

# 3. Servo Pin Mapping

The project uses **2 SG90 servo motors**.

| Servo | Signal Pin | Power | Ground | Purpose |
|------|------------|-------|--------|---------|
| **Horizontal Servo** | **D2** | Arduino 5V | Arduino GND | Left-right panel rotation |
| **Vertical Servo** | **D13** | Arduino 5V | Arduino GND | Up-down panel tilt |

---

# 4. LED Control Pin Mapping

| Component | Arduino Pin | Notes |
|----------|-------------|------|
| **MOSFET Gate** | **D4** | Connected through **1kΩ resistor** |

### LED Power Path (not direct Arduino power)
- **TP4056 OUT+** → LED+
- **LED-** → MOSFET Drain
- **MOSFET Source** → TP4056 OUT-

The Arduino only controls the **MOSFET gate**, not the LED directly.

---

# 5. TP4056 Pin Mapping

| TP4056 Pin | Connected To | Function |
|-----------|--------------|----------|
| **IN+** | Solar panel positive through 1N4007 diode | Solar charging input |
| **IN-** | Solar panel negative | Solar charging input ground |
| **B+** | 18650 battery positive | Battery connection |
| **B-** | 18650 battery negative | Battery connection |
| **OUT+** | LED positive | Output to load |
| **OUT-** | MOSFET source + Arduino GND | Output ground / common reference |

---

# 6. Solar Panel Connections

| Solar Panel Terminal | Connected To |
|----------------------|--------------|
| **Solar +** | 1N4007 diode non-banded side |
| **Solar -** | TP4056 IN- |

After diode:
- **1N4007 banded side** → **TP4056 IN+**

---

# 7. Battery Connections

| Battery Terminal | Connected To |
|------------------|--------------|
| **Battery +** | TP4056 B+ |
| **Battery -** | TP4056 B- |

Battery type:
- **1 × 18650 Li-ion cell (1S, 3.7V nominal)**

---

# 8. MOSFET Pin Mapping

| MOSFET Pin | Connected To |
|-----------|--------------|
| **Gate** | Arduino D4 through 1kΩ resistor |
| **Drain** | LED negative terminal |
| **Source** | TP4056 OUT- |

> Important:  
> Verify the **exact MOSFET pinout** from the datasheet before final soldering, because pin order differs by model.

---

# 9. Power Inputs

## Arduino Power
- **USB cable** (recommended for initial testing)
OR
- **12V adapter via barrel jack** (standalone operation)

## LED / Lighting Power
- Powered from:
  - **18650 battery**
  - charged through **solar panel + TP4056**

---

# 10. Summary Table

| Function | Pin / Connection |
|---------|------------------|
| Horizontal Servo Signal | D2 |
| Vertical Servo Signal | D13 |
| LED Control (MOSFET Gate) | D4 |
| Top Left LDR | A0 |
| Top Right LDR | A1 |
| Bottom Left LDR | A2 |
| Sensor / Servo Supply | 5V |
| Common Ground | GND |
| Solar Input | TP4056 IN+ / IN- |
| Battery Connection | TP4056 B+ / B- |
| LED Power | TP4056 OUT+ / OUT- |

---

# 11. Important Notes

- The current design uses **3 LDRs**, not 4.
- Vertical tracking is derived using:
  - Top = average of TL + TR
  - Bottom = BL
- Arduino controls the LED **indirectly** through the MOSFET.
- Since Arduino controls the MOSFET gate, **Arduino GND must be connected to TP4056 OUT-**.

---

# 12. Recommended File Usage

This file should be used as the quick reference for:

- Wiring
- Debugging
- Report writing
- Breadboard assembly
- Final soldering reference
