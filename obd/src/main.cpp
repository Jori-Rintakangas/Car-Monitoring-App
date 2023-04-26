#include <Arduino.h>
#include "BluetoothSerial.h"
#include "OBD9141.h"

// ESP32 UART2 pins
#define RX_PIN 16
#define TX_PIN 17

#define VEHICLE_SPEED 0x0D
#define ENGINE_RPM 0x0C
#define TEMPERATURE 0x05
#define MASS_AIR_FLOW 0x10
#define ENGINE_LOAD 0x04
#define THROTTLE_POS 0x11

OBD9141 k_line;
BluetoothSerial serial_bt;

void setup()
{
    k_line.begin(Serial2, RX_PIN, TX_PIN);
    serial_bt.begin("OBD");
    delay(2000);
}

void loop()
{
    bool init_success = k_line.init();

    if (init_success)
    {
        delay(3000);
        while (1)
        {
            delay(200);
            if (k_line.getCurrentPID(VEHICLE_SPEED, 1))
            {
                uint8_t speed = k_line.readUint8();
                serial_bt.println(String(speed) + 'S');
            }

            delay(200);
            if (k_line.getCurrentPID(ENGINE_RPM, 2))
            {
                uint16_t rpm = k_line.readUint16() / 4;
                serial_bt.println(String(rpm) + 'R');
            }

            delay(200);
            if (k_line.getCurrentPID(TEMPERATURE, 1))
            {
                uint8_t temp = k_line.readUint8() - 40;
                serial_bt.println(String(temp) + 'T');
            }

            delay(200);
            if (k_line.getCurrentPID(MASS_AIR_FLOW, 2))
            {
                uint16_t maf = k_line.readUint16() / 100;
                serial_bt.println(String(maf) + 'M');
            }

            delay(200);
            if (k_line.getCurrentPID(ENGINE_LOAD, 1))
            {
                uint8_t load = k_line.readUint8() * 2.55;
                serial_bt.println(String(load) + 'L');
            }

            delay(200);
            if (k_line.getCurrentPID(THROTTLE_POS, 1))
            {
                uint16_t throttle = k_line.readUint8() * 2.55;
                serial_bt.println(String(throttle) + 'P');
            }
        }
    }
    delay(3000);
}