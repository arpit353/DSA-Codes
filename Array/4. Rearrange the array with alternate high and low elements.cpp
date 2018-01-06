#include <iostream>
using namespace std;

/*

Given an array of integers, rearrange the array such that every second element of the array is greater than its left and right elements. Assume no duplicate elements are present in the array.

For example,

Input:  {1, 2, 3, 4, 5, 6, 7}
Output: {1, 3, 2, 5, 4, 7, 6}

Input:  {9, 6, 8,3, 7}
Output: {6, 9, 3, 8, 7}

Input:  {6, 9, 2, 5, 1, 4}
Output: {6, 9, 2, 5, 1, 4}

*/

/*

In this code we have to make a sequence of alternative numbers. We can solve this by taking every even positioned element as the highest of the three(one left and one on right.) If we do this with every even positioned element we can solve this question.

*/


// Function to rearrange the array such that every second element 
// of the array is greater than its left and right elements
void rearrangeArray(int arr[], int n)
{
    // start from second element and increment index
    // by 2 for each iteration of loop
    for (int i = 1; i < n; i += 2) 
    {
        // If the prev element is greater than current element, 
        // swap the elements
        if (arr[i - 1] > arr[i])
            swap(arr[i - 1], arr[i]);
 
        // if next element is greater than current element, 
        // swap the elements
        if (i + 1 < n && arr[i + 1] > arr[i])
            swap(arr[i + 1], arr[i]);
    }
}
 
// main function
int main()
{
    int arr[] = { 9, 6, 8, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    rearrangeArray(arr, n);
 
    // print output array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}