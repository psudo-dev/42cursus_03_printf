# 42 | São Paulo  <!-- omit in toc -->

Projects and Exercises from the `School 42`:

- ***Level 01***
  - ***03. Printf***

> #### `moulinette:`
>
> _This project will not pass in the moulinette's test as it's here in this repository since I changed a few things in the Makefile._

### Table of Contents  <!-- omit in toc -->

- [Project](#project)
- [Mandatory Part](#mandatory-part)
- [Bonus Part <a name = "bonus_part"></a>](#bonus-part-)
- [Usage](#usage)
- [Tests](#tests)
- [ft_printf](#ft_printf)
  - [Implementation](#implementation)
  - [Makefile](#makefile)
  - [Directories and Files](#directories-and-files)
- [Issues and Suggestions](#issues-and-suggestions)
- [References and Links](#references-and-links)
- [License](#license)

## Project

This project consists in recreating the function PRINTF from the C Language Standard Library. It's not as complete as the original one, but with the bonus part, the most important aspects of it are reproduced here.

#### Variadic Functions <!-- omit in toc -->

One of the main parts or maybe what's new with this project was to learn how to work with variadic functions.

```c
#include <stdarg.h>
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

## Bonus Part <a name = "bonus_part"></a>

The Major challenge of the Bonus Part is to not only manipulate the arguments you are going to print but mainly to understand:

- how each flag changes the final output of each type
- how each flag interacts with each other
- what flag is a priority over the other and in which situation
- manage corner cases nightmare

> - If the Mandatory part is not perfect don’t even think about bonuses
> - You don’t need to do all the bonuses
> - ***Bonus A***
> _Manage any combination of the following:_
>   - **`"-"`** _left justification_
>   - **`"0"`** _zero padding_
>   - **`"."`** `precision`
>   - **`width`** _minimum field of characters for all conversions_
> - ***Bonus B***
>   _Manage all the following flags:_
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
> - **`make clean`** *clean object files*
> - **`make fclean`** *clean object files and `libftprintf.a`*
> - **`make re`** *clean project files and recompiles*
> - **`make exit`** *clean project files and delete test files*

## Tests

It's passing in all 2,385,584 tests of the following testers:

- [Paulo Santana](https://github.dev/paulo-santana/ft_printf_tester)
- [Tripouille](https://github.dev/Tripouille/printfTester)

#### Commands <!-- omit in toc -->
>
> - **`make t`** *clone printf testers to `/test` directory*
> - **`make m`** *run `mandatory` tests*
> - **`make b`** *run `bonus` tests*
> - **`make a`** *run `all` tests*
> - **`make c`** *clean test object files*
> - **`make f`** *clean **`*.c`**, **`*.o`** and **`*,h`** and `libftprintf.a`*
> - **`make d`** *delete `test` files*

---

## ft_printf

### Implementation

```c
[ % ]  ["+", " ", "#", "-" and "0"] [ width ] [ . precision ] [ type ]

ft_printf("%-+10.3d", 42);
  output: "+042      "

[ % ] [ flags: "-" and "+" ] [ width: 10 ] [ precision: .3 ] [ type: d ]
```

### Makefile

I invested some time learning more about the Makefile in order to understand it better and make it work like I wanted.

- If any project file is changed (including source files and header), the library is recompiled
- Color coded messages for each step after running the commands
  - "✔" a check mark after each completed task
- Download testers directly from their Git
  - Compile and copy all the necessary files to `/test` directory
  - Run `mandatory`, `bonus` or `all` the tests from the main Makefile
- Delete and clear all changes

### Directories and Files

> - `Makefile` _**Makefile** for **ft_printf** project_
> - `inc/`
>   - `ft_printf.h` _it's the **header** file for this project_
> - `lib/`
>   - `libft/` _**libft** project directory_
> - `src/`
>   - `printers.c` _printing functions, including **ft_printf()**_
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

For the bonus part, we had to implement `width`, `precision` and a few `flags`, which might sound simple but it changes everything.

They say that in case you are going to do the bonus part, you should approach the mandatory part already thinking about the bonus. That would be great if you build upon what you did in the mandatory part, which is what we usually expect out of the Bonus Part.

In the end you basically have to redo the whole project, it would have been best to simply say to those that intend to make the bonus part to jump straight to the bonus or maybe they should have kept the `width` and the `Bonus B` flags in the **Mandatory** part and the **Bonus** would be the `Bonus A`.

The fact that you have to handle a lot of different things interacting with different priorities and print things before, after and in the middle of what you've done in the mandatory part completely changes how you think this through.

It makes no sense to call it a bonus when it's basically double the work of the mandatory. A Bonus should be something like 20% extra work, not 200%.

## More Info <!-- omit in toc -->

-   [Oni UI](https://github.com/psudo-dev/nebula-oni-theme/blob/main/doc/ONI-UI.md)
-   [Nebula Syntax](https://github.com/psudo-dev/nebula-oni-theme/blob/main/doc/SYNTAX.md)
-   [Extensions](https://github.com/psudo-dev/nebula-oni-theme/blob/main/doc/EXTENSIONS.md)
-   [VSCode Customization](https://github.com/psudo-dev/nebula-oni-theme/blob/main/doc/CUSTOMIZATION.md)

## Issues and Suggestions

-   [more information](https://github.com/psudo-dev/42cursus_03_printf/issues/new/choose)

## References and Links

- <https://github.dev/julioakira/42sp_ft_printf>
- <https://github.dev/paulo-santana/ft_printf_tester>
- <https://github.dev/Tripouille/printfTester>

## License

-   [Apache 2.0](https://github.com/psudo-dev/nebula-oni-theme/blob/main/LICENSE.md)
