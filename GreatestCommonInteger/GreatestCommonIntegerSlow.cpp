/*******************************************************************************
 * Program: Greatest Common Divisor (GCD) - Naive Implementation
 * 
 * Purpose: 
 * Finds the largest number that divides both input integers using brute force.
 * 
 * Time Complexity: O(min(a,b))
 * - Checks all numbers from 1 to min(a,b)
 * - Inefficient for large numbers
 * 
 * Example:
 * Input: 20 15
 * Output: GCD(20, 15) = 5
 * 
 * Note: For better performance, I am using Euclidean algorithm in next version.
 * 
 * Author: [Nouman Zahid]
 * Date: September 7, 2025
 ******************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int best = 0;
    for (int d = 1; d <= min(a, b); d++) {
        if (a % d == 0 && b % d == 0) {
            best = d;
        }
    }
    return best;
}

int main() {
    int a;
    int b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    return 0;
}