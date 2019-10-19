// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#ifndef MenuOption_hpp
#define MenuOption_hpp

#include <stdio.h>
#include <string>

using namespace std;


// For the menu options, I store a description of the operation and
// a function pointer to the implementation of the function that should
// be ran once the option is selected
class MenuOption    {
private:
    void (*operation)();
    string description;
public:
    MenuOption(string desc, void (*op)());
    string get_decription();
    void runOperation();
};
#endif 
