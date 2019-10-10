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
    
    string testd  = "This is our test";
    MenuOption testop(testd, &testfunction);
    testop.runOperation();
    
    
    
    
    
    
    
    Timer testTimer;
    int test[] = { -2, -3, 4, -1, -2,
                    1, 5, -3, 3, 4,
                    5, -4, 6, -3, 8,
                    4, -6, -2, 1, -3,
                    9, -7, -1, 1, 2
    };
    int size_of_test = 25;
    int max = 0;
    
    testTimer.start_timer();
    max= MSS1(test, size_of_test);
    testTimer.stop_timer();
    cout << "The maximum subarray from SOLUTION 1 is: " << max << endl;
    cout << "The time elapsed by SOLUTION 1 is: " << testTimer.get_time() << " ns" << endl;
    testTimer.reset_timer();
    max = 0;
    
    testTimer.start_timer();
    max= MSS2(test, size_of_test);
    testTimer.stop_timer();
    cout << "The maximum subarray from SOLUTION 2 is: " << max << endl;
    cout << "The time elapsed by SOLUTION 2 is: " << testTimer.get_time() << " ns" << endl;
    testTimer.reset_timer();
    max = 0;
    
    testTimer.start_timer();
    max= MSS3(test, 0, size_of_test-1);
    testTimer.stop_timer();
    cout << "The maximum subarray from SOLUTION 3 is: " << max << endl;
    cout << "The time elapsed by SOLUTION 3 is: " << testTimer.get_time() << " ns" << endl;
    testTimer.reset_timer();
    max = 0;
    
    testTimer.start_timer();
    max= MSS4(test, size_of_test);
    testTimer.stop_timer();
    cout << "The maximum subarray from SOLUTION 4 is: " << max << endl;
    cout << "The time elapsed by SOLUTION 4 is: " << testTimer.get_time() << " ns" << endl;
    testTimer.reset_timer();
    
    
    
    
    return 0;
}


void testfunction() {
    cout << "Hello World" << endl;
}
