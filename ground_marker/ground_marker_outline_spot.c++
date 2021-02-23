/*
Use low level computer vision techniques to identify potential ground marker locations.
*/

// method to acquire new camera image and check if blurry (1)

// method to store in memory aircraft frame relative to a (0,0,0) and the image taken by camera (2)

// method to run thresholding on image (3)

// method to check if shape is roughly square and of right size, return center position of shape (x,y) (4)

// method to find location of potential ground marker (ground_marker_location.py) (5)

// method to check ground marker is close enough. IE: is the density of the image sufficient. (Maybe implement this)

/* method returns extracted ground marker from scene. We know we are extracting a square. As such this method should
# return a none rotated square.
*/

// method to add to list of potential ground markers (this method is in ground_marker_message.py)

// method to run 1,2,3,4,5