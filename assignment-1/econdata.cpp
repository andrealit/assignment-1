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

struct state* allocate_states(int n) {
    struct state* states = new state[n];
    return states;
}

/*
 * Function: allocate_counties
 * Description: Will allocate space for counties struct by creating an array
 * Parameters: Takes in an integer from file in for size
 * Pre-Conditions: Can only operate with file input
 * Post-Conditions: Returns a set array
 *
 */
struct county* allocate_counties(int n) {
    struct county* counties = new struct county[n];
    return counties;
}

/*
 * Function: read_state_data
 * Description: using ifstream to funnel data into the array
 * Parameters: takes the struct, the number of the state, and the ifstream
 * Pre-Conditions: must have a struct state present
 * Post-Conditions: must be deleted after to prevent data chaos
 */
void read_state_data(struct state *s, int numState, ifstream &file) {
    file >> s[numState].name
    >> s[numState].unemployed2007
    >> s[numState].unemployed2015
    >> s[numState].medianIncome
    >> s[numState].numCounties;
}

/*
* Function: read_county_data
* Description: using ifstream to funnel data into the array
* Parameters: takes the struct, the number of counties, and the ifstream
* Pre-Conditions: must have a struct state present
* Post-Conditions: no data left out, should be deleted
*/
void read_county_data(struct county *c, int numCounties, ifstream &file){
    for (int i = 0; i < numCounties; i++) {
        file >> c[i].name
        >> c[i].unemployed2007
        >> c[i].unemployed2015
        >> c[i].medianIncome;
    }
}

///*
//* Function: free_state_data
//* Description: releases all the data to the given array (memory clear)
//* Parameters: takes the struct, the number of states
//* Pre-Conditions: memory exists
//* Post-Conditions: none
//*/
//void free_state_data(struct state *stateInput, int numStates) {
//    // using the loop to clear each state one by one here
//    for (int i = 0; i<numStates; i++) {
//        // clear the data here
//        delete [] stateInput[i].counties;
//    }
//    delete [] stateInput;
//}

/*
 * Function: highIncome
 * Description: sorts to find which state has the higher income
 * Parameters: takes in the state, the number of states
 * Preconditions: the selection must be selected
 * Postconditions: none
 */
//void highIncome(struct state *stateInput, int numStates) {
//    // use a loop here? the sort algorithm?
//
//    // what variables do you need here?
//    // name, the income data
//    string stateName;
//    float incomeData;
//    int tempInt = 0;
//
//    stateName = stateInput[0].name;
//
//    // loop is going through each state
//    // starting from 1 because the first value in data is actually the number of the states (so irrelevant)
//    for(int i = 1; i < numStates; ++i) {
//        // must check if the next one is greater or less than the next?
//        if(stateInput[tempInt].medianIncome < stateInput[i].medianIncome) {
//            // order needs rearranging
//            stateName = stateInput[i].name;
//            incomeData = stateInput[i].medianIncome;
//            tempInt = i;
//        }
//    }
//
//    cout << "\n State with Highest Median Income \n";
//    cout << "name: " << stateName << "\n";
//    cout << "median income: " << incomeData << "\n";
//}
//
///*
// * Function: lowIncome
// * Description: sorts to find which state has the lowest income
// * Parameters: takes in the state, the number of states
// * Preconditions: the selection must be selected
// * Postconditions: none
// */
//void lowIncome(struct state *stateInput, int numStates) {
//    string stateName;
//    float incomeData;
//    int tempInt = 0;
//
//    stateName = stateInput[0].name;
//
//    for(int i = 1; i < numStates; numStates++) {
//        if(stateInput[tempInt].medianIncome > stateInput[i].medianIncome) {
//            // order is already good
//            stateName = stateInput[i].name;
//            tempInt = i;
//        }
//    }
//
//    cout << "\n State with Lowest Median Income \n";
//    cout << "name: " << stateName;
//    cout << "median income: " << incomeData << "\n";
//}

/*
 * Function: highUnemployment
 * Description:
 * Parameters:
 * Preconditions:
 * Postconditions:
 */
//void highUnemployment(struct state *stateInput, int ) {
//    string stateName;
//    float employData;
//    int tempInt = 0;
//
//    stateName = stateInput[0].name;
//
//    for(int i = 1; i < employData; employData++) {
//        if(stateInput[tempInt].unemployed2015 < stateInput[i].unemployed2015) {
//            // this means
//            stateName = stateInput[i].name;
//        }
//    }
//
//    cout << "";
//    cout << "";
//    cout << "";
//}



///*
// * Function: highUnemployment
// * Description:
// * Parameters:
// * Preconditions:
// * Postconditions:
// */
//void employSort() {
//
//}

 
