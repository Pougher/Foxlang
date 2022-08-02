# Fox programming language

Lightweight programming language written in C++ in under 3000 lines.

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

```rust
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
