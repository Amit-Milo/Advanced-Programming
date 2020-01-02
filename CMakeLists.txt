cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3 Containers/SocketsContainer.cpp Containers/SocketsContainer.h Containers/Container.h Containers/MapsContainer.h Commands/OpenDataServerCommand.cpp Commands/OpenDataServerCommand.h Commands/ConnectControlClientCommand.cpp Commands/ConnectControlClientCommand.h Containers/MapsContainer.cpp)