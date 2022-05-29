#ifndef QROMA_BLUETOOTH_H
#define QROMA_BLUETOOTH_H

#include <NimBLEDevice.h>
#include <NimBLEServer.h>


NimBLEServer * initBluetoothServer(const char * deviceName);
void startBluetoothServer(NimBLEServer * server);


#endif