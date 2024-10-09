# Quaternion Operations on ARM (Bare-Metal)

This project implements quaternion operations such as multiplication, dot product, and conjugate using the C99 standard. The project is set up for cross-compiling and testing on ARM architecture in a bare-metal environment using `arm-none-eabi-gcc`.

## Logic

The code deals with quaternions, which are used for 3D rotations. It has basic operations like creating a quaternion with quat(), getting its conjugate (flipping the vector signs) using complement_quat(), multiplying two quaternions with mult_quat(), and checking their similarity with dot_quat(). In the main() function, it creates a quaternion, computes its conjugate, multiplies them, and calculates the dot product, then prints the results.	

## Requirements

- ARM cross-compiler: `arm-none-eabi-gcc`
- Development environment: Linux

## File Structure

- `quaternion.c`: Contains the quaternion operations (`quat`, `complement_quat`, `mult_quat`, `dot_quat`) and the `main` function.
- `syscalls.c`: Implements dummy system calls required for bare-metal execution.

## Steps to Setup and Compile

### 1. **Setup : Install the ARM Toolchain**

Ensure that `arm-none-eabi-gcc` is installed on your system. If not, install it with:

```bash
sudo apt-get install gcc-arm-none-eabi
```

### 2. **Compile :**
```bash
arm-none-eabi-gcc -std=c99 -o quaternion_arm quaternion.c syscalls.c -lc -specs=nosys.specs
```

##### **-std=c99:** Use the C99 standard.
##### **syscalls.c:** Includes dummy system calls required for the bare-metal environment.
##### **-lc:** Link with the C standard library.
##### **-specs=nosys.specs:** Avoid linking with system-dependent functions (as this is a bare-metal setup).

