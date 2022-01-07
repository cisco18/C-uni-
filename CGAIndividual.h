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

    CGAIndividual();

    CGAIndividual(CGAIndividual mum, CGAIndividual dad);


    void crossOver(CGAIndividual partner);

    void mutate();

    int fitness();

    vector<bool> assignRandomSolution();

private:


};


#endif //MINIPROJEKT_CGAINDIVIDUAL_H
