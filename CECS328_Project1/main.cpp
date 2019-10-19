// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#include <iostream>
#include "MenuOption.hpp"
#include "Implementations.hpp"
#include "Timer.hpp"
#include "Menu.hpp"


using namespace std;

int main() {
    
    // I created this in this format so that for future projects,
    // I can simply create a new menu and pass in the needed parameters
    string proj_1_description = "MAXIMUM SUB-ARRAY PROJECT";
    string proj_1_intruction = "Please enter the number of your desired menu option:";
    
    // The descriptions of each menu
    string step_1_description  = "Runs each MSS algorithm on a user entered array";
    string step_2_description = "Runs each MSS algorithm on a random array on a size determined by the user ";
    string step_3_description = "Runs a MSS algorithm on an input of size m and predicts the time for input of n";
    string quit_description = "Quits the application";
    
    MenuOption op1(step_1_description, &Step1);
    MenuOption op2(step_2_description, &Step2);
    MenuOption op3(step_3_description, &Step3);
    MenuOption op4(quit_description, &Quit);
    
    // Creates a list of all the menu options
    MenuOption listOfOptions[] = {op1, op2, op3, op4};
    // Makes a new table object
    Menu Project1Menu(1, proj_1_description, proj_1_intruction, 4, listOfOptions);
    Project1Menu.display_menu();


    return 0;
}
