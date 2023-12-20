# fract-ol

This project will be an opportunity to familiarize myself with miniLibX, to discover and use the mathematical notion of complex numbers and to learn about the concept of optimization in CGI and practice event handling.
I am going to use the 42 graphics library: the miniLibXThis library has been created internally and includes basic tools necessary to open a window, create images and deal with keyboard and mouse events.

Your project will have to follow the following rules:
* You have to use miniLibX, either the version available on campus computers or the one you install using its original sources.
* You will need to deliver a Makefile that will compile your source files. You should not relink.
* Global variables are prohibited.

Rendering
* Your program must offer the Julia and Mandelbrot sets.
* The mouse wheel zooms in and zooms out and does so almost infinitely (within the limits of the computer). That is the concept of a fractal.
* You should be able to create a different Julia set using the program parameters.
* A parameter will be passed through the CLI to define the type of fractal displayed. ◦ You can use more parameters as rendering options. ◦ If a parameter is not entered, or if the parameter is invalid, the program will display a list of available parameters and terminate successfully.
* You should use at least a few colors to show the depth of each fractal. It's even better if you delve into the psychedelic effects.

Graphic representation
* Your program has to display the image in a window.
* The management of your window must be fluid (switching to another window, minimization and so on)
* ESC should close the window and exit the program cleanly.
* Clicking on the cross in the window frame should close it and close the program cleanly.
* The use of MiniLibX images is mandatory.
