# Flight Simulator Executer

## The Goal Of Project

In this project, we impelemented a mechanism that gets a text file that contains flight simulator's commands, formatted like a new coding language.
Our project interprets the file - first, we build a "lexer" that converts the file to a list of commands, and then a "parser" runs the commands, while communicating with the simulator.

## Installing And Running

In order to run out program, you first need to [install](https://sourceforge.net/projects/flightgear/) the flight simulator.
Then, add the fllowing settings to the Additional Settings section:
 1. --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
 2. --telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080\n
Finally, provide a commands file and run our program with the file's path as an argument.

## Built With

[Clion](https://www.jetbrains.com/clion/promo/?gclid=CjwKCAiA0svwBRBhEiwAHqKjFtmdeINGBWxR4nVxX0uMlDRj040mA5VabRmVGNzRgEpsk51j_XhrmBoCA5QQAvD_BwE&gclsrc=aw.ds) by JetBrains

## Versioning

[GitHub](https://github.com/), and this is [our project](https://github.com/Amit-Milo/Advanced-Programming)

## Authors

Amit Milo
Yoav Carmel

#### Done for the course "Advanced Programming 1" in Bar Ilan university







