//
// Created by cisco on 04.01.2022.
//

#include <fstream>
#include <utility>
#include <sstream>
#include "CMax3SatProblem.h"
#include <cstring>
#include <random>


string CMax3SatProblem::load(string fileName) {
    ifstream myfile;
    char temp;
    myfile.open(fileName);
    if (myfile.is_open()) {
        while (myfile.good()) {// always check whether the file is open
            temp = myfile.get();
            // pipe stream's content to standard output
            fileContent = fileContent + temp;
        }
    }
    myfile.close();
    //std::cout << fileContent;
    return fileContent;
}
/*

vector<bool> createRandomSolution() {
    vector<bool> solution;
    bool rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 1); // define the range

    for (int i = 0; i < 99; ++i) {
        rng = distr(gen);
        solution.push_back(rng);
    }
    for (int i = 0; i < 99; ++i) {
        cout << solution.at(i);
    }
    return solution;
}

*/
//vector<bool> solution
int CMax3SatProblem::calculateQuality(CGAIndividual dude, int columns) {

    std::stringstream stringStream(fileContent);
    string to;
    string **twoDthings = nullptr;
    two_dimensional_table(&twoDthings, 3, columns);

    if (!fileContent.empty()) {
        int b = 0;
        int a = 0;
        while (std::getline(stringStream, to, ' ')) {
            if (!to.empty() && to != "(" && to != ")") {
                if (a == 3) {
                    a = 0;
                    b++;
                }
                if ((to.find("(") == string::npos || to.find(")") == string::npos) && b < columns) {
                    twoDthings[a][b] = to;
                    a++;
                }
            }
        }
    }
    int quality = 0;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < 3; ++j) {
            int tempSol = stoi(twoDthings[j][i]);
            if (dude.solution.at(tempSol + 49) == 1) {
                quality++;
                j = 3;
            }
        }
    }
    cout << "\nquality: " << quality;
    dude.fitnes = quality;
    twoDimensionalTableDealocate(twoDthings, 3, columns);


    return quality;
}

CMax3SatProblem::CMax3SatProblem(string fileName) {
    load(fileName);

}


bool CMax3SatProblem::two_dimensional_table(string ***table2d, int rows, int columns) {
    if (rows <= 0 || columns <= 0) {
        std::cout << "Input a positive size" << std::endl;
        return false;
    }

    (*table2d) = new string *[rows];
    for (int i = 0; i < rows; i++) {
        (*table2d)[i] = new string[columns];
    }
    return true;

}


bool CMax3SatProblem::twoDimensionalTableDealocate(string **table2d, int rows, int columns) {
    if (rows <= 0 || columns <= 0) {
        std::cout << "Wrong size" << std::endl;
        return false;
    }
    for (int i = 0; i < rows; i++) {
        delete[] (table2d)[i];
    }

    delete[] table2d;
    table2d = NULL;
    return true;
}