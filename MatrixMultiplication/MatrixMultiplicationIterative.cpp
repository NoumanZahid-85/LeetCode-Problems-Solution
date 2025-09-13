#include <iostream>
using namespace std;
/*
 * Matrix Multiplication Program
 * ---------------------------
 * This program implements matrix multiplication for two matrices:
 * - Matrix A of size m x n
 * - Matrix B of size n x p
 * - Resulting Matrix C of size m x p 
 * Time Complexity: O(m*n*p)
 * Space Complexity: O(m*p)
 */

#define MAX_SIZE 10

void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultiply(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int m, int n, int p) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;  
            for(int k = 0; k < n; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int m, n, p;

    // Input dimensions
    cout << "Enter dimensions of first matrix (m x n): ";
    cin >> m >> n;
    cout << "Enter dimensions of second matrix (n x p): ";
    cin >> p;

    // Input matrices
    cout << "\nEnter elements of first matrix:\n";
    inputMatrix(A, m, n);
    
    cout << "\nEnter elements of second matrix:\n";
    inputMatrix(B, n, p);

    // Multiply matrices
    matrixMultiply(A, B, C, m, n, p);

    // Display results
    cout << "\nFirst Matrix:\n";
    displayMatrix(A, m, n);
    
    cout << "\nSecond Matrix:\n";
    displayMatrix(B, n, p);
    
    cout << "\nResult Matrix:\n";
    displayMatrix(C, m, p);

    return 0;
}