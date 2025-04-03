#include "RCSwitch.h"
#include "rc_switch.h"
#include "esphome/core/log.h"

namespace esphome {
namespace rc_switch {

    static const char *const TAG = "rc_switch";

    void RCSwitchComponent::setup() {
        ESP_LOGCONFIG(TAG, "Setting up RCSwitch on pin %d", this->rx_pin_);
        this->rc_switch_.enableReceive(this->rx_pin_);        
    }

    void RCSwitchComponent::loop() {
        if (this->rc_switch_.available()) {
            unsigned long value = this->rc_switch_.getReceivedValue();
            unsigned long bitlen = this->rc_switch_.getReceivedBitlength();
            unsigned long protocol = this->rc_switch_.getReceivedProtocol();
            if (value != 0) {
                ESP_LOGCONFIG(TAG, "Received: %d / %d Protocol: %d", value, bitlen, protocol);
                char buffer[32];
                snprintf(buffer, sizeof(buffer), "%lu", value);
                this->publish_state(buffer);
            }
            this->rc_switch_.resetAvailable();
        }
    }

}  // namespace rc_switch
}  // namespace esphome