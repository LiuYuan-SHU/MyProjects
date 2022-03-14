# Logs

## Error1 - [solved]

> 21st, Feb, 2022

### Describe

input the infix notation:`( a - ( b - c)/(e * ( f + g )))`
`( a - ( b -3)/(e * ( f + g )))`
`(-)cefg+*/-`
find problem: when judge a negative char, only consider number and forget letters however space is also a problem.

### Note

1. the way to distinguish negative char and minus operator char is wrong

    1. `( a - ( b - 3)/(e * ( f + g )))`

        `(-)3efg+*/-`

    2. `( a - ( b -3)/(e * ( f + g )))`

        `b(-3)efg+*/-`

2. Don't know why 'a' is not included in the tree yet, and the expression is also processed in a wrong order

### Analysis

**If a '-' means a negative char**, there will be conditions as follows:

1. The negative char must appears after '(', which means the top of operator stack must be ‘(’ . 

    ```cpp
    /*
    6 * (-2)
         ^
         |
    
                                     nullptr
     | ( |                         /
     | * |            | 6 |      6
    stack_operator stack_node      \
                                     nullptr
    */
    
    /*
    (2 - (-2))
          ^
          |
          
          | ( |                           nullptr
          | - |                         /
          | ( |            | 2 |      2
     stack_operator     stack_node      \ 
                                          nullptr
    */
    ```

2. As for node stack, there are only two conditions:

    1. The stack is empty

        ```cpp
        /*
        (-2) * 6
         ^
         |
          
              | ( |         | (empty) |
         stack_operator     stack_node
        */
        ```

    2. The top element of the stack is an operator

        ```cpp
        /*
        (1 + 2) * ( -2 * 6)
                    ^
                    |
                                            2
            | ( |                         /
            | * |             | + |     +
        stack_operator     stack_node     \
                                            1
        */
        ```

    ***So the judgment condition can be:***`stack_operator.top() == '(' && (stack_node.empty() || priority[stack_node.top()] > 0)`

**if a '-' means a minus char**, there will be conditions as follows:

1. There must be an operand before the operator, which means the top node in `stack_node` is not an operator. <span style="background:yellow;"><b><i>This is an easier way to distinguish</i></b></span>

    ```cpp
    /*
    (1 - 2)
       ^
       |
       
         | ( |        | 1 |
    stack_operator  stack_node
    */
    ```

### ~~Resolution~~

~~***If read a '-', then take a look at the top of `stack_node`, if the top element is a number, then it is a minus operator, otherwise it is a negative char***~~

### Resolution

***Add function `bool isNegative(const char* current, const char* start)` to find the previous operator. If find an operator of reach the start of the expression, it is a negative char, otherwise it is a minus operator***