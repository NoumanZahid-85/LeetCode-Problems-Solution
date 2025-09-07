/*******************************************************************************
 * Program: Greatest Common Divisor (GCD) - Euclidean Algorithm
 * 
 * Purpose: 
 * Efficiently calculates the GCD of two integers using Euclidean algorithm.
 * 
 * Algorithm:
 * - Uses repeated division with remainder
 * - GCD(a,b) = GCD(b, a mod b)
 * - Continues until remainder is 0
 * 
 * Time Complexity: O(log min(a,b))
 * - Logarithmic time complexity
 * - Much faster than naive approach
 * - Efficient even for very large numbers
 * 
 * Example:
 * Input: 48 18
 * Output: GCD(48, 18) = 6
 * Steps: (48,18) → (18,12) → (12,6) → (6,0) = 6
 * 
 * Author: [Nouman Zahid]
 * Date: September 7, 2025
 ******************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a;
    int b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    return 0;
}