#include <RTOS.h>
#include "bluetooth.h"


void logInfo(const char * msg) { }


NimBLEServer * initBluetoothServer(const char * deviceName) {

  NimBLEDevice::init(deviceName);
  logInfo("BLUETOOTH DEVICE NAME");
  logInfo(deviceName);

  /** Optional: set the transmit power, default is 3db */
  NimBLEDevice::setPower(ESP_PWR_LVL_P3); /** +9db */
  
  /** Set the IO capabilities of the device, each option will trigger a different pairing method.
   *  BLE_HS_IO_DISPLAY_ONLY    - Passkey pairing
   *  BLE_HS_IO_DISPLAY_YESNO   - Numeric comparison pairing
   *  BLE_HS_IO_NO_INPUT_OUTPUT - DEFAULT setting - just works pairing
   */
  NimBLEDevice::setSecurityIOCap(BLE_HS_IO_DISPLAY_ONLY); // use passkey

  NimBLEDevice::setSecurityAuth(BLE_SM_PAIR_AUTHREQ_BOND | BLE_SM_PAIR_AUTHREQ_MITM | BLE_SM_PAIR_AUTHREQ_SC);

  NimBLEServer* server = NimBLEDevice::createServer();

  return server;
}


void startBluetoothServer(NimBLEServer * server) {
  NimBLEAdvertising* pAdvertising = server->getAdvertising();
  /** Add the services to the advertisment data **/
  // pAdvertising->addServiceUUID(pDeadService->getUUID());
  // pAdvertising->addServiceUUID(pBaadService->getUUID());
  /** If your device is battery powered you may consider setting scan response
   *  to false as it will extend battery life at the expense of less data sent.
   */
  pAdvertising->setScanResponse(true);
  pAdvertising->start();

  logInfo("BLUETOOTH ADDRESS");
  logInfo(NimBLEDevice::getAddress().toString().c_str());
  logInfo("BLUETOOTH INIT COMPLETE");
}
