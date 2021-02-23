/*
Code that should be launched as soon as we start trying to ID ground markers.
When a potential ground marker is IDed it gets added to an array in here.
When a potential ground marker is identified as a ground marker it is added here.
When a potential ground marker was not identified as a ground marker it is added here.
Note: each array contains (location, ground marker main colour, ground marker alpha numeric value)
The array of identified as a ground marker needs to be sent to ground station. The other 2 arrays act as tools for
debugging.
*/

// Array of potential ground markers

// Array of identified ground markers

// Array of not ground markers

// method to clear potential ground marker array

// method to add new elements to array of potential ground markers. Make sure there are no duplicates.

// method to add new elements to array of identified ground markers. Make sure there are no duplicates.

/* method to compare potential ground markers - identified ground markers. The difference should be not ground markers.
# (The other way around identified ground markers - potential ground markers is of no interest so not taken note off.)
*/

/* method to send last element of identified ground markers.  If the last array is no different from the previously sent
# element, don't send a message to the ground station. (Maybe when search is over resend full array to check is there
# are any mistakes).
*/