// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    int count = v.size();
    if (count < 2) return true;

    bool rising = false;
    int i = 0;

    // Ignore starting repeated values
    while (i < (count - 1) && v[i] == v[i + 1])
        i++;
    if (i == (count - 1))  // All values are the same
        return true;

    // First slope
    if (v[i] < v[i + 1])
        while (i < (count - 1) && v[i] <= v[i + 1])
            i++;
    else
        while (i < (count - 1) && v[i] >= v[i + 1])
            i++;
    if (i == (count - 1))
        return true;  // Monotonic sequence

    // Second slope
    if (v[i] < v[i + 1])
        while (i < (count - 1) && v[i] <= v[i + 1])
            i++;
    else
        while (i < (count - 1) && v[i] >= v[i + 1])
            i++;
    if (i == (count - 1))
        return true;  // Bitonic sequence

    // Third slope
    if (v[i] < v[i + 1]) {
        rising = true;
        while (i < (count - 1) && v[i] <= v[i + 1])
            i++;
    } else {
        rising = false;
        while (i < (count - 1) && v[i] >= v[i + 1])
            i++;
    }
    if (i < (count - 1))
        return false;  // Not a bitonic sequence because there is a 4th slope

    // 3 slopes
    if (rising && v[i] <= v[0])  // The last rising slope is the same as the first slope
        return true;
    if (!rising && v[i] >= v[0])  // The last falling slope is the same as the first slope
        return true;
    return false;  // The third slope is different from the first one (there is a 4th slope)
}

// Main function
int main(){
   // Test data: vector and expected result
    std::vector<std::pair<std::vector<int>, bool>> test_cases = {
        {{1, 2, 5, 4, 3}, true},
        {{1, 1, 1, 1, 1}, true},
        {{3, 4, 5, 2, 2}, true},
        {{3, 4, 5, 2, 4}, false},
        {{1, 2, 3, 4, 5}, true},
        {{1, 2, 3, 1, 2}, false},
        {{5, 4, 6, 2, 6}, false},
        {{5, 4, 3, 2, 1}, true},
        {{5, 4, 3, 2, 6}, true},
        {{5, 4, 6, 5, 4}, false},
        {{5, 4, 6, 5, 5}, true}
    };

    int passed = 0;
    int total = test_cases.size();

    for (int i = 0; i < total; i++) {
        std::vector<int> vec = test_cases[i].first;
        bool expected = test_cases[i].second;
        bool result = is_bitonic(vec);

        std::cout << "Test " << (i + 1) << ": ";
        std::cout << "{ ";
        for (int j = 0; j < vec.size(); j++) {
            std::cout << vec[j];
            if (j < vec.size() - 1) std::cout << ", ";
        }
        std::cout << " } -> ";
        std::cout << (result ? "Yes" : "No");
        std::cout << " (Expected: " << (expected ? "Yes" : "No") << ") ";
        
        if (result == expected) {
            std::cout << "[PASS]";
            passed++;
        } else {
            std::cout << "[FAIL]";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Results: " << passed << "/" << total << " tests passed." << std::endl << std::flush;
    return 0;
}
