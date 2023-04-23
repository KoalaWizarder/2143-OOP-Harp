import sys
from rich import print
import random
import math

###############################################################################
# round_half_up() 
#  Function meant to perform rounding operations in the same way
#    they are normally performed in mathematics 
#  -Round UP when point is >= 5
#  -Round DOWN when point is <= 4
def round_half_up(n, decimals=0):
  multiplier = 10 ** decimals
  return math.floor(n*multiplier + 0.5) / multiplier

###############################################################################
# Class serves to represent singular dice of any size
#
# Data Members:
#   self.sides    -> Variable to hold number of sides for Die
# Methods:
#   __init__ |> Die()  -> Constructs Die object with 6 sides
#            |> Die(s) -> Constructs Die object with (s) sides
#   __str__  -> Allows for easy outputting of Die object
#                (Format: "[1d{Number of Sides}]")
#   roll()   -> Returns random value between 1 and {Number of Sides}
class Die(object):
  #############################################################################
  # __init__
  #  []Checks to see if 'sides' is an int
  #    ()If NO, output error message and end program
  #    ()If YES, 'self.sides' is initialized to 'sides'
  def __init__(self,sides=6):
    if not isinstance(sides, int):
      print("Error! Improper 'Die' Construction Syntax")
      print("-Please refer to documentation")
      sys.exit()
    self.sides = sides
    
  #############################################################################
  # roll()
  #  []Build list containing values [0, ..., (sides-1)]
  #  []Shuffle List
  #  []Return first value in list
  def roll(self):
    values = [x for x in range(self.sides)]
    random.shuffle(values)
    return values[0] + 1
    
  #############################################################################
  # __str__
  #  []Output Die info
  #    Format: "[1d" + {Number of Sides} + "]"
  # print(Die(6)) -> "[1d6]" 
  def __str__(self):
    return f"[1d{self.sides}]"
###############################################################################
    
