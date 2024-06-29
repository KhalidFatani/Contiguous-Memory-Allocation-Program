## Multithreaded Sorting Application

Names: Elizabeth Fassler (6336712) and Khalid Fatani (6363026).

Operating Systems Principles

Programming Assignment 3

1245-FIU01-COP-4610-SECRVDC-52544

Professor Kiavash Bahreini - Email: kbahrein@fiu.edu

Samreen Abbasi (She/Her) - Email: sabba027@fiu.edu

Shabazuddin Mohammad (He/Him/His) - Email: smoha102@fiu.edu

Github Repository: [https://github.com/Operating-Systems-Group/Multithreaded-Sorting-Application/tree/main](https://github.com/KhalidFatani/Contiguous-Memory-Allocation-Program/tree/main)

_____________________________________________________________________________________________________________
Elizabeth Fassler: 
- Finished and updated memory.c file.
- Designed a working Makefile.
_____________________________________________________________________________________________________________
Khalid Fatani: 
- Created team project repository and readme file on Github.
- Wrote basic pseudocode.
- Worked on memory.c file.
- Created video for programming assignment 3.
_____________________________________________________________________________________________________________
### Meetings


_____________________________________________________________________________________________________________
### Run Commands in Terminal


_____________________________________________________________________________________________________________
### Introduction

Write a multithreaded sorting program in C that works as follows: A list of integers is divided into two smaller lists of equal size. Two separate threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged by a third thread—a merging thread—which merges the two sublists into a single sorted list.

Because global data are shared across all threads, perhaps the easiest way to set up the data is to create a global array. Each sorting thread will work on one-half of this array. A second global array of the same size as the unsorted integer array will also be established. The merging thread will then merge the two sublists into this second array. Graphically, this program is structured as in the figure below.

Figure 1: Multithreaded Sorting.

![69d5e8c4-4ca7-4e46-a1e1-4ccf80639ecc](https://github.com/Operating-Systems-Group/Multithreaded-Sorting-Application/assets/128157075/403d8a27-c6eb-41ce-a420-19480d7cdcd6)

This programming project will require passing parameters to each of the sorting threads. In particular, it will be necessary to identify the starting index from which each thread is to begin sorting. Refer to the instructions in Project 1 for details on passing parameters to a thread.
Once all sorting threads have exited, the parent thread will output the sorted array.
_____________________________________________________________________________________________________________
### Notes

- Create your application using the C programming language on the FIU Ocelot server for the UNIX operating system.
- Create a short video of a maximum of 6 minutes of your running application and source codes.
- Create a text or Word file called Instructions.txt and write down the steps to run your application (your source codes should be error-free).
- Add the recorded video file, the text/Word files, and your project, including the source codes, Makefile, etc., into a zip file.
- Upload the zip file to Canvas before the deadline.
_____________________________________________________________________________________________________________
### Basic pseudocode:




