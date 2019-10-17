// Name: Andrew Gomez
// Class: CECS328
// Project: Project 1
// Due Date: 10/18/19

#ifndef Implementations_hpp
#define Implementations_hpp

#include <stdio.h>

using namespace std;
// I used this constant to represent negative infinity becuase our algorithms
// work on arrays of integers, and this is the smallest value that can be
// stored in the integer data type.
const int NEGATIVE_INFINITY = -2147483648;


int MSS1(int arr[], int size);
int MSS2(int arr[], int size);
int MSS3(int arr[], int left, int right);
int MSS3_find_max_crossing(int arr[], int left, int mid, int right);
int MSS4(int arr[], int size);
void Step1();
void Step2();
void Step3();
void Quit();
void get_array_of_ints_from_string(string comma_sep_string, int* &values, int &sizeofarr, bool is_delimeter);
void get_random_array(int* &rand_array, int size_of_rand_array);

#endif
