# assembly-fundamental-lowlevelacademy
ARM assemby study
```sh
           /:-------------:\          ndd@th1nkd0m
        :-------------------::        OS: Fedora
      :-----------/shhOHbmp---:\      Kernel: x86_64 Linux 6.13.10-200.fc41.x86_64
    /-----------omMMMNNNMMD  ---:     Uptime: 2h 37m
   :-----------sMMMMNMNMP.    ---:    Packages: 1730
  :-----------:MMMdP-------    ---\   Shell: zsh 5.9
 ,------------:MMMd--------    ---:   Resolution: No X Server
 :------------:MMMd-------    .---:   WM: i3
 :----    oNMMMMMMMMMNho     .----:   GTK Theme: Adwaita [GTK3]
 :--     .+shhhMMMmhhy++   .------/   Disk: 136G / 937G (16%)
 :-    -------:MMMd--------------:    CPU: 13th Gen Intel Core i7-13700H @ 20x 4.8GHz [58.0°C]
 :-   --------/MMMd-------------;     GPU: NVIDIA RTX 2000 Ada Generation Laptop GPU
 :-    ------/hMMMy------------:      RAM: 8190MiB / 31742MiB
 :-- :dMNdhhdNMMNo------------;
 :---:sdNMMMMNds:------------:
 :------:://:-------------::
 :---------------------://
```

## Setup
```sh
sudo dnf install arm-none-eabi-gcc-cs arm-none-eabi-newlib qemu-user

sudo dnf install dnf-plugins-core
sudo dnf copr enable lantw44/arm-linux-gnueabi-toolchain
sudo dnf install arm-linux-gnueabi-{binutils,gcc,glibc}
```
For Fedora 41, `gdb` supports multiarch by default. Example:

```sh
gdb -ex "set architecture-arm" ./test
```

Quick access to using gdb for ARM:
1. Create a `.gdbinit` file
2. Before running, set `GDBINIT=./.gdbinit` and run `gdb ./file`

```
# In your project directory's .gdbinit
set architecture arm


# Optional helpful settings
set print pretty on
set print array on
set print array-indexes on
set pagination off
set debuginfod enabled on
```

## Computer Architecture
### Architecture
CPU
- Control unit (CU)
- Processor
  - Registers
  - Combinational logic

ALU: Arithmetic Logic Unit - Combinational logic

**Flow**
- Code is stored in memory
- Code is converted to instructions and loaded to control unit.
- CU sends command to processor to execute instructions one by one (on one core)
- CU can:
    - access/load data on memory
    - write result of an execution onto memory

### Operation
Fetch-Decode-Execute cycle
**1. Fetch**
Program Counter (PC) register (`$pc`)
- Before being executed, an instruction needs to be loaded
- At the end of the Fetch stage, CU has the instruction to execute
**2. Decode**
- CU instructs the rest of the CPU to execute the instruction
- At the end of the Decode stage, components in CPU have the orders
**3. Execute**
- The instruction is executed
- Registers are filled with new value
- At the end of the Execute stage, `$pc` then points to the next instruction.

### ARM Registers
- General purpose registers
  - r0 to r7: value calculation and data manipulation
  - r8 to r12: data storage during computations
- Special purpose register
  - Link register (LR): return address
  - Program counter (PC): target instruction in program
  - Stack pointer (SP): top of stack memory storing
    - addresses
    - local variables
    - passing functions arguments
  - Current program status register (CPSR): state of the processor
    - Negative (N), Zero (Z), Carry (C), Overflow (V)

Video notes
- r11: frame pointer (FP) (bottom of the stack memory)
- r12: intra procedure call (put data here and send between functions, weird use case)
- r13: stack pointer (SP) >< FP
- r14: link register (LR). Function A, jumps, needs to remeber where to return.
- r15: program counter (PC) - instruction of the next instruction to run
- CPSR: status of processor
- Takeaway: don't do operation on special purpose registers

Notes
- You can do whatever you want with registers r0-r10.
- However, in calling convention, r0-r3 and r7 have special use cases.
