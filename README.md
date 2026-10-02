# 8080 Space Invaders Emulator

An Intel 8080 CPU emulator and disassembler, running the original Space Invaders arcade ROM via SDL3.

## Build

```
make
```

## Run

```
./8080 <path-to-rom>
```

Example:
```
./8080 invaders
```

## Controls

- Left / Right arrow — move
- Space — fire
- 1 — P1 start
- C — insert coin

## TODO

- **Sound is not implemented.** Port 3 and port 5 writes (sound effect triggers) are currently stubbed/ignored.
- **Cycle-accurate timing is not implemented.** The CPU currently runs a fixed number of instructions per frame rather than tracking actual clock cycles per instruction, so timing is only approximate.
