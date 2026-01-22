#  Automotive Vehicle Control Unit (VCU)
### SAE Electric Vehicle Platform

> **Embedded Automotive ECU | Power Management | CAN | Safety-Critical I/O**

---

##  Overview
This repository documents the **end-to-end design and development of an Automotive Vehicle Control Unit (VCU)** for an SAE electric vehicle platform.

The VCU serves as the **central controller for vehicle operation**, coordinating power management, communication, sensing, and safety-critical control functions.

The project focuses on **system-level robustness, fault tolerance, and automotive-style design practices**, bridging the gap between academic projects and real-world EV electronics.

---

##  Key Objectives
- Design a **production-oriented VCU architecture**
- Ensure **robust power management with backup operation**
- Implement **safe, opto-isolated I/O for vehicle interfaces**
- Build a **modular, diagnostics-ready firmware foundation**
- Enable vehicle communication, sensing, and data logging

---

##  System Architecture
The VCU architecture is centered around an **STM32L496RE (ARM Cortex-M4)** microcontroller operating at **3.3 V**.

### Functional Domains
-  Power architecture & power sequencing
-  Core processing & embedded firmware
-  Vehicle communication & connectivity
-  Sensing & analog signal conditioning
-  Safety-critical I/O & vehicle mode control

> Block-level and power-flow diagrams are included to illustrate subsystem interactions.

---

##  Power Architecture
- **12 V vehicle input** with fuse protection
- **TPS54331 buck converter** for 12 V → 3.3 V primary regulation
- **Li-ion backup battery (3.6 V)** with **BQ25300RTER charger**
- **TPS799315DDCT LDO** for backup operation during brownouts
- OR-ing and enable logic for seamless rail switching
- MCU-controlled power sequencing  
  (`EN_BUCK`, `EN_CH`, `EN_BATOP`)
- ADC-based voltage & temperature monitoring

 Enables controlled startup, shutdown, and fault-tolerant operation.

---

##  Core Processing & Firmware
**Microcontroller:** STM32L496RE (ARM Cortex-M4)  
**Operating Voltage:** 3.3 V  

### Peripherals Used
- CAN
- UART
- ADC / DAC
- GPIO
- Timers
- I²C / SPI

### Firmware Highlights
- Interrupt-driven architecture using **STM32 HAL**
- Modular drivers for communication, sensing, and I/O
- Structured fault handling and diagnostics hooks
- UART-based logging for bring-up and debugging
- Clear separation between HAL and application logic

---

##  Communication & Connectivity
### CAN
- Dual **TJA1057 CAN transceivers** (5 V rail)
- Communication with:
  - Motor controller
  - BMS
  - Dashboard
  - Other vehicle ECUs

### GPS / GSM
- **MC60CA-04-STD GPS-GSM module** (3.3 V)
- UART interfaces for GPS and GSM
- Control lines: `PWRKEY`, `DTR`, `Netlight`
- Supports:
  - Vehicle tracking
  - Telemetry
  - Remote diagnostics
- External antennas for GPS, GSM, and Bluetooth

---

##  Sensing & Signal Conditioning
- **ICM-20600 IMU** for inertial and motion data
- Voltage, current, and temperature sensing via:
  - Fractional op-amp conditioning
  - MCU ADC channels
- Battery & board temperature monitoring
- Throttle input/output processed using op-amp circuits
- MCU DAC used for controlled analog output generation

---

##  Safety-Critical I/O & Mode Control
- Opto-isolated digital I/O for:
  - Key / ignition
  - BMS wake-up
  - Drive modes (Normal / Eco / Sport / Reverse)
  - Side-stand sensor
  - Dashboard ignition
- Isolation protects MCU from:
  - Voltage spikes
  - Ground loops
  - External wiring faults
- Additional opto-isolated GPIOs for diagnostics and vehicle status signaling

---

##  Security & Data Logging
- **ATSHA204A secure authentication IC**
  - Device identity protection
- **SD card interface (3.3 V)**
  - Vehicle data logging
  - Diagnostics & validation support

---

##  Engineering Outcomes
- Designed a **robust, vehicle-ready VCU architecture**
- Implemented **fault-tolerant power and safety design**
- Built a **scalable embedded firmware foundation**
- Applied real automotive isolation & diagnostics concepts
- Delivered a VCU suitable for **real vehicle integration**

---

## Notes
Some design files and implementation details are **confidential** and shared selectively due to stakeholder and vehicle program requirements.

---

## 📬 Contact
For questions, collaboration, or technical discussion, feel free to reach out via my portfolio or LinkedIn.
