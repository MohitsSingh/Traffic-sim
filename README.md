# Traffic-sim

So what i mainly changed is that i took out the DataClass with all that informations inside of it and instaid made all those items a private part of IntersectionData. This way we now only need to make one set of getters to access all of out data from inside the class. Also i changed all the item information we are going to be changing into pointers and i store those values inside the array at its location.

Example now you store intersection #156 Nb name like this: NbName[156] = College;
This will keep things a little simpler since we now only need two main classes for the data.

If there is any problems or questions please email me at me d2l email.

Wesley Stutzman
