import sys
from rich import print
import random
import math

def round_half_up(n, decimals=0):
  multiplier = 10 ** decimals
  return math.floor(n*multiplier + 0.5) / multiplier

class Die(object):
  def __init__(self,sides=6):
    if not isinstance(sides, int):
      print("Error! Improper 'Die' Construction Syntax")
      sys.exit()
    self.sides = sides

  def roll(self):
    values = [x for x in range(self.sides)]
    random.shuffle(values)
    return values[0] + 1
    
  def __str__(self):
    return f"[1d{self.sides}]"
    

class Dice:
  def __init__(self,sides=6,num_dice=1):
    if isinstance(sides, str):
      # Build List without '.' (4.d.12 -> '4', 'd', '12')
      list1 = sides.split('.')  
      num_dice, sides = int(list1[0]),int(list1[2])
    elif not isinstance(sides, int):
        print("Error! Improper 'Dice' Construction Syntax")
        sys.exit()
      
    # create a container
    self.dice = []
    self.rolls = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  def rollDice(self):
    if self.rolls : self.rolls.clear()
    for i in range(len(self.dice)):
      self.rolls.append(self.dice[i].roll())

  def avg(self):
    return round_half_up(sum(self.rolls)/len(self.rolls),1)
  def max(self):
    return max(self.rolls)
  def min(self):
    return min(self.rolls)
  def sum(self):
    return sum(self.rolls)
    
  def roll(self,rollType=None):
    self.rollDice()
    if rollType:
      if rollType =='avg':
        return self.avg()
      elif rollType == 'max':
        return self.max()
      elif rollType == 'sum':
        return self.sum()

  def __str__(self):
    s = "Dice: "
    t = f"[{len(self.dice)}d{self.dice[0].sides}]"
    if not self.rolls : 
      return s + t + " - (No Rolls Stored)"
    else:
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
  
