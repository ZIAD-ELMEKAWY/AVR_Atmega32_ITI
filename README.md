<div align="center">

# ⚡ ATmega32 AVR Drivers – ITI Embedded Systems

[![Microchip AVR](https://img.shields.io/badge/Microcontroller-ATmega32-blue.svg)](https://www.microchip.com/en-us/product/ATmega32)
[![Language](https://img.shields.io/badge/Language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Architecture](https://img.shields.io/badge/Architecture-Layered%20Software-brightgreen.svg)](#-layered-software-architecture)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A fully modular, production-grade **C driver suite** for the **8-bit AVR ATmega32 microcontroller**.  
Built following standard **Layered Embedded Software Architecture** principles taught during the **ITI (Information Technology Institute)** Embedded Systems track.

</div>

---

## 📐 Layered Software Architecture

<div align="center">
  <img src="architecture_animation.svg" width="600" alt="Layered Architecture Animation"/>
</div>

<br>

| Layer | Components | Purpose |
|:-----:|:-----------|:--------|
| **APP** | `main.c` · System Integration | High-level application logic |
| **HAL** | LED · SSD · LCD · KEYPAD · MOTOR | External hardware abstraction |
| **MCAL** | DIO · EXTI · GIE · ADC · TIMER · USART · SPI · TWI · WDT | Internal peripheral control |
| **LIB** | STD_Types · BIT_Math | Common utilities & type definitions |

---

## 📁 Repository Structure

```
AVR_Atmega32_ITI/
├── 📂 APP/
│   ├── DIO_test.c              # 🔌 DIO driver test application
│   └── Seven_Segment.c         # 7️⃣ Seven-Segment test application
│
├── 📂 HAL/
│   ├── 📂 LED/
│   │   ├── LED_Config.h
│   │   ├── LED_Interface.h     # 💡 Public LED API
│   │   ├── LED_Private.h
│   │   └── LED_Program.c
│   └── 📂 SSD/
│       ├── SSD_Config.h
│       ├── SSD_Interface.h     # 7️⃣ Public SSD API
│       ├── SSD_Private.h
│       └── SSD_Program.c
│
├── 📂 MCAL/
│   └── 📂 DIO/
│       ├── DIO_Config.h
│       ├── DIO_Interface.h     # 🔌 Public DIO API
│       ├── DIO_Private.h
│       └── DIO_Program.c
│
├── 📂 LIB/
│   ├── STD_Types.h             # 📋 Standard type definitions
│   └── BIT_Math.h              # 🔧 Bit manipulation macros
│
├── 📂 Hardware_Connection/
│   ├── LED_Simulation.PNG      # 🖼️ LED Proteus schematic
│   └── 7_Segment_Simulation.PNG # 🖼️ 7-Segment Proteus schematic
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## 📋 File Structure Design Rule

Each module inside **MCAL** and **HAL** strictly follows the **4-file structure pattern**:

| File Pattern | Description |
| :--- | :--- |
| `MODULE_Interface.h` | **Public API:** Contains exposed function prototypes, enums, and macros. |
| `MODULE_Config.h` | **User Configurations:** Pre-compile configurations (e.g., prescalers, pin mappings). |
| `MODULE_Private.h` | **Private Registers:** Memory addresses, register structures, and internal macros. |
| `MODULE_Program.c` | **Implementation:** C source code implementation of public and private functions. |

---

## 🔌 DIO Driver (GPIO) – MCAL

The **DIO** driver provides complete control over the ATmega32 GPIO pins and ports.

### 📌 Supported Operations

| Function | Description |
|----------|-------------|
| `DIO_enumSetPinDirection(port, pin, direction)` | Set a single pin as **Input** or **Output**. |
| `DIO_enumSetPinValue(port, pin, value)` | Write **HIGH** or **LOW** to a single pin. |
| `DIO_enumGetPinValue(port, pin, *data)` | Read the current logic level of a single pin. |
| `DIO_enumTogglePinValue(port, pin)` | Toggle (invert) the logic level of a single pin. |
| `DIO_enumSetPortDirection(port, direction)` | Set the direction of an entire 8-bit port. |
| `DIO_enumSetPortValue(port, value)` | Write an 8-bit value to an entire port. |
| `DIO_enumGetPortValue(port, *data)` | Read the current 8-bit value of a port. |
| `DIO_enumTogglePortValue(port)` | Toggle all bits of an entire port. |

### 📌 Constants

```c
// Ports
DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD

// Pins
DIO_PIN0 … DIO_PIN7

// Directions
DIO_PIN_INPUT, DIO_PIN_OUTPUT
DIO_PORT_INPUT, DIO_PORT_OUTPUT

// Values
DIO_PIN_LOW, DIO_PIN_HIGH
DIO_PORT_LOW, DIO_PORT_HIGH
```

### 💻 Example Usage

```c
#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL

int main()
{
    // Set PC0 and PC1 as outputs
    DIO_enumSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);

    // Set entire PORTA as output
    DIO_enumSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);

    while (1)
    {
        DIO_enumSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
        _delay_ms(100);
        DIO_enumSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);

        DIO_enumSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_HIGH);
        _delay_ms(100);
        DIO_enumSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_LOW);

        DIO_enumSetPortValue(DIO_PORTA, DIO_PORT_HIGH);
    }
    return 0;
}
```

---

## 💡 LED Driver – HAL

High-level abstraction over the DIO driver for controlling LEDs.

### 📌 LED Configuration Structure

```c
typedef struct {
    u8 Port;           // LED_PORTA … LED_PORTD
    u8 Pin;            // LED_PIN0  … LED_PIN7
    u8 Active_State;   // ACTIVE_HIGH or ACTIVE_LOW
} LED_Type;
```

### 📌 API

| Function | Description |
|----------|-------------|
| `LED_voidInit(LED_Type config)` | Initialize the LED pin as output. |
| `LED_voidOn(LED_Type config)` | Turn the LED ON. |
| `LED_voidOff(LED_Type config)` | Turn the LED OFF. |
| `LED_voidToggle(LED_Type config)` | Toggle the LED state. |

### 💻 Example

```c
#include "HAL/LED/LED_Interface.h"

