# Foobar-Project

## About the Project:
This project is a part of 3 repositories project. This repository provides the integration of a TCP server with a Bloom filter to boost the security of a web application by quickly verifying URLs for possible threats. This guide outlines the process of compiling and running both the Bloom filter component and the TCP server using Docker (or manually), ensuring smooth interaction with the Node.js server and web client.

## Compilation and running instructions:

### Manually:
**First of all: make sure you have the c++ Compiler (e.g g++).**
- Download the project.
- Unzip (=extract) the project.
- Open the terminal and navigate to the project's folder (cd <foldername> until the project's folder)
- Compile the project with the command: "g++ -I./headers ./src/*.cpp -o my_program"
- Run the program with the command: "./my_program"
- Enter the arguments you wish to the program and ENJOY it.

### Via Docker: 
**First of all: download Docker Desktop and open it.**
-  Open terminal and navigate to the project's folder.
- Run the command: "docker build -t foobar-project ."
- Then, run the command: "docker run -it foobar-project"
- Enter your arguments and ENJOY it.


## Setup and Configuration
For the complete setup and configuration instructions of the whole project, please refer to the project's [Wiki](https://github.com/DeanCo100/FooBar-Server/tree/main/WIKI).
