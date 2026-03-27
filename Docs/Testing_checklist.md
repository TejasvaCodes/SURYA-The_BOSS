# Testing Checklist

This checklist helps verify that the **SURYA** system is working correctly.

---

## 1. Solar Panel Check

- [ ] Measure solar panel voltage in sunlight
- [ ] Confirm voltage is present at panel terminals
- [ ] Ensure panel polarity is correct

---

## 2. TP4056 Charging Check

- [ ] Solar panel connected to TP4056 IN+ and IN-
- [ ] 1N4007 diode orientation verified
- [ ] Battery connected correctly to B+ and B-
- [ ] TP4056 charging LED turns ON in sunlight
- [ ] Battery voltage increases over time

---

## 3. Battery Check

- [ ] Battery voltage is above 3.0V
- [ ] Battery polarity is correct
- [ ] Battery holder connections are secure

---

## 4. LED System Check

- [ ] TP4056 OUT+ connected to LED+
- [ ] LED- connected to MOSFET Drain
- [ ] MOSFET Source connected to TP4056 OUT-
- [ ] LED turns ON when commanded
- [ ] LED turns OFF in bright conditions

---

## 5. MOSFET Check

- [ ] MOSFET pinout confirmed before wiring
- [ ] Arduino D4 connected to MOSFET Gate through 1kΩ resistor
- [ ] Arduino GND connected to TP4056 OUT-
- [ ] MOSFET does not overheat during operation

---

## 6. Arduino Power Check

- [ ] Arduino powers ON via USB
- [ ] Code uploads successfully
- [ ] Serial Monitor opens at correct baud rate
- [ ] No random resets during basic operation

---

## 7. LDR Check

- [ ] All 3 LDRs show changing values in Serial Monitor
- [ ] Top Left LDR changes when light is applied
- [ ] Top Right LDR changes when light is applied
- [ ] Bottom Left LDR changes when light is applied
- [ ] Values drop or rise consistently when covered/exposed

---

## 8. Horizontal Tracking Check

- [ ] Shine light more on left side → horizontal servo moves left
- [ ] Shine light more on right side → horizontal servo moves right
- [ ] Servo stays within safe mechanical limits
- [ ] No excessive jitter

---

## 9. Vertical Tracking Check

- [ ] Shine light on top sensors → vertical servo moves upward
- [ ] Shine light on bottom sensor → vertical servo moves downward
- [ ] Vertical response is visible and stable
- [ ] Servo stays within mechanical limits

---

## 10. Night Detection Check

- [ ] Average LDR value visible in Serial Monitor
- [ ] Cover all LDRs → LED turns ON
- [ ] Expose LDRs to light → LED turns OFF
- [ ] Night threshold is calibrated correctly

---

## 11. Full System Check

### Day Mode
- [ ] Tracker follows light source
- [ ] LED remains OFF
- [ ] Solar charging is active

### Night Mode
- [ ] LED turns ON automatically
- [ ] Tracking stops or reduces (if programmed)
- [ ] Battery powers LED correctly

---

## 12. Thermal / Safety Check

- [ ] Arduino does not overheat
- [ ] MOSFET remains within safe temperature
- [ ] TP4056 does not overheat
- [ ] No loose wires or polarity mistakes
- [ ] No sparking or abnormal heating

---

## 13. Final Validation

- [ ] System runs continuously without reset
- [ ] Tracking is smooth
- [ ] LED switching is reliable
- [ ] Solar charging works as expected
- [ ] All components are mounted securely