LED_Type myLed = { LED_PORTC, LED_PIN0, ACTIVE_HIGH };

int main()
{
    LED_voidInit(myLed);

    while (1)
    {
        LED_voidOn(myLed);
        _delay_ms(500);
        LED_voidOff(myLed);
        _delay_ms(500);
    }
    return 0;
}
```

---

## 7️⃣ Seven-Segment Display (SSD) Driver – HAL

Driver for common-cathode and common-anode 7-segment displays.

### 📌 SSD Configuration Structure

```c
typedef struct {
    u8 Type;      // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
    u8 DataPort;  // SSD_PORTA … SSD_PORTD
} SSD_Type;
```

### 📌 API

| Function | Description |
|----------|-------------|
| `SSD_InitialDataPort(SSD_Type ssd)` | Initialize the data port as output. |
| `SSD_SendNumber(SSD_Type ssd, u8 number)` | Display a digit (0–9) on the 7-segment. |

### 💻 Example

```c
#include "HAL/SSD/SSD_Interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL

SSD_Type ssd1 = { SSD_COMMON_CATHODE, SSD_PORTC };
SSD_Type ssd2 = { SSD_COMMON_ANODE,   SSD_PORTD };

int main()
{
    SSD_InitialDataPort(ssd1);
    SSD_InitialDataPort(ssd2);

    while (1)
    {
        for (u8 i = 0; i <= 9; i++)
        {
            SSD_SendNumber(ssd1, i);
            _delay_ms(500);
        }
        for (u8 i = 0; i <= 9; i++)
        {
            SSD_SendNumber(ssd2, i);
            _delay_ms(500);
        }
    }
    return 0;
}
```

---

## 🎬 Simulation Demos

> 🎥 **Tip:** Record your Proteus simulations and convert them to GIFs for live demos!

<div align="center">

### 💡 LED Blinking Demo
<img src="Hardware_Connection/LED_Simulation.PNG" width="500" alt="LED Simulation"/>

*Replace with `LED_Demo.gif` for animated playback*

### 7️⃣ Seven-Segment Counting Demo
<img src="Hardware_Connection/7_Segment_Simulation.PNG" width="500" alt="7-Segment Simulation"/>

*Replace with `7Segment_Demo.gif` for animated playback*

</div>

---

## 🛠️ Toolchain & Setup

### 📌 Prerequisites

| Tool | Purpose |
|------|---------|
| **avr-gcc** | AVR C compiler |
| **Microchip Studio** (or Atmel Studio) | Full IDE with simulator & programmer |
| **VS Code** + Embedded Tools | Lightweight alternative IDE |
| **avrdude** | Flashing tool (USBasp, AVRISP mkII, Arduino as ISP) |
| **Proteus VSM / SimulIDE** | Circuit simulation & debugging |

### 💻 Build & Flash (Command Line)

```bash
# Compile
avr-gcc -mmcu=atmega32 -DF_CPU=8000000UL -O2 \
    -o main.elf APP/main.c \
    MCAL/DIO/DIO_Program.c \
    HAL/LED/LED_Program.c \
    HAL/SSD/SSD_Program.c

# Generate HEX
avr-objcopy -O ihex main.elf main.hex

# Flash (example with USBasp)
avrdude -c usbasp -p m32 -U flash:w:main.hex:i
```

---

## 🚀 Quick Start

```bash
# 1. Clone the repository
git clone https://github.com/ZIAD-ELMEKAWY/AVR_Atmega32_ITI.git

# 2. Open in your preferred IDE
#    (Microchip Studio / VS Code / Eclipse)

# 3. Include the required headers in your main.c
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/LED_Interface.h"

# 4. Build & Flash to your ATmega32
```

---

## 📜 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

<div align="center">

## 👤 Author

**[Ziad Elmekawy](https://github.com/ZIAD-ELMEKAWY)**  
*Information Technology Institute (ITI) – Embedded Systems Track*

---

⭐ If you find this project helpful, please consider giving it a star!

</div>
