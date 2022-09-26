# Tema1---PC Microprocessor

    Task 1:
Decoding the instructions - first 3 bits represent the number of instructions,
the next 2 * N bits represent N op codes (one op code is formed with 2 bits) and
the last 4 bits represent the operand dimension.

    Task 2:
Executing instructions - using N and Dim we can compute how many numbers 
(unsigned shorts) we have to read from stdin in order to obtain our operands.
In this task, Dim can only be a power of 2 (that way every unsigned short will
always exactly divide in order to get the operands).

    Task 3:
Extending the functionality of Task 2 by being able to create operands
of dimension not power of 2 (the operand can be formed by extracting bits from 2
or more numbers).

    Task 4:
Extending the functionality of Task 2 by respecting the operation order 
(multiply and divide compute first).
