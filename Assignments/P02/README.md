## P02 - MyVector Class 2
### Mervyn Harp
### Description:

#### Program iterates upon [P02]() by implementing [Overloaded Operators](Broken_Link_To_My_Own_Wiki). Included operators that have been altered and their respective functionalities are detailed within source.cpp, but a short list has been provided below:
- ostream ```<<``` -> Allows easy outputting to terminal
  - ##### ```cout << (Vector)v1```
- ofstream ```<<``` -> Allows easy outputting to output file
  - ##### ```outfile << (Vector)v1```
- ```[]``` -> Allows for accessing data members in the same fashion as an array
  - ##### ```int x = v1[n]```
- ```+``` -> Sums corresponding values in two different Vectors. If one Vector is larger than the other, extra values are unaltered.
  - ##### ```(v1 + v2)``` (Returns Vector with updated values. Normally used with the [Assignment Operator](LINK_LINK))
- ```-``` -> Subtracts corresponding values in one Vector from another. If one Vector is larger than the other, extra values are unaltered.
  - ##### ```(v1 - v2)``` (Returns Vector with updated values. Normally used with the [Assignment Operator](LINK_LINK))
- ```*``` -> Multiplies corresponding values in two different Vectors. If one Vector is larger than the other, extra values are unaltered.
  - ##### ```(v1 * v2)``` (Returns Vector with updated values. Normally used with the [Assignment Operator](LINK_LINK))
- ```/``` -> Divides corresponding values from two Vectors. If one Vector is larger than the other, extra values are unaltered.
  - ##### ```(v1 / v2)``` (Returns Vector with updated values. Normally used with the [Assignment Operator](LINK_LINK))
- ```==``` -> Checks to see if two Vectors contain equal values. If they are equal, return TRUE.
  - ##### ```(v1 == v2)``` (Returns TRUE or FALSE Boolean)
- ```=``` -> Copies and assigns values from one Vector to another.
  - ##### ```(v1 = v2)``` (v1 will now contain the same values as v2)



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
