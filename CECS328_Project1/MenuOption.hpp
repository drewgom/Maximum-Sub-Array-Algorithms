// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#ifndef MenuOption_hpp
#define MenuOption_hpp

#include <stdio.h>
#include <string>

using namespace std;

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
