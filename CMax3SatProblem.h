//
// Created by cisco on 04.01.2022.
//

#ifndef MINIPROJEKT_CMAX3SATPROBLEM_H
#define MINIPROJEKT_CMAX3SATPROBLEM_H

#include <iostream>
#include <vector>
#include "CGAIndividual.h"

using namespace std;

class CMax3SatProblem {

public:
    string fileContent;

    CMax3SatProblem(string fileName);

    string load(string fileName);

    static vector<bool> createRandomSolution();

    bool two_dimensional_table(string ***table2d, int rows, int columns);

    bool twoDimensionalTableDealocate(string **table2d, int rows, int columns);

    int calculateQuality(CGAIndividual dude, int columns);

    vector<bool> solution;
private:


};


#endif //MINIPROJEKT_CMAX3SATPROBLEM_H
