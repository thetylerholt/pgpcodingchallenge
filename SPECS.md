# Challenge: Dynamic QT QObject and QML component creation Application

## Summary:
This skills assessment exercise requires the creation of a Qt6 application with a C++ backend and a QML graphical interface. The applicant must develop a system where the backend dynamically reads configuration files to instantiate QObject instances with specific behaviors, such as emitting signals based on timer intervals and updating values. Simultaneously, the QML frontend should visually represent these changes using custom components displayed in a QQuickWindow.

## Project Instructions:
Complete as much of the following project you can in 5 hours.  It's okay if you are not able to complete the project in the time limit. 

## Detailed Requirements:
Using QT6 write a program that fulfills the following requirements:



C++:

In the C++ backend, a configuration file must be read, which contains parameters for a variable number of objects of a QObject class.  This configuration file must be a structured format, like JSON, XML, etc.

The QObject class will have a property called “val”, emit a signal every “sec” seconds when val changes, and print to console a message indicating the value changes. Example: “data1 value changed to 123”.  The emitted signal will be an unsigned integer of random value between the “min” and “max” values.  


These parameters in the configuration file must include:
- id: a text parameter identifying the specific object. Example: “data1”, “data2”, “data3”
- sec: an integer parameter which sets the number of seconds between when the object emits a signal.
- min: the minimum value of the emitted signal 
- max:  the maximum value of the emitted signal


Please provide 3 example configuration files that contain parameters for one instance of your QOject, 3 instances, and 5 instances.  Each config file should contain instances with unique id, and sec values.



QML:

In the QML GUI, a configuration file must be read when the program starts, which contains parameters for a variable number of QML objects.  These objects will be instances of a custom QML component.  The QML component will be a rectangle, with a text string inside it. This configuration file must be a structured format, like JSON, or XML, but is open to your discretion. The component will have a property named “val”, which is what the text string value will be set to.  The QML objects will be instantiated in an empty QML window (QQuickWindow).  As the C++ QObjects update their val member variable, the QML object text should update to reflect the values.

These parameters in the configuration file must include:
- id: a text parameter identifying the specific object. Example: “box1”, “box2”, “box3”
- x: the x coordinate of the object in the parent window
- y: the y coordinate of the object in the parent window
- color: the color of the rectangle behind the text
- dataSource: the id of the QObject instance written in C++ that it gets its value from.

Provide a configuration file for the QML front end that creates a number of these components, and matches the configurations associated with the various C++ backend configurations.



## Deliverables:
- Source code files for the Qt project, including C++, QML, and configuration files.
- A README file with instructions on how to build and run the application.

## Submit the result:
To submit this exercise, send me your work via your preferred method.  If you were able to complete the exercise, I should be able to download and compile your program on my workstation using Qt Creator, or your specific build instructions.  If you were not able to complete it, tell me what parts are incomplete.
*Tell me why you choose this exercise instead of the others.
Tell me how much time it took you to complete the exercise.
Provide me an explanation of your work.  I would prefer a recorded video of you stepping through the code, explaining how and why you architected the pieces this way, and how various components of the code work.  If you can not provide a recorded video, a written response will be acceptable, but must be thorough, and easy to understand.

