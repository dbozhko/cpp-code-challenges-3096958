// Unit tests for game_state() function in ch10_tictactoe.cpp
// Tests all possible game outcomes including wins, ties, and active games

#include <iostream>
#include <string>
#include <cassert>

// game_state() from ch10_tictactoe.cpp
char game_state(char game[][3]){
    int empty_count = 0;
    // Check diagonals
    if(game[0][0]==game[1][1] && game[1][1]==game[2][2] && game[0][0]!=' ')
        return game[0][0];
    if(game[0][2]==game[1][1] && game[1][1]==game[2][0] && game[0][2]!=' ')
        return game[0][2];

    for(int i=0; i<3; i++){
        // Check rows and columns
        if(game[i][0]==game[i][1] && game[i][1]==game[i][2] && game[i][0]!=' ')
            return game[i][0];
        if(game[0][i]==game[1][i] && game[1][i]==game[2][i] &&  game[0][i]!=' ')
            return game[0][i];
        // Count empty cells
        for(int j=0; j<3; j++){
            if(game[i][j]==' ')
                empty_count++;
        }
    }
    if(empty_count==0)
        return 't';
    return 'a';
}

// Helper function to initialize a game board
void init_board(char game[][3], const char* config) {
    int idx = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game[i][j] = config[idx++];
        }
    }
}

// Helper function to print game board
void print_test_board(const char game[][3]) {
    std::cout << "\n";
    for(int i = 0; i < 3; i++) {
        std::cout << game[i][0] << " | " << game[i][1] << " | " << game[i][2] << "\n";
        if(i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

int main(){
    char game[3][3];
    int test_count = 0, passed = 0;

    // Test 1: X wins on row 0
    test_count++;
    init_board(game, "XXX      ");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on row 0\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on row 0\n";
        print_test_board(game);
    }

    // Test 2: X wins on row 1
    test_count++;
    init_board(game, "   XXX   ");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on row 1\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on row 1\n";
        print_test_board(game);
    }

    // Test 3: X wins on row 2
    test_count++;
    init_board(game, "      XXX");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on row 2\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on row 2\n";
        print_test_board(game);
    }

    // Test 4: O wins on row 0
    test_count++;
    init_board(game, "OOO      ");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on row 0\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on row 0\n";
        print_test_board(game);
    }

    // Test 5: O wins on row 1
    test_count++;
    init_board(game, "   OOO   ");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on row 1\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on row 1\n";
        print_test_board(game);
    }

    // Test 6: O wins on row 2
    test_count++;
    init_board(game, "      OOO");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on row 2\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on row 2\n";
        print_test_board(game);
    }

    // Test 7: X wins on column 0
    test_count++;
    init_board(game, "X  X  X  ");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on column 0\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on column 0\n";
        print_test_board(game);
    }

    // Test 8: X wins on column 1
    test_count++;
    init_board(game, " X  X  X ");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on column 1\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on column 1\n";
        print_test_board(game);
    }

    // Test 9: X wins on column 2
    test_count++;
    init_board(game, "  X  X  X");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on column 2\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on column 2\n";
        print_test_board(game);
    }

    // Test 10: O wins on column 0
    test_count++;
    init_board(game, "O  O  O  ");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on column 0\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on column 0\n";
        print_test_board(game);
    }

    // Test 11: O wins on column 1
    test_count++;
    init_board(game, " O  O  O ");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on column 1\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on column 1\n";
        print_test_board(game);
    }

    // Test 12: O wins on column 2
    test_count++;
    init_board(game, "  O  O  O");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on column 2\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on column 2\n";
        print_test_board(game);
    }

    // Test 13: X wins on main diagonal (top-left to bottom-right)
    test_count++;
    init_board(game, "X  OX  OX");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on main diagonal\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on main diagonal\n";
        print_test_board(game);
    }

    // Test 14: X wins on anti-diagonal (top-right to bottom-left)
    test_count++;
    init_board(game, "  XOX X O ");
    if(game_state(game) == 'X') {
        std::cout << "✓ Test " << test_count << " PASSED: X wins on anti-diagonal\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: X wins on anti-diagonal\n";
        print_test_board(game);
    }

    // Test 15: O wins on main diagonal
    test_count++;
    init_board(game, "O  XO  XO");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on main diagonal\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on main diagonal\n";
        print_test_board(game);
    }

    // Test 16: O wins on anti-diagonal
    test_count++;
    init_board(game, "  OXO O X ");
    if(game_state(game) == 'O') {
        std::cout << "✓ Test " << test_count << " PASSED: O wins on anti-diagonal\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: O wins on anti-diagonal\n";
        print_test_board(game);
    }

    // Test 17: Tie game - full board with no winner
    test_count++;
    init_board(game, "XXOOOXXOO");
    if(game_state(game) == 't') {
        std::cout << "✓ Test " << test_count << " PASSED: Tie game (full board, no winner)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Tie game\n";
        print_test_board(game);
    }

    // Test 18: Tie game - alternative pattern
    test_count++;
    init_board(game, "OXOXOXXOX");
    if(game_state(game) == 't') {
        std::cout << "✓ Test " << test_count << " PASSED: Tie game (alternating pattern)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Tie game (alternating)\n";
        print_test_board(game);
    }

    // Test 19: Active game - empty board
    test_count++;
    init_board(game, "         ");
    if(game_state(game) == 'a') {
        std::cout << "✓ Test " << test_count << " PASSED: Active game (empty board)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Active game (empty)\n";
        print_test_board(game);
    }

    // Test 20: Active game - partially filled
    test_count++;
    init_board(game, "X  O     ");
    if(game_state(game) == 'a') {
        std::cout << "✓ Test " << test_count << " PASSED: Active game (partially filled)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Active game (partially filled)\n";
        print_test_board(game);
    }

    // Test 21: Active game - almost full but not complete
    test_count++;
    init_board(game, "XXOOXOXO ");
    if(game_state(game) == 'a') {
        std::cout << "✓ Test " << test_count << " PASSED: Active game (one empty cell)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Active game (one empty)\n";
        print_test_board(game);
    }

    // Test 22: No winner with two in a row
    test_count++;
    init_board(game, "XX   OO  ");
    if(game_state(game) == 'a') {
        std::cout << "✓ Test " << test_count << " PASSED: Active game (incomplete rows)\n";
        passed++;
    } else {
        std::cout << "✗ Test " << test_count << " FAILED: Active game (incomplete rows)\n";
        print_test_board(game);
    }

    // Print summary
    std::cout << "\n========== TEST SUMMARY ==========\n";
    std::cout << "Tests passed: " << passed << "/" << test_count << "\n";
    if(passed == test_count) {
        std::cout << "✓ All tests passed!\n";
        return 0;
    } else {
        std::cout << "✗ Some tests failed.\n";
        return 1;
    }
}
