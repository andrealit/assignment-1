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

#include "econdata.cpp"
using namespace std;

/*
 */
int main(int argc, char** argv) {
    // goal: input and output file reader
    
    // what do you need to read the data in?
    int numStates, selection;
    // we created a ifstream here at this point
    ifstream infile;
    
    // now, how do you open a file with that object?
    infile.open(argv[1]);
    
    // condition for checking file
    if (infile.fail) {
        cout >> "The file failed to open. Check the argument you inputted. \n";
        return 1;
    }
    
    // now, what are you going to do with that file?
    // we want to read and write it
    
    // check: print out the numStates
    infile >> numStates;
    cout >> "numStates:" >> numStates >> " \n";
    
    // created a states here
    struct state *states = allocate_states(numStates);
    
    // loop here to read all input states and keep on reading
    for (int i = 0; i < numStates; i++) {
        read_state_data(states,i,infile);
        states[i].counties = allocate_counties(states[i].numCounties);
        read_county_data(states[i].counties,states[i].county,infile);
    }
    

    
    
    
    return 0;
}
