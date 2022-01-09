//
// Created by cisco on 06.01.2022.
//

#include "CGAOptimizer.h"


CGAOptimizer::CGAOptimizer(int population, int chanceOfMutation, int chanceOfCrossover) {
    if (population < 0 || chanceOfCrossover < 0 || chanceOfMutation < 0 || chanceOfMutation > 100 ||
        chanceOfCrossover > 100) {
        throw invalid_argument("received wrong value value, can't create that population");
    } else {
        this->chanceOfCrossover = chanceOfCrossover;
        this->population = population;
        this->chanceOfCrossover = chanceOfCrossover;
    }
}

void CGAOptimizer::assignSpecies(initializer_list<CGAIndividual> species) {
    this->species.assign(species);
}

void CGAOptimizer::addASpeciman(CGAIndividual speciman) {
    this->species.push_back(speciman);
}

vector<bool> createRandomSolution(int numberOfSolutions) {
    vector<bool> solution;
    bool rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 1); // define the range

    for (int i = 0; i < numberOfSolutions; ++i) {
        rng = distr(gen);
        solution.push_back(rng);
    }
    for (int i = 0; i < numberOfSolutions ; ++i) {
        solution.push_back(0);
        solution.at(numberOfSolutions+i) = !solution.at(numberOfSolutions-i-1);
    }
    for (int i = 0; i < solution.size(); ++i) {
        //cout<< solution.at(i);
    }
   // cout << "       ";
    return solution;
}


void CGAOptimizer::runInstance(string filename, int columns, int fileValue) {
    CMax3SatProblem cMax3SatProblem(filename);
    this->columns = columns;
    this->filename = filename;
    createSpecies(population, fileValue);
    for (int i = 0; i < population; ++i) {
        species.at(i).fitnes = cMax3SatProblem.calculateQuality(species.at(i), columns, fileValue);
    }
}

void CGAOptimizer::createSpecies(int numberOfSpecies, int fileValue) {
    for (int i = 0; i < numberOfSpecies; ++i) {
        CGAIndividual speciman(createRandomSolution(fileValue));
        this->species.push_back(speciman);

    }


}


CGAIndividual CGAOptimizer::chooseParent(int fileValue) {
    CGAIndividual parent1(fileValue);
    CGAIndividual parent2(fileValue);
    bool rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, species.size() - 1); // define the range
    parent1 = species.at(distr(gen));
    parent2 = species.at(distr(gen));
    if (parent1.fitnes >= parent2.fitnes) {
        return parent1;
    }
    return parent2;

}

void CGAOptimizer::runIteration(int fileValue) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100);
    vector<CGAIndividual> newPopulation;
    while (newPopulation.size() < species.size()) {
        CGAIndividual parent1 = chooseParent(fileValue);
        CGAIndividual parent2 = chooseParent(fileValue);
        CGAIndividual child1(parent1, parent2, fileValue, chanceOfCrossover);
        CGAIndividual child2(parent1, parent2, fileValue, chanceOfCrossover);
        int rng = distr(gen);
        if (chanceOfMutation < rng) {
            child1.mutate(fileValue);
        }
        rng = distr(gen);
        if (chanceOfMutation < rng) {
            child2.mutate(fileValue);
        }
        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }

    species = newPopulation;

    CMax3SatProblem cMax3SatProblem(filename);

    for (int i = 0; i < species.size(); ++i) {
        species.at(i).fitnes = cMax3SatProblem.calculateQuality(species.at(i), columns, fileValue);
    }


}

void CGAOptimizer::runIterationMultiple(int fileValue, int quantity) {
    for (int i = 0; i < quantity; ++i) {
        runIteration(fileValue);
    }
}

int CGAOptimizer::findHighestSolution() {
    int solution = 0;
    vector<bool> sol;
    for (int i = 0; i < species.size(); ++i) {
        if (species.at(i).fitnes > solution)
            solution = species.at(i).fitnes;
            sol = species.at(i).solution;
    }
    cout << solution<< " ";
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol.at(i);
    }
    return solution;
}


void CGAOptimizer::printPopulation() {
    for (auto &specie: species) {
        cout << specie.fitnes << "\n";
    }
}


