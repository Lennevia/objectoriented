paravia.c compiles, but there is one warning about a c-string. With no effort to fix it, the game
still runs and is even playable within terminal. I'm not terribly sure what everyone is talking about
with the "curses" file and the issues they're having because I haven't gotten anything like that.

Boolean type. The way this variable is defined in the .c file is backwards. There's an enum that
lists the 'True' first and the 'False' second, meaning that the true value of True is 0 and False is 1.
I want to get rid of this type, but I'm nervous the backward bool will cause issue later.


I believe the first necessary entity that needs to be converted into c++ is the information in
relation to the player. SO, that means we're gonna create a player class in order for the game
to then interface with after so many things have been decided.

This class will not be difficult to create logic wise, just a bit time consuming with all the information
that will be contained within it. SO, I think separate enums for things like cities will be useful.

Gitwise, I think it would be best to keep paravia.c untouched completely and copy over
things that need to be changed so there is always a clean slate to look back on.

Of course, the player is a struct already and technically is a class, so hey that's a good sign.
But a very important class as it's passed around by almost every function within the game's
logic.

Another big change I'm going to attempt to make is converting all the char arrays into
strings. This is c++, we can do that.

Ideally, I want to be able to harvest functions from the paravia.c file and to keep the
best track of what I've already converted to c++, I want to create a copy of paravia
where I can simply extract pieces of the game from this and eventually decimate
the copy of this file. Effectively crossing off a to-do list of sorts.

Right now I'm looking at InitializePlayer() and I'm not really sure how the pointer part will work with the strings, so we'll see how that goes I guess!
AKA: Do pointers pointing to strings point to the whole string or just the first character and then
         to follow up, would I then need to iterate through them in order to get a string? 


