// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



// Function to display a matrix
void displayMatrix(int matrix[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


// Part A: Transpose a matrix
void transposeMatrix(int matrix[][10], int rows, int cols)
{
    cout << "\nTransposed Matrix:" << endl;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(5) << matrix[j][i];
        }
        cout << endl;
    }
}


// Part B: Add two matrices
void addMatrices(int A[][10], int B[][10], int result[][10],
                 int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


// Part C: Multiply two matrices
void multiplyMatrices(int A[][10], int B[][10], int result[][10],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


// Function to input matrix values
void inputMatrix(int matrix[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


int main()
{
    int rows, cols;

    int matrix[10][10];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    // Input first matrix
    inputMatrix(matrix, rows, cols);


    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);


    // Part A
    transposeMatrix(matrix, rows, cols);



    // Part B: Addition

    int matrixB[10][10];
    int additionResult[10][10];


    cout << "\nEnter second matrix for addition:" << endl;

    inputMatrix(matrixB, rows, cols);


    addMatrices(matrix, matrixB, additionResult, rows, cols);


    cout << "\nAddition Result:" << endl;
    displayMatrix(additionResult, rows, cols);



    // Part C: Multiplication

    int rowsB, colsB;

    int multiplyMatrixB[10][10];
    int multiplyResult[10][10];


    cout << "\nEnter rows of second matrix for multiplication: ";
    cin >> rowsB;

    cout << "Enter columns of second matrix for multiplication: ";
    cin >> colsB;


    if (cols != rowsB)
    {
        cout << "Error: Columns of first matrix must equal rows of second matrix."
             << endl;

        return 1;
    }


    cout << "\nEnter second matrix for multiplication:" << endl;

    inputMatrix(multiplyMatrixB, rowsB, colsB);


    multiplyMatrices(matrix, multiplyMatrixB, multiplyResult,
                     rows, cols, colsB);


    cout << "\nMultiplication Result:" << endl;

    displayMatrix(multiplyResult, rows, colsB);


    return 0;
}