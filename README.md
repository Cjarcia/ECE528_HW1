# ECE 528/L - Homework 1

Cristian Garcia

## Section I: Review Questions

**1. (a)**

A compiler translates the whole source file into machine code before the program runs, so you get an executable that can be run without the source. Errors show up at compile time. An interpreter reads and runs the program one statement at a time while it's executing, so there's no separate executable and errors only show up when that line is reached. Compiled code usually runs faster. C is compiled, Python is interpreted.

**1. (b)**

main() returns an int, and by default it returns 0, which tells the OS the program finished successfully. Since C99, if main() reaches its closing brace without a return statement, it returns 0 automatically. A nonzero value is used to signal an error.

**2.**

A header file (.h) holds declarations that other source files need, such as function prototypes, macros, type definitions, and extern variables. For example, stdio.h declares printf() and scanf(), and msp.h defines the MSP432 registers.

The #include directive tells the preprocessor to copy the contents of the named file into the source file before compiling. Angle brackets search the system include paths, while quotes search the project directory first.

**3.**

A declaration (prototype) gives the return type, name, and parameter types so the function can be called before the compiler sees the body. The definition includes the body.

```c
int multiply(int a, int b);     // declaration

int multiply(int a, int b)      // definition
{
    return a * b;
}
```

The return statement ends the function and sends a value back to the caller. In a void function it just exits. A function can have more than one return statement, for example one inside an if and one at the end, but only the first one reached is executed.

**4.**

Type casting converts a value from one data type to another. The compiler does implicit casting automatically, and explicit casting is done by putting the type in parentheses. Casting a double to an int drops the decimal part instead of rounding.

```c
int add_as_int(double a, double b)
{
    return (int)(a + b);
}
```

**5.**

A local variable is declared inside a function and only exists while that function is running, so it can only be used inside it. A global variable is declared outside of all functions, exists for the entire program, and can be used by any function in the file.

```c
int button_count = 0;   // global

void Count_Press(void)
{
    int pressed = 1;    // local
    button_count += pressed;
}
```

**6.**

C doesn't have a string type, so a string is a char array that ends with the null terminator '\0'.

```c
char name[] = "MSP432";
char name2[10] = "LED";
char name3[] = {'L', 'E', 'D', '\0'};
```

When a string literal is used, the compiler adds '\0' automatically. The null terminator marks where the string ends, so functions like printf() and strlen() know when to stop reading. Without it they would keep reading past the end of the array. This is also why the array needs one extra byte.

**7.**

A pointer is a variable that stores the memory address of another variable. To pass a pointer to a function, the parameter is declared as a pointer and the address of the variable is passed using &.

```c
void Increment(int *value)
{
    (*value)++;
}

Increment(&count);
```

Passing a pointer lets the function change the original variable instead of a copy. It also avoids copying large arrays or structs, since only the address is passed, which saves memory and time on a microcontroller.

**8.**

The & operator gives the address of a variable. The * operator is used to declare a pointer, and when used on a pointer it dereferences it, meaning it accesses the value stored at that address.

**9.**

A while loop checks the condition before running the body, so the body might never run. A do...while loop checks the condition after the body, so the body always runs at least once.

**10.**

The break statement exits the loop immediately. The continue statement skips the rest of the current iteration and moves on to the next one, so the loop keeps running.

**11.**

Bitwise operators work on the individual bits of an integer. & is AND, | is OR, ^ is XOR, ~ inverts every bit, << shifts bits left, and >> shifts bits right. To set a bit use |, to clear a bit use & with the inverted mask, to toggle a bit use ^, and to check a bit use &.

```c
reg |= 0x08;        // set bit 3
reg &= ~0x08;       // clear bit 3
reg ^= 0x08;        // toggle bit 3
if (reg & 0x08)     // check bit 3
```

**12.**

PxSEL0 and PxSEL1 select the function of each pin. When both bits are 0 the pin is GPIO. The other combinations (01, 10, 11) connect the pin to the primary, secondary, or tertiary module function, like UART or a timer.

```c
P1->SEL0 &= ~0x81;
P1->SEL1 &= ~0x81;
```

**13.**

```c
void P1_1_and_P1_4_Init(void)
{
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;
    P1->DIR &= ~0x12;
    P1->REN |= 0x12;
    P1->OUT |= 0x12;
}
```

**14.**

```c
void Buttons_Init(void)
{
    P3->SEL0 &= ~0x42;
    P3->SEL1 &= ~0x42;
    P3->DIR &= ~0x42;
    P3->REN |= 0x42;
    P3->OUT &= ~0x42;

    P5->SEL0 &= ~0x11;
    P5->SEL1 &= ~0x11;
    P5->DIR &= ~0x11;
    P5->REN |= 0x11;
    P5->OUT &= ~0x11;
}
```

**15.**

```c
void LEDs_Init(void)
{
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR |= 0xFF;
    P7->OUT &= ~0xFF;
}
```
