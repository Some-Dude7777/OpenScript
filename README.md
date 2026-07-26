# OpenScript
A fast, dynamically typed interpreted language written in C++. Syntax similar to Python, Lua, Ruby and some other languages.
Youtube tutorial and syntax highlighting will be created once the language is finished.

# Hello, world!

Here's how to print "Hello World!" in this language:

```
from std use print()

print("Hello World!") // Hello World!
```

As you can see, this language requires you to import things from the standard library.

# Variables

There are 3 types of variables: regular variables, constands and fields. 

Each one of them is declared like this:

```
var Counter = 5  // variable
const Pi = 3.14159265358979 // constant

class This_Is_A_Class(x): // we'll get into classes later
  field x = x // field
end

var Class_1 = new This_Is_A_Class(5)
```

# Functions

Every programming language has functions.

Functions are declared like this:
```
from input use mouse // input is a standard library, we'll get into them later
from std use print()

func MouseClicked():
  print("Mouse Clicked!")
end

mouse.OnClicked(MouseClicked())
```

# Modules

Modules have 3 separate keywords: ```use```,```from```,```as```.

You use ```use``` when you want to import a whole library:

```
use std // imports the entire standard library
```

You use ```from``` when you want to just use a single function, class, variable, etc. from the specified file.

```
from std use print() // only imports the print() function
```
And you use ```as``` when you want to use a library or a function, class, variable, etc. with a different name.

```
from std use print() as cout() // the interpreter now doesn't understand print() and only understands cout(), althought they have the exact same functionality
```
