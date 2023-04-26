#include <Arduino.h>
#include "BluetoothSerial.h"
#include "OBD9141.h"

#define VEHICLE_SPEED 0x0D
#define ENGINE_RPM 0x0C
#define TEMPERATURE 0x05
#define MASS_AIR_FLOW 0x10
#define ENGINE_LOAD 0x04
#define THROTTLE_POS 0x11

BluetoothSerial SerialBT;

void setup()
{
    SerialBT.begin("OBD");
}

void loop()
{

}