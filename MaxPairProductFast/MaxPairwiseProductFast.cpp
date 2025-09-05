#include <iostream>
#include <vector>

using std::vector;
using std::cin;    
using std::cout;

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();
    
    /*Here I find the first max index in the Array of Integers*/
    int first_max_index = -1;
    for (int i = 0; i < n; ++i) {
        if (first_max_index == -1 || numbers[i] > numbers[first_max_index]) {
            first_max_index = i;
        }
    }
    /*Here I find the second max index in the Array of Integers*/
    int second_max_index = -1;
    for (int j = 0; j < n; ++j) {
        if (j != first_max_index && (second_max_index == -1 || numbers[j] > numbers[second_max_index])) {
            second_max_index = j;
        }
    }
    return (long long)numbers[first_max_index] * numbers[second_max_index];
}

int main(){
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