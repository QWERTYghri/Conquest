Conquest
=========


About
--------
Conquest is an Ncurses grand strategy game. It features systems such as political systems, war, economic systems, and more.
The game is on the premise that you manage these systems and make your country last as long as possible.

### Value System
The game features a value system to hold important info about a country
such as money, debt, income, trade, war, and more.

* List shows the important values, may ignore less important programming specific ones.

1. War
    * Countries: Current countries in war
    * Deaths: Amount of deaths from wars.
    * Soldiers: Amount of Soldiers
    * Tanks: Amount of tanks
    * Planes: Amount of planes
    * Conscription: Increases soldier amount but lessens skills
    * Skill: Skill of soldiers
    * Manpower: The amount of people able to be in the military.
2. General
    * Money: The amount of money you have
    * Income: Income from trade and more.
    * Expense: Payment for military and more.
    * Stability: Represents state of Citizens
    * Political Power: Represents availability to pass policies and more
    * Political Ideology: Choice
    * Tax: Amount of money paid by the people
3. Trade
    * Countries in trade with: Availability with different countries depends
    * Resources: Depends on country
    * Factory output: Output of resources.

### Difficulty Settings
There are three difficulties that act as a modifier to the incremented values in the system.
These modifiers affect the following


1. Easy: Doesn't change anything and your income stays the same
2. Medium: 25% of your income is subtracted
3. Hard: 50% of your income is subtracted

### Political Ideologies
The game features 7 different political ideologies with their own benefits and negatives

1. Nationalism
    * Increases Stat in politcal Power
    * Lessens trade availability
2. Facism
    * Increases Stat in politcal Power
    * Increases military skill
    * Lessens trade availability
    * Stability Decreases

3. Liberalism
    * More money from Taxes
    * Less skill of military
4. Democracy
    * More money from Taxes
    * Increased Stability
    * Less skill of military
    * Less Political Power

5. Socialism
    * Less stability
    * Increased Factory Output
6. Communism
    * Less Stability
    * Increased Soldiers
    * Increased Income
    * Soldier Skills are low
7. Neutral

### Resources
1. _Titanium_:
    * Natural
2. _Oil_:
    * Natural
3. Electronics
    * Copper + Gold
4. _Phosphate_
    * Natural
5. Fertilizer
    * Phosphate
6. Steel:
    * Iron + Titanium
7. _Copper_
    * Natural
8. _Gold_
    * Natural
9. _Aluminium_
    * Natural
10. Motor Parts:
    * Steel + Oil
11. Airplane Parts:
    * Titanium + Aluminum

Countries
---------
Discusses starter abilties

High	= 100,000
Low	=  10,000
Med	=  50,000

### Pasternak
Pasternak is a big country that would be equivalent to the Soviet Union. It defaults to Communism
It has a lot of soldiers but all default to the lowest skill.

It has a lot of resources:
	* Phosphate
	* Iron
	* Titanium
	* Oil

### Atifa
A medium country similiar towards Germany and defaults to Nationalism. It has high military skill
but a medium amount of soldiers.

It has a low amount of resources:
	* Gold
	* Copper

### Oceania
A big country similiar to the US and defaults to democracy, military skill is medium with a high amount of soldiers

It has a medium amount of resources:
	* Gold
	* Copper
	* Iron

### Kubo
A small country similiar to Japan and defaults to liberalism, military skill is medium with a medium amount of soldiers

It has a low amount of resources:
	* Aluminum
	* Oil

### Zanton
A small country similiar to Yugoslavia and defaults to Socialism, it's military skill is low, with medium amount of soldiers

It has a high amount of resources:
	* Gold
	* Copper
	* Aluminum
	* Titanium

Notes
------
**1/24/23**
Currently there is plans for only one playing mode which is single player. However I am planning for some sort of way
for multiplayer. Perhaps the ability to set up a server and have people join it. But I'd have to plan the single player
build to accomodate that plan which really isn't thought out much.
