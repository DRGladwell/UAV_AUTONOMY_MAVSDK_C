
/*
This is the main loop of the project. From here the code running on the Rasberry Pi2
is controlled. For the most part the code operates as follows.
 1) Determine current mission state of UAV.
 2) If necessary, launch code block that manages that UAV mission state.
 3.1) the code block will usually communicate with the flight controller. If so
    this is achieved through MAVSDK.
 3.2) the code block may communicate to the ground station in some mission states. This
    communication will use MAVlink, but the MAVSDK (which simplifies MAVLink communication)
    might not be able to handle the custom messages.
*/




// Main that performs setup and launches main loop