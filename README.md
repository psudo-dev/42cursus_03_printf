# ft_printf  <!-- omit in toc -->

#### 42 Cursus  <!-- omit in toc -->

ft_printf project for [42 | São Paulo](https://github.com/42sp)

[École 42/42 School](https://github.com/42School):

- ***[Level 01](https://github.com/psudo-dev/42cursus_index)***
  - ***03. Printf***

### Table of Contents  <!-- omit in toc -->

- [Project](#project)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Usage](#usage)
- [ft_printf](#ft_printf)
  - [Implementation](#implementation)
  - [Makefile](#makefile)
  - [Directories and Files](#directories-and-files)
- [Tests](#tests)
- [Issues and Suggestions](#issues-and-suggestions)
- [References and Links](#references-and-links)
- [License](#license)

## Project

This project consists in recreating the function **printf()** from the C Language as well as learning a bit more how things run under the hood of the OS. It's not as complete as the original but with the bonus part, the most important aspects of it are reproduced here.

#### Variadic Functions <!-- omit in toc -->

One of the main parts or maybe what's new with this project was to learn how to work with variadic functions.

```c
#include <stdarg.h> // Variadic Functions
#include <stdlib.h> // malloc(), free()
```

For more information you check the README of [Julio Akira](https://github.dev/julioakira/42sp_ft_printf)'s project implementation, he explained it in more details.

## Mandatory Part

They changed the requirements for the mandatory part, which became a bit too basic.

It's just the straight forward implementation of a few types:

> - **`%c`** _print a single character_
> - **`%s`** _print a string of characters_
> - **`%p`** _The void * pointer argument is printed in hexadecimal_
> - **`%d`** _print a decimal (base 10) number_
> - **`%i`** _print an integer in base 10_
> - **`%u`** _print an unsigned decimal (base 10) number_
> - **`%x`** _print a number in hexadecimal (base 16), with lowercase_
> - **`%X`** _print a number in hexadecimal (base 16), with uppercase_
> - **`%%`** _print a percent sign_

## Bonus Part

The Major challenge of the Bonus Part is to not only manipulate the arguments you are going to print but mainly to understand:

- how each flag/specifier changes the final output of each type
- how each flag/specifier interacts with each other
- what is a priority over the other and in which situation
- manage corner cases nightmare

#### Bonus A  <!-- omit in toc -->

> _Manage any combination of the following:_
>
>   - **`"-"`** _left justification_
>   - **`"0"`** _zero padding_
>   - **`"."`** `precision`
>   - **`width`** _minimum field of characters for all conversions_
>
#### Bonus B  <!-- omit in toc -->

> _Manage all the following flags:_
>
>   - **`"#"`** _hash_
>   - **`"+"`** _positive sign_
>   - **`" "`** _space_

---

## Usage

#### Clone the repository <!-- omit in toc -->

```sh
git clone https://github.com/psudo-dev/42cursus_03_printf.git <DIR_NAME>
```

#### Commands <!-- omit in toc -->
>
> - **`make`** *compiles `libftprintf.a` library*
> - **`make clean`** *cleans object files*
> - **`make fclean`** *cleans object files and `libftprintf.a`*
> - **`make re`** *cleans project files and recompiles*
> - **`make exit`** *cleans project files and delete test files*
> - **`make norm <DIR>`** *runs norminette*
>   - *<span style="font-size:0.8em; color:rgba(0, 0, 0, 0.75)">(default = root directory)</span>*

---

## ft_printf

### Implementation

```c
 %  ["+", " ", "#", "-" and "0"] [ width ] [ . precision ] type

i.e.:
ft_printf("%-+10.3d", 42);
  output: "+042      "

 % [ flags: "-" and "+" ] [ width: 10 ] [ precision: .3 ] type: d
```

### Makefile

I invested some time learning more about the Makefile in order to understand it better and make it work like I wanted.

- If any project file changes (including source files and header), the library is recompiled if `make` is called again
- Color coded messages for each step after running the commands
  - "✔" a check mark after each completed task
- Download testers directly from their Git
  - Compile and copy all the necessary files to `/test` directory
  - Run `mandatory`, `bonus` or `all` the tests from the main Makefile
- Delete and clear all changes, set it to the original state

### Directories and Files

> - `Makefile` _**Makefile** for **ft_printf** project_
> - `inc/`
>   - `ft_printf.h` _it's the **header** file for this project_
> - `lib/`
>   - `libft/` _**libft** project directory_
> - `src/`
>   - `ft_printf.c` _**ft_printf()**_
>   - `printers.c` _printing functions_
>   - `utils.c` _supporting functions for the project_
>   - `structs.c` _all the struct functions to handle data_
>   - `specifiers.c` _functions to handle incoming data check for the specifiers_
>     - `type_char.c` _**char**, **%** and **string**_
>     - `type_int.c` _**int** and **unsigned int**_
>     - `type_char.c` _**lower case hex**, **upper case hex** and **pointer**_
>     - `flags.c` _functions to check **flags**_
>     - `precision.c` _functions to check and handle **precision**_
>     - `width.c` _functions to check and handle **width**_
> - `test/` _directory for the testers_

#### Bonus: 200% Extra Work <!-- omit in toc -->

For the bonus part, we had to implement **`width`**, **`precision`** and a few **`flags`**, which might sound simple but it changes everything.

They say that in case you are going to do the **Bonus part**, you should approach the **Mandatory** part already thinking about the bonus. That would be great if you could build upon what you already did in the mandatory part, which is what we usually expect out of the Bonus Part, but that wasn't not the case.

In the end you basically have to redo the whole project, it would have been best to simply say to those that intend to make the bonus part to jump straight to the bonus or maybe they should have kept the **`width`** and the **`Bonus B`** flags in the **Mandatory** part and the **Bonus** would be the **`Bonus A`**.

The fact that you have to handle a lot of different modifiers interacting with each other priorities and print a substring **before**, **after** and in the **middle** of what you've done in the mandatory part completely changes how you think this through compared to the Mandatory part.

> It makes no sense to call it a bonus when it's basically double the work of the mandatory. A Bonus should be something like 20% extra work, not 200%.

## Tests

It's passing in all 2,385,584 tests of the following testers:

- [Paulo Santana](https://github.dev/paulo-santana/ft_printf_tester)
- [Tripouille](https://github.dev/Tripouille/printfTester)

#### Commands <!-- omit in toc -->
>
> - **`make t`** *clones printf testers to `/test` directory*
> - **`make m`** *runs `mandatory` tests*
> - **`make b`** *runs `bonus` tests*
> - **`make a`** *runs `all` tests*
> - **`make c`** *cleans test object files*
> - **`make f`** *cleans **`*.c`**, **`*.o`** and **`*.h`** and `libftprintf.a`*
> - **`make r`** *rebuilds `test` files*
> - **`make d`** *deletse `test` files*

## Issues and Suggestions

-   Feel free to contact me or create an [issue](https://github.com/psudo-dev/42cursus_03_printf/issues/new/choose)!

## References and Links

- <https://github.com/42sp>
- <https://github.com/42School>
- <https://github.dev/julioakira/42sp_ft_printf>
- <https://github.dev/paulo-santana/ft_printf_tester>
- <https://github.dev/Tripouille/printfTester>

## License

-   [GNU General Public License v3.0](https://github.com/psudo-dev/42cursus_03_printf/blob/main/LICENSE.md)
