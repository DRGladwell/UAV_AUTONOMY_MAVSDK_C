/*
Code to access the position of the ground marker relative to a 0,0,0 position on earth.
The calibration of the camera must take place first to find some intrinsic parameters (notably focal length).
The calibration will also remove distortion in the camera.
*/

// matrix containing the camera position relative to aircraft position

/* method that contains information from the camera calibration matrix. Notable the focal length and pixel deviation.
# This works by relating the (delta X of camera)/(focal length) = (real x )/(altitude).  The only unknown us real x.
# This equation holds true so long as the aircraft is level and the ground is a level plane. If ground isn;t a level
# the more work must be done. Returns a frame.  Return the ground marker position relative to the aircraft position.
*/ 

// Method that multiplies transforms together to return ground marker position relative to (0,0,0)

// method to tun all the ground_marker_location methods. Input is the aircraft position relative a (0,0,0) and image x,y