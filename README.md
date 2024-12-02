# PGP QT6/QML Coding Challenge

Author: Tyler Holt

Dependencies:
- QT ver >= 6.5
- CMake ver >= 3.16
- Built and tested on Windows 11, untested on other platforms

Instructions:
- Import all source files into Qt Creator.
- Build the project using the MinGW compiler.
- Run the program from Qt Creator or the executable file created in the project directory.

### NOTE ABOUT CONFIG FILES:
Included are 4 configuration files:
- backend_1.json
- backend_3.json
- backend_5.json
- frontend.json

By default, the program will run using backend_5.json and frontend.json.

All 4 of the included files work fine, and they may be modified so long as the JSON schema is unchanged. HOWEVER, please note the following:
- Due to time limitations and ambiguity in the instructions, the filepath for the backend and frontend configuration files are hard coded as constants at the top of main.cpp
- If you use a relative filepath (as I have done by default), please ensure that Qt Creator is properly configured to use the proper working directory (found under Projects->Run->Working Directory on the left of the IDE). It seems to default to the folder where the executable is created rather than the folder where the source code is stored. Alternatively, change the relative path in main.cpp to an absolute path where the files are stored.
