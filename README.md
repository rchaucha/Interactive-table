# Interactive table
This is a C++ project that aims at at making any table interactive to add fun at parties and board games.
I'm in charge of the programming part while my friend makes the physical / electronics parts.

## Description 
The product has three main components:
* Projector
* RGB camera
* IR camera
And uses Arduino to get the information.

First, we use the RGB camera to detect objects on the table and track them using a modified version of the MOSSE tracker algorithm from OpenCV I made. The goal here is to track glasses, cards,... to project animations around them using the projector.

The user can then interact with the interface projected using little stylus equipped with IR leds so that clicks are detected by an IR camera. This allows to make any surface "touch-sensitive".

This should allow the computer to manage board games, add cool effects on the table (if someone looses for instance) et can animate parties with cool custom effects around glasses.


## What has been done
* The program can already manage the clicks with the IR camera, no matter if the camera isn't perfectly aligned thanks to a calibration at the start of the program
* Glasses are detected and tracked correctly using the modified version of the MOSSE tracker from OpenCV I made
* The program has a GUI made with [SFML](https://github.com/SFML/SFML) that allows the user to manage the applications he wants to be launched (for instance launching or not the glass tracking, launching a game,...). This interface uses a very flexible menu that shows buttons at the center of the table to allow the user to either launch / close applications or even interact with them when they are running if they define buttons.

  
## Demo
Here you can see a demo of the project making the wall touch-sensitive. I hold the stylus in my hand and click on the wall, making the program click on the computer.
At the end, I click on the glass tracking app icon, which launches it and opens it. You can see two new icons : one to reset the trackers, which basically re-scan the table for new glasses, and the other one to close the application. 

![demo](https://user-images.githubusercontent.com/18093026/105180130-125c8100-5b22-11eb-830f-0aa012456ed6.gif)