###############################################################################
# Class serves as a container for multiple Die() objects that can 
#    then perform various functions using those objects
#
# Data Members:
#   self.dice[]  -> Contains each Die() that makes up Dice()
#   self.rolls[] -> Contains the current roll(s) of each Die
# Methods:
#   __init__ |> Dice()    -> Constructs Dice object containing [1] Die()
#            |> Dice(s,n) |> (if s is int)   -> Constructs Dice object 
#                                                containing [n] Die(s)
#                         |> (elif s is str) -> Constructs Dice object from `s`
#                                            -> 's' must be formatted in the 
#                                                same way as ("1.d.6")
#   __str__    -> Allows for easy outputting of Dice object 
#                  Format: "Die() - ( Die.Roll() )" 
#   rollDice() -> Rolls each Die from Dice, storing the value from each roll
#                  within Dice.rolls[]
#   avg()      -> Returns the average of self.rolls[]
#   max()      -> Returns MAXIMUM value within self.rolls[]
#   min()      -> Returns MINIMUM value within self.rolls[]
#   sum()      -> Returns SUM of self.rolls[]
#   roll(rT)   -> Performs self.rollDice()
#              \> (if rT is keyword) -> Return value based on keyword
#                      [Keywords: "avg", "max, "min", "sum"]
class Dice:
  #############################################################################
  # __init__
  #  []Checks to see if 'sides' is a str
  #    ()If YES, 'sides' is split into a list where:
  #      []list[0] = Number of Dice
  #      []list[1] = "d"
  #      []list[2] = Size of each Die
  #      []List[0]/list[2] are stored within num_dice/sides respectively
  #    ()If NO, checks to see if 'sides' is an int
  #      ()If NO, output error message and terminate program
  #  []Builds dice[] and rolls[] as empty lists, then attaches them to Dice
  #  []Populates dice[] with an amount of Die('sides') equal to 'num_sides'
  def __init__(self,sides=6,num_dice=1):
    if isinstance(sides, str):
      # Build List without '.' (4.d.12 -> '4', 'd', '12')
      list1 = sides.split('.')  
      num_dice, sides = int(list1[0]),int(list1[2])
    elif not isinstance(sides, int):
        print("Error! Improper 'Dice' Construction Syntax")
        print("-Please refer to documentation")
        sys.exit()
    # create a container
    self.dice = []
    self.rolls = []
    for die in range(num_dice):
      self.dice.append(Die(sides))

  #############################################################################
  # rollDice()
  #  []Checks to see if self.rolls[] is populated with any values
  #    ()if YES, self.rolls[] is cleared of all values
  #    ()if NO, do nothing (Not expressed inline)
  #  []Populates self.rolls[] by rolling each Die object within self.Dice[], 
  #    then recording the results in self.rolls[]
  def rollDice(self):
    if self.rolls : self.rolls.clear()
    for i in range(len(self.dice)):
      self.rolls.append(self.dice[i].roll())
      
  #############################################################################
  # avg()
  #  []Returns average of all values within self.rolls[]
  def avg(self):
    return round_half_up(sum(self.rolls)/len(self.rolls),1)
  #############################################################################
  # max()
  #  []Returns maximum value within self.rolls[]
  def max(self):
    return max(self.rolls)
  #############################################################################
  # min()
  #  []Returns minimum value within self.rolls[]
  def min(self):
    return min(self.rolls)
  #############################################################################
  # sum()
  #  []Returns sum total of all values within self.rolls[]
  def sum(self):
    return sum(self.rolls)

  #############################################################################
  # roll(rT)
  #  []Performs rollDice() to repopulate self.rolls[]
  #  []Checks to see if rT contains a value
  #    ()if NO          -> Do nothing (Not expressed inline)
  #    ()if YES: 
  #      ()if rT is not keyword -> Print Error message and terminate program
  #      ()if rT is 'avg'       -> Return self.avg() of self.rolls[]
  #      ()if rT is 'max'       -> Return self.max() of self.rolls[]
  #      ()if rT is 'min'       -> Return self.min() of self.rolls[]
  #      ()if rT is 'sum'       -> Return self.max() of self.rolls[]
  def roll(self,rollType=None):
    self.rollDice()
    if rollType:
      if rollType =='avg':
        return self.avg()
      elif rollType == 'max':
        return self.max()
      elif rollType == 'min':
        return self.min()
      elif rollType == 'sum':
        return self.sum()
      else:
        print("ERROR! Chosen Roll-Type is not found!")
        print("\n-Please refer to documentation")
        sys.exit()

  #############################################################################
  # __str__
  #  []Create starting Variables (s,t) to hold output in
  #  []Checks to see if self.rolls[] is populated
  #    ()if NO, perform self.rollDice()
  #    ()if YES, do nothing (Not expressed inline)
  #  []Iterate through self.dice[]/self.rolls[], formatting and adding each 
  #    each member to 's'
  #    FORMAT: " self.Dice[ x ] - ( self.rolls[ x ] ) "
  #                           . . .                   
  #            "  {Total Dice}  - ( Sum of all rolls) "
  #  []Calculate final dice amount/roll total, then add to 's'
  #  []Return 's'
  # print(Dice(6,3)) -> "Dice:  [1d6] - (3)" 
  #                     "       [1d6] - (6)" 
  #                     "       [1d6] - (1)" 
  #                     "Total:[[3d6]]-((10))"
  def __str__(self):
    s = "Dice: "
    t = f"[{len(self.dice)}d{self.dice[0].sides}]"
    if not self.rolls : 
      self.rollDice()
    s = s + f" {self.dice[0]} - ({self.rolls[0]})\n"
    for x in range(len(self.dice)-1):
      s = s + f"       {self.dice[x+1]} - ({self.rolls[x+1]})\n"

    s = s + f"Total:[{t}]-(({sum(self.rolls)}))"
    return s

if __name__=='__main__':
  d1 = Die()
  d2 = Die(30)

  print(d1)
  print(d2)
  print(d2.roll())
  d3 = Dice("2.d.20")
  print(d3)
  d3.rollDice()
  print(f"\n{d3}")
  print(d3.sum())
  print(d3.avg())
  print(d3.max())
  d3.roll()
  print(d3.roll("avg"))
  print(d3.dice[0])
  print(Dice(10,5))
  
