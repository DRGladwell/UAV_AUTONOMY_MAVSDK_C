/*
This code will optimise the search of ground markers in a search area. The most direct responsibility of the code
is to plan a path around the search area that reduces distance covered. This achieved by taking into account
the height of the drone. This consideration and knowing the field of view of the aircraft we asses the pixel density
over every 2x2 meters patch of land in the search space, making sure it doesn't go bellow a threshold.
It would be recommended the path doesn't involve any sharp turn to enable a smoother journey.
A stretch goal it to pane the aircraft (either by role or pitch) to increase the search speed.
Care must be taken to avoid motion blur in input feed.
*/

// method to calculate the pixel density of a 2x2 piece of land related to aircraft height (1)

/* method that generates the least amount of point in an area such that if the aircraft was positioned in each
# point it would cover the entire search area with it's field of view. (2)
*/

// method to find the shortest way to navigate through all these points from current position (or some set) position. (3)

// method to returns an ordered lost of waypoints (4)

// method to adapt speed of aircraft if images are coming out blurry. (maybe)

// ideally add a method that allows for controller rolling and pitching of the plane in order to extend field of view

// method that runs 1,2,3,4

