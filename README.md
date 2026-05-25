# Chip-8 Emulator (C99, macOS)

![C99](https://img.shields.io/badge/C-99-blue)
![Platform](https://img.shields.io/badge/platform-macOS-lightgrey)

A simple Chip-8 emulator written in C99 for macOS. It currently runs the IBM Logo test on Apple Silicon. I have not tested on Intel macs, but it should work.

The display is ASCII-based (not SDL), and opcode coverage is incomplete. The main goal was to refresh my C skills.

## Build

From the repository root:

```bash
make
```

## Run

```bash
./chip8 ./tests/IBM.ch8
```

## Notes

- ASCII rendering only (no SDL yet)
- Partial opcode support

## TODO

- Error handling
- User input
- Better rendering
- Sound
- Full opcode support