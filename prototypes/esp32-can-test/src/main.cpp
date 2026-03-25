#include <Arduino.h>
#include "driver/twai.h"


void setup() {
  Serial.begin(115200);

  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT((gpio_num_t)5, (gpio_num_t)4, TWAI_MODE_NORMAL);
  twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

  if (twai_driver_install(&g_config, &t_config, &f_config) == ESP_OK){
    Serial.println("CAN Driver Installed");
  }

  if(twai_start() == ESP_OK){
    Serial.println("CAN Driver Started");
  }
}

void loop() {
  twai_message_t message;

  if (twai_receive(&message, pdMS_TO_TICKS(1000)) == ESP_OK){
    Serial.printf("ID: 0x%03X | Data: ", message.identifier);
    for (int i=0; i<message.data_length_code; i++){
      Serial.printf("%02X ", message.data[i]);
    }
    Serial.println();
  }else {
    Serial.println("Waiting for CAN data...");
  }
}

