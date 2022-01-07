//
// Created by cisco on 06.01.2022.
//

#include "CGAIndividual.h"
#include <random>

/*
void CGAIndividual::crossOver(CGAIndividual partner) {
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(nums, nums + 9, std::mt19937(std::random_device()()));
    CGAIndividual child;
    for (int i = 0; i < 5; ++i) {
        int temp = nums[i];
        for (int j = 0; j < 10; ++j) {
            this->solution.at(temp + j) = this->solution.at(temp + j);
        }
    }
    for (int i = 5; i < 10; ++i) {
        int temp = nums[i];
        for (int j = 0; j < 10; ++j) {
            this->solution.at(temp + j) = partner.solution.at(temp + j);
        }
    }
}

 */


void CGAIndividual::mutate() {
    int rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 9); // define the range
    rng = distr(gen);

    for (int i = 0; i < 10; ++i) {
        solution.at(rng * 10 + i) = !solution.at(rng * 10 + i);
    }


}

int CGAIndividual::fitness() {
    return fitnes;
}

CGAIndividual::CGAIndividual() {
    for (int i = 0; i < 100; ++i) {
        solution.push_back(0);
    }
}

CGAIndividual::CGAIndividual(CGAIndividual mum, CGAIndividual dad) {
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(nums, nums + 9, std::mt19937(std::random_device()()));
    CGAIndividual child;
    for (int i = 0; i < 5; ++i) {
        int temp = nums[i];
        for (int j = 0; j < 10; ++j) {
            // WYWALA BŁĄD TUTAJ
            child.solution.at(temp * 10 + j) = dad.solution.at(temp * 10 + j);
        }
    }
    for (int i = 5; i < 10; ++i) {
        int temp = nums[i];
        for (int j = 0; j < 10; ++j) {
            if (!(i == 9 && j == 9)) {
                child.solution.at(temp * 10 + j) = mum.solution.at(temp * 10 + j);
            }
        }
    }
    solution = child.solution;
}

CGAIndividual::CGAIndividual(const vector<bool> solution) {
    this->solution = solution;
    fitnes = 0;
}






