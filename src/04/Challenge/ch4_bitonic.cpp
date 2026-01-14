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
    
    int n = v.size();
    if (n < 3) return true; // Sequences with less than 3 elements are bitonic by definition
    
    // Check each possible rotation
    //int start = 0;
    for (int start = 0; start < n; start++) 
    {
        int i = 0;
        bool is_valid = true;
        
        // Ascending phase (using modulo for circular shift)
        while (i < n - 1 && v[(start + i) % n] <= v[(start + i + 1) % n]) {
            i++;
        }
        
        // If we reached the end, it's monotonic increasing
        if (i == n - 1) return true;
        
        // Descending phase
        while (i < n - 1 && v[(start + i) % n] >= v[(start + i + 1) % n]) {
            i++;
        }
        
        // If we reached the end with this rotation, it's bitonic
        if (i == n - 1) return true;
    }
    
    return false;
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
