# ⚡ ATmega32 AVR Drivers – ITI Embedded Systems

[![Microchip AVR](https://img.shields.io/badge/Microcontroller-ATmega32-blue.svg)](https://www.microchip.com/en-us/product/ATmega32)
[![Language](https://img.shields.io/badge/Language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Architecture](https://img.shields.io/badge/Architecture-Layered%20Software-brightgreen.svg)](#-layered-software-architecture)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A fully modular, production-grade C driver suite for the **8-bit AVR ATmega32 microcontroller**. Built following standard **Layered Embedded Software Architecture** principles taught during the **ITI (Information Technology Institute)** Embedded Systems track.

---

## 📐 Layered Software Architecture

This repository separates low-level hardware registers from high-level application logic using a 4-tier design model:
              +-----------------------------------+
              |         APP (Application)         |
              +-----------------------------------+
                                |
              +-----------------------------------+
              |    HAL (Hardware Abstraction)     |
              +-----------------------------------+
                                |
              +-----------------------------------+
              |  MCAL (Microcontroller Abstraction)|
              +-----------------------------------+
                                |
              +-----------------------------------+
              |      LIB (Libraries / Common)     |
              +-----------------------------------+

### 1. **LIB (Software Libraries)**
Contains utility headers for standard data types and bit manipulations:
* `STD_TYPES.h`: Standard integer type definitions (`u8`, `u16`, `u32`, `s8`, `s16`, `s32`, `f32`, `f64`, `ErrorState`).
* `BIT_MATH.h`: Bitwise operation macros (`SET_BIT`, `CLR_BIT`, `TOG_BIT`, `GET_BIT`).

### 2. **MCAL (Microcontroller Abstraction Layer)**
Directly interacts with internal ATmega32 hardware peripherals:
* **`DIO` (GPIO):** Pin & Port direction setting, reading, and writing.
* **`EXTI`:** External Interrupts (`INT0`, `INT1`, `INT2`) with configurable trigger modes.
* **`GIE`:** Global Interrupt Enable control (SREG bit 7).
* **`ADC`:** Analog-to-Digital Converter with single/chain conversion, polling, and interrupt capability.
* **`TIMER0`, `TIMER1`, `TIMER2`:** Timers/Counters operating in Normal, CTC, Fast PWM, and Phase Correct PWM modes, plus Input Capture Unit (ICU).
* **`USART`:** Serial asynchronous communication (TX/RX, polling, interrupts).
* **`SPI`:** Serial Peripheral Interface (Master/Slave modes).
* **`TWI` (I2C):** Two-Wire Interface with master/slave transmitter and receiver modes.
* **`WDT`:** Watchdog Timer control.

### 3. **HAL (Hardware Abstraction Layer)**
Provides high-level APIs for external components connected to the microcontroller:
* **`LCD`:** Character LCD (4-bit / 8-bit mode) driver for 16x2 / 20x4 screens.
* **`KEYPAD`:** 4x4 matrix keypad scanner.
* **`SSD`:** Seven Segment Display driver (Common Anode & Common Cathode).
* **`LED` & `SWITCH`:** Abstraction drivers for simple digital IO peripherals.
* **`DC_MOTOR` / `STEPPER_MOTOR`:** Motor direction and speed control interfacing via drivers like L293D / ULN2003.

### 4. **APP (Application Layer)**
Contains `main.c` and system integration logic, utilizing HAL and MCAL services to execute target tasks.

---

## 📁 File Structure Design Rule

Each module inside **MCAL** and **HAL** strictly follows the 4-file structure pattern:

| File Pattern | Description |
| :--- | :--- |
| `MODULE_interface.h` | **Public API:** Contains exposed function prototypes, ENUMs, and macros. |
| `MODULE_config.h` | **User Configurations:** Pre-compile configurations (e.g., prescalers, pin mappings). |
| `MODULE_private.h` | **Private Registers:** Memory addresses, register structures, and internal macros. |
| `MODULE_program.c` | **Implementation:** C source code implementation of public and private functions. |

---

## 🛠️ Toolchain & Setup

### Prerequisites
* **Compiler:** `avr-gcc`
* **IDE Options:** Microchip Studio (formerly Atmel Studio), VS Code with Embedded Tools, or Eclipse IDE.
* **Flashing Tool:** `avrdude` with USBasp, AVRISP mkII, or Arduino as ISP.
* **Simulation Tool:** Proteus VSM or SimulIDE.

# Author & Acknowledgments
## Author: Ziad Elmekawy
## Program: Information Technology Institute (ITI) – Embedded Systems Track
