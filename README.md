
<div align="center">

# AditiOS

### Project Aditi - An Open-Source Operating System Initiative

**Rooted in Bharat. Built from the Kernel Up.**

An experimental operating system project focused on kernel research, low-level programming, and systems engineering.

![Status](https://img.shields.io/badge/Status-Early_Development-orange)
![Platform](https://img.shields.io/badge/Architecture-x86-blue)
![Project](https://img.shields.io/badge/Project-Open_Source-brightgreen)
![Kernel](https://img.shields.io/badge/Kernel-Experimental-lightgrey)

</div>

---

## Overview

**AditiOS** is an independent, open-source operating system research and development initiative focused on building an operating system from the ground up.

The project begins at the most fundamental layer of computing: the **kernel**.

Rather than building upon an existing operating system kernel, AditiOS aims to explore operating system architecture through hands-on implementation of core systems components.

The initiative serves as a platform for research, experimentation, learning, and long-term systems engineering.

> **AditiOS is not intended to be another Linux distribution.**
>
> It is an effort to understand, design, and build an operating system starting from its foundational components.

---

## The Name: Aditi (अदिति)

In Vedic philosophy, **Aditi** represents boundlessness, freedom, and the encompassing whole.

The name reflects the project's foundational vision: a kernel that provides the underlying structure upon which an entire computing environment can be built.

Just as Aditi symbolizes the encompassing whole, the operating system kernel serves as the foundation connecting hardware, software, and computation.

The name represents both the project's Indian origins and its aspiration toward open-ended exploration in computer science.

---

## Project Status

**Current Phase: Initial Kernel Research & Development**

AditiOS is currently in its early development stage.

An initial kernel prototype has been developed, establishing the starting point for further exploration of operating system internals.

The project currently focuses on:

- Understanding x86 computer architecture
- Exploring boot and kernel initialization
- Developing low-level kernel components
- Investigating memory and hardware interaction
- Establishing a modular foundation for future development

**Note:** AditiOS is an experimental research project and is not currently intended for production use.

---

## Architecture

The long-term architecture is envisioned as a layered operating system design.

```text
+--------------------------------------+
|          User Applications           |
+--------------------------------------+
|        System Libraries / APIs       |
+--------------------------------------+
|             System Calls             |
+--------------------------------------+
|                                      |
|             Aditi Kernel             |
|                                      |
|  +--------------------------------+  |
|  |       Process Management       |  |
|  +--------------------------------+  |
|  |        Memory Management       |  |
|  +--------------------------------+  |
|  |        Interrupt Handling      |  |
|  +--------------------------------+  |
|  |        Device Management       |  |
|  +--------------------------------+  |
|  |        File System Layer       |  |
|  +--------------------------------+  |
|                                      |
+--------------------------------------+
|             x86 Hardware             |
+--------------------------------------+
```

*This diagram represents the intended architecture, not a list of fully implemented features.*

---

## Development Roadmap

The following roadmap outlines the planned direction of AditiOS.

### Phase 1 - Kernel Foundation

- [ ] Bootloader integration
- [ ] Kernel entry point and initialization
- [ ] Basic terminal output
- [ ] Global Descriptor Table (GDT)
- [ ] Interrupt Descriptor Table (IDT)
- [ ] Basic exception handling

### Phase 2 - Memory Management

- [ ] Physical memory management
- [ ] Paging and virtual memory
- [ ] Kernel heap allocation
- [ ] Memory protection

### Phase 3 - Process Management

- [ ] Task and process structures
- [ ] Context switching
- [ ] Process scheduling
- [ ] Multitasking
- [ ] System call interface

### Phase 4 - Hardware and I/O

- [ ] Keyboard input
- [ ] Timer interrupts
- [ ] Basic device drivers
- [ ] Disk I/O
- [ ] File system implementation

### Phase 5 - User Environment

- [ ] User-mode execution
- [ ] Basic command-line shell
- [ ] System utilities
- [ ] Executable loading
- [ ] User-space applications

### Phase 6 - Long-Term Research

- [ ] Multiprocessor support
- [ ] Advanced scheduling algorithms
- [ ] Improved memory management
- [ ] Security and isolation
- [ ] Performance optimization
- [ ] Exploration of graphical interfaces

The roadmap is experimental and may evolve as development progresses.

---

## Engineering Principles

AditiOS is guided by five foundational principles.

**1. Simplicity**

Build understandable, maintainable systems before introducing unnecessary complexity.

**2. Modularity**

Design components with clearly defined responsibilities and interfaces.

**3. Reliability**

Prioritize predictable behavior, correctness, and fault isolation.

**4. Efficiency**

Explore efficient use of hardware resources through low-level systems programming.

**5. Openness**

Encourage experimentation, knowledge sharing, and collaborative development.

---

## Technology Focus

| Area | Technologies / Concepts |
|------|--------------------------|
| Architecture | x86 |
| Kernel Development | C, Assembly |
| Systems Programming | Low-level programming |
| Boot Process | Bootloaders, CPU initialization |
| Memory | Paging, allocation, virtual memory |
| Concurrency | Processes, scheduling, interrupts |
| Development Tools | GCC, GNU Binutils, Make |
| Testing & Emulation | QEMU, GDB |

*Technologies listed represent the project's development focus and intended tooling.*

---

## Getting Started

AditiOS is currently under active experimentation.

Build instructions and emulator setup documentation will be added as the kernel implementation stabilizes.

Future developer documentation will cover:

1. Setting up the development toolchain
2. Compiling the bootloader and kernel
3. Creating a bootable image
4. Running AditiOS in QEMU
5. Debugging kernel execution using GDB

---

## Contributing

AditiOS is intended to grow as an open-source research and engineering initiative.

Contributions, technical discussions, architectural suggestions, and bug reports are welcome as the project develops.

Potential contribution areas include:

- Kernel architecture
- Memory management
- Process scheduling
- Device drivers
- Low-level debugging
- Documentation
- Testing and emulation

Contribution guidelines will be published as the project matures.

---

## Project Philosophy

> An operating system is more than a collection of programs.
> It is the foundation that enables hardware and software to work together.

AditiOS begins with a small kernel prototype and a simple objective: to understand computing systems by building their foundations.

There is still a long journey ahead.

The project will evolve through incremental development, research, experimentation, and continuous learning.

---

## License

License information will be added to the repository.

Until a license is provided, the repository's source code is not automatically licensed for reuse or redistribution.

---

<div align="center">

### AditiOS

**Project Aditi**

*Rooted in Bharat. Built from the Kernel Up.*

**Built with curiosity. Driven by research. Open to possibilities.**

</div>
