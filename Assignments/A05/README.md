# A05 - Designing your Game
## Mervyn Harp
### Description:
UML diagram representing my take on the base classes needed to form a D&D-inspired RPG program 

<img src="https://user-images.githubusercontent.com/45467263/236113759-413fc664-a090-4e3e-969e-9a3f8c4ea12f.png">

# Class Design.

## Encounter
Basis for actually simulating combat between a `Party` and any `Entity`. Allows storage of both these types, as well as a string titled `terrain` which represents
any special description of the fight location.
## Party
Is a collection of `Entity`. Most commonly, these will be `Player`, but the option exists to have a `Monster` within the `Party`. Allows for storage of Party Loot 
and any Social Renown the `Party` may have due to their exploits
## AbilityScr
Represents a single ability, such as `Strength`, `Dexterity`, `Constitution`, `Intelligence`, `Wisdom`, and `Charisma`
## Entity
Represents any Player Character or monster within the game. Attributes include `hitpoints`, `type`, an array of [6] `AbilityScr`, description of any 
special abilities, and an array of `item` which represents any gear the `Entity` has.
## Monster:
Child-Class of `Entity`. Has designated area for any `Special Attacks` or `Special Defenses` of the `Monster`.
## Player
Child-Class of `Entity`. Has designated area for the `level` of the character, as well as its `SpecClass` and any `feats`
## SpecClass
Child-Class of `Player`. Is what gives `Player` Special Abilities, `spell` acess, and bonus `feats`/`HP`.
## Spell
Represents any magic spell able to be cast within the game. Is used by `SpecClass` and `ArcaneCrystal`
## Item
Can be any item found in game. Can even represent a number of Gold Pieces by setting `value` and `weight`
## Weapon
Child-Class of `Item`. Has special values and methods to allow attacking from `Entity`
## Armor
Child-Class of `Item`. Has values and methods that represent `Armor` 'blocking' an attack from a `Weapon`
## ArcaneCrystal
Child-Class of `Item`. Is my personal spin on Potions/Scrolls. This `Item` allows any `Entity` to cast a `Spell` depending on how many uses are left within the 
`ArcaneCystal`



