# Home-Automation-Fire-Smoke-Safety-System

# Overview

This project implements a low-cost automated fire & smoke detection solution using Arduino.It detects fire with an IR flame sensor, monitors smoke using an MQ gas sensor, and triggers
instant safety responses such as activating a buzzer, switching LEDs, running a water pump, and displaying live readings on an LCD.

The system aims to enhance home safety with quick and automated reactions.

#  Features

1. **Real-time fire detection** using IR flame sensor
2. **Smoke & gas level detection** using MQ-2/MQ-5 sensor
3. **Buzzer alarms** during emergency conditions
4. **Red & Green LED indicators**
5. **Automatic water pump activation** via relay module when fire is detected
6. **Live sensor data and warnings** on 16×2 I2C LCD display
7. Fully automated and continuous monitoring


##  Tech Stack

* Arduino Uno
* C/C++ (Arduino Sketch)
* Embedded Systems & Sensor Integration



##  Hardware Components

* IR Flame Sensor
* MQ-2 / MQ-5 Gas Sensor
* Relay Module
* Water Pump
* Buzzer
* Red/Green LEDs
* 16×2 LCD Display (I2C)
* Jumper wires, power supply, resistors



##  System Workflow


[Sensors: Flame + Smoke] --> 
[Arduino Microcontroller] --> 
[Read sensor values, Compare to thresholds, Trigger buzzer & LEDs, Activate water pump (relay), Update LCD display]-->
[Outputs: Pump, Buzzer, LEDs, LCD]


#  How It Works

1. Flame and smoke sensors send analog readings to the Arduino.

2. If flame level reaches the threshold, the system:
        Activates the water pump
        Turns on red LED
        Sounds the buzzer
        Displays “FIRE DETECTED” on LCD

3. If smoke level exceeds limit, the system:
        Turns on red LED
        Activates the buzzer
        Shows “SMOKE DETECTED” on LCD

4. When everything is safe, the system shows normal readings and activates the green LED.


##  How to Run

1. Upload the `.ino` file to Arduino Uno.
2. Connect sensors, relay, pump, LEDs, buzzer, and LCD as per your circuit.
3. Power up the system (ensure safe power for relay and pump).
4. Observe live readings and test fire/smoke detection safely.



##  Safety Notes

1. Always test sensors in a controlled environment.
2. Never expose the system to dangerous fire—use lighter flames at a small distance.
3. Handle the relay and water pump carefully (may involve higher voltage).
