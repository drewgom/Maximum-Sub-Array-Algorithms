// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#include <iostream>
#include <string>
#include <sstream>
#include "Implementations.hpp"
#include "Timer.hpp"

#include <algorithm>
using namespace std;


// MSS IMPLEMENTATION 1: Bad Brute Force Implementation
// This implementation is the simplest. All this algorithm does is goes through
// every element, and checks every sub array that starts with that element.
// It also has a for loop that iterates over every element to add its value to the
// current sub array being tested.
// ESTIMATED RUN TIME: O(n^3)

int MSS1(int arr[], int size) {
    int max_sum = NEGATIVE_INFINITY;
    
    
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



// MSS IMPLEMENTATION 2: Good(?) Brute Force Implementation
// This implementation is the same as IMPLEMENATION 1, except it adds the values
// continually as it iterates through each subarray. This allows for there to be
// one less for loop.
// ESTIMATED RUN TIME: O(n^2)

int MSS2(int arr[], int size)  {
    int max_sum = NEGATIVE_INFINITY;
    
    
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




// MSS IMPLEMENTATON 3: Divide and Conquer
// This implementation relys on two functions:
//      1. MSS3
//      2. MSS3_find_max_crossing()
// The first function recursively finds the maximum subarray that spans between
// 2 indices. The second function takes in two arguments: The left subarray and
// the right subarray.
// ESTIMATED RUN TIME: O(n lg(n))

int MSS3(int arr[], int left, int right) {
    
    
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
    int max_from_left = MSS3(arr, left, mid);
    
    // Gets the maximum subarray from the right side
    int max_from_right = MSS3(arr, mid+1, right);
    
    // Gets the maximum subarray that crosses over the the the index of middle
    int max_from_middle = MSS3_find_max_crossing(arr, left, mid, right);
    
    // Whichever of those three is largest has to be the largest subarray from left to right
    return max( max(max_from_left, max_from_right), max_from_middle);
    
}


int MSS3_find_max_crossing(int arr[], int left, int mid, int right)    {
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



// MSS IMPLEMENTATON 4: Clever Solution
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

int MSS4(int arr[], int size)  {
    int max_sum = NEGATIVE_INFINITY;
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



// INTRUCTIONS STEP 1: Takes in a comma-delimited array of integers, and
// prints out the MSS from each function
void Step1()    {
    string comma_delimited_array;
    
    // Gets the list of integers and saves it as a string - since, to my
    // knowledge, that is the only way to do this
    cout << "Please enter a comma-delimited array of integers:" << endl;
    getline(cin,comma_delimited_array);
    int *arrayofvalues = NULL;
    int size_of_array = 0;
    get_array_of_ints(comma_delimited_array, arrayofvalues, size_of_array);
    
    // Here, we run each of the MSS functions.
    
    int max = 0;
    max= MSS1(arrayofvalues, size_of_array);
    cout << "The maximum subarray from SOLUTION 1 is: " << max << endl;
    max = 0;
    
    max= MSS2(arrayofvalues, size_of_array);
    cout << "The maximum subarray from SOLUTION 2 is: " << max << endl;
    max = 0;
    
    max= MSS3(arrayofvalues, 0, size_of_array-1);
    cout << "The maximum subarray from SOLUTION 3 is: " << max << endl;
    max = 0;
    
    max= MSS4(arrayofvalues, size_of_array);
    cout << "The maximum subarray from SOLUTION 4 is: " << max << endl;
    
    
    
    delete arrayofvalues;
}

void Step2()   {
    
    
}


void Step3()    {
    
}

void Quit()    {
    exit(0);
}


void get_array_of_ints(string comma_sep_string, int* &values, int &sizeofarr)   {
    
    // I need to use a string stream to get the data out of the string directly,
    // Since I don't know its exact size.
    stringstream stream_of_raw_text(comma_sep_string);
    
    // First, I find the number of commas. I did this because if there
    // is n commas, then there are n+1 numbers.
    sizeofarr = 1;
    for(char i; stream_of_raw_text >> i;) {
        if(i == ',')    {
            sizeofarr++;
        }
    }
    
    // Now, I need to put all of the integers into an array
    values = new int[sizeofarr];
    
    // After I have the array, I know that I can have a new string where it adds
    // every integer to a string, and then knows that it needs to terminate once
    // it hits a comma.
    
    stringstream second_stream_of_raw_text(comma_sep_string);
    for(int i = 0; i < sizeofarr; i++)   {
        // current_number_as_a_string is a string that adds all the characters
        // that need to be in the next number. For example, if the next number
        // in the array is 123, then current_number_as_a_string will be "", then
        // "1" after the first pass of the loop, then "12" after the second pass,
        // then "123" after the third pass. Once it is in this state, then we can
        // convert it into an int.
        
        // I was having trouble getting the loop to detect the charcter '\0'. However,
        // the terminating character for a string stream is saved as -1, so I was able
        // to simply use that
        
        string current_number_as_a_string = "";
        while (second_stream_of_raw_text.peek() != ',' && second_stream_of_raw_text.peek() != -1) {
            char tempchar;
            second_stream_of_raw_text >> tempchar;
            current_number_as_a_string.append(1,tempchar);
        }
        // If the while loop ended, and the next character is ',' then we still
        // want to run the code
        if (second_stream_of_raw_text.peek() == ',')    {
            char throwaway;
            second_stream_of_raw_text >> throwaway;
        }
        
        // Here, we convert current_number_as_a_string into an int, and add it to
        // the array.
        values[i] = stoi(current_number_as_a_string);
    }
    
    
}
