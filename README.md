# 3dsandbox
this is the software component of "3d sandbox." it is an openFrameworks application that processes video frames from a USB camera. One stereo channel shows the newest frame, and the other side shows a delayed frame. The camera is mechanically actuated to move along a linear track, perpendicularly to the camera's view ray. When the camera reaches the end of the track, in either direction, this application receives a message via the Arduino usbserial adapter, and responds by swapping the stereo images.

settings are given as command line arguments, so the app has to be launched from the command line, like so:

	analglyph.app/Contents/MacOS/analglyph 0 1280 720 20 0 0

0 is which camera (every time you run it they are listed)
1280 720 is the desired resolution (if it's too large there will be an error describing how large it can be)
20 is the amount of frames to delay (max is 60)
0 is the serial device (you probably only have one anyway)

the last 0 flips the left/right if you change it to something that isnt 0.
