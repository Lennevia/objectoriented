Day 1: figuring out what is going on in this text-based game--

Paravia compiles, but there is one warning about a c-string. With no effort to fix it, the game
still runs and is even playable within terminal. I'm not terribly sure what everyone is talking about
with the "curses" file and the issues they're having because I haven't gotten anything like that.

Day 2:

Boolean type. The way this variable is defined in the .c file is backwards. There's an enum that
lists the 'True' first and the 'False' second, meaning that the true value of True is 0 and False is 1.
I want to get rid of this type, but I'm nervous the backward bool will cause issue later. 


