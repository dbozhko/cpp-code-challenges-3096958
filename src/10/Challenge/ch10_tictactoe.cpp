// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

#define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // Write your code here and comment out the definition of TWO_PLAYERS above

    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char oldgame_state(char game[][3]){

    // Write your code here
    char winner = ' ';
    int empty_count = 0;
    // Check diagonals
    if(game[0][0]==game[1][1] && game[1][1]==game[2][2] && game[0][0]!=' ')
        winner= game[0][0];
    if(game[0][2]==game[1][1] && game[1][1]==game[2][0] && game[0][2]!=' ')
        winner= game[0][2];

    for(int i=0; i<3 && winner==' '; i++){
        // Check rows and columns
        if(game[i][0]==game[i][1] && game[i][1]==game[i][2] && game[i][0]!=' ')
            winner= game[i][0];
        if(game[0][i]==game[1][i] && game[1][i]==game[2][i] &&  game[0][i]!=' ')
            winner= game[0][i];
        // Count empty cells
        for(int j=0; j<3; j++){
            if(game[i][j]==' ')
                empty_count++;
        }
    }
    if(winner!=' ')
        return winner;
    if(empty_count==0)
        return 't';
    return 'a';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int notmain(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(oldgame_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(oldgame_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << oldgame_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
