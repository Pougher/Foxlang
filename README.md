# Fox programming language

Lightweight programming language written in C++ in under 3000 lines.

*NOTE: README IS CURRENTLY UNDER CONSTRUCTION*

---

## Contents
- [keywords](#keywords)

## Keywords

| Keyword                                           | Brief Description                                                                                                                                                                                           | C Translation            |
|---------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------|
| [`while`](#while-keyword)                         | Repeats the block of code until a condition is not met                                                                                                                                                          | `while`                  |
| [`for`](#for-keyword)                             | Repeats the block of code until a condition is not met                                                                                                                                                          | `for`                    |
| [`if`](#if-keyword)                               | Executes a block of code if the condition is met. Otherwise, the block of code is skipped.                                                                                                               | `if`                     |
| [`elif`](#elif-keyword)                           | If a previous if condition fails, the condition within the elif statement is evaluated, and if it is met, then the code within the statement is executed. Otherwise,<br>the block of code is skipped. | `else if`                |
| [`else`](#else-keyword)                           | If all of the above conditions have failed, then the code within the else block will be executed.                                                                                                        | `else`                   |
| [`struct`](#struct-keyword)                       | Creates a user-defined object with different attributes.                                                                                                                                                    | `struct`                 |
| [`static`](#static-keyword)                       | Any identifier declared with this keyword will remain static across all files within a project.                                                                                                          | `static`                 |
| [`const`](#const-keyword)                         | Any identifier declared as const will be made immutable.                                                                                                                                                    | `const`                  |
| [`inline`](#inline-keyword)                       | Any block of code declared as inline will be effectively "pasted in" when referenced.                                                                                                                    | `inline`                 |
| [`volatile`](#volatile-keyword)                   | Indicates to the compiler that the code declared as volatile cannot be optimized.                                                                                                                        | `volatile`               |
| [`union`](#union-keyword)                         | A union is another user-defined object similar to a struct, however its size is the size of its largest attribute.                                                                                       | `union`                  |
| [`and`, `or`, `xor` and `not`](#binary-operators) | Performs binary operations on values.                                                                                                                                                                       | `&`, `\|`, `^` and `~`   |
| [`let`](#variable-declaration)                    | Declares an initialized variable. All variables declared with let must be initialized.                                                                                                                   | `<type> <name> = { 0 };` |
| [`fn`](#function-declaration)                     | Declares a function that may be called later.                                                                                                                                                               | `<type> <name>() {...}`  |
| [`extern`](#interfacing-with-c)                   | Provides a front in which the programmer may interface with an existing C library.                                                                                                                       |                          |
| [`namespace`](#namespaces)                        | Allows for functions and variables to be grouped into larger categories.

---

## While Keyword
A while loop allows for any code declared within the loop to be executed an infinite number of times until a specific condition is no longer met.

For example, the while loop below will execute 10 times before the loop is exited:
```rust
let i: i32 = 0;

while (i < 10) {
    i++;
}
```

## For Keyword
A for loop allows for the code declared wihtin the loop to be executed any number of times until the condition is no longer true. For loops differ from
while loops as they allow for the iterator to be declared within the loop declaration.

```rust
for (let i: i32 = 0; i < 10; i++) {
    // ...
}
```

## If Keyword
The if statement executes the code within it's block if the condition provided evalutes to true. As an example, the code below will only run if 10 is
equal to 10.

```rust
if (10 == 10) {
    // ...
}
```

## Elif Keyword
The elif statement only executes code if the above if/elif block(s) have failed to execute. If they have failed to execute, and the condition within the
elif statement evaluates to true, then the code within the elif statement will execute.

```python
if (2 > 5) {
    // fails to execute
} elif (5 == 5) {
    // will execute
}
```

## Else Keyword
The else keyword executes the code in it's block if all of the if statements above have conditions which evaluate to false.

```rust
if (2 == 3) {
    // will absolutely not run
} else {
    // will run
}
```

## Struct Keyword
The struct keyword allows for the creation of a custom object that can be referenced without your programs.

### Size
A structure's size is dictated by the size of the elements it contains. Please note that as well as this, the order in which these attributes
are written can also affect the size of the structure when it is allocated.

### Definition
A structure can be declared with attributes in the following way:
```c
struct SomeStruct {
    attribute_1: i32;
    attribute_2: i64;
    attribute_3: u64;
}
```
And variables can be declared as structures:
```rust
let structure_variable: SomeStruct = { 0 }; // let must initialize a variable
structure_variable.attribute_1 = 42;
structure_variable.attribute_2 = 411;
structure_variable.attribute_3 = 69;
```

## Static Keyword
A variable declared as static exists for the lifetime of the translation unit that it is defined in.
This allows the variable to posess the following properties:
- If the variable is within a function, it may be accessed from outside the function.
- The variable is stored in static storage.
- If the variable is defined outside of a function, then it can't be accessed from any other translation unit.

```rust
fn test() -> void {
    static let x: i32 = 42;
}

// ...

fn main() -> void {
    printf("x = %d\n", x);
}
```

## Const Keyword
A constant variable means that the variable is internally marked as immutable, meaning the value of the variable cannot be changed
and therefore may be used to optimize certain procedures.

```rust
const let x: i32 = 42;

x = 20; // error
```

## Inline Keyword
If a function is declared as inline, then whenever the function is called, the function body will be inserted into the generated executable instead
of the function being called. This means that inlining functions could increase the program size, but could also reduce the program size if the generated
function call is larger than inserting the function's body.

Furthermore, another benefit of inlining is a performance increase, as in some scenarios where speed matters, inlining a function would remove an unnessecary
call to jump, therefore increasing the speed of the program fractionally.

```rust
inline fn test() -> i32 {
    return 50 * 50;
}

// ...

test();
```
This results in:
```rust
50 * 50;
```

## Volatile Keyword
Volatile indicates to the compiler that it should not attempt to optimize any code that deals with a volatile variable.

As an example, writing to 0xB8000 on a device that uses a VGA driver will write directly to screen memory. To prevent this code from
being optimized, it must be declared as volatile:

```C
*((volatile i8*) 0xB8000) = 0x41;
```

> Above program writes 0x41 to address 0xB8000, resulting in the character 'A' appearing in the top left of the screen.

## Union Keyword

A union is similar to a structure except unions have a size limited to the size of the largest element. Furthermore, all memory allocated
to a union may be modified by accessing each element of the union.

For example, here is a union:
```C
union Union {
    element_1: i8;
    element_2: i16;
    element_3: i32;
}

let UnionVariable: Union = { 0 };
```
And here is the union's memory:
```
UnionVariable: 00 00 00 00
```

Now, writing to `element_2` modifies the unions memory
```rust
UnionVariable.element_2 = 0xC0DE;
```

Now, the memory looks like this
```
UnionVariable: 00 00 DE C0
```

This means that reading from each of the other elements will yield the following results
```rust
UnionVariable.element_1; // -> 0xC0
UnionVariable.element_2; // -> 0xC0DE
UnionVariable.element_3; // -> 0x0000C0DE
```

## Binary Operators
Binary operators perform binary manipulation on values.

- The and operator (`and`) performs a bitwise and on two values: `0011 and 1101 = 0001`
- The or operator (`or`) performs a bitwise or on two values: `1010 or 0001 = 1011`
- The xor operator (`xor`) performs a bitwise xor on two values: `1101 xor 0100 = 1001`
- The not operator (`not`) performs a binary negation on one value: `not 1010 = 0101`

## Variable Declaration
The let keyword allows for variables to be declared. A let declaration must take the following form: `let <identifier>: <type> = <value>`.
All variables declared with let must be initialized, and therefore for user defined types, the zero memory operator must be used (`{ 0 }`)

For example, to declare the variable X as a signed 32-bit integer with a value of 20, you would do the following:
```rust
let X: i32 = 20;
```

However, to declare X as a structure type, you would do the following:
```rust
let X: SomeStruct = { 0 };
```

## Function Declaration

Functions must be defined as having a type and a name, as well as having zero or more positional arguments.
They must take the form `fn <identifier>(<arguments>) -> <return type> { ... }`

For example, to declare the function `hello` which prints `Hello, world!`:
```rust
fn hello() -> void {
    printf("Hello, world!\n");
}
```

In order to call functions, simply do `<identifier>(<arguments>)`
```rust
hello();
// -> Hello, world!
```

## Interfacing With C
As this language is built on top of C, there is a way to interface with existing C libraries.
For example, if I had the following file in C and wished to interface it in Fox, you could do the following:

```C
// File extension.h
#ifndef EXTENSION_C_H
#define EXTENSION_C_H

void add_two_numbers(int a, int b);

#endif
```

```C
// File: extension.c
void add_two_numbers(int a, int b)
{
    return a + b;
}
```

```rust
// File: main.fox
include "extension.h"

extern function add_two_numbers;
extern function printf;

fn main() -> i32 {
    printf("%d\n", add_two_numbers(1, 2));
    return 0;
}
```

The following things may be interfaced with Fox:
- Functions: `extern function <identifier>`
- Types: `extern type <identifier>`
- Structures (union and struct): `extern structure <identifier>`
- Variables: `extern variable <identifier>`

# Namespaces
Namespaces are a Fox exclusive feature. Namespaces allow for functions or variables to be grouped based off of their
purpose or a common task that they perform. All namespaces are also scoped and so any variable or function declared
within a namespace may not be accessed outside of a namespace.

To declare a namespace, use the namespace keyword:
```C++
namespace SomeNamespace {
    fn namespace_function() -> void {
        printf("Function within a namespace\n");
    }
}
```

The Fox transpiler will generate C code based off of this, and namespace functions go through a processing step.

Firstly, the name of the namespace(s) that the function is nested with are grouped into a list.
This list then is joined by an underscore character - e.g.:

```
SomeNamespace -> namespace_function -> SomeNamespace_namespace_function
```

Then, to make sure that no redefinition errors are generated, a random garbage string is appended to the end of the
name:

```
SomeNamespace_namespace_functionqW8734aL2E
```

This entry is then added to a symbol table with the original function name mapped to the new mangled one. This ensures
that whenever this function is called in your programs, the identifier is replaced by the mangled name:

```C++
SomeNamespace::namespace_function();

// Becomes

SomeNamespace_namespace_functionqW8734aL2E();
```
