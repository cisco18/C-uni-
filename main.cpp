#include <iostream>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"

int main() {
CGAOptimizer cgaOptimizer(100,2,15);
cgaOptimizer.runInstance("/home/cisco/CLionProjects/miniprojekt/50/m3s_50_0.txt", 213);
cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.runIteration();
    cgaOptimizer.printPopulation();


}
