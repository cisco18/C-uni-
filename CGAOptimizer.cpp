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
    return solution;
}


void CGAOptimizer::runInstance(string filename, int columns) {
    CMax3SatProblem cMax3SatProblem(filename);
    this->columns = columns;
    this->filename = filename;
    createSpecies(population);
    for (int i = 0; i < population; ++i) {
        species.at(i).fitnes = cMax3SatProblem.calculateQuality(species.at(i), columns);
    }
}

void CGAOptimizer::createSpecies(int numberOfSpecies) {
    for (int i = 0; i < numberOfSpecies; ++i) {
        CGAIndividual speciman(createRandomSolution());
        this->species.push_back(speciman);

    }


}



CGAIndividual CGAOptimizer::chooseParent() {
    CGAIndividual parent1;
    CGAIndividual parent2;
    bool rng;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, species.size()-1); // define the range
    parent1 = species.at(distr(gen));
    parent2 = species.at(distr(gen));
    if (parent1.fitnes >= parent2.fitnes) {
        return parent1;
    }
    return parent2;

}

void CGAOptimizer::runIteration() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100);
    vector<CGAIndividual> newPopulation;
    while (newPopulation.size() < species.size()) {
        CGAIndividual parent1 = chooseParent();
        CGAIndividual parent2 = chooseParent();
        CGAIndividual child1(parent1, parent2);
        CGAIndividual child2(parent1, parent2);
        int rng = distr(gen);
        if (chanceOfMutation<rng){
            child1.mutate();
        }
        rng = distr(gen);
        if (chanceOfMutation<rng){
            child2.mutate();
        }
        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }

    species = newPopulation;

    CMax3SatProblem cMax3SatProblem(filename);

    cout << species.size() << " AAAAAAAAAA";


    for (int i = 0; i < species.size(); ++i) {
        species.at(i).fitnes = cMax3SatProblem.calculateQuality(species.at(i), columns);
    }


}

void CGAOptimizer::printPopulation(){
    for (auto & specie : species) {
        cout << specie.fitnes << "\n";
    }
}


