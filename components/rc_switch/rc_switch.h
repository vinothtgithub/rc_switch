#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "RCSwitch.h"

namespace esphome {
namespace rc_switch {

class RCSwitchComponent : public text_sensor::TextSensor, public Component {
 public:
  RCSwitchComponent(int rx_pin) : rx_pin_(rx_pin) {}

  void setup() override;
  void loop() override;

//  private:
  int rx_pin_;
  RCSwitch rc_switch_;
};

}  // namespace rc_switch
}  // namespace esphome