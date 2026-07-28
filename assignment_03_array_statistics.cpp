// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


// Function to calculate the sum of all numbers
int calculateSum(int numbers[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    return sum;
}


// Function to calculate the average
double calculateAverage(int numbers[], int size)
{
    int sum = calculateSum(numbers, size);

    return static_cast<double>(sum) / size;
}


// Function to find the maximum number
int findMaximum(int numbers[], int size)
{
    int max = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    return max;
}


// Function to find the minimum number
int findMinimum(int numbers[], int size)
{
    int min = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }

    return min;
}


int main()
{
    int n;

    cout << "How many numbers? ";
    cin >> n;


    // Check if number of inputs is valid
    if (n <= 0)
    {
        cout << "Error: Please enter a positive integer." << endl;
        return 1;
    }


    int numbers[100];


    // Getting numbers from user
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }


    // Calling functions
    int sum = calculateSum(numbers, n);
    double average = calculateAverage(numbers, n);
    int maximum = findMaximum(numbers, n);
    int minimum = findMinimum(numbers, n);


    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;


    return 0;
}
