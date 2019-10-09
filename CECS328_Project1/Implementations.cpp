//
//  Implementations.cpp
//  CECS328_Project1
//
//  Created by Andrew Gomez on 10/7/19.
//  Copyright © 2019 Andrew Gomez. All rights reserved.
//

#include "Implementations.hpp"
#include <algorithm>
using namespace std;


// IMPLEMENTATION 1: Bad Brute Force Implementation
// This implementation is the simplest. All this algorithm does is goes through
// every element, and checks every sub array that starts with that element.
// It also has a for loop that iterates over every element to add its value to the
// current sub array being tested.
// ESTIMATED RUN TIME: O(n^3)

int Solution1(int arr[], int size) {
    int max_sum = 0;
    
    
    for (int i = 0; i < size; i++) {
        
        for (int j = i; j < size; j++)  {
            int this_sum = 0;
            
            // Adds all the element that are in the rest of the array
            for(int k = i; k<=j; k++)   {
                this_sum += arr[k];
            }
            
            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    
    return max_sum;
}



// IMPLEMENTATION 2: Good(?) Brute Force Implementation
// This implementation is the same as IMPLEMENATION 1, except it adds the values
// continually as it iterates through each subarray. This allows for there to be
// one less for loop.
// ESTIMATED RUN TIME: O(n^2)

int Solution2(int arr[], int size)  {
    int max_sum = 0;
    
    
    for (int i = 0; i < size; i++) {
        int this_sum = 0;
        
        for (int j = i; j < size; j++)  {
            this_sum += arr[j];
            
            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    
    return max_sum;
}




// IMPLEMENTATON 3: Divide and Conquer
// This implementation relys on two functions:
//      1. Solution3
//      2. Solution3_find_max_crossing()
// The first function recursively finds the maximum subarray that spans between
// 2 indices. The second function takes in two arguments: The left subarray and
// the right subarray.
// ESTIMATED RUN TIME: O(n lg(n))

int Solution3(int arr[], int left, int right) {
    
    
    // BASE CASE 1: If left and right are equal
    if (left == right)  {
        return arr[left];
    }
    
    // BASE CASE 2: If left and right are next to each other
    if (left == right - 1)  {
        
        // max is called twice becuase it takes only two arguments. So, I take the maximum
        // of arr[left] and arr[right], and then the maximum of that and arr[left] + arr[right]
        return max( max(arr[left],arr[right]) , arr[left] + arr[right]);
    }
    

    // If there is more than two terms, then we have to do the divide and conquer portion
    int mid = (left+right)/2;
    
    // Gets the maximum subarray from the left side
    int max_from_left = Solution3(arr, left, mid);
    
    // Gets the maximum subarray from the right side
    int max_from_right = Solution3(arr, mid+1, right);
    
    // Gets the maximum subarray that crosses over the the the index of middle
    int max_from_middle = Solution3_find_max_crossing(arr, left, mid, right);
    
    // Whichever of those three is largest has to be the largest subarray from left to right
    return max( max(max_from_left, max_from_right), max_from_middle);
    
}


int Solution3_find_max_crossing(int arr[], int left, int mid, int right)    {
    int max_left_sum = NEGATIVE_INFINITY;
    int max_right_sum = NEGATIVE_INFINITY;
    int sum;
    
    
    // This finds the maximum sub array between left and mid that MUST INCLUDE
    // the element arr[mid]
    sum = 0;
    for (int i = mid; i>=left; i--) {
        sum += arr[i];
        
        if(sum > max_left_sum)  {
            max_left_sum = sum;
        }
    }
    
    // This finds the maximum sub array between mid+1 and right that MUST INCLUDE
    // the element arr[mid+1]
    sum = 0;
    for (int i = mid+1; i<=right; i++) {
        sum += arr[i];
        
        if(sum > max_right_sum)  {
            max_right_sum = sum;
        }
    }
    
    // Since max_left_sum and max_right_sum will always include the
    // points arr[mid] and arr[mid+1] respectively, we do in fact know that
    // their sum is the maximum crossing function. So, we return that sum
    return max_left_sum + max_right_sum;
}



// IMPLEMENTATON 4: Clever Solution
// The clever solution works by realizing that for whatever value the
// maximum subarray starts on, that sum of all the previous elements in
// the array has to be less than or equal to 0.
// It iterates through every variable, and adds the value of the current element.
// If adding the current element makes it largert than the maximum so far, then we make
// that the new maximum. Otherwise, we just move on.
// Next, if the current sum is less than 0, we know that the maximum subarray does not
// start on any of the elements in the array before the one we are currently on, so we
// can just reassign that to 0.
// ESTIMATED RUN TIME: O(n)

int Solution4(int arr[], int size)  {
    int max_sum = 0;
    int current_sum = 0;
    
    // Iterates through the whole list, and checks the two conditions
    for(int i = 0; i < size; i++)  {
        
        current_sum += arr[i];
        
        // Checks to see if the new sum is the maximum
        if(current_sum > max_sum)   {
            max_sum = current_sum;
        }
        
        // Sets the current sum to zero if the current sum is less than zero, becuase
        // we know that the maximum will not start at any of the previous values if
        // that is the case
        else if (current_sum < 0)  {
            current_sum = 0;
        }
    }
    
    return max_sum;
}
