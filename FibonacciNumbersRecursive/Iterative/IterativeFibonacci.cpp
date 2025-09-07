#include <iostream>
using namespace std;

/*******************************************************************************
 * Program: Iterative Fibonacci Number Calculator
 * 
 * Purpose: 
 * Calculates the nth Fibonacci number using an iterative approach.
 * This implementation is significantly more efficient than the recursive version
 * as it avoids repeated calculations.
 * 
 * Algorithm:
 * - Uses three variables (a, b, c) to track fibonacci sequence
 * - Iteratively updates values without recursion
 * - Maintains only the last two numbers needed for next calculation
 * 
 * Time Complexity: O(n)
 * - Linear time complexity
 * - Single pass through loop from 2 to n
 * - Highly efficient even for large values of n
 * 
 * Space Complexity: O(1)
 * - Constant space usage
 * - Only three variables needed regardless of input size
 * 
 * Example running times on typical hardware:
 * n = 20: <1ms
 * n = 30: <1ms
 * n = 40: <1ms
 * n = 50: <1ms
 * 
 * Author: [Nouman Zahid]
 * Date: September 7, 2025
 ******************************************************************************/

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}