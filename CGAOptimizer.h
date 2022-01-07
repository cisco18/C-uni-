//
// Created by cisco on 06.01.2022.
//

#ifndef MINIPROJEKT_CGAOPTIMIZER_H
#define MINIPROJEKT_CGAOPTIMIZER_H

#include <fstream>
#include <utility>
#include <sstream>
#include "CMax3SatProblem.h"
#include <cstring>
#include <random>

class CGAOptimizer {
public:
    CGAOptimizer(int population, int chanceOfMutation, int chanceOfCrossover);

    int columns;
    string filename;
    int population;
    int chanceOfMutation;
    int chanceOfCrossover;
    vector<CGAIndividual> species;

    void assignSpecies(initializer_list<CGAIndividual>);

    void runIteration();

    void addASpeciman(CGAIndividual);

    void createSpecies(int numberOfSpecies);

    void runInstance(string filename, int columns);

    void printPopulation();
private:
    CGAIndividual chooseParent();


};


#endif //MINIPROJEKT_CGAOPTIMIZER_H
