# Open Flights
CS225 Data Structures and Algorithms Final Project 



Repository Structure
------------

+ All code can be found in the [Code/](https://github.com/kyt525/CS225_Final_Project_22/tree/main/Code) folder

+ Datasets are stored as csv files under [Data/](https://github.com/kyt525/CS225_Final_Project_22/tree/main/Data)

+ The development logs, team contract, etc can be found under [Documents/](https://github.com/kyt525/CS225_Final_Project_22/tree/main/Documents)

+ The final presentation, project report, and final results can be found under the [Final Deliverables/](https://github.com/kyt525/CS225_Final_Project_22/tree/main/Final%20Deliverables)


Running Instructions
----------
The user will be able to run our program by running `make test` followed by  `./main` where they will be allowed to change any of data they want. They also can see our test cases by running `./test`. All the functions are tested in both files.

Within the [Test/](https://github.com/kyt525/CS225_Final_Project_22/tree/main/Code/CS_Project/tests) folder the user can also see all the .csv files used to test our code. We have numerous test cases for each file used to test each function that can be switched out for each other in main. 

Below we have listed the inputs and outputs for each function:
-	ShortestPath (Dijkstra’s):
	  -	Input: TravelGraph, source airport, and destination airport
	  -	Output: vector of pair of airports and the distance from the previous airport.
-	BetweennessCentrality
	  -	Input: TravelGraph and an airport node 
	  -	Output: decimal for how connected an airport is on a scale of 0-1
-	BFS
	  -	Input: TravelGraph and the source airport
	  -	Output: vector of airport IDs



Team:
--------
Frank Lu (yuzhelu2),
Kathryn Thompson (kyt3),
Neha Valvala (nehasv2),
Shriya Surti (ssurt2)


"The README clearly and succintly describes the following:

The linkage and location of all major code, data, results, and deliverable files.

The necessary commands to run the assignment are well described and include instructions for selecting the input dataset and output location

The test suite is well described and instructions on how to reproduce the tests are provided."
