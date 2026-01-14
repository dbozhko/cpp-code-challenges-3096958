// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    if (knight.length() != 2) {
        return moves; // Invalid input length
    }
    
    char file = knight[0];
    char rank = knight[1];

    // Knight moves are L-shaped: 2 squares in one direction and 1 square perpendicular
    // Possible moves: (file ±2, rank ±1) and (file ±1, rank ±2)
    // Check all 8 possible knight moves
    if (file >= 'a' && file <= 'h' && rank >= '1' && rank <= '8') {
        // Move 2 files right, 1 rank up
        if (file + 2 <= 'h' && rank + 1 <= '8')
            moves.push_back(std::string(1, file + 2) + std::string(1, rank + 1));
        // Move 2 files right, 1 rank down
        if (file + 2 <= 'h' && rank - 1 >= '1')
            moves.push_back(std::string(1, file + 2) + std::string(1, rank - 1));

        // Move 2 files left, 1 rank up
        if (file - 2 >= 'a' && rank + 1 <= '8')
            moves.push_back(std::string(1, file - 2) + std::string(1, rank + 1));
        // Move 2 files left, 1 rank down
        if (file - 2 >= 'a' && rank - 1 >= '1')
            moves.push_back(std::string(1, file - 2) + std::string(1, rank - 1));

        // Move 2 ranks up, 1 file right
        if (rank + 2 <= '8' && file + 1 <= 'h')
            moves.push_back(std::string(1, file + 1) + std::string(1, rank + 2));
        // Move 2 ranks up, 1 file left
        if (rank + 2 <= '8' && file - 1 >= 'a')
            moves.push_back(std::string(1, file - 1) + std::string(1, rank + 2));

        // Move 2 ranks down, one file right
        if (rank - 2 >= '1' && file + 1 <= 'h')
            moves.push_back(std::string(1, file + 1) + std::string(1, rank - 2));
        // Move 2 ranks down one file left
        if (rank - 2 >= '1' && file - 1 >= 'a')
            moves.push_back(std::string(1, file - 1) + std::string(1, rank - 2));
    }
    return moves;
}

