# STM32F401 Modular Motor Control

A modular Arduino (STM32duino) codebase for driving a DC motor through three
different motor driver architectures — **L298N**, **Cytron MD10A/MDD10A**, and
**BTS7960** — behind a single common interface, controlled live by a
potentiometer.

## Hardware

- **MCU:** STM32F401 (Arduino IDE + STM32duino core)
- **Input:** 1x potentiometer (speed/direction control)
- **Motor drivers (any one, or all three wired in parallel for comparison):**
  - L298N
  - Cytron MD10A / MDD10A
  - BTS7960

## Architecture

All three drivers implement a common abstract interface, `MotorDriver`, so
`Main.ino` controls any of them the same way:

```
MotorDriver (abstract base)
 ├── virtual void Drive(int speed_in_pwm) = 0;
 │
 ├── L298N       — digitalWrite(IN1/IN2) + analogWrite(ENA)
 ├── CytronMD10A — wraps a CytronMD object from the Cytron library
 └── BTS7960     — analogWrite(RPWM) / analogWrite(LPWM)
```

`speed_in_pwm` is a signed value from **-255 to 255**: positive drives
forward, negative drives backward (magnitude only, `abs()` handles the sign
internally), and `0` stops the motor.

### File structure

| File | Purpose |
|---|---|
| `Main.ino` | Pin definitions, object creation, `setup()`/`loop()` control logic |
| `MotorDriver.h` | Abstract base class / common interface |
| `L298N.h` / `.cpp` | L298N driver implementation |
| `CytronMD10A.h` / `.cpp` | Cytron MD10A/MDD10A driver implementation |
| `BTS7960.h` / `.cpp` | BTS7960 driver implementation |

## Pin Mapping

| Signal | Pin | Driver |
|---|---|---|
| Potentiometer | `PA2` | — |
| `ENA` | `PA3` | L298N |
| `IN1` | `PA4` | L298N |
| `IN2` | `PA5` | L298N |
| `PWM` | `PA6` | Cytron |
| `DIR` | `PA12` | Cytron |
| `RPWM` | `PA7` | BTS7960 |
| `LPWM` | `PA8` | BTS7960 |
| `R_EN` | `PB2` | BTS7960 |
| `L_EN` | `PB12` | BTS7960 |

> ⚠️ **Check before wiring:** on common STM32F401 "Black Pill" boards, `PA11`/`PA12`
> are physically the USB D-/D+ lines. If your board uses USB for programming or
> serial, confirm `PA12` is safe to use as a plain GPIO (`DIR`) on your specific
> board before connecting it.

## Control Logic

`loop()` reads the potentiometer (12-bit ADC, `0`–`4095`) and maps it to a
signed PWM speed with a small deadband at center to guarantee a clean stop:

| `potVal` range | Behavior | `speed_in_pwm` |
|---|---|---|
| `0` – `1999` | Backward | `-255` → `0` |
| `2000` – `2100` | Deadband (stop) | `0` |
| `2101` – `4095` | Forward | `0` → `255` |

The same `speed_in_pwm` value is sent to all three driver objects every loop
pass, so all three motors track the same knob simultaneously.

## Adding a new driver

1. Create `NewDriver.h` / `NewDriver.cpp`.
2. Inherit from `MotorDriver` and implement `void Drive(int speed_in_pwm) override;`.
3. Have your header `#include "MotorDriver.h"` (and any third-party library
   header your driver depends on) directly — don't rely on include order in
   other files.
4. Instantiate it in `Main.ino` and call `.Drive(speed_in_pwm)` alongside the
   others.

## Known limitations

- Verified by compiling/linking/running the logic in a desktop simulation
  (stand-in headers in place of `Arduino.h`/`CytronMotorDriver.h`) — **not yet
  tested on physical hardware.**
- `CytronMD10A.h` uses the `CytronMD` type without including
  `CytronMotorDriver.h` itself; it currently compiles only because
  `Main.ino`/`CytronMD10A.cpp` happen to include it first elsewhere.
- `Serial.print`/`println` runs every `loop()` pass — fine for debugging, but
  will spam the serial monitor at full speed; consider gating it with
  `millis()` if that becomes an issue.
