# convert infix notation to expression tree

> A repetition

## Reference

[geeks for geeks: program to convert infix notation to expression tree](https://www.geeksforgeeks.org/program-to-convert-infix-notation-to-expression-tree/)

And I copied the source code in [geeksforgeeks.cpp](./geeksforgeeks.cpp)

******

## Personal Improvement

### The name of variables

Some of the names in the original code is hard to read, I renamed them in [my own file](./Convert Infix Notation to Expression Tree.cpp)

### Make code more modular

I split `priority` from `buildTree()`, which make code more modular and make other functions able to use it.

### The type of the expression elements

In the original program, the elements can only be letters like `((a+b)*c-e*f)`, in my own edition, they can be numbers or letters

Thus, I add function `isNegative()` to help distinguish minus and negative. You can find the call of this function at `line:90`

### Add negative edition

I transformed the origin file into [Convert Infix Notation to Expression Tree_no_negative.cpp](Convert Infix Notation to Expression Tree_no_negative.cpp), which can deal with negative arguments.

******

## Notes

### The difference of `size()` and `length()` of class `string`

#### from [API](https://www.cplusplus.com/reference/string/string/)

- [**size**](https://www.cplusplus.com/reference/string/string/size/)

  Return length of string (public member function )

- [**length**](https://www.cplusplus.com/reference/string/string/length/)

  Return length of string (public member function )

***We can find that they are the same***

#### Explanation from [Stack Overflow](https://stackoverflow.com/questions/905479/stdstring-length-and-size-member-functions/905487#905487)

As per the [documentation](http://en.cppreference.com/w/cpp/string/basic_string), these are just synonyms. `size()` is there to be consistent with other STL containers (like `vector`, `map`, *etc.*) and `length()` is to be consistent with most peoples' intuitive notion of character strings. People usually talk about a word, sentence or paragraph's *length*, not its size, so `length()` is there to make things more readable.
