# OpenScript

OpenScript is a fast, dynamically typed, object-oriented interpreted programming language written in C++.

It is intended to be a modern successor to Python, with syntax inspired by Python, Lua, Ruby, and several other languages.

A YouTube tutorial and syntax-highlighting extensions will be created once the language reaches a usable state.

## Features

- Dynamic typing
- Functions and anonymous functions
- Closures
- Classes
- Structs
- Enums
- Modules
- Built-in event handling
- A large standard library

## Installation

OpenScript is currently under development.

Installation instructions will be added once the first public release is available.

## Hello, world!

Here's how to print "Hello World!" in this language:

```openscript
from std use print()

print("Hello World!") // Hello World!
```

As you can see, this language requires you to import things from the standard library.

## Variables

There are 3 types of variables: regular variables, constands and fields.

Each one of them is declared like this:

```openscript
var Counter = 5  // variable
const Pi = 3.14159265358979 // constant

class This_Is_A_Class(x): // we'll get into classes later
  field x = x // field
end

var Class_1 = new This_Is_A_Class(5) // the new keyword creates an object out of a class
```

## Functions

Every programming language has functions.

Functions are declared like this:

```openscript
from input use mouse // input is a standard library, we'll get into them later
from std use print()

func MouseClicked():
  print("Mouse Clicked!")
end

mouse.OnClicked(MouseClicked())
```

## Anonymous Functions

An anonymous function is a function that gets called instantly upon definition. Defined with the lambda keyword.

```openscript
from input use mouse
from std use print()

mouse.OnClicked(
  lambda():
    print("Mouse Clicked!")
  end
)
```

## Modules

Modules have 3 separate keywords: use,from,as.

You use use when you want to import a whole library:
```openscript
use std // imports the entire standard library
```
You use from when you want to just use a single function, class, variable, etc. from the specified file.
```openscript
from std use print() // only imports the print() function
```
And you use as when you want to use a library or a function, class, variable, etc. with a different name.
```openscript
from std use print() as cout() // the interpreter now doesn't understand print() and only understands cout(), althought they have the exact same functionality
```

## Loops

There are 3 types of loops (its a coincidence that every feature has 3 types): for loop, repeat loop and repeat while loop

```openscript
from std use print()
from system use sleep()

for i = 0, 10, 1:
  print("This has been printed " .. i .. " times")
end

repeat 5:
  print("This will be printed 5 times")
end

repeat while true:
  print("this will print every second")
  sleep(1)
end
```

## Classes, Structs and Enums

Classes are defined like this:

```openscript
from std use print

class Ship(type, name):
  field type = type // note: there is an automatic constructor, so you don't need a __init__ method unlike Python.
  field name = name


  func Go_Sailing(self):
    print("Ship with the name " .. self.name .. " and type " .. self.type " has went sailing."
  end

end

var Cargo_Ship = new Ship("Cargo", "Herena")
Cargo_Ship.Go_Sailing()
```

Structs are defined like this:

```openscript
from std use print()

struct Example:
  var this = "that"
end
```
Enums are defined like this:
```openscript
enum Colors:
  Red,
  Blue,
  Green,
  Yellow
end
```
## If / Elif / Else

Just an if statement, executes only if the condition is true.

```
from std use print()
from system use os

if os.name == "Win32":
  print("Hello from windows")
elif os.name == "Linux":
  print("Hello from linux")
end
```
