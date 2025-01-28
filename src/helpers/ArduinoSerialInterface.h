#pragma once

#include "BaseSerialInterface.h"
#include <Arduino.h>

class ArduinoSerialInterface : public BaseSerialInterface {
  bool _isEnabled;
  uint8_t _state;
  uint8_t _frame_len;
  uint8_t rx_len;
  HardwareSerial* _serial;
  uint8_t rx_buf[MAX_FRAME_SIZE];

public:
  ArduinoSerialInterface() { _isEnabled = false; _state = 0; }

  void begin(HardwareSerial& serial) { _serial = &serial; }

  // BaseSerialInterface methods
  void enable() override;
  void disable() override;
  bool isEnabled() const override { return _isEnabled; }

  bool isConnected() const override;

  bool isWriteBusy() const override;
  size_t writeFrame(const uint8_t src[], size_t len) override;
  size_t checkRecvFrame(uint8_t dest[]) override;
};