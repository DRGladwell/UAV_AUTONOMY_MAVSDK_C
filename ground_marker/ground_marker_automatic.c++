/*
Launch this code to run the rest of the ground marker code. External impacts are the following:
It will propose new missions plans to the flight controller.(for now no other behavior is planned such as offboard mode)
The code will send messages to the ground station via mavlink.
A lot of the raspberry pi2 resources such as memory and compute power will be taken.
*/

// method to control passive ground marker identification

/*
NOTE: this code shouldn't add to the list of potential ground markers in ground_marker_message.py.
# loop continuously until told externally otherwise
while (!exit condition from main UAV control)
    # find potential ground markers in an image
    groundmarker_outline.py (method to run 1,2,3,4,5)
    
    # check to see if a potential ground marker was found in an image
    if the list of potential ground markers found in single image is not none:
        # extract the potential ground marker patch of image
        groundmarker_outline.py (method to return ROI)
        # run extracted patch of image in CNN
        groundmarker_marker_identification.py (method that runs all other methods)
        # send message to ground station    
        ground_marker_message.py (method to send last element of identified ground markers)
    
NOTE: BE VERY CAREFUL AS THREADING IS PROBABLY REQUIRED    
*/

// method to control active ground marker identification

/*
# clear array of potential ground markers, just to be safe
ground_marker_message.py (method to clear potential ground maker array)
# loop continuously until told externally otherwise
while (!exit condition from main UAV control)
# this code is launched when approaching search area. must generate plan to search the area based on current location.
path_plan_search_area.py (method to run 1,2,3,4)
# upload the plan to the flight controller and save previous plan 
generate new mission plan around search space and save old plan
# complete the new current mission plan: this is just searching the search space
While(!arrived at last waypoint of new mission plan)
    
    # find potential ground markers in an image
    groundmarker_outline.py (method to run 1,2,3,4,5)
    
    # check to see if a potential ground marker was found in an image
    if the list of potential ground markers found in single image is not none:
        # add the potential ground marker to a list 
        groundmarker_outline.py (method to add to list of potential ground markers)
        
        NOTE: we still check the potential ground marker. If IDed it's later removed from the list of potential ground markers
        # extract the potential ground marker patch of image
        groundmarker_outline.py (method to return ROI)
        # run extracted patch of image in CNN
        groundmarker_marker_identification.py (method that runs all other methods)
        # send message to ground station    
        ground_marker_message.py (method to send last element of identified ground markers)
# method that ouputs a list of potential ground markers that have not been IDed so we don't revisit known ground markers
ground_marker_message.py (method to compare potential ground markers - identified ground markers)
# generate a new mission plan to at low altitude by each potential ground marker
potential_ground_marker_shortestpath.py (method to generate shortest path around potential ground markers)
generate new mission from potential ground marker to ground marker plan     
# loop continuously until told externally otherwise
while (!arrived at last waypoint of new mission plan)
    # find potential ground markers in an image
    groundmarker_outline.py (method to run 1,2,3,4,5)
    
    # check to see if a potential ground marker was found in an image
    if the list of potential ground markers found in single image is not none:
        # extract the potential ground marker patch of image
        groundmarker_outline.py (method to return ROI)
        # run extracted patch of image in CNN
        groundmarker_marker_identification.py (method that runs all other methods)
        # send message to ground station    
        ground_marker_message.py (method to send last element of identified ground markers)
NOTE: BE VERY CAREFUL AS THREADING IS PROBABLY REQUIRED
# revert back to the normal mission
reload old mission plan. Start mission from the waypoint after search for ground markers step. 
!exit condition from main UAV control = exit condition from main UAV control
*/