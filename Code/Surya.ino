#include <Servo.h>

// =====================================================
// SURYA - Solar Utility for Real-time Yield and Automation
// Final Arduino Code
//
// Features:
// - Real-time dual-axis solar tracking using 3 LDRs
// - Automatic LED control using MOSFET
// - LED turns ON when ambient light falls below threshold
// - Serial Monitor debugging for all LDR values
// =====================================================

// ---------------- SERVO OBJECTS ----------------
Servo horizontalServo;
Servo verticalServo;

// ---------------- PIN DEFINITIONS ----------------
const int horizontalServoPin = 2;   // Horizontal servo signal
const int verticalServoPin   = 13;  // Vertical servo signal

const int ledPin = 4;               // MOSFET gate control

const int ldrTL = A0;               // Top Left LDR
const int ldrTR = A1;               // Top Right LDR
const int ldrBL = A2;               // Bottom Left LDR

// ---------------- SERVO POSITION VARIABLES ----------------
int horizontalPos = 90;   // Initial horizontal position
int verticalPos   = 45;   // Initial vertical position

// ---------------- SERVO LIMITS ----------------
const int horizontalMin = 10;
const int horizontalMax = 170;

const int verticalMin = 20;
const int verticalMax = 100;

// ---------------- TRACKING SETTINGS ----------------
int toleranceHorizontal = 30;   // Horizontal sensitivity
int toleranceVertical   = 20;   // Vertical sensitivity

// ---------------- NIGHT DETECTION ----------------
int nightThreshold = 300;       // Adjust after testing Serial Monitor

// ---------------- LOOP TIMING ----------------
const int moveDelay = 15;       // Delay after servo movement
const int serialDelay = 300;    // Delay for stable Serial output

// =====================================================
// SETUP
// =====================================================
void setup() {
  // Attach servos
  horizontalServo.attach(horizontalServoPin);
  verticalServo.attach(verticalServoPin);

  // Set LED control pin
  pinMode(ledPin, OUTPUT);

  // Move servos to initial positions
  horizontalServo.write(horizontalPos);
  verticalServo.write(verticalPos);

  // Start serial monitor
  Serial.begin(9600);

  delay(2000); // Allow system to settle
}

// =====================================================
// MAIN LOOP
// =====================================================
void loop() {
  // -------- READ LDR VALUES --------
  int tl = analogRead(ldrTL);   // Top Left
  int tr = analogRead(ldrTR);   // Top Right
  int bl = analogRead(ldrBL);   // Bottom Left

  // -------- CALCULATE AVERAGE LIGHT FOR NIGHT DETECTION --------
  int avgLight = (tl + tr + bl) / 3;

  // -------- CALCULATE TRACKING VALUES --------
  int leftAvg   = (tl + bl) / 2;
  int rightAvg  = tr;

  int topAvg    = (tl + tr) / 2;
  int bottomAvg = bl;

  int diffHorizontal = leftAvg - rightAvg;
  int diffVertical   = topAvg - bottomAvg;

  // -------- SERIAL MONITOR OUTPUT --------
  Serial.print("TL: ");
  Serial.print(tl);

  Serial.print(" | TR: ");
  Serial.print(tr);

  Serial.print(" | BL: ");
  Serial.print(bl);

  Serial.print(" | Avg: ");
  Serial.print(avgLight);

  Serial.print(" | LeftAvg: ");
  Serial.print(leftAvg);

  Serial.print(" | RightAvg: ");
  Serial.print(rightAvg);

  Serial.print(" | TopAvg: ");
  Serial.print(topAvg);

  Serial.print(" | BottomAvg: ");
  Serial.print(bottomAvg);

  Serial.print(" | H_Pos: ");
  Serial.print(horizontalPos);

  Serial.print(" | V_Pos: ");
  Serial.println(verticalPos);

  // =====================================================
  // NIGHT / LOW-LIGHT MODE
  // =====================================================
  if (avgLight < nightThreshold) {
    digitalWrite(ledPin, HIGH);   // Turn LED ON

    // Stop tracking in low light / night
    delay(500);
    return;
  }

  // =====================================================
  // DAY MODE
  // =====================================================
  digitalWrite(ledPin, LOW);      // Turn LED OFF

  // -------- HORIZONTAL TRACKING --------
  if (abs(diffHorizontal) > toleranceHorizontal) {
    if (diffHorizontal > 0) {
      // More light on left -> move left
      horizontalPos--;
    } else {
      // More light on right -> move right
      horizontalPos++;
    }

    horizontalPos = constrain(horizontalPos, horizontalMin, horizontalMax);
    horizontalServo.write(horizontalPos);

    delay(moveDelay);
  }

  // -------- VERTICAL TRACKING --------
  if (abs(diffVertical) > toleranceVertical) {
    if (diffVertical > 0) {
      // More light on top -> move upward
      verticalPos++;
    } else {
      // More light on bottom -> move downward
      verticalPos--;
    }

    verticalPos = constrain(verticalPos, verticalMin, verticalMax);
    verticalServo.write(verticalPos);

    delay(moveDelay);
  }

  delay(serialDelay);
}
