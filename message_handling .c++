#!/usr/bin/env python3

/*
code will check that a message is received through a handshake. This goes for regular and custom messages.
It's unclear if this code block is necessary.
*/

from mavsdk import System
import asyncio
from collections import namedtuple
from datetime import datetime

port_numbers = {
    "USB": "/dev/ttyACM0",
    "TELEM1": "	/dev/ttyS1",
    "TELEM2": "/dev/ttyS2",
    "NSHPort": "/dev/ttyS5"
}

Message = namedtuple('Message', ['data', 'timestamp'])


class SerialCommunicationSetup:

    def __init__(self, serial_port_number=port_numbers["TELEM2"], baud_rate=921600):
        """ Constructor for serial communication class"""
        self.uav = System()
        self.log = []
        self.connect_to(serial_port_number, baud_rate)

    def connect_to(self, serial_port_number=port_numbers["TELEM2"], baud_rate=921600):
        """ Connects to UART port on PixRacer and sets the baud rate for transmission """
        transmission_line = "serial://" + serial_port_number + ":" + str(baud_rate)
        await self.uav.connect(system_address=transmission_line)

        # wait until connection is stable
        async for port_state in self.uav.core.connection_state():
            if port_state.is_connected:
                print(f"-- Connected to UAV with UUID: {port_state.uuid}")
                break

    def log_message(self, data, timestamp):
        """Logs messages and corresponding timestamps """
        self.log.append(Message(data, timestamp))

    def save_log_to_disk(self, csv_file_name, append):
        """ Saves array log to file, if append false over-writes file, include
        '.csv. inside file name """
        file = "UAV/logs/" + csv_file_name

        # check type of operation to be performed on file
        op = 'a' if append else op = 'w'

        # check if it exists, if not write header of file
        try:
            f = open(file, 'r')
            f.close()
        except IOError:
            f = open(file, 'w')
            f.write("Data, Timestamp")
            f.close()

        # write to file
        with open(file, op) as csv_file:
            # if overwriting skip header line
            if op == "w":
                next(csv_file)
            # write log to file
            for log in self.log:
                line = log.data + ", " + log.timestamp.strftime("%d/%m/%Y, %H:%M:%S")
                csv_file.write(line)

    def handshake(self):
        """ Method that send the message or message type sent in the input. Will
        return 1 if successful handshake and 0 if failed handshake. Will retry a
        number A SET NUMBER of times over a very short period of time, but not
        too short. If handshake fails it's up to the the code running this method
        to handle the issue. """
        pass


# main method
if __name__ == '__main__':
    comm = SerialCommunicationSetup()
    comm.connect_to(port_numbers["TELEM2"])

    # test log data
    test_message = "tutto apposto di là?"
    current_time = datetime.now()
    comm.log_message(test_message, current_time)
    assert comm.log[0].data == test_message
    assert comm.log[0].timestamp == current_time

    # test save to file
    comm.log_message(test_message, current_time)
    comm.log_message(test_message, current_time)
    comm.log_message(test_message, current_time)
    comm.log_message(test_message, current_time)
    comm.save_log_to_disk("log1.csv", False)

    # runs event loop until program stopped
    asyncio.get_event_loop().run_forever()