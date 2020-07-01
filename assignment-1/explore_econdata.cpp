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
using namespace std;

/*
 */
int main(int argc, char** argv) {
    // goal: input and output file reader
    
    // what do you need to read the data in?
    int numStates;
    int selection;
    
    // we created a ifstream here at this point
    ifstream infile;
    
    infile.open(argv[1]);
    
    // condition for checking file
    if (infile.fail()) {
        cout << "The file failed to open. Check the argument you inputted. \n";
        return 1;
    }
    
    // check: print out the numStates
    infile >> numStates;
    cout << "numStates:" << numStates << " \n";
    
    // created states here
    struct state *states = allocate_states(numStates);
    
    // loop here to read all states
    for (int i = 0; i < numStates; i++) {
        // read the state, store
        read_state_data(states,i,infile);
        
        // creating the counties in the states
        states[i].counties = allocate_counties(states[i].numCounties);
        
        // read the county data here
        read_county_data(states[i].counties,states[i].numCounties,infile);
    }
    
    // Create a MENU of selection that can be chosen by the user
    
    
    

    infile.close();
    
    
    return 0;
}
