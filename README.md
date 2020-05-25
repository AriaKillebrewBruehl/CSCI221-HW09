# Homework 09: C++ classes and operators

*Due: April 18th, 9am PST*

Here we modify and create a few C++ classes. In some cases, we've
provided client code so that you can test that your implementation
works.


---

Exercise 1: enhancing the stack
-------------------------------

On Friday's lecture we gave an example stack class and its implementation.
I've included its code in the folder `Stck`. In this code we test our
stack with a calculator program that uses the stack to store calculated
values. Enter this folder and type `make` to build that calculator
program `dc`.

Here is how it works: the user enters one of a family of short commands
that operate on the stack, initially empty. If the command entered is `p`,
then the program outputs the contents of the stack. If the command
entered is an integer, then that integer gets pushed onto the top of
the stack. If `t` is entered, then the top value is printed. Here
is an example of an interaction:

    command? p
    []
    command? 21
    command? 43
    command? 65
    command? p
    [(65) 43 21]
    command? t
    65

The program also lets you add, subtract, multiply, and divide the top
two values on the stack. For each of these, the top item is the
first operand, and the item just below that is the second operand.
Both are popped and then the operation's result is pushed onto the
top. For example, continuing the above,  testing `-` and  then `+`:

    command? -
    command? p
    [(22) 21]
    command? +
    command? t
    43

There are a few other commands, including  `h` which gives a helpful
summary of all the commands.

This exercise has you modify the `Stck` class as two separate
parts.

**Part 1.** The stack stores its items as an array and it only
allows you to inspect the top item. Change the code in the following
ways:

* Add a default constructor, one that takes no arguments, that
constructs a stack, but with a capacity equal to a `Stck` class
`const` member named `kInitialCapacity`.  Have that class
variable set to something small, say, 5. Change `dc.cc` so that
it uses this default constructor, instead of the one that
takes an initial capacity parameter.

* When the stack's number of elements is equal to its capacity
and `push` is invoked, it should resize its storage by allocating
a new array of twice the capacity, and use that new array instead.
Don't forget to `delete` the storage of the old one.

* Add a method `inspect` that takes an integer argument `position`
and gives back an integer value. It should work so that `s.inspect(0)`
for an instance `s` gives back the top element. And `s.inspect(1)`
gives the value just below the one at the top. So, working
from top to bottom, the stack elements' position are 0, 1,
2, all the way down the number of elements minus one. You
can use `assert` to raise an error if a client gives two
large a `position` value.

* Change the `to_string` method so that it uses the `inspect` method,
rather than directly accessing the `elements` array.

**Part 2.** Make a copy of the `dc.cc` program, call it `opdc.cc`.
We're going to modify it here. It'll work the same as `dc.cc` but
will use the built-in C++ operator syntax to work with the `Stck`
object instead. We'll overload those operators with functions and
methods that act on a `Stck` instance. You can compile the code with

    make opdc

Add these `public` methods to the `Stck` class, most of them being
operator methods:

    int operator+=(int value);
    int operator--(void);
    int operator()(void) const;
    int operator[](int position) const;
    int size(void) const;

The first one should push a value onto a stack. For example, the
expression

    s += 42;

would push `42` onto the top of `s`. The second one is normally
*prefix decrement* and pops a value off the top of the stack,
so

    int x = --s;

would set `x` to `42` if the push above had just happened. The
next two are equivalent to `top` and `inspect`. So, for example

    Stck s {};
    s += 42;
    s += 21;
    std::cout << s() << std::endl;
    std::cout << s[0] << std::endl;
    std::cout << s[1] << std::endl;

would print `21`, `21`, and `42`. We're doing two pushes, checking the top
using `operation()`, checking the top again with `operation[]`, and then checking
the item under the top with `operation[]` again.

The `size` method just returns `num_elements`.

The last three listed are each declared as *constant methods*, which means that
none of then should modify the instance variables of their `Stck` instance.
(This is the meaning of the keyword `const` in their signature.) You'll need
to also have this keyword in their definition. For example, the `size`
method's code should look something like this:

    int Stck::size(void) const { ... }

