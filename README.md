# Keypad Door Lock System using Arduino

## Project Overview
This project is an Arduino-based keypad door lock system designed to enhance basic security using password authentication.

## Objective
The objective of this project is to design a simple, low-cost, and reliable door locking system using a keypad and servo motor.

## Components Used
- Arduino Uno
- 4x4 Matrix Keypad
- Servo Motor
- Breadboard
- Jumper Wires
- Power Supply

## Working Principle
1. The system remains locked initially.
2. The user presses the **'#' key** to start entering the password.
3. The password is entered using the keypad.
4. If the entered password is correct, the servo motor rotates and unlocks the door.
5. The door remains unlocked for **4 seconds**.
6. After 4 seconds, the servo motor automatically rotates back and locks the door again.
7. If the password is incorrect, access is denied and the door remains locked.

## Features
- Password-protected door access
- Automatic re-locking after 4 seconds
- Simple and user-friendly operation
- Low-cost security solution

## Applications
- Home security systems
- Office door access control
- Locker security
- Educational embedded system projects

## Technologies Used
- Arduino IDE
- Embedded C/C++
- Keypad Interfacing
- Servo Motor Control

## Conclusion
This project successfully demonstrates a secure keypad-based door locking system using Arduino.  
The automatic re-locking feature improves safety by ensuring the door does not remain unlocked unintentionally.

*This project was developed as part of an academic embedded systems course.*
