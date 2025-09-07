#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

/*******************************************************************************
 * Program: Maximum Pairwise Product with Stress Testing
 * 
 * Purpose: 
 * This program implements and tests two algorithms for finding the maximum 
 * product of two distinct elements in an array:
 * 1. Naive solution (MaxPairwiseProduct) - O(n²)
 * 2. Optimized solution (MaxPairwiseProductFast) - O(n)
 * 
 * Stress Testing:
 * - Generates random test cases automatically
 * - Compares results from both algorithms
 * - Helps identify edge cases and verify correctness
 * 
 * Input Format:
 * - First line: Integer n (size of array)
 * - Second line: n integers (array elements)
 * 
 * Output Format:
 * - Maximum pairwise product of two distinct elements
 * 
 * Example:
 * Input:
 *   5
 *   1 2 3 4 5
 * Output:
 *   20    // (4 * 5 = 20)
 * 
 * Stress Test Output Example:
 *   6           // Random size
 *   1234 5678 910 1112 1314 1516  // Random array
 *   OK          // Test passed
 *   8           // Next test case
 *   ...
 * 
 * Time Complexity:
 * - Naive Solution: O(n²)
 * - Fast Solution: O(n)
 * 
 * Space Complexity: O(1) additional space
 * 
 * Author: [Nouman Zahid]
 * Date: September 7, 2025
 ******************************************************************************/

long long MaxPairwiseProduct(const vector<int>& numbers){
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long)numbers[i] * numbers[j]) > result) {
                result = ((long long)numbers[i] * numbers[j]);
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;

    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;

    return ((long long)numbers[max_index1] * numbers[max_index2]);
}

int main() {
    while (true) {
        int n = rand() % 10 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << "\n";

        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);

        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else {
            cout << "OK\n";
        }
    }
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}