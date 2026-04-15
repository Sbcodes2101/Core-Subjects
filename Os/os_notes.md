# Operating System — Quick Revision Notes

> Topics: Process Management, PCB, Memory Segments, Context Switching, Process States

---

## 1. What is an OS?

- **OS = Software that mediates between applications and hardware**
- Acts as a **resource manager** — CPU, memory, I/O devices
- Provides abstraction so apps don't talk to hardware directly
- Examples: Linux, Windows, macOS

---

## 2. What Does an OS Do?

| Function | Description |
|---|---|
| Process Management | Creates, schedules, terminates processes |
| Memory Management | Allocates/deallocates RAM |
| File System | Manages files and directories |
| I/O Management | Handles devices (keyboard, disk, etc.) |
| Security | Access control, user isolation |

---

## 3. How OS Runs a Program: Process Creation

1. Program (executable on disk) is loaded into RAM
2. OS creates a **Process** — a running instance of the program
3. OS assigns resources (memory, CPU time, file handles)
4. A **Dispatcher** hands the process to the CPU

```
Disk → [Program] → Load into RAM → [Process] → CPU runs it
```

---

## 4. What is a Process?

- A **program in execution**
- One program → can have multiple processes (e.g., two Chrome windows)
- Each process is **isolated** — has its own memory space
- Managed entirely by the OS

---

## 5. Program vs Process vs Dispatcher

| Term | Meaning |
|---|---|
| **Program** | Static code sitting on disk |
| **Process** | Live, running instance in memory |
| **Dispatcher** | OS component that assigns CPU to a process |

---

## 6. Programs When You Start a PC

- OS itself launches background processes (daemons/services)
- User-space apps start on top
- View them with: `top` (Linux/macOS) or Task Manager (Windows)

### `top` command — key columns
```
PID   USER   %CPU   %MEM   COMMAND
1234  root    0.3    1.2   systemd
```
- **PID** = Process ID  
- **%CPU** = CPU usage  
- **%MEM** = Memory usage  

---

## 7. Process Control Block (PCB)

> The OS stores all info about a process in a data structure called **PCB**

### PCB Contents:

| Field | Description |
|---|---|
| **Process Number (PID)** | Unique ID assigned to each process |
| **Process State** | Current state (ready / running / waiting) |
| **Program Counter (PC)** | Address of the next instruction to execute |
| **Registers** | CPU register values (saved during context switch) |
| **Memory Limits** | Base & limit addresses of the process's memory |
| **List of Open Files** | File descriptors the process has open |

---

## 8. Memory Parts (Segments) of a Process

```
High Address
┌──────────────┐
│    Stack     │  ← grows downward
├──────────────┤
│     ↓  ↑    │
│    Heap      │  ← grows upward
├──────────────┤
│    Data      │  ← global/static variables
├──────────────┤
│  Text/Code   │  ← actual program instructions
└──────────────┘
Low Address
```

| Segment | Contains | Notes |
|---|---|---|
| **Text / Code** | Compiled instructions | Read-only, shared if multiple instances |
| **Data** | Global & static variables | Initialized at program start |
| **Heap** | Dynamic memory (`malloc`, `new`) | Grows upward, managed manually |
| **Stack** | Local variables, function calls | Grows downward, auto-managed |

---

## 9. Context Switching

> Switching the CPU from one process to another

### Steps:
1. **Save** current process state → PCB (registers, PC, etc.)
2. **Load** next process state ← from its PCB
3. CPU starts executing the new process

```
Process A running
    → interrupt / time slice ends
    → save A's state to PCB_A
    → load B's state from PCB_B
Process B running
```

- **Overhead**: Context switching takes time — no useful work done during switch
- Faster CPUs / fewer switches = better performance

---

## 10. Process States

### Basic 3 States:
```
         admit
New ──────────→ Ready
                  ↑  ↓ dispatch
                  │  Running
                  │     ↓ I/O or event wait
                  └── Waiting/Blocked
```

| State | Meaning |
|---|---|
| **Ready** | Process is in RAM, waiting for CPU |
| **Running** | Currently executing on CPU |
| **Waiting / Blocked** | Waiting for I/O or an event (not using CPU) |

### Extended States:
| State | Meaning |
|---|---|
| **New** | Process being created |
| **Terminated** | Process finished execution |
| **Suspended (Swapped)** | Moved to disk to free RAM; brought back when needed |

### Full State Diagram:
```
New → Ready ⇄ Running → Terminated
              ↕              
           Waiting
              ↕
         Suspended
```

---

## 11. Key Terms Cheatsheet

| Term | One-liner |
|---|---|
| OS | Mediator between apps and hardware |
| Process | Running instance of a program |
| PCB | OS data structure holding all process info |
| PID | Unique process identifier |
| Program Counter | Pointer to next instruction |
| Context Switch | Saving/restoring process state when switching CPU |
| Heap | Dynamic memory, grows up |
| Stack | Function calls & locals, grows down |
| Dispatcher | OS module that gives CPU to a process |
| Swapping | Moving process to disk when RAM is full |

---

*Studied from: OS lecture covering process management, PCB, memory segments, context switching, and process state diagrams.*
