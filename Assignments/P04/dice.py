from dice import Die
from dice import Dice



def dieTester(diceObj, runs=10, testType="sum"):
    """Example function to test a die or dice.
    """
    if isinstance(diceObj, Die):
      print(f"Testing {diceObj.sides} sided die for {runs} rolls:")
      print("    [ ", end="")
      for i in range(runs):
          print(diceObj.roll(), end=" ")
      print("]")
    else:
      # print(f"Rolling {len(diceObj.dice)} {len(diceObj.dice[0].sides)} sided die {runs} times to get the {testType} value:")
      print(f"Rolling {len(diceObj.dice)}d{diceObj.dice[0].sides} [{runs}] times to get the {testType} value:")
      diceObj.rollDice()
      print("    [ ", end="")
      for i in range(runs):
        diceObj.rollDice()
        if testType == "avg":
          print(diceObj.avg(), end=" ")
        elif testType == "max":
          print(diceObj.max(), end=" ")
        elif testType == "min":
          print(diceObj.min(), end=" ")
        else:
          print(diceObj.sum(), end=" ")
      print("]")
  

if __name__ == '__main__':

  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice("8.d.20")

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  dieTester(d4, 20, "max")