putting `const` between the parameters and the opening curly brace.
Note: if your `operator()` implementation just uses `top` to do
its work, you'll want to make `top` a constant method also.

Put the type signature below in `Stck.hh`:

    ostream& operator<<(ostream& os, const Stck& s);

outside the class definition (it should not be a `friend`). Write the
code for this operator into `Stck.cc`.  The operator should output a
representation of the stack's contents to the output stream `os` (with
no `endl`).  It should only use the new public methods we've just
added above with the `const` annotation. It should mimic `to_string`
but not use `to_string` to do its work. 

Finally, modify the code `opdc.cc` so that it uses operators in place
of the methods `push`, `pop`, and `top` everywhere in the code.



Exercise 3. a circular buffer queue class
-----------------------------------------

Dust off your code from Homework 03 that tests a queue, namely `test_queue.cc`
which worked like the following interaction:

    $ ./test_queue
    Your queue contains []
    Enter a command: head
    Your queue is empty and has no head.
    Your queue contains []
    Enter a command: enqueue 1
    Your queue contains [(1)]
    Enter a command: enqueue 2
    Your queue contains [(1) 2]
    Enter a command: enqueue 3
    Your queue contains [(1) 2 3]
    Enter a command: head
    1 is at the head of your queue.
    Enter a command: dequeue
    1 was removed from the head of your queue.
    Your queue contains [(2) 3]
    Bye!
    $
    
In this exercise, you're going to change that code so that it is instead
a client of a `class Queue`, one that allocates its `Queue` instance that
it tests within the stack of `main`.

Invent a `Queue` class that holds a sequence of integers
with the following methods:

* `enqueue`: puts a new item onto back of the queue
* `dequeue`: removes the item at the front of the queue
* `head`: returns (but does not remove) the item at the front of the queue
* `is_empty`: returns whether or not there are any items in the queue
* `to_string`: gives back a string displaying the elements held in the queue

You should also give a constructor and a destructor for `Queue`. The
constructor should take an integer capacity as its sole parameter.
(You'll see why, just below.)

For the underlying representation, I would like you to heap-allocate an
array of integers of the capacity specified.  You'll then interpret
that array as a *circular buffer*. This treats the array as if it
its front and end is connected. That is, we think of the last element
in the array as having the first element as its successor.

To make this clear, let's work with an example. Imagine we have an array of
length 5 and we've enqueued 5, 6, and 6 onto its queue. Then the queue's
array should have these contents:

      0   1   2   3   4
    +---+---+---+---+---+
    | 5 | 6 | 7 | . | . |
    +---+---+---+---+---+

(where the last values aren't important so we mark them with `.`).  If we
dequeue, the slot holding 5 becomes unimportant and 5 is returned. We
picture the queue array this way:

      0   1   2   3   4
    +---+---+---+---+---+
    | . | 6 | 7 | . | . | (*)
    +---+---+---+---+---+ 

Note that we didn't bother shifting elements to the left. Enqueuing an 8,
we get this array

      0   1   2   3   4
    +---+---+---+---+---+
    | . | 6 | 7 | 8 | . |
    +---+---+---+---+---+

Enqueuing a 5 we get this:

      0   1   2   3   4
    +---+---+---+---+---+
    | . | 6 | 7 | 8 | 5 |
    +---+---+---+---+---+

Dequeing again gives us this

      0   1   2   3   4
    +---+---+---+---+---+
    | . | . | 7 | 8 | 5 |
    +---+---+---+---+---+

What should happen when we perform another enqueue? It turns out
that, with this circular buffer implementation, we wrap things
around, and so enqueuing a 9 leads to this array:

      0   1   2   3   4
    +---+---+---+---+---+
    | 9 | . | 7 | 8 | 5 |
    +---+---+---+---+---+

A dequeue, followed by an enqueue of 6 gives us this

      0   1   2   3   4
    +---+---+---+---+---+
    | 9 | 6 | . | 8 | 5 |
    +---+---+---+---+---+

In the above, 8 is at the head, and then the consecutive elements
after it in  line go to the end of the array and then  continue at
the front.

Write the code for the methods of `Queue` using this representation.
Normally, the way this is done, the programmer keeps track of two
other pieces of information: a `headIndex` which gives the index
of the head value and a `tailIndex` which gives the index in the
array where the next enqueued item will be placed into the array.
So in the last array depicted, the `Queue` would have a `headIndex`
of 3 and a `tailIndex` of 2.  In the second array depicted (marked
with `*`) it the head is at 2 and the next tail element will
be placed at index 4.

Normally, also, these two index variables are used to check whether
the queue is empty. (Note: for this to work, that means that the
queue can only  hold `capacity-1` elements.)

Complete the code for `Queue.hh`, `Queue.cc`, and `test_queue.cc`
using this circular buffer representation.

Exercise 4. turtles on a grid
-----------------------------

In this exercise you write code for two object classes `Grid` and
`Turtle`.  A turtle is an object that lives on a 2-D world that
is a finite rectangular grid of square cells. It walks on the
grid cell boundaries and can leave a trail when it does so.
Let's talk about each object, in turn.

A grid consists of an even number of rows and an even number of
columns.  For example, the one depicted below has 6 columns and
4 rows:

    +---+---+---+---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+

This means that it has 24 cells. Turtles walk along the lines
of this grid, and so along the edges of the cells. When not moving,
turtles sit at the intersections (or corners) of the grid
cells. Call these locations on the grid *points*. There are
35 points in the grid above. A turtle might sit at any one
of these points. When it walks, traveling in one of four
directions, it goes along an edge, from one point to another.
It cannot leave the grid.

At any moment, we can describe the location of a turtle
living on the grid with a coordinate, given by row and
column, as labelled below:

    +---+---+---+---+---+---+ 0
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+ 1
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+ 2
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+ 3
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+ 4
    0   1   2   3   4   5   6

Thus the bottom right corner point of the grid is (4,6). The
middle point is (2,3).

When a turtle is created, it is placed at the center of its
grid, looking north. It can do any of the following to
move:

    bool forward(void); // move forward along one edge
    void left(void);    // turn 90 degrees clockwise 
    void right(void);   // turn 90 degrees counterclockwise

So, a new turtle moving forward, then turning left, then moving
forward twice, then turning right, and then moving forward, will end
up at (0,1) facing north. If he tried to move forward again, since he
is at the top edge, he would not change location (and his `forward`
method would return `false`; normally it returns `true`).

The turtle can optionally leave a trail and this is controlled by
the method defined like so:

    void trail(bool on);    // turn trail on/off

If, before he moved, he turned his trail on, then the contents
of the grid would be:

    +---@---+---+---+---+---+
    |   Z   |   |   |   |   |
    +---@zzz@zzz@---+---+---+
    |   |   |   Z   |   |   |
    +---+---+---@---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+
    |   |   |   |   |   |   |
    +---+---+---+---+---+---+

**Exercise** Write the C++ code for a `Grid` class and `Turtle`
class representing these two objects decribed above.
A grid gets created with the constructor

    Grid(int rows, int columns);

and it has a `display` method for outputting its state to
`std::cout`. You can use any representation you like for
the grid's data. My recommendation is that you keep track
of an array of the characters that make up the grid's picture
and then turtles use `Grid` methods to update the contents
of this picture (say, with methods like `setPoint` and
`setEdge` to  mark its trail).

A `Grid` should not keep track of the turtles that live on it.
Instead, a turtle should be created with the constructor

    Turtle(Grid* grid);

This means that a turtle, when it is leaving a trail, tells
the grid to change as it moves.

To test your classes, write a `main` test program in a file
called `trail.cc` that creates a grid and a turtle and
accepts commands to move that turtle around. The commands
should be

    forward
    left
    right
    on
    off

to invoke the turtle's methods (`on`/`off` are for
controlling its trail).
