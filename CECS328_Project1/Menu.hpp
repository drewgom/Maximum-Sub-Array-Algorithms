// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "MenuOption.hpp"
#include <vector>
#include <string>

using namespace std;

class Menu  {
private:
    int project_number;
    string description;
    string instructions;
    int number_of_menu_options;
    MenuOption *array_of_options;
    
public:
    Menu(int projnum, string desc, string instr, int numofops, MenuOption *arrofops);
    void display_menu();
    
};


#endif
