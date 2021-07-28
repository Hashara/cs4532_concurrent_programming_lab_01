cmake_minimum_required(VERSION 3.19)
project(cs4532_concurrent_programming_lab_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cs4532_concurrent_programming_lab_01
        .idea/.gitignore
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        linked_list.c
        linked_list.h
        main.c linked_list.c linked_list.h)
