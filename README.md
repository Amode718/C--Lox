# C++lox
C++ implementation of a **Lox** interpreter

This project contains a C++ implementation of the **Lox** language following the book [Crafting Interpreters](http://www.craftinginterpreters.com) written by [Bob Nystrom](https://twitter.com/munificentbob). [Crafting Interpreters in GitHub](https://github.com/munificent/craftinginterpreters)



## A TREE-WALK INTERPRETER

- [x] 4.  [**Scanning**](http://www.craftinginterpreters.com/scanning.html)

- [x] 5.  [**Representing Code**](http://www.craftinginterpreters.com/representing-code.html)
  - [x] 5.3  Replace AstPrinter with RpnPrinter, which performs a postorder tree traversal instead of an inorder one to output an equivalent expression in RPN. Separate tokens with a space (but don't leave spaces at either end of the string).

- [x] 6. [**Parsing Expressions**](http://www.craftinginterpreters.com/parsing-expressions.html) 
  - [x] Challenge 2: Add support for the C-style conditional or “ternary” operator `?:`


- [x] 7. [**Evaluating Expressions**](http://www.craftinginterpreters.com/evaluating-expressions.html)
  - [x] Challenge 1: Allowing comparisons on types other than numbers could be useful.

- [x] 8. [**Statements and State**](http://www.craftinginterpreters.com/statements-and-state.html)
  - [x] Challenge 1: Add support to the REPL to let users type in both statements and expressions.
  - [x] Challenge 2O: Extend the interpreter at the end of Chapter 8 (or 9) to add an exit statement that immediately quits the interpreter.

- [x] 9. [**Control Flow**](http://www.craftinginterpreters.com/control-flow.html)
  - [x] Challenge 1: Add break and continue statements to the Lox interpreter at the end of Chapter 9. Each of those statements consist of just the keyword followed by a semicolon--it's the semantics that are interesting. Make sure they work (like they would in C) with both while and for loops. Having either one outside of a loop is a syntax error.
  - [x] Challenge 2: Enrich your Lox interpreter from the end of Chapter 9 with a switch-case construct. Like the C equivalent, the switch keyword is followed by an expression that will be compared for equality with the expression following each case in  its body. Unlike the C family of languages, this will not support case fall-through. Instead, each case will control a single statement (possibly a block), so the break statement at the end of the case is unnecessary (and may be a syntax error, depending on its placement). Don't forget the optional default alternative at the end!
  

- [] 10. [**Functions**](http://www.craftinginterpreters.com/functions.html)



