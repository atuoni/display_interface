# STM32 TFT Menu System with Rotary Encoder

## Overview

This project implements a modular graphical menu system for STM32 microcontrollers using:

* STM32 HAL drivers
* TFT LCD display
* Rotary encoder (KY-040)
* Finite State Machine (FSM)
* Table-driven menu architecture

The firmware demonstrates how to build scalable embedded user interfaces by separating screens, menu widgets, navigation logic, and hardware control.

## Features

* Rotary encoder navigation
* Encoder push-button selection
* TFT graphical interface
* State machine based screen management
* Table-driven menu system
* Flicker-free menu updates
* Callback-based menu actions
* Easy addition of new screens and menu items
* Modular source code organization

## Hardware

### Tested Platform

* STM32 NUCLEO-F446RE

### Display

* TFT LCD compatible with:

  * ILI9340
  * ST7789

### Input Device

* KY-040 Rotary Encoder

## Software Architecture

The project is organized using a Finite State Machine (FSM).

Each screen is treated as a state:

```text
SCREEN_1
SCREEN_2
SCREEN_3
SCREEN_4
SCREEN_5
```

Navigation between screens occurs through menu selections.

### Screen Structure

Each screen implements:

```c
static void screen_draw(void);
static void screen_event(void);
```

and exports a screen object:

```c
Screen_t screen_x =
{
    .draw  = screen_draw,
    .event = screen_event
};
```

## Project Structure

```text
Core/
│
├── Inc/
│   ├── screen.h
│   ├── menu.h
│   ├── encoder.h
│   ├── menu_widget.h
│   ├── screen_1.h
│   ├── screen_2.h
│   ├── screen_3.h
│   └── screen_4.h
│
└── Src/
    ├── main.c
    ├── menu.c
    ├── encoder.c
    ├── menu_widget.c
    ├── screen.c
    ├── screen_1.c
    ├── screen_2.c
    ├── screen_3.c
    └── screen_4.c
```

## Encoder Operation

### Clockwise Rotation

Moves selection down.

### Counter-Clockwise Rotation

Moves selection up.

### Button Press

Executes selected item action or navigates to another screen.

## Flicker-Free Rendering

To improve user experience, the menu system does not redraw the entire screen during navigation.

Only the affected menu items are updated:

This reduces display refresh time and eliminates visible flicker.

## License

This project is intended for educational and embedded systems development purposes.

## Author

Amauri Tuoni

STM32 Embedded Systems Development
