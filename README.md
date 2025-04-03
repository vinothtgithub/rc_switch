# rc_switch
433mhz remote receiver component for Esphome

This rc_switch receiver component is extended from rc-switch arduino library v2.6.4 https://github.com/sui77/rc-switch 

```yaml
external_components:
  - source: github://vinothtgithub/rc_switch
    components: [ rc_switch ]

esphome:
    name: esp32c3device
    platformio_options:
        platform: https://github.com/platformio/platform-espressif32.git#feature/arduino-upstream
        platform_packages:
        - framework-arduinoespressif32@https://github.com/espressif/arduino-esp32.git#2.0.0
        - espressif/toolchain-riscv32-esp @ 8.4.0+2021r2-patch5
        board_build.variant: esp32c3
        board_build.f_cpu: 160000000L
        board_build.f_flash: 40000000L
        upload_protocol: esptool
        board_build.flash_mode: dio

esp32:
    board: esp32-c3-devkitm-1
    framework:
        type: arduino

text_sensor:
  - platform: rc_switch
    pin: 7 #GPIO7
    name: "RC Switch Received Code"
    id: rc_switch_sensor
```
