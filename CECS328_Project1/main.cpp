// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19


#include <iostream>
#include "MenuOption.hpp"
#include "Implementations.hpp"
#include "Timer.hpp"


using namespace std;

void testfunction();

int main() {
    
    string testd  = "Acts as what the main function was";
    MenuOption testop(testd, &Step1);
    MenuOption testop2(testd, &Step2);
    testop2.runOperation();
    
    return 0;
}
