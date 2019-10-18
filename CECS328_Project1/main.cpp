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
    
    string step_1_description  = "Acts as what the main function was";
    string step_2_description = "";
    string step_3_description = "";
    string quit_description = "Quit the application";
    MenuOption op1(step_1_description, &Step1);
    MenuOption op2(step_2_description, &Step2);
    MenuOption op3(step_3_description, &Step3);
    MenuOption op4(quit_description, &Quit);
    
    op3.runOperation();
    
    return 0;
}
