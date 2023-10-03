# Car-Monitoring-App

An android application that can be used to display data read from a vehicle OBD port.
ESP32 microcontroller module is used to interface with the vehicle OBD port and send
data to smartphone via bluetooth.

The hardware is operational with cars that use ISO 9141 (K-line) protocol for
signaling the data. MC33290 K-line transceiver with
[OBD9141](https://github.com/iwanders/OBD9141) library is used to communicate
between ESP32 and the vehicle K-line.

## Application

Application receives six different diagnostic values from the car:
speed, engine speed, coolant temperature, engine load, mass air flow, and
throttle pedal position.

![image](images/app.jpg)

## Schematic
![image](images/schematic.PNG)

## Hardware
![image](images/hardware.jpg)
