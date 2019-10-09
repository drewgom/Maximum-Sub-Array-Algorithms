// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19


#include <iostream>
#include "Implementations.hpp"

using namespace std;

int main() {
    int test[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size_of_test = 8;
    int max = 0;
    
    max= Solution1(test, size_of_test);
    cout << "The maximum subarray from 1 is: " << max << endl;
    
    max= Solution2(test, size_of_test);
    cout << "The maximum subarray from 2 is: " << max << endl;
    
    max= Solution3(test, 0, size_of_test-1);
    cout << "The maximum subarray from 3 is: " << max << endl;
    
    max= Solution4(test, size_of_test);
    cout << "The maximum subarray from 2 is: " << max << endl;
    
    return 0;
}
