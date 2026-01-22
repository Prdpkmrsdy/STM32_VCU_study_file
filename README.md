Automotive Vehicle Control Unit (VCU) – SAE Electric Vehicle
Overview

This repository documents the design and development of an Automotive Vehicle Control Unit (VCU) for an SAE electric vehicle platform. The VCU serves as the central controller for vehicle operation, coordinating power management, communication, sensing, and safety-critical control functions.

The project focuses on system-level robustness, fault tolerance, and automotive-style design practices, bridging the gap between academic projects and real-world EV electronics.

Key Objectives

Design a production-oriented VCU architecture

Ensure robust power management with backup operation

Implement safe, isolated I/O for vehicle interfaces

Build a modular, diagnostics-ready firmware foundation

Enable vehicle communication, sensing, and data logging

System Architecture

The VCU architecture is centered around an STM32L496RE (ARM Cortex-M4) microcontroller operating at 3.3 V. The system is partitioned into the following functional domains:

Power architecture and power sequencing

Core processing and embedded firmware

Vehicle communication and connectivity

Sensing and analog signal conditioning

Safety-critical I/O and vehicle mode control

Block-level and power-flow diagrams are included to illustrate subsystem interactions.

Power Architecture

12 V vehicle input with fuse protection

TPS54331 buck converter for 12 V → 3.3 V primary regulation

Li-ion backup battery (3.6 V) with BQ25300RTER charger

TPS799315DDCT LDO for backup operation during brownouts

OR-ing and enable logic for seamless rail switching

MCU-controlled power sequencing (EN_BUCK, EN_CH, EN_BATOP)

ADC-based voltage and temperature monitoring

This design enables controlled startup, shutdown, and fault-tolerant operation.

Core Processing & Firmware

MCU: STM32L496RE (ARM Cortex-M4)

Supply: 3.3 V

Peripherals used:

CAN

UART

ADC / DAC

GPIO

Timers

I²C / SPI

Firmware Highlights

Interrupt-driven architecture using STM32 HAL

Modular driver structure for communication, sensing, and I/O

UART-based logging for bring-up and debugging

Structured fault handling and diagnostics hooks

Clean separation between hardware abstraction and application logic

The firmware is designed to scale with additional features and testing requirements.

Communication & Connectivity

Dual CAN transceivers (TJA1057) powered from a 5 V rail

CAN communication with:

Motor controller

Battery Management System (BMS)

Dashboard

Other vehicle ECUs

MC60CA-04-STD GPS-GSM module (3.3 V)

GPS and GSM UART interfaces

Supports tracking, telemetry, and remote diagnostics

External antennas for GPS, GSM, and Bluetooth

Sensing & Signal Conditioning

ICM-20600 IMU for motion and inertial data

Voltage, current, and temperature sensing via:

Fractional op-amp conditioning

MCU ADC channels

Battery and board temperature monitoring

Throttle input/output processed using op-amp circuits

MCU DAC used for controlled analog output generation

Safety-Critical I/O & Mode Control

Opto-isolated digital inputs/outputs for:

Key / ignition

BMS wake-up

Drive modes (Normal / Eco / Sport / Reverse)

Side-stand sensor

Dashboard ignition

Isolation protects the MCU from:

Voltage spikes

Ground loops

External wiring faults

Additional opto-isolated GPIOs for diagnostics and vehicle status signaling

Security & Data Logging

ATSHA204A secure authentication IC

Device identity protection

Basic access control

SD card interface (3.3 V)

Vehicle data logging

Diagnostics and validation support
