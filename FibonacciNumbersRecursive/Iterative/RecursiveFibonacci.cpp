#include <iostream>
using namespace std;

/*******************************************************************************
 * Program: Recursive Fibonacci Number Calculator
 * 
 * Purpose: 
 * Calculates the nth Fibonacci number using a recursive approach.
 * This implementation demonstrates the concept of recursion but is not 
 * efficient for large values of n due to repeated calculations.
 * 
 * Time Complexity: O(2ⁿ)
 * - Exponential time complexity
 * - Each function call spawns two more recursive calls
 * - Very inefficient for large values of n
 * - For n > 40, computation time becomes noticeably slow
 * 
 * Space Complexity: O(n)
 * - Due to recursive call stack depth
 * 
 * Example running times on typical hardware:
 * n = 20: ~1ms
 * n = 30: ~10ms
 * n = 40: ~1second
 * n = 50: ~2minutes
 * 
 * Author: [Nouman Zahid]
 * Date: September 7, 2025
 ******************************************************************************/
int fibonacci(int n){
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);    
}

int main(){
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    return 0;
}