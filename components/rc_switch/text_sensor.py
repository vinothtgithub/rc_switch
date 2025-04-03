import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_PIN, CONF_ID

rc_switch_ns = cg.esphome_ns.namespace("rc_switch")
RCSwitchComponent = rc_switch_ns.class_("RCSwitchComponent", cg.Component, text_sensor.TextSensor)

CONFIG_SCHEMA = text_sensor.TEXT_SENSOR_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(RCSwitchComponent),
        cv.Required(CONF_PIN): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], config[CONF_PIN])
    yield cg.register_component(var, config)
    yield text_sensor.register_text_sensor(var, config)