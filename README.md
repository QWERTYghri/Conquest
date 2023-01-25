Conquest
=========

About
---------

Conquest is an ncurses game based on the grand strategy game _Hearts of Iron_. You're able 
select a country to control and follow a different political ideology to benefit yourself.
You're able to get taxes from the people and control resources to other countries. You can
invade other countries as well for their money and resources.

You have different values that set up your country and it's affect towards you.

Random events occur that can damage your country and include things such as
revolution, worker strike, pandemic, and economic fall.


Gameplay
-----------
A cycle of two seconds occurs that increases the status values
for a struct country. Difficulty affects the increase of values.

There is also a random change every 5 minutes for a rate depending on difficulty of a country
invading you.

Threads used to count with status vals along with random change for each country.


**Difficulties**

* Easy		: Country vals increase with high rates and no countries declare war
* Medium	: Country vals increase with med rates and a 1/6 chance of invasion with each country
* Hard		: Country vals increase with low rates and a 1/4 chance of invasion with each country.

(w s) (↑↓)
----------
Cycle through panel options, press enter
to open a panel in the left panel side which
will open a prompt for its purpose

(a d) (←→)
----------
Cycle through different countries. Countries
that aren't yours have read only values and cannot
press enter on a specific value to change it.

Compilation
----------------------------
Use the Make utility to compile executable
Use `conf.mk` to change compilation flags and other stuff

Run `make` to compile binary
