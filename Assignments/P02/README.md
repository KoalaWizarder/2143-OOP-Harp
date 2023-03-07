## P02 - MyVector Class 2
### Mervyn Harp
### Description:

#### Program iterates upon [P02]() by implementing [Overloaded Operators](Broken_Link_To_My_Own_Wiki). Included operators that have been altered and their respective functionalities are detailed within source.cpp, but a short list has been provided below:


### Needed Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [source.cpp](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P02/source.cpp)  | Main driver of project that contains all program functionality |
|   2   | [input.dat](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P02/input.dat)   | Input file that holds various integers to be read into ```Vector```       |
|   3   | [test.out](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P02/output.txt)    | Output file where results are stored |


### Overloaded Operators
|   Operator   | Standard Inline<br>Syntax |Return<br>Type| Description |
| :-----------: | :------: | :------: | :----- |
| +  | `(v1 + v2)` | `Vector` | Sums corresponding values in two different Vectors. If one Vector is larger than the other, extra values are unaltered.  |
| -  | `(v1 - v2)` | `Vector` | Subtracts corresponding values in one Vector from another. If one Vector is larger than the other, extra values are unaltered. |
| *  | `(v1 * v2)` | `Vector` | Multiplies corresponding values in two different Vectors. If one Vector is larger than the other, extra values are unaltered. |
| /  | `(v1 / v2)` | `Vector` | Divides corresponding values from two Vectors. If one Vector is larger than the other, extra values are unaltered. |
| =  | `(v1 = v2)` | N/A | Copies and assigns values from one Vector to another. |
| == | `(v1 == v2)` | `Bool` | Checks to see if two Vectors contain equal values. If they are equal, return TRUE. |
| [ ] | `v1[n]` | `int` | Allows for accessing data members in the same fashion as an array |
| ostream&#160;<< | `cout << v1` | `ostream` | Allows easy outputting to terminal |
| ofstream&#160;<< | `fout << v1` | `ofstream` | Allows easy outputting to output file |

### Instructions

- As it stands, the program will simply run and allow you to trace its workings through the easy-to-follow commands found within `main()`
- Parameters `<input.dat>` `<output.txt>`
- The input file must be formatted in such a way that there is white-space between values


- Example Command:
    - `Vector v1;` - Initalizes a Vector
    - `v1.pushFront(x);` - Pushes `int x` onto the front of v1
    - `v1.peekAt(n);` - Returns value found at index `n` within the `Vector`
    - `Vector v3 = v1 + v2;` - Creates Vector 'v3', then sums values in v1 and v2 before assigning them to v3
    - `cout << v1;` - Prints all values within Vector to the terminal
