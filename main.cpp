#include <iostream>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"

int main() {

/*
    CGAOptimizer cgaOptimizer(50, 2, 90);
    cgaOptimizer.runInstance("/home/cisco/CLionProjects/miniprojekt/50/m3s_50_0.txt", 213, 50);
    cgaOptimizer.runIterationMultiple(50,100);
    cout << "\nHighest found solution is: " ;
    cgaOptimizer.findHighestSolution();

*/


    CGAOptimizer cgaOptimizer(100, 2, 90);
    cgaOptimizer.runInstance("/home/cisco/CLionProjects/miniprojekt/100/m3s_100_0.txt", 427, 100);
    cgaOptimizer.runIterationMultiple(100,30);
    cout << "\nHighest found solution is: " ;
    cgaOptimizer.findHighestSolution();



/*
    CGAOptimizer cgaOptimizer2(300, 1, 90);
    cgaOptimizer2.runInstance("/home/cisco/CLionProjects/miniprojekt/350/m3s_350_0.txt", 1494, 350);
    cgaOptimizer2.runIterationMultiple(350,70);
    cout << "\nHighest found solution is: " ;
    cgaOptimizer2.findHighestSolution();
*/

}
