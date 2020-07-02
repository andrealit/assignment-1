//
//  explore_econdata.cpp
//  assignment-1
//
// holds the main function, allows for command line user input and calls the functions in the program
//
//
//  Created by Andrea Tongsak on 6/29/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

// THIS WAS THE CAUSE OF THE ERROR! must be hpp because it's the declaration (cpp defines it)
#include "econdata.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
 * Main program
 */
int main(int argc, char** argv) {
    // Setting program variables
    int numStates;
    int userSelect;
    string line;
    
    // create and open infile
    ifstream infile;
    infile.open("test_0.txt");
    
    cout << "Hello, testing reading data from file!" << endl;
    
    // Checking file open
    if (infile.fail()) {
        cout << "The file failed to open. Check the argument you inputted." << endl;
        return 1;
    } else {
        cout << "The file opened!" << endl;
    }
    cout << endl;
    
    // Read and print out the number of states
    getline(infile, line);
    istringstream is1(line);
    is1 >> numStates;
//    cout << "Number of States = " << numStates << endl;
    
    // Create the array to store the states
    struct state *stateArray = allocate_states(numStates);
      
    // loop to go through each state
    for (int i = 0; i < numStates; i++) {

        // read and store the state data
        read_state_data(stateArray,i,infile);
        
        // create the array to store counties
        stateArray[i].counties = allocate_counties(stateArray[i].numCounties);
                
        // read and store county data
        read_county_data(stateArray[i].counties, stateArray[i].numCounties, infile);
        
    }
    
    // print out
//    for (int i = 0; i < numStates; i++) {
//        cout << "State Name = " << stateArray[i].name << endl;
//        cout << "2007 Unemployment % = " << stateArray[i].unemployed2007 << endl;
//        cout << "2015 Unemployment % = " << stateArray[i].unemployed2015 << endl;
//        cout << "Median Income = " << stateArray[i].medianIncome << endl;
//        cout << "Number of Counties = " << stateArray[i].numCounties << endl;
//        cout << endl;
//
//        for (int j = 0; j < stateArray[i].numCounties; j++) {
//
//                    cout << "County Name = " << stateArray[i].counties[j].name << endl;
//                    cout << "2007 Unemployment % = " << stateArray[i].counties[j].unemployed2007 << endl;
//                    cout << "2015 Unemployment % = " << stateArray[i].counties[j].unemployed2015 << endl;
//                    cout << "Median Income = " << stateArray[i].counties[j].medianIncome << endl;
//                    cout << endl;
//        }
//    }

    // WORKS UP TO THIS POINT and reads data
    
    cout << "MENU INTERFACE" << endl;
    cout << "1. Print the state with the highest median household income." << endl;
    cout << "2. Print the state with the lowest median household income." << endl;
    cout << "3. Print the state with the highest unemployment in 2015." << endl;
    cout << "4. Print the state with the lowest unemployment in 2015." << endl;
    cout << "5. Print the states in sorted order by change in unemployment from 2007 to 2015. (Largest decrease then largest increase)" << endl;
    cout << "6. Print the states in sorted order based on median household income." << endl;
    cout << "7. Select a state and then..." << endl;
    cout << "8. Quit the program." << endl;
    cout << endl;
    
    // Display a MENU INTERFACE
    do {
        
        
        cin >> userSelect;
        
        
        // Condition for cin
        if(cin.fail()) {
            // clear data
            // close?
        }
        
        // When selection is made correctly
        if (userSelect > 0 && userSelect <= 8) {
            // switch statement for each case
            
            switch (userSelect) {
                case 1:
                    highIncome(stateArray, numStates);
                    break;
                case 2:
                    lowIncome(stateArray, numStates);
                    break;
                case 3:
                    highUnemployment(stateArray, numStates);
                    break;
                case 4:
                    lowUnemployment(stateArray, numStates);
                    break;
                case 5:
                    employSort(stateArray, numStates);
                    break;

            }
            
            
            
        } else {
            cout << "Select a MENU between 1 to 8." << endl;
        }
        

    } while (userSelect != 8);




    infile.close();


    return 0;
}
