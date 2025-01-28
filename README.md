# FreeRTOS Learning Repository

This repository showcases my journey learning FreeRTOS as part of my Real-Time Systems course. The examples provided demonstrate core FreeRTOS features such as task creation and queue handling in an Arduino environment.

---

## Overview

FreeRTOS is a lightweight, real-time operating system designed for microcontrollers. This repository explores its capabilities through practical examples, focusing on task scheduling and inter-task communication.

---

## Projects

### 1. Task Creation Example ([FreeRTOS_task_creation.ino](FreeRTOS_task_creation/FreeRTOS_task_creation.ino))
This example demonstrates how to create multiple tasks with FreeRTOS. Key features include:
- **TaskBlink1:** Controls an LED on pin 8 to blink at a 200ms interval.
- **TaskBlink2:** Controls an LED on pin 7 to blink at a 300ms interval.
- **TaskPrint:** Prints a counter value to the serial monitor every 500ms.
  
**Demo:**
![InAction](https://github.com/Tadyboii/FreeRTOS-basics/blob/main/ac1.gif)

### 2. Queue Handling Example ([FreeRTOS_queues.ino](FreeRTOS_queues/FreeRTOS_queues.ino))
This example showcases inter-task communication using queues. Key features include:
- Reading light intensity values from an LDR sensor connected to `A0`.
- Sending the sensor readings to a queue.
- Displaying the readings on an LCD using the LiquidCrystal_I2C library.

---

## Usage

1. Clone this repository:
   ```bash
   git clone https://github.com/your_username/freertos-learning.git
   ```
2. Open the desired `.ino` file in the Arduino IDE.
3. Install the required libraries via the Arduino Library Manager.
4. Upload the code to your Arduino board.
5. Monitor the output using the Serial Monitor or the connected LCD.

---

## Contributing

Feel free to fork this repository, open issues, or submit pull requests to add more FreeRTOS examples or improve existing ones. Collaboration is welcome!

---

## License

This repository is licensed under the MIT License. See [LICENSE](LICENSE) for more details.

---



