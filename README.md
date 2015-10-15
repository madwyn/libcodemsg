# libcodemsg

`libcodemsg` is a library for organising CODE-MESSAGE style value paris.

Using `C` style macro and string, it's simple and easy. No more hassle, no more mismatch.

---

## Usage:

Use macro `DEF_MSG` to define a macro and message pair:

```c
DEF_MSG(CODE_OK,   "OK!")
DEF_MSG(CODE_FAIL, "Fail!")
```

`CODE_OK` is the macro to use, and `"OK!"` is the corresponding message.

Use `get_message()` or just `gm()` to get the message:

```c
get_message(CODE_FAIL);  // will return "Fail!"
gm(CODE_FAIL);           // works exactly the same as above
```

Use `MSG_NUM` to find out how many macros have been defined. This will automatically increse, you don't need to do anything.

Predefined messages:

```c
MSG_OK:     OK!
MSG_BOTTOM: Message bottom
```

---

## Full usage:

To make the lib fully functional, there are several steps, once done, you won't need to go through it any more.

1. Create the message definition header files.
2. Create the message entry header file.
3. Tell libcodemsg where your message entry header file is.

You can refer to the example project for real world usage.

### Create the message definition header files

Every definition file should include `message_inc.h` to use the `DEF_MSG` macro.

```c
#include <message_inc.h>
```

Then define some CODE-MESSAGEs:

```c
DEF_MSG(JUST_SAY_HI, "Hi!")
```

Messages with a prefix:

```c
#define MSG_HEAD_HELLO  "Hello: "

DEF_MSG(HELLO_WORLD, MSG_HEAD_HELLO "world!")
DEF_MSG(HELLO_YOU,   MSG_HEAD_HELLO "you!")
```

A sufix, or anything string you want.

Then name the file, for example `message_hello.h`. You can create as many definition files as you like, but remember, the macros should be unique.

### Createa the message entry header file

Create a header file with any name you like, e.g., `message_hello.h`.

Include the definition header files in it:

```c
#include "message_hello.h"
...
#include "message_anything.h"
```

### Define the entry header file in CMake

CMake needs to know where your entry header file is, define variable `CODE_MESSAGE_ENTRY` to do this.

For example:

```cmake
set(CODE_MESSAGE_ENTRY "path/to/message_all.h")
```

### To use

Just include one header file:

```c
#include <message_def.h>
```

Then you get access to all the macros and `get_message()` function.

---

## Compile example

```bash
mkdir build
cd build
cmake -DBUILD_EXAMPLE=ON ..
make
```
