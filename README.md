# Table-Driven Cooperative Scheduler (C)

This project demonstrates a minimal bare-metal scheduler using:
- A single global tick source
- Table-driven task configuration
- Function pointers for task dispatch
- Cooperative (non-preemptive) execution

## Key Concepts
- Function pointer typedefs
- Array of structs with sentinel termination
- `extern` and `volatile` for ISR/main coordination
- Interval-based task execution using modulo arithmetic

## How It Works
- A simulated timer updates a global tick
- The main loop consumes ticks one at a time
- Tasks are executed when elapsed time is a multiple of their interval

## Why This Design
This pattern avoids switch/if chains, scales cleanly by adding table entries,
and is commonly used in bare-metal embedded systems without an RTOS.

## Build & Run
```sh
gcc -Wall -Wextra main.c scheduler.c -o scheduler
./scheduler
