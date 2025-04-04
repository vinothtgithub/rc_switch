#include "RCSwitch.h"
#include "rc_switch.h"
#include "esphome/core/log.h"

namespace esphome {
namespace rc_switch {

    static const char *const TAG = "rc_switch";

    void RCSwitchComponent::setup() {
        ESP_LOGCONFIG(TAG, "Setting up RCSwitch on pin %d", this->rx_pin_);
        
        // Use digitalPinToInterrupt to map the pin to an interrupt
        int interrupt = digitalPinToInterrupt(this->rx_pin_);
        if (interrupt == NOT_AN_INTERRUPT) {
            ESP_LOGE(TAG, "Pin %d is not an interrupt-capable pin!", this->rx_pin_);
            return;
        }
        this->rc_switch_.enableReceive(interrupt);        
    }

    void RCSwitchComponent::loop() {
        if (this->rc_switch_.available()) {
            unsigned long value = this->rc_switch_.getReceivedValue();            
            if (value != 0) {                
                char buffer[32];
                snprintf(buffer, sizeof(buffer), "%lu", value);
                this->publish_state(buffer);

                unsigned long bitlen = this->rc_switch_.getReceivedBitlength();
                unsigned long protocol = this->rc_switch_.getReceivedProtocol();
                ESP_LOGCONFIG(TAG, "Received: %d / %d Protocol: %d", value, bitlen, protocol);
            }
            this->rc_switch_.resetAvailable();
        }
    }

}  // namespace rc_switch
}  // namespace esphome
