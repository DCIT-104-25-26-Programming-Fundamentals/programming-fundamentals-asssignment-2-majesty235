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
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& title) {
    cout << "\n" << title << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int total = 0;
            for (int k = 0; k < colsA; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

void partA_transpose() {
    cout << "\n--- Part A: Transpose a Matrix ---" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols, result);

    printMatrix(matrix, rows, cols, "Original Matrix:");
    printMatrix(result, cols, rows, "Transposed Matrix:");
}

void partB_addition() {
    cout << "\n--- Part B: Add Two Matrices ---" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "\nMatrix A:" << endl;
    readMatrix(matrixA, rows, cols);

    cout << "\nMatrix B:" << endl;
    readMatrix(matrixB, rows, cols);

    addMatrices(matrixA, matrixB, rows, cols, result);

    printMatrix(matrixA, rows, cols, "Matrix A:");
    printMatrix(matrixB, rows, cols, "Matrix B:");
    printMatrix(result, rows, cols, "Sum (A + B):");
}

void partC_multiplication() {
    cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A (= rows of Matrix B): ";
    cin >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "\nMatrix A:" << endl;
    readMatrix(matrixA, m, n);

    cout << "\nMatrix B:" << endl;
    readMatrix(matrixB, n, p);

    multiplyMatrices(matrixA, matrixB, m, n, p, result);

    printMatrix(matrixA, m, n, "Matrix A:");
    printMatrix(matrixB, n, p, "Matrix B:");
    printMatrix(result, m, p, "Product (A x B):");
}

int main() {
    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;

    int choice;
    cout << "Choose an operation (1-3): ";
    cin >> choice;

    if (choice == 1) {
        partA_transpose();
    } else if (choice == 2) {
        partB_addition();
    } else if (choice == 3) {
        partC_multiplication();
    } else {
        cout << "Error: Invalid choice." << endl;
    }

    return 0;
}