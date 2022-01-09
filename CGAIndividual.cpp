//
// Created by cisco on 06.01.2022.
//

#include "CGAIndividual.h"
#include <random>



void CGAIndividual::mutate(int fileValue) {
    int rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 9); // define the range
    rng = distr(gen);

    for (int i = 0; i < fileValue / 5; ++i) {
        solution.at(rng * 10 + i) = !solution.at(rng * 10 + i);
        //solution.at(fileValue - (rng * 10 + i + 1)) = !solution.at(rng * 10 + i);
    }
    for (int i = 0; i < fileValue; ++i) {
        solution.push_back(0);
        solution.at(fileValue + i) = !solution.at(fileValue - i - 1);
    }


}

int CGAIndividual::fitness() {
    return fitnes;
}

CGAIndividual::CGAIndividual(int fileValue) {
    for (int i = 0; i < fileValue * 2; ++i) {
        solution.push_back(0);
    }
}

CGAIndividual::CGAIndividual(CGAIndividual mum, CGAIndividual dad, int fileValue, int chanceOfCrossover) {

    int rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100); // define the range
    rng = distr(gen);

    if (rng < chanceOfCrossover) {

        int nums[fileValue / 10];
        for (int i = 0; i < fileValue / 10; ++i) {
            nums[i] = i;
        }
        shuffle(nums, nums + (fileValue / 10 - 1), std::mt19937(std::random_device()()));
        CGAIndividual child(fileValue);

        for (int i = 0; i < fileValue / 10; ++i) {
            int temp = nums[i];
            for (int j = 0; j < 10; ++j) {
                if (i < fileValue / 20) {
                    child.solution.at(temp * 10 + j) = dad.solution.at(temp * 10 + j);
                } else {
                    child.solution.at(temp * 10 + j) = mum.solution.at(temp * 10 + j);
                }

            }

        }


        for (int i = 0; i < fileValue; ++i) {
            child.solution.at(fileValue + i) = !child.solution.at(fileValue - i - 1);
        }

        solution = child.solution;
    } else solution = mum.solution;

}

CGAIndividual::CGAIndividual(const vector<bool> solution) {
    this->solution = solution;
    fitnes = 0;
}






