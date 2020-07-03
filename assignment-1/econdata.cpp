/*
 Program Filename: ECONDATA.cpp
 Author: ANDREA TONGSAK
 Date: 05.29.20
 Description: Specific file used for housing the I/O assignment. Take in a file as command line arguments. Next, sort data that users can look through.
 Input: Integers, Infiles, Structs
 Output: Deletion of Memory Structs, File Reading
 */

#include "econdata.hpp"

// the implementations of the functions prototyped in econdata.hpp

/*
 * Function: CreateStates
 * Description: Will allocate space for state struct by creating an array
 * Parameters: Takes in an integer from file in for size
 * Pre-Conditions: Can only operate with file input
 * Post-Conditions: Returns a set array
 */
// The symbol "*" is used to display the content of the memory location pointed to.
struct state* allocate_states(int numStates) {
    struct state* stateArray = new state[numStates];
    return stateArray;
}

/*
 * Function: allocate_counties
 * Description: Will allocate space for counties struct by creating an array
 * Parameters: Takes in an integer from file in for size
 * Pre-Conditions: Can only operate with file input
 * Post-Conditions: Returns a set array
 *
 */
struct county* allocate_counties(int numCounties) {
    struct county* countyArray = new struct county[numCounties];
    return countyArray;
}

/*
 * Function: read_state_data
 * Description: using ifstream to funnel data into the array
 * Parameters: takes the struct, the number of the state, and the ifstream
 * Pre-Conditions: must have a struct state present
 * Post-Conditions: must be deleted after to prevent data chaos
 */
void read_state_data(struct state *stateArray, int numStates, ifstream &infile) {
    
    string line;
    
    // assign the read state data to members of the array
        getline(infile, line);
        istringstream is2(line);
        is2 >> stateArray[numStates].name >> stateArray[numStates].unemployed2007 >> stateArray[numStates].unemployed2015 >> stateArray[numStates].medianIncome >> stateArray[numStates].numCounties;
    
    
}

/*
* Function: read_county_data
* Description: using ifstream to funnel data into the array
* Parameters: takes the struct, the number of counties, and the ifstream
* Pre-Conditions: must have a struct state present
* Post-Conditions: no data left out, should be deleted
*/
void read_county_data(struct county *countyArray, int numCounties, ifstream &infile){
    
    string line;
    
    for (int i = 0; i < numCounties; i++) {
        
        getline(infile, line);
        istringstream is3(line);
        is3 >> countyArray[i].name >> countyArray[i].unemployed2007 >> countyArray[i].unemployed2015 >> countyArray[i].medianIncome;
        
    }
}

/*
* Function: free_state_data
* Description: releases all the data to the given array (memory clear)
* Parameters: takes the struct, the number of states
* Pre-Conditions: memory exists
* Post-Conditions: none
*/
void free_state_data(struct state *stateInput, int numStates) {
    // using the loop to clear each state one by one here
    for (int i = 0; i<numStates; i++) {
        // clear the data here
        delete [] stateInput[i].counties;
    }
    delete [] stateInput;
}

/*
 * Function: highIncome
 * Description: sorts to find which state has the higher income
 * Parameters: takes in the state, the number of states
 * Preconditions: the selection must be selected
 * Postconditions: none
 */
void highIncome(struct state *stateInput, int numStates) {
    
    // Variables
    string stateName;
    float maxIncome = stateInput[0].medianIncome;
    int tempInt = 0;

    stateName = stateInput[0].name;

    for(int i = 1; i < numStates; i++) {
        // must check if the next one is greater or less than the current?
        if(stateInput[tempInt].medianIncome < stateInput[i].medianIncome) {
            // order needs to switch
            stateName = stateInput[i].name;
            maxIncome = stateInput[i].medianIncome;
            tempInt = i;
        }
    }

    cout << "State with Highest Median Income \n";
    cout << "State Name: " << stateName << endl;
    cout << "Median Income: " << maxIncome << endl;
    cout << endl;
}

