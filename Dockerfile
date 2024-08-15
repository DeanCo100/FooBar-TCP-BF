# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory to /Foobar-Project
WORKDIR /Foobar-Project

# Copy the source code and headers to the container
COPY headers /Foobar-Project/headers
COPY src /Foobar-Project/src

# Create the build directory
RUN mkdir /Foobar-Project/build

# Install any dependencies
RUN apt-get update

# Expose port 5555 for server connection
EXPOSE 5555

# Explicitly list and compile each source file
RUN g++ -std=c++11 -Wall -Iheaders -c src/DupRemoveVec.cpp -o build/DupRemoveVec.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/IterativeHash.cpp -o build/IterativeHash.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/BasicHash.cpp -o build/BasicHash.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/BloomFilter.cpp -o build/BloomFilter.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/ProgramFlow.cpp -o build/ProgramFlow.o


RUN g++ -std=c++11 -Wall -Iheaders -c src/BloomFilterChecker.cpp -o build/BloomFilterChecker.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/ListExistenceChecker.cpp -o build/ListExistenceChecker.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/UrlCommandChecker.cpp -o build/UrlCommandChecker.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/LookUpCommand.cpp -o build/LookUpCommand.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/AddUrlCommand.cpp -o build/AddUrlCommand.o
RUN g++ -std=c++11 -Wall -Iheaders -c src/main.cpp -o build/main.o  # Add this line to include main.cpp
RUN g++ -std=c++11 -Wall -Iheaders -c src/TCPServer.cpp -o build/TCPServer.o


# Link the object files to create the executable
RUN g++ -std=c++11 -Wall -o my_program \
    build/DupRemoveVec.o \
    build/IterativeHash.o \
    build/BasicHash.o \
    build/BloomFilter.o \
    build/ProgramFlow.o \
    build/BloomFilterChecker.o \
    build/ListExistenceChecker.o \
    build/UrlCommandChecker.o \
    build/LookUpCommand.o \
    build/AddUrlCommand.o \
    build/main.o \
    build/TCPServer.o


# Run the executable when the container launches
CMD ["./my_program"]
