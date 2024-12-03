# The-Monty-Hall-Problem-CSCI301-HW
Most people find the solution to the Monty Hall problem to be a bit counter-intuitive at first glance (hence the "paradox"). For this assignment I would like you to write a program that simulates the execution of the game over a large number of possible runs.

You may choose any programming language for this simulation, but please include instructions for compiling and running.

For this program you will write:

monty_hall - A function that simulates the Monty hall problem, ask the user if they want to stay or switch. When you run the function it should generate a random permeation of values behind the doors (car, goat, and goat) and should simulate the problem: The user selects a random door, the host selects a door with a goat that is not the door the user selected. The function should return a bool value based on the result: True if you found the car and False otherwise.
simulate(num_iterations) - A method that simulates num_iterations of the monty hall problem. Your method should collect statistics regarding how many times the user won and lost. It should print those statistics, and the ratio times_won/total_runs (the actual percentage as calculated by the program, not a rounded value).
 

Your program should ask the user for how many iterations they wish to simulate the problem. In order collect sufficient statistics with which we can draw conclusions about the problem, your program should be able to perform 100,000 simulations (in reasonable time) where it randomly assigns the three doors (one getting a car, the other two a goat) and performs the operation requested by the user (either keeping the original door or switching to the other). After each call to your simulate method your program should output the total number of times won, the total number of times lost, and the percent of the total runs won. For large numbers of runs your simulations should show a percentage that is very close to the expected percentages for staying with your door (1/3) and switching (2/3).

You are to run your simulation for the following number of trials: 10, 100, 1000, 10 000, and 100 000. If your implementation is capable of running for higher values feel free to include more. Please submit all the documents in Canvas:

your code
an page with your results and graph (preferably computer generated) of trials for 10, 100, ...
A short reaction to the problem. In your reaction think about contrasting your beliefs/understanding of the problem before and after the simulation. 
 

I am aware that being a very well known problem in the discipline and that there are numerous implementations available in the wild. My expectation is still the same as it is described in the syllabus. Your solution should be the result of your own work, and the academic honesty policies of the syllabus do apply since this is an individual assignment. Please do not copy work from a classmate or the internet to complete this program.