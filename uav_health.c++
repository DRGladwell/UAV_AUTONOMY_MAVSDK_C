/*
This code block can only launch before a flight. It is launched from the ground station.
The goal is to check the UAV will operate correctly whilst in flight. That means the
communications, hardware (and maybe software) of the UAV are checked.
The ground station via MAVlink will request the UAV to enter pre flight check state.
The UAV will check it is not in a mission. IF it's not in a mission it will perform a first
test. The user on the ground station will validate if the test worked. If the validation message
received by te UAV is positive, the next test will take place. If a test fails then the
UAV has an issue that needs resolving.
The code in here is just for the UAV side of the pre flight check.
*/


// each method here represents a check which corresponds to an action of the UAV. (Output)

// This method represents the reception of a validation method. (Input)

// Thus method cancels pre-flight check. This occurs upon user request (Input)

// This is the main method of the code block. Every check is ran and validated here (control)