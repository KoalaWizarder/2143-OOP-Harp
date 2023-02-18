## P01 - Vector Class
### Mervyn Harp
### Description:

Program implements a class named ```Vector``` to allow for easy, dynamic storage of 
integers. Through the use of creating ```new``` ```node```'s that are automatically 
tied together, the user will not run into issues commonly associated with normal
static storage containers.


### Needed Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [source.cpp](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P01/source.cpp)  | Main driver of my project that displays program functionality |
|   2   | [input.dat](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P01/input.dat)   | Input file that holds various integers to be read into ```Vector```       |
|   3   | [test.out](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P01/test.out)    | Output file where results are stored |

### Instructions

- As it stands, the program will simply run and allow you to trace its workings through the easy-to-follow commands found within `main()`
- Parameters `<input.dat>` `<test.out>`
- The input file must be formatted in such a way that there is white-space between values


- Example Command:
    - `Vector v1` - Initalizes a Vector
    - `v1.pushFront(x)` - Pushes `int x` onto the front of v1
    - `v1.peekAt(n)` - Returns value found at index `n` within the `Vector`
