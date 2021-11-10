# BlinkPlus

A library to help use the LED built into many micro-contoller boards (or device connected to a digital IO pin) to convey the state of operation. The LED can be made to blink at two different rate depending if an error flag has been set. This allows a fast visial only analysis to work out if one (or more) functions in the code have returned with an error. See the example code included for useage.

The code has been tested with Teensy 3.6 and an Adafuit Feather M0 with an eternal micro-SD breakout board.