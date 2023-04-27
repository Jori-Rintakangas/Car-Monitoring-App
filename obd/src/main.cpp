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

uint16_t maf = 0;
uint16_t rpm = 0;
uint8_t speed = 0;
uint8_t temp = 0;
uint8_t load = 0;
uint8_t throttle = 0;

uint8_t new_val = 0;

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
            if (k_line.getCurrentPID(VEHICLE_SPEED, 1) && (new_val = k_line.readUint8() != speed))
            {
                speed = new_val;
                serial_bt.println(String(speed) + 'S');
            }

            delay(200);
            if (k_line.getCurrentPID(ENGINE_RPM, 2) && (new_val = k_line.readUint16() / 4 != rpm))
            {
                rpm = new_val;
                serial_bt.println(String(rpm) + 'R');
            }

            delay(200);
            if (k_line.getCurrentPID(TEMPERATURE, 1) && (new_val = k_line.readUint8() - 40 != temp))
            {
                temp = new_val;
                serial_bt.println(String(temp) + 'T');
            }

            delay(200);
            if (k_line.getCurrentPID(MASS_AIR_FLOW, 2) && (new_val = k_line.readUint16() / 100 != maf))
            {
                maf = new_val;
                serial_bt.println(String(maf) + 'M');
            }

            delay(200);
            if (k_line.getCurrentPID(ENGINE_LOAD, 1) && (new_val = k_line.readUint8() * 2.55 != load))
            {
                load = new_val;
                serial_bt.println(String(load) + 'L');
            }

            delay(200);
            if (k_line.getCurrentPID(THROTTLE_POS, 1) && (new_val = k_line.readUint8() * 2.55 != throttle))
            {
                throttle = new_val;
                serial_bt.println(String(throttle) + 'P');
            }
        }
    }
    delay(3000);
}