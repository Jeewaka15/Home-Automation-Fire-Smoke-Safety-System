#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Pin assignments
int flame = A0;
int gasSensor = A1;
int Beep = 9;
int redLED = 10;
int greenLED = 11;
int relay = 12;
int flameVal = 0;
int gasVal = 0;

// Thresholds for detection
int flameThreshold = 1000;
int gasThreshold = 500;

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// SIM800L GSM Module Pins
SoftwareSerial SIM800L(7, 8);

void setup() {
    pinMode(Beep, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(relay, OUTPUT);
    pinMode(flame, INPUT);
    pinMode(gasSensor, INPUT);

    Serial.begin(9600);
    SIM800L.begin(9600);

    lcd.init();
    lcd.backlight();

    // Initialize SIM800L module
    sendGSMCommand("AT");
    delay(1000);
    sendGSMCommand("AT+CMGF=1");
    delay(1000);
}

void loop() {
    flameVal = analogRead(flame);
    gasVal = analogRead(gasSensor);

    // Print sensor values for debugging
    Serial.print("Flame sensor value: ");
    Serial.println(flameVal);
    Serial.print("Gas sensor value: ");
    Serial.println(gasVal);

    // Flame detection logic
    if (flameVal >= flameThreshold) {
        digitalWrite(relay, HIGH);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DANGER: FIRE!!");
        lcd.setCursor(0, 1);
        lcd.print("Water Activated");

        digitalWrite(Beep, HIGH);
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);

        sendSMS("ALERT: Fire detected! Water pump activated.");
    }
    // Smoke detection logic
    else if (gasVal >= gasThreshold) {
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(Beep, HIGH);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DANGER: SMOKE!");
        lcd.setCursor(0, 1);
        lcd.print("Check ASAP!");

        digitalWrite(relay, LOW);

        sendSMS("ALERT: Smoke detected! Immediate attention required.");
    }
    // Normal operation
    else {
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(Beep, LOW);
        digitalWrite(relay, LOW);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Flame: ");
        lcd.print(flameVal);
        lcd.setCursor(0, 1);
        lcd.print("Smoke: ");
        lcd.print(gasVal);
    }

    delay(500);
}

void sendSMS(String message) {
    SIM800L.println("AT+CMGF=1");
    delay(1000);
    SIM800L.println("AT+CMGS=\"+1234567890\"");
    delay(1000);
    SIM800L.println(message);
    delay(1000);
    SIM800L.println((char)26);
    delay(1000);
}

void sendGSMCommand(String command) {
    SIM800L.println(command);
    delay(1000);
}