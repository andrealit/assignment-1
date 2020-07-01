//
//  econdata.hpp
//  assignment-1
//
//  Created by Andrea Tongsak on 6/29/20.
//  Copyright © 2020 Andrea Tongsak. All rights reserved.
//

#ifndef TONGSAK_ECONDATA_HPP
#define TONGSAK_ECONDATA_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct county {
    string name;
    float unemployed2007;
    float unemployed2015;
    int medianIncome;
};

struct state {
    string name;
    float unemployed2007;
    float unemployed2015;
    int medianIncome;
    struct county* counties;
    int numCounties;
};

// allocates an array of a specified number of states
struct state* allocate_states(int);
// reads data for a specified number of states from input file stream into an array
void read_state_data(struct state*,int,ifstream&);
// allocates an array of a specified number of states from an input file
struct county* allocate_counties(int);
// reads data fo a specified number of counties from an input
void read_county_data(struct county*, int, ifstream&);
// releases all data allocated to given array. call function to make sure any allocated data is freed before the program exits
void free_state_data(struct state*, int);

// returns which county has the highest income
void highIncome(struct state*,int);

// returns which county has the lowest income
void lowIncome(struct state*,int);

// returns which county has the highest unemployment
void highUnemployment(struct state*,int);

// returns which county has the lowest unemployment
void lowUnemployment(struct state*, int);

// sorts the state by the unemployment rates
void employSort(struct state*, int);

// sorts
void incomeSort(struct state*, int);
void countyEmploySort(struct state*, int);
void countyIncomeSort(struct state*, int);


#endif /* econdata_hpp */
