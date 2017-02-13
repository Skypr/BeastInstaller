Requirements for this program.

Because the elections are described in the language c, you need a working c compiler on your system.

Right now we support:

For Linux: gcc

For Windows: cl.exe (comes with Visual Studio (if you include the c++ pack))


To start the program, simply start the jar.

The main window of our program is the "ParameterEditor". If you close it, you close the whole program.
All other windows can be started from here under the menu point "window"

To see some examples you can load them through the parametereditor by clicking the "folder" icon.

Also, if you have the number of maximal processes set to zero, we determine the maximal amount of threads your computer can support
and start convert that number in the background to it.

In case you run BEAST on linux and get an error starting it, please make sure that the cbmc programs under /linux/cbmcLin/ are executable.
If they arend, please make them, so they can be called by BEAST.