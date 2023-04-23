## P01 - Vector Class
### Mervyn Harp
### Description:

Program uses Python to implement a Die and Dice class. 


### Needed Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.py](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P04/main.py)  | Main driver of my project that displays program functionality |
|   2   | [dice.py](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P04/dice.py)  | File where Die/Dice class implementation is stored |

### Instructions

- As it stands, the program will simply run and allow you to trace its workings through the easy-to-follow commands found within `main()`

- Example Command:
    - `foo = Die(s)` - Initalizes a singular die of size `s` (Default: `s = 6`)
      - `foo.roll()` - Returns a random `int` between `1` and `s`
    - `bar = Dice(s,n)` - Initializes a object containing (`n`) `Die` objects of size `s` (Default: `n = 1`, `s = 6`)
      - `bar.rollDice()` - Rolls each `Die` within `bar`, then saves the results within `bar.rolls[]`
      - `bar.max()` - Returns maximum value chosen from rolls within `bar` (Dice Object)

- Parameters: `N/A`
