from esphome.components import text_sensor
from esphome.const import CONF_PIN

DEPENDENCIES = ["text_sensor"]

CODEOWNERS = ["@your_github_username"]

# No direct imports of text_sensor.TEXT_SENSOR_SCHEMA to avoid circular imports.