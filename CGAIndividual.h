//
// Created by cisco on 06.01.2022.
//

#ifndef MINIPROJEKT_CGAINDIVIDUAL_H
#define MINIPROJEKT_CGAINDIVIDUAL_H

#include <fstream>
#include <utility>
#include <sstream>
using namespace std;
#include <cstring>
#include <random>
#include "iostream"

class CGAIndividual {


public:

    vector<bool> solution;
    int fitnes;

    CGAIndividual(const vector<bool> solution);

    CGAIndividual(int fileValue);

    CGAIndividual(CGAIndividual mum, CGAIndividual dad, int fileValue, int chanceOfCrossover);


    void mutate(int fileValue);

    int fitness();


private:


};


#endif //MINIPROJEKT_CGAINDIVIDUAL_H
