# myRtos

A bare-metal real-time operating system for the STM32F401, built from scratch using ARM Cortex-M and STM32 reference manuals , no CMSIS, no HAL.

## Why this project exists

Most embedded projects lean on vendor-provided abstraction layers (HAL, CMSIS) from day one. This project takes the opposite approach: every peripheral driver, every register struct, and every piece of the interrupt and scheduling infrastructure is written directly from the manufacturer's reference manuals, with no generated code in between.

The goal is to build a genuine understanding of what happens at the hardware level — how the NVIC arbitrates interrupts, how the SCB configures system exceptions, how the Cortex-M exception model enables context switching — and to use that understanding as the foundation for a real-time scheduler suitable for safety-critical style applications.

## Current status

| Component | Status |
|---|---|
| NVIC driver (register-level, full ISER/ICER/IPR blocks) | ✅ Complete |
| SCB driver (AIRCR, priority grouping, SHPR) | ✅ Complete |
| Interrupt-driven SysTick (ms-parameterized API) | ✅ Complete, hardware-verified |
| Cortex-M exception model (MSP/PSP separation, PendSV, SVC) | 🔄 In progress |
| Scheduler (TCBs, context switching, task states) | ⏳ Planned |
| Synchronization primitives (semaphores, mutexes, queues) | ⏳ Planned |
| Application layer (redundant sensor voting system) | ⏳ Planned |

## Architecture

The project follows a layered design, separating concerns the way a production embedded codebase would:

```
Application  →  Kernel (RTOS)  →  BSP  →  Drivers  →  Core (Cortex-M)  →  Hardware
```

- **Core** : ARM Cortex-M architectural drivers: NVIC, SCB, SysTick. These are core-level, not STM32-specific.
- **Driver** : STM32 peripheral drivers: GPIO, RCC, USART. Generic and reusable across STM32F401-based boards.
- **BSP** *(planned)* : board-specific configuration: pin assignments, sensor wiring, board init.
- **Kernel** *(planned)* : the RTOS itself: scheduler, task control blocks, context switching.
- **App** : application-level logic, currently a placeholder pending the scheduler.

This separation exists so that, for example, the application layer will eventually be able to describe *what* it wants (read three IMUs, vote on consensus) without knowing anything about which STM32 registers are involved.

## Repository structure

```
myRtos/
├── Core/
│   ├── Inc/            # base.h, nvic.h, scb.h, systick.h
│   └── Src/            # nvic.c, scb.c, systick.c, syscalls.c, sysmem.c
├── Driver/
│   ├── Inc/            # gpio.h, rcc.h
│   └── Src/            # gpio.c, rcc.c
├── Startup/
│   └── startup_stm32f401retx.s
├── app/
│   └── main.c
├── version.h
├── CMakeLists.txt
└── STM32F401RETX_FLASH.ld
```

## Toolchain

- **MCU**: STM32F401RE (ARM Cortex-M4)
- **Build system**: CMake (no STM32CubeIDE auto-generated project files)
- **Compiler**: arm-none-eabi-gcc
- **Verification**: Saleae logic analyzer for hardware-level signal verification

Built with CMake rather than IDE auto-discovery to keep the full build process — startup file, linker script, compiler flags  explicit and under direct control.

## Notable engineering decisions and bugs caught

Building without a HAL means catching your own bugs at the register level. A few worth noting:

- **AIRCR silent write rejection**: the SCB's Application Interrupt and Reset Control Register requires the `VECTKEY` field (`0x5FA`) to be written on every access, or the write is silently discarded no error, just ignored.
- **NVIC struct alignment**: an incorrect reserved-field size in the register struct caused a silent misalignment across the entire NVIC register block.
- **SysTick priority field**: the priority field occupies specific bit positions within a 32-bit register (bits requiring shifts of 28 and 20), and only the top 4 bits of the priority value are implemented in hardware writing the full byte without masking corrupts adjacent fields.

A full debugging log is maintained alongside development and will be published as the project progresses.

## Roadmap

1. Complete the Cortex-M exception model: MSP/PSP separation, PendSV-based context switching, SVC for privileged transitions.
2. Implement the scheduler: task control blocks, task states, priority-based scheduling.
3. Add synchronization primitives: semaphores, mutexes, queues.
4. Build the application layer: a redundant three-sensor (IMU/barometer) voting system with fault isolation logic, inspired by triplex flight computer architectures.
5. Apply MISRA C 2012-oriented static analysis across the codebase.

## About

Built by Anfel Sakni, an Embedded Systems & IoT engineering student at ISIMG Gabès, Tunisia, as part of a safety-critical embedded software portfolio targeting firmware and embedded software roles.

- GitHub: [github.com/Sakni-Anfel](https://github.com/Sakni-Anfel)
