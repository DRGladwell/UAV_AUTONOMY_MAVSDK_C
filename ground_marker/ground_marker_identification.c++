/*
This code launches when ground marker_outline_spot.py spots a potential ground marker.
This code stop searching when a the potential ground marker is out of view. Multiple threads of this code should
be launched in parallel.
Code to access the position of the ground marker relative to a 0,0,0 position on earth.
The calibration of the camera must take place first to find some intrinsic parameters (notably focal length).
The calibration will also remove distortion in the camera.
It's assumed that, if a potential ground marker is not a ground marker it will never be IDed as a ground marker.
Thus the aircraft will be fly over ground marker and write of the potential ground marker as a false positive.
If the potential ground marker is an actual ground marker, it's assumed it will eventually be identified with a
sufficiently high probability. The ground marker will be removed from the list of potential ground markers.
A special error case occurs if ever image taken by the aircraft is always blurry. (solution is to control aircraft
speed based on blurriness of image. Make sure to never stall aircraft)
*/

/* method that thresholds the black and white of the ROI (region of interest). The majority colour of the ROI is
# binned into one of the possible colours a ground marker can be. The ROI then has this colour masked to return
# as black <- this will make the next step more consistent. Return the four possible rotations of the thresholded ROI
# (one for each possible orientation of the ground marker).
*/

/* method that feeds the ROI (region of interest) into a trained CNN model. Returns identity of ground marker with
# probability.
*/

/* method that checks the probability of ground marker identification. If high enough, the ground marker has been
# correctly ID. Otherwise the ground marker has not been IDed.
# Add to list of identified ground markers (this method is in ground_marker_message.py)
*/

// method that runs all methods of ground_marker_identification. (extra work may be needed to thread this work)
