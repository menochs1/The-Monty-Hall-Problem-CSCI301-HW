/**
 * @file MontyHall.cpp
 * @author Mason Enochs
 * @brief 
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

bool montyHall();

bool montyHall(int chosen, bool swap, int iteration);

double simulate(int numIterations);

int main()
{
    int numIterations, input = 0;

    cout << "Welcome to the Monty Hall Paradoox!" << endl;
    cout << "What would you liike to do?" << endl;

    while(input != 3)
    {
        cout << "1. Play the Monty Hall game " << endl;
        cout << "2. simulate x number of Monty Hall games " << endl;
        cout << "3. quit" << endl;
        cin >> input;
        cout << endl;
        if(input != 1 and input != 2 and input != 3)
        {
            cout << "Incorrect input, try again. " << endl;
            cin >> input;
        }
        if(input == 2) {
            cout << "please enter the number of iterations you want to simulate: ";
            cin >> numIterations;
            cout << endl;
            simulate(numIterations);
        } else if(input == 1) {
            montyHall();
        }
    }

    cout << "Thanks for playing!" << endl;
    

    return 0;
}

bool montyHall()
{
    bool doors[3] = {false};
    bool selectedDoor[3] = {false};

    int input;
    srand((unsigned) time(NULL));
    int random = rand() % 3 + 1;

    doors[random] = true;

    cout << "select a door: 1, 2, or 3. ";
    cin >> input;
    while ((input != 1) and (input != 2) and (input != 3))
    {
        if((input != 1) and (input != 2) and (input != 3))
        {
            cout << endl << "Incorrect Input." << endl;
            cout << "select a door: 1, 2, or 3. ";
            cin >> input;
        }
    }
    cout << endl;
    selectedDoor[input-1] = true;

    int revealedDoor, chosenDoor, unchosenDoor;

    cout << "door " << input << " was your choice!" << endl;
    for(int i = 0; i < 3; i++)
    {
        if(selectedDoor[i])
        {
            chosenDoor = i;
            continue;
        }
        if(!doors[i] and !selectedDoor[i])
        {
            cout << "Behind door " << i + 1 << " is a GOAT!" << endl;
            revealedDoor = i;
            break;
        }
    }

    switch (chosenDoor)
    {
    case 0:
        if(revealedDoor == 1)
        {
            unchosenDoor = 2;
        }
        unchosenDoor = 1;
        break;
    case 1:
        if(revealedDoor == 0)
        {
            unchosenDoor = 2;
        }
        unchosenDoor = 1;
        break;
    case 2:
        if(revealedDoor == 1)
        {
            chosenDoor = 0;
        }
        chosenDoor = 1;
    }

    cout << "Do you want to switch or stay?" << endl;
    cout << "1. Switch" << endl;
    cout << "2. Stay" << endl;
    cin >> input;
    while (input != 1 and input != 2)
    {
        cout << "Incorrect Input, please try again." << endl;
        cout << "1. Switch" << endl;
        cout << "2. Stay" << endl;
        cin >> input;
    }
    
    if(input == 1)
    {
        selectedDoor[chosenDoor] = false;
        selectedDoor[unchosenDoor] = true;

        cout << "You have switched to door " << unchosenDoor + 1 << "!" << endl;
        if(selectedDoor[unchosenDoor] == doors[unchosenDoor])
        {
            cout << "Congradulations! YOU WIN!" << endl;
            return true;
        } else {
            cout << "Oh no! You got a GOAT!" << endl;
            return false;
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(selectedDoor[i] and doors[i]){
            cout << "Congradulations! YOU WIN!" << endl;
            return true;
        }
    }
    cout << "Oh no! You got a GOAT!" << endl;
    return false;
}

double simulate(int numIterations)
{
    int door, swap;
    
    cout << "which door do you choose? 1, 2, or 3?";
    cin >> door;
    while(door != 1 and door != 2 and door != 3)
    {
        cout << endl << "Incorrect, please try again. ";
        cin >> door;
        cout << endl;
    }
    cout << endl;

    cout << "Do you wish to switch or stay from this door?" << endl;
    cout << "1. switch" << endl;
    cout << "2. stay" << endl;
    cin >> swap;
    while(swap != 1 and swap != 2)
    {
        cout << endl << "Incorrect, please try again. ";
        cin >> swap;
        cout << endl;
    }

    int wins = 0, total = 0;

    if(swap == 1)
    {
        for(int i = 0; i < numIterations; i++){
            if(montyHall(door, false, i))
            {
                wins++;
            }
            total++;
        }
    } else {
        for(int i = 0; i < numIterations; i++){
            if(montyHall(door, true, i))
            {
                wins++;
            }
            total++;
        }
    }

    cout << "Total Games: " << total << endl;
    cout << "Games Won: " << wins << endl;
    cout << "Games Lost: " << total - wins << endl;
    cout << "Win Rate: " << fixed << setprecision(2) << (double(wins) / double(total)) * 100 << "%" << endl;

    return double(wins) / double(total);
    
}

bool montyHall(int chosen, bool swap, int iteration)
{
    bool doors[3] = {false};
    bool selectedDoor[3] = {false};

    srand(time(0) + iteration);
    int random = rand() % 3 + 1;

    doors[random] = true;
    selectedDoor[chosen - 1] = true;

    if(swap)
    {
        int revealedDoor, chosenDoor, unchosenDoor;
        for(int i = 0; i < 3; i++)
        {
            if(selectedDoor[i])
            {
                chosenDoor = i;
                continue;
            }
            if(!doors[i] and !selectedDoor[i])
            {
                revealedDoor = i;
                break;
            }
        }

        switch (chosenDoor)
        {
        case 0:
            if(revealedDoor == 1)
            {
                unchosenDoor = 2;
            }
            unchosenDoor = 1;
            break;
        case 1:
            if(revealedDoor == 0)
            {
                unchosenDoor = 2;
            }
            unchosenDoor = 1;
            break;
        case 2:
            if(revealedDoor == 1)
            {
                chosenDoor = 0;
            }
            chosenDoor = 1;
        }

        selectedDoor[chosenDoor] = false;
        selectedDoor[unchosenDoor] = true;

        if(selectedDoor[unchosenDoor] == doors[unchosenDoor])
        {
            return true;
        } else {
            return false;
        }
    } else {
        if(selectedDoor[chosen] == doors[chosen])
        {
            return true;
        }
        return false;
    }
}