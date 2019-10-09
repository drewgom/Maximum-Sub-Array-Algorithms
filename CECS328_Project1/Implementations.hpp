//
//  Implementations.hpp
//  CECS328_Project1
//
//  Created by Andrew Gomez on 10/7/19.
//  Copyright © 2019 Andrew Gomez. All rights reserved.
//

#ifndef Implementations_hpp
#define Implementations_hpp

#include <stdio.h>

// I used this constant to represent negative infinity becuase our algorithms
// work on arrays of integers, and this is the smallest value that can be
// stored in the integer data type.
const int NEGATIVE_INFINITY = -2147483648;


int Solution1(int arr[], int size);
int Solution2(int arr[], int size);
int Solution3(int arr[], int left, int right);
int Solution3_find_max_crossing(int arr[], int left, int mid, int right);
int Solution4(int arr[], int size);
#endif
