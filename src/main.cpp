#include <Arduino.h>

// put function declarations here:


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
 
    Serial.printf("Deafult free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
    Serial.printf("PSRAM free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    Serial.printf("Flash size: %d bytes\n", ESP.getFlashChipSize());
}

void loop() {
    // put your main code here, to run repeatedly:
}

// put function definitions here:
