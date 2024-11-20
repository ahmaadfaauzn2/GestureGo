# Schematic Design PCB
The Schematic Design illustrates the electrical connections and components used in the Arduino Gesture Control Car Transmitter. This design includes the gesture sensor, microcontroller (e.g., Arduino or ESP32), and any additional components such as motors, power supply.
![Screenshot 2024-09-26 202606](https://github.com/user-attachments/assets/421712aa-31dc-47cd-8b22-1dc68a4f2eec)
![Screenshot 2024-09-26 204025](https://github.com/user-attachments/assets/275e83ac-6812-4eb8-866f-9da2d033ff32)


# Wiring Diagram 
The Wiring Diagram shows how to physically connect the components of the system. It includes wiring details for the transmitter, motors, sensors, and any other connected devices.
This diagram provides the physical connections between the components, ensuring proper wiring of:
- Gesture sensor to the microcontroller.
- Motor driver to DC motors.
- Power supply for the microcontroller and motors.

Example Pin Configuration:

```
MPU6050 Connections:
VCC -> 3.3V
GND -> GND
SCL -> A5 (Arduino)
SDA -> A4 (Arduino)

Motor Driver (L298N) Connections:
IN1, IN2 -> Digital Pins 2, 3
IN3, IN4 -> Digital Pins 4, 5
```



![Screenshot 2024-09-26 203713](https://github.com/user-attachments/assets/8ab5fb18-68a8-4e24-a83e-456ae4ab7094)
![Screenshot 2024-09-26 203739](https://github.com/user-attachments/assets/541d3c01-8be4-49ce-91c5-7900381a6eb5)


# Block Diagram
The block diagram illustrates the system architecture, including the following components:

1. Microcontroller: Arduino/ESP32 processes the sensor data.
2. Gesture Sensor: Captures hand movements.
3. Motor Driver: Controls the DC motors based on processed data.
4. DC Motors: Enable movement of the car.
5. Power Supply: Powers the entire system.

![Screenshot 2024-09-26 203807](https://github.com/user-attachments/assets/007df720-2d19-4ac6-b208-f73ac81b11a7)


# Flowchart System
The flowchart represents the logic of the system, detailing how the program:
1. Reads inputs from the gesture sensor.
2. Interprets gestures into directional commands.
3. Sends signals to the motor driver to move the car.

```
Start
  |
  V
Read Gesture Sensor Data
  |
  V
Determine Command:
  - Forward
  - Backward
  - Left
  - Right
  - Stop
  |
  V
Send Command to Motor Driver
  |
  V
End
```


# Key Code Snippets
## Gesture Sensor Integration

```
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 sensor!");
        while (1);
    }
    Serial.println("MPU6050 Found!");
}

void loop() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    Serial.print("Accel X: "); Serial.print(a.acceleration.x); 
    Serial.print(", Y: "); Serial.print(a.acceleration.y);
    Serial.print(", Z: "); Serial.println(a.acceleration.z);

    delay(500);
}
```

# Motor Control

```
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

void setupMotors() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    moveForward();
    delay(2000);  // Move forward for 2 seconds
    stopMotors();
    delay(1000);  // Stop for 1 second
}
```

## Installation and Setup
## Step 1: Clone the Repository

```
git clone https://github.com/ahmaadfaauzn2/GestureGo.git
cd GestureGo
```

# Step 2: Configure the Hardware
1. Wire the components as per the Wiring Diagram.
2. Upload the Arduino code to the microcontroller.

# Step 3: Flash the Code
1. Open the src/main.cpp in the Arduino IDE or PlatformIO.
2. Select the appropriate board and port.
3. Upload the code.

# Step 4: Test the System
1. Place the gesture sensor on your hand.
2. Observe the car's movement based on gestures.


   
![Screenshot 2024-09-26 203836](https://github.com/user-attachments/assets/70498481-5fc8-42bb-83d9-ac69fbecd811)

# 3D Design Model Car
![Screenshot 2024-09-26 203913](https://github.com/user-attachments/assets/4dbfbb7a-b5b3-4452-b7b8-45fa2d3b5b06)

# 3D Design Controller
![Screenshot 2024-09-26 203933](https://github.com/user-attachments/assets/fe321777-0cd7-4273-b5ec-badbb490e0d3)

# Car
![Screenshot 2024-09-26 204306](https://github.com/user-attachments/assets/60971864-be1a-48ee-884d-ea333872be8c)

# Controller
![Screenshot 2024-09-26 204108](https://github.com/user-attachments/assets/f5be216d-f4cb-4c56-bdd9-e2fd84aa7058)