// Test helper function
bool validate_knight_moves(std::string position, const std::vector<std::string>& expected_moves) {
    auto actual_moves = knight_moves(position);
    
    // Check if sizes match
    if (actual_moves.size() != expected_moves.size()) {
        return false;
    }
    
    // Check if all expected moves are present (order doesn't matter)
    for (const auto& expected : expected_moves) {
        bool found = false;
        for (const auto& actual : actual_moves) {
            if (actual == expected) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// Main function
int main(){
    // All 64 board positions with their expected knight moves
    std::vector<std::pair<std::string, std::vector<std::string>>> test_cases = {
        // Corners (2 moves each)
        {"a1", {"b3", "c2"}},
        {"a8", {"b6", "c7"}},
        {"h1", {"f2", "g3"}},
        {"h8", {"f7", "g6"}},
        
        // Edge positions adjacent to corners (3 moves each)
        {"a2", {"b4", "c3", "c1"}},
        {"a7", {"b5", "c6", "c8"}},
        {"b1", {"a3", "c3", "d2"}},
        {"b8", {"a6", "c6", "d7"}},
        {"g1", {"e2", "f3", "h3"}},
        {"g8", {"e7", "f6", "h6"}},
        {"h2", {"f1", "f3", "g4"}},
        {"h7", {"f6", "f8", "g5"}},
        
        // Edge positions near corners (4 moves each)
        {"a3", {"b1", "b5", "c2", "c4"}},
        {"a6", {"b4", "b8", "c5", "c7"}},
        {"c1", {"a2", "b3", "d3", "e2"}},
        {"c8", {"a7", "b6", "d6", "e7"}},
        {"f1", {"d2", "e3", "g3", "h2"}},
        {"f8", {"d7", "e6", "g6", "h7"}},
        {"h3", {"f2", "f4", "g1", "g5"}},
        {"h6", {"f5", "f7", "g4", "g8"}},
        
        // More edge positions (6 moves each)
        {"a4", {"b2", "b6", "c3", "c5"}},
        {"a5", {"b3", "b7", "c4", "c6"}},
        {"b2", {"a4", "c4", "d1", "d3"}},
        {"b7", {"a5", "c5", "d6", "d8"}},
        {"g2", {"e1", "e3", "f4", "h4"}},
        {"g7", {"e6", "e8", "f5", "h5"}},
        {"h4", {"f3", "f5", "g2", "g6"}},
        {"h5", {"f4", "f6", "g3", "g7"}},
        
        // Edge positions (6 moves each)
        {"a1", {"b3", "c2"}},  // Already covered above
        {"b3", {"a1", "a5", "c1", "c5", "d2", "d4"}},
        {"b4", {"a2", "a6", "c2", "c6", "d3", "d5"}},
        {"b5", {"a3", "a7", "c3", "c7", "d4", "d6"}},
        {"b6", {"a4", "a8", "c4", "c8", "d5", "d7"}},
        {"g3", {"e2", "e4", "f1", "f5", "h1", "h5"}},
        {"g4", {"e3", "e5", "f2", "f6", "h2", "h6"}},
        {"g5", {"e4", "e6", "f3", "f7", "h3", "h7"}},
        {"g6", {"e5", "e7", "f4", "f8", "h4", "h8"}},
        
        // Interior positions (8 moves each)
        {"c2", {"a1", "a3", "b4", "d4", "e1", "e3"}},
        {"c3", {"a2", "a4", "b1", "b5", "d1", "d5", "e2", "e4"}},
        {"c4", {"a3", "a5", "b2", "b6", "d2", "d6", "e3", "e5"}},
        {"c5", {"a4", "a6", "b3", "b7", "d3", "d7", "e4", "e6"}},
        {"c6", {"a5", "a7", "b4", "b8", "d4", "d8", "e5", "e7"}},
        {"c7", {"a6", "a8", "b5", "d5", "e6", "e8"}},
        {"d2", {"b1", "b3", "c4", "e4", "f1", "f3"}},
        {"d3", {"b2", "b4", "c1", "c5", "e1", "e5", "f2", "f4"}},
        {"d4", {"b3", "b5", "c2", "c6", "e2", "e6", "f3", "f5"}},
        {"d5", {"b4", "b6", "c3", "c7", "e3", "e7", "f4", "f6"}},
        {"d6", {"b5", "b7", "c4", "c8", "e4", "e8", "f5", "f7"}},
        {"d7", {"b6", "b8", "c5", "e5", "f6", "f8"}},
        {"e2", {"c1", "c3", "d4", "f4", "g1", "g3"}},
        {"e3", {"c2", "c4", "d1", "d5", "f1", "f5", "g2", "g4"}},
        {"e4", {"c3", "c5", "d2", "d6", "f2", "f6", "g3", "g5"}},
        {"e5", {"c4", "c6", "d3", "d7", "f3", "f7", "g4", "g6"}},
        {"e6", {"c5", "c7", "d4", "d8", "f4", "f8", "g5", "g7"}},
        {"e7", {"c6", "c8", "d5", "f5", "g6", "g8"}},
        {"f2", {"d1", "d3", "e4", "g4", "h1", "h3"}},
        {"f3", {"d2", "d4", "e1", "e5", "g1", "g5", "h2", "h4"}},
        {"f4", {"d3", "d5", "e2", "e6", "g2", "g6", "h3", "h5"}},
        {"f5", {"d4", "d6", "e3", "e7", "g3", "g7", "h4", "h6"}},
        {"f6", {"d5", "d7", "e4", "e8", "g4", "g8", "h5", "h7"}},
        {"f7", {"d6", "d8", "e5", "g5", "h6", "h8"}},
    };

    // Negative test cases: invalid positions (out of board)
    std::vector<std::pair<std::string, std::vector<std::string>>> negative_test_cases = {
        {"i1", {}},      // File out of bounds (too far right)
        {"a9", {}},      // Rank out of bounds (too high)
        {"z5", {}},      // File out of bounds (too far)
        {"b0", {}},      // Rank out of bounds (too low)
        {"A1", {}},      // Invalid case (uppercase should not match)
        {"e$", {}},      // Invalid character
        {"", {}},        // Empty string
        {"e", {}},       // Incomplete position
        {"33", {}}      // Numeric input
    };

    int passed = 0;
    int total = test_cases.size() + negative_test_cases.size();
    int failed_tests = 0;

    std::cout << "Running Knight Moves Unit Tests" << std::endl;
    std::cout << "===============================" << std::endl << std::endl;
    
    std::cout << "POSITIVE TEST CASES (Valid Positions)" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    for (int i = 0; i < test_cases.size(); i++) {
        std::string position = test_cases[i].first;
        std::vector<std::string> expected_moves = test_cases[i].second;
        
        bool test_passed = validate_knight_moves(position, expected_moves);
        
        std::cout << "Test " << (i + 1) << " - Position " << position << ": ";
        auto actual_moves = knight_moves(position);
        std::cout << actual_moves.size() << " moves ";
        
        if (test_passed) {
            std::cout << "[PASS]" << std::endl;
            passed++;
        } else {
            std::cout << "[FAIL]" << std::endl;
            std::cout << "  Expected: ";
            for (const auto& move : expected_moves) 
                std::cout << move << " ";
            std::cout << std::endl << "  Got:      ";
            for (const auto& move : actual_moves) 
                std::cout << move << " ";
            std::cout << std::endl;
            failed_tests++;
        }
    }

    std::cout << std::endl << "NEGATIVE TEST CASES (Invalid Positions)" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    for (int i = 0; i < negative_test_cases.size(); i++) {
        std::string position = negative_test_cases[i].first;
        std::vector<std::string> expected_moves = negative_test_cases[i].second;
        
        bool test_passed = validate_knight_moves(position, expected_moves);
        
        std::cout << "Test " << (test_cases.size() + i + 1) << " - Position \"" << position << "\": ";
        auto actual_moves = knight_moves(position);
        std::cout << actual_moves.size() << " moves ";
        
        if (test_passed) {
            std::cout << "[PASS]" << std::endl;
            passed++;
        } else {
            std::cout << "[FAIL]" << std::endl;
            std::cout << "  Expected: (no moves)" << std::endl;
            std::cout << "  Got:      ";
            for (const auto& move : actual_moves) 
                std::cout << move << " ";
            std::cout << std::endl;
            failed_tests++;
        }
    }

    std::cout << std::endl << "===============================" << std::endl;
    std::cout << "Results: " << passed << "/" << total << " tests passed." << std::endl;
    if (failed_tests > 0) {
        std::cout << "Failed: " << failed_tests << " tests" << std::endl;
    }
    std::cout << std::endl << std::flush;
    
    return 0;
}