/*
 * Function: lowIncome
 * Description: sorts to find which state has the lowest income
 * Parameters: takes in the state, the number of states
 * Preconditions: the selection must be selected
 * Postconditions: none
 */
void lowIncome(struct state *stateInput, int numStates) {
    string stateName;
    float minIncome = stateInput[0].medianIncome;
    int tempInt = 0;

    stateName = stateInput[0].name;

    for(int i = 1; i < numStates; i++) {
        if(stateInput[tempInt].medianIncome > stateInput[i].medianIncome) {
            // the min state is the next
            stateName = stateInput[i].name;
            minIncome = stateInput[i].medianIncome;
            tempInt = i;
        }
    }

    cout << "State with Lowest Median Income \n";
    cout << "State Name: " << stateName << endl;
    cout << "Median Income: " << minIncome << endl;
    cout << endl;
}

/*
 * Function: highUnemployment
 * Description: sorts to find high unemployment in 2015
 * Parameters: takes in state, the number of states
 * Preconditions: the selection is chosen
 * Postconditions: none
 */
void highUnemployment(struct state* stateInput, int numStates) {
    string stateName;
    float highUnemp = stateInput[0].unemployed2015;
    int tempInt = 0;

    stateName = stateInput[0].name;

    for(int i = 1; i < numStates; i++) {
        
        if(stateInput[tempInt].unemployed2015 < stateInput[i].unemployed2015) {
            // this means they must be switched
            stateName = stateInput[i].name;
            highUnemp = stateInput[i].unemployed2015;
            tempInt = i;
        }
    }

    cout << "State with Highest 2015 Unemployment \n";
    cout << "State Name: " << stateName << endl;
    cout << "2015 Unemployment %: " << highUnemp << endl;
    cout << endl;
}

/*
 * Function: lowUnemployment
 * Description: sorts to find low unemployment in 2015
 * Parameters: takes in state, the number of states
 * Preconditions: the selection is chosen
 * Postconditions: none
 */
void lowUnemployment(struct state* stateInput, int numStates) {
    string stateName;
    float lowUnemp = stateInput[0].unemployed2015;
    int tempInt = 0;

    stateName = stateInput[0].name;

    for(int i = 1; i < numStates; i++) {
        
        if(stateInput[tempInt].unemployed2015 > stateInput[i].unemployed2015) {
            // this means they must be switched
            stateName = stateInput[i].name;
            lowUnemp = stateInput[i].unemployed2015;
            tempInt = i;
        }
    }

    cout << "State with Lowest 2015 Unemployment \n";
    cout << "State Name: " << stateName << endl;
    cout << "2015 Unemployment %: " << lowUnemp << endl;
    cout << endl;
}

/*
* Function: employSort
* Description: print the states in sorted order by change in unemployment from 2007 to 2015
* Parameters: takes in state, the number of states
* Preconditions: the selection is chosen
* Postconditions: none
*/
void employSort(struct state* stateInput, int numStates) {
    string statename;
    
    // outer loop
    for(int i = 0; i < numStates-1; i++) {
        // inner loop
        for(int j = 0; j < numStates-i-1; j++) {
            
            // one is less than the other (so must be switched)
            // EX: SMALLER, BIGGER
            if((stateInput[j].unemployed2007 - stateInput[j].unemployed2015) > (stateInput[j+1].unemployed2007 - stateInput[j+1].unemployed2015)) {
                // store the BIGGER array in temp
                struct state temp = stateInput[j];
                // assign the SMALLER into the previous
                stateInput[j] = stateInput[j+1];
                // assign the BIGGER into the one after the SMALLER
                // EX: BIGGER, SMALLER
                stateInput[j+1] = temp;
            }
        }
    }
    
    cout << "States Sorted by Change in Unemployment (Largest increase to largest decrease)  \n";
    cout << ">>Largest Increase" << endl;
    for (int i = 0; i < numStates; i++) {
        cout << stateInput[i].name << endl;
    }
    cout << ">>Largest Decrease" << endl;
    cout << endl;
}

/*
* Function: incomeSort
* Description: print the states in sorted order by median income
* Parameters: takes in state, the number of states
* Preconditions: the selection is chosen
* Postconditions: none
*/
void incomeSort(struct state* stateInput, int numStates) {
    string statename;
    
    // outer loop
    for(int i = 0; i < numStates-1; i++) {
        // inner loop
        for(int j = 0; j < numStates-i-1; j++) {
            if (stateInput[j].medianIncome < stateInput[j+1].medianIncome) {
                struct state temp = stateInput[j];
                stateInput[j] = stateInput[j+1];
                stateInput[j+1] = temp;
            }
        }
    }
    
    cout << "States Sorted by Median Household Income (High to Low) \n";
    for (int i = 0; i < numStates; i++) {
        cout << "State: " << stateInput[i].name << " Median Income: " << stateInput[i].medianIncome << endl;
    }
    cout << endl;
    
}


/*
* Function: countyFunc
* Description: print the states in sorted order by median income
* Parameters: takes in state, the number of states
* Preconditions: the selection from 7 choices is chosen from menu
* Postconditions: none
*/
void countyFunc(struct state* states, int numStates) {
    // Declare variables
    string statename;
    string countyName;
    float maxIncome = states[0].counties[0].medianIncome;
    float minIncome = states[0].counties[0].medianIncome;
    float highUnemp = states[0].counties[0].unemployed2015;
    float lowUnemp = states[0].counties[0].unemployed2015;;
    int tempInt;
    int countySelect;
    int stateSelect;
    
    // Let the user select a state
    do {
        cout << "Select a state: " << endl;
        
        for (int i = 0; i < numStates; i++) {
            cout << i << "." << states[i].name << endl;
        }
        
        if(cin.fail()) {
            // clear data
            cin.clear();
            cin.ignore();
            cout << "Invalid \n";
        }
        
        cin >> stateSelect;
        
        if(stateSelect < 0 || stateSelect > numStates - 1) {
            cout << "State selection is invalid, try again." << endl;
        }
        
    } while(stateSelect < 0 || stateSelect > (numStates-1));
    
    // Print out the county menu options once a state is selected
    cout << endl;
    cout << "COUNTY MAIN MENU" << endl;
    cout << "1. Print county with highest median income." << endl;
    cout << "2. Print county with lowest median income." << endl;
    cout << "3. Print county with highest unemployment in 2015." << endl;
    cout << "4. Print county with lowest unemployment in 2015." << endl;
    cout << "5. Print the counties in sorted order by change in unemployment from 2007 to 2015. (Largest decrease then largest increase)" << endl;
    cout << "6. Print the county in sorted order based on median household income." << endl;
    cout << endl;
    
    
    // Have the county specific functions for each type
    //do {
        cin >> countySelect;
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        
        if (countySelect > 0 && countySelect <= 6){
            
            switch (countySelect) {
                    
                case 1: { // Print county with highest median income
                    tempInt = 0;
                    countyName = states[stateSelect].counties[0].name;
                    
                    for (int i = 0; i < states[stateSelect].numCounties; i++) {
                        // must check if the next one is greater than the current
                        if (states[stateSelect].counties[tempInt].medianIncome < states[stateSelect].counties[i].medianIncome) {
                            countyName = states[stateSelect].counties[i].name;
                            maxIncome = states[stateSelect].counties[i].medianIncome;
                            tempInt = i;
                        }
                    }
                    cout << "County with Highest Median Income \n";
                    cout << "County Name: " << countyName << endl;
                    cout << "Median Income: " << maxIncome << endl;
                    cout << endl;
                    break;
                }
                    
                case 2: { // Print county with lowest median income
                    tempInt = 0;
                    countyName = states[stateSelect].counties[0].name;
                    
                    for (int i = 0; i < states[stateSelect].numCounties; i++) {
                        // must check if the next one is greater than the current
                        if (states[stateSelect].counties[tempInt].medianIncome > states[stateSelect].counties[i].medianIncome) {
                            countyName = states[stateSelect].counties[i].name;
                            minIncome = states[stateSelect].counties[i].medianIncome;
                            tempInt = i;
                        }
                    }
                    cout << "County with Lowest Median Income \n";
                    cout << "County Name: " << countyName << endl;
                    cout << "Median Income: " << minIncome << endl;
                    cout << endl;
                    break;
                }
                    
                case 3: { // Print county with highest unemployment
                    tempInt = 0;
                    countyName = states[stateSelect].counties[0].name;
                    
                    for (int i = 0; i < states[stateSelect].numCounties; i++) {
                        if (states[stateSelect].counties[tempInt].unemployed2015 < states[stateSelect].counties[i].unemployed2015) {
                            countyName = states[stateSelect].counties[i].name;
                            highUnemp = states[stateSelect].counties[i].unemployed2015;
                            tempInt = i;
                        }
                    }
                    cout << "County with Highest Unemployment \n";
                    cout << "County Name: " << countyName << endl;
                    cout << "2015 Unemployment %: " << highUnemp << endl;
                    cout << endl;
                    break;
                }
                    
                case 4: { // Print county with lowest unemployment
                    tempInt = 0;
                    countyName = states[stateSelect].counties[0].name;
                    
                    for(int i = 0; i < states[stateSelect].numCounties; i++) {
                        if (states[stateSelect].counties[tempInt].unemployed2015 > states[stateSelect].counties[i].unemployed2015) {
                            countyName = states[stateSelect].counties[i].name;
                            lowUnemp = states[stateSelect].counties[i].unemployed2015;
                            tempInt = i;
                        }
                    }
                    cout << "County with Lowest 2015 Unemployment \n";
                    cout << "County Name: " << countyName << endl;
                    cout << "2015 Unemployment %: " << lowUnemp << endl;
                    cout << endl;
                    break;
                }
                    
                case 5: { // Sort county data based on unemployment change
                    // sort until the last one
                    for (int i = 0; i < states[stateSelect].numCounties-1; i++) {
                        // sort the remaining in the list for each index
                        for (int j = 0; j < states[stateSelect].numCounties-i-1; j++) {
                            // THIS WAS THE PROBLEM! Must be thorough.

                            if ((states[stateSelect].counties[j].unemployed2007 - states[stateSelect].counties[j].unemployed2015) > (states[stateSelect].counties[j+1].unemployed2007 - states[stateSelect].counties[j+1].unemployed2015)) {
                                
                                struct county tempC = states[stateSelect].counties[j];
                                states[stateSelect].counties[j] = states[stateSelect].counties[j+1];
                                states[stateSelect].counties[j+1] = tempC;
                            }
                        }
                    }
                    
                    cout << "County Sorted by Change in Unemployment (Largest increase to largest decrease)  \n";
                    cout << ">>Largest Decrease" << endl;
                    for (int i = 0; i < states[stateSelect].numCounties; i++) {
                        cout << states[stateSelect].counties[i].name << endl;
                    }
                    cout << ">>Largest Increase" << endl;
                    cout << endl;
                    break;
                }
                    
                case 6: { // Sort county data based on income
                    // stop before the last county because it should be sorted?
                    for (int i = 0; i < states[stateSelect].numCounties-1; i++) {
                        // sort through the remaining counties
                        for (int j = 0; j < states[stateSelect].numCounties-i-1; j++) {
                            if (states[stateSelect].counties[j].medianIncome > states[stateSelect].counties[j+1].medianIncome) {
                                struct county tempC = states[stateSelect].counties[j];
                                states[stateSelect].counties[j] = states[stateSelect].counties[j+1];
                                states[stateSelect].counties[j+1] = tempC;
                            }
                        }
                    }
                    cout << "County Sorted by Median Household Income (Low to High) \n";
                    for (int i = 0; i < states[stateSelect].numCounties; i++) {
                        cout << "County: " << states[stateSelect].counties[i].name << " Median Income: " << states[stateSelect].counties[i].medianIncome << endl;
                    }
                    cout << endl;
                    break;
                }
            }
            
        } else {
            cout << "Select a county MENU between 1 to 6.";
        }
        
  //  } while (countySelect < 0 || countySelect > 6);
    
}


 
