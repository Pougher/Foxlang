# Fox programming language

Lightweight programming language written in C++ in under 3000 lines.

---

## Contents
- [keywords](#keywords)

## Keywords

| Keyword                                           | Brief Description                                                                                                                                                                                           | C Translation            |
|---------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------|
| [`while`](#while-keyword)                         | Repeats the block of code until a condition is met                                                                                                                                                          | `while`                  |
| [`for`](#for-keyword)                             | Repeats the block of code until a condition is met                                                                                                                                                          | `for`                    |
| [`if`](#if-keyword)                               | Executes a block of code if the condition is met.<br>Otherwise, the block of code is skipped.                                                                                                               | `if`                     |
| [`elif`](#elif-keyword)                           | If a previous if condition fails, the condition within<br>the elif statement is evaluated, and if it is met, then<br>the code within the statement is executed. Otherwise,<br>the block of code is skipped. | `else if`                |
| [`else`](#else-keyword)                           | If all of the above conditions have failed, then the code<br>within the else block will be executed.                                                                                                        | `else`                   |
| [`struct`](#struct-keyword)                       | Creates a user-defined object with different attributes.                                                                                                                                                    | `struct`                 |
| [`static`](#static-keyword)                       | Any identifier declared with this keyword will remain static<br>across all files within a project.                                                                                                          | `static`                 |
| [`const`](#const-keyword)                         | Any identifier declared as const will be made immutable.                                                                                                                                                    | `const`                  |
| [`inline`](#inline-keyword)                       | Any block of code declared as inline will be effectively<br>"pasted in" when referenced.                                                                                                                    | `inline`                 |
| [`volatile`](#volatile-keyword)                   | Indicates to the compiler that the code declared as volatile<br>cannot be optimized.                                                                                                                        | `volatile`               |
| [`union`](#union-keyword)                         | A union is another user-defined object similar to a struct,<br>however its size is the size of its largest attribute.                                                                                       | `union`                  |
| [`and`, `or`, `xor` and `not`](#binary-operators) | Performs binary operations on values.                                                                                                                                                                       | `&`, `\|`, `^` and `~`   |
| [`let`](#variable-declaration)                    | Declares an initialized variable. All variables declared with<br>let must be initialized.                                                                                                                   | `<type> <name> = { 0 };` |
| [`fn`](#function-declaration)                     | Declares a function that may be called later.                                                                                                                                                               | `<type> <name>() {...}`  |
| [`extern`](#interfacing-with-c)                   | Provides a front in which the programmer may interface with<br>an existing C library.                                                                                                                       |                          |
| [`namespace`](#namespaces)                        | Allows for functions and variables to be grouped into larger<br>categories.    
