#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
QueueHandle_t queue_1;

LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(A0, INPUT);
  
  queue_1 = xQueueCreate(5, sizeof(int));
  if (queue_1 == NULL) {
    Serial.println("Queue can not be created");
  }
  xTaskCreate(TaskDisplay, "Display_task", 128, NULL, 1, NULL);
  xTaskCreate(TaskLDR, "LDR_task", 128, NULL, 1, NULL);
  vTaskStartScheduler();
}

void TaskDisplay(void * pvParameters) {
  int intensity = 0;
  while(1) {
    Serial.println("TaskDisplay");
      if (xQueueReceive(queue_1, &intensity, portMAX_DELAY) == pdPASS) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Intensity:");
      lcd.setCursor(11, 0);
      lcd.print(intensity);
    }
  }
}

void TaskLDR(void * pvParameters) {
  int current_intensity;
  while(1) {
    Serial.println("TaskLDR");
    current_intensity = analogRead(A0);
    Serial.println(current_intensity);
    xQueueSend(queue_1, &current_intensity, portMAX_DELAY);
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}

void loop(){
}
