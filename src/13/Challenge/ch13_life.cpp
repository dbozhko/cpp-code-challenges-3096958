// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 25
#define M 25

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];
    std::memset(game,'-',N*M); // Initialize game with dashes.
/*
    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    */
    // An R-pentomino   // - - - - - 
    game[11][12]='X';   // - - X X - 
    game[11][13]='X';   // - X X - - 
    game[12][11]='X';   // - - X - - 
    game[12][12]='X';
    game[13][12]='X';

    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        char newgame [N][M];
        //initialize newgame with current game state
        memcpy(newgame,game,N*M);

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                int count = 0;
                //go over all 8 neighbors, but exclude the cell itself
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        //the same cell, skip
                        if (di == 0 && dj == 0)
                            continue;
                        int ni = (i + di + N) % N; //roll over edges
                        int nj = (j + dj + M) % M; //roll over edges
                        if (game[ni][nj] == 'X') 
                            count++;
                    }
                }
                //cell is alive
                if (game[i][j] == 'X')
                {
                    //die - underpopulation or overpopulation
                    if (count < 2 || count > 3)
                        newgame[i][j] = '-';
                }
                else
                {
                    //live - reproduction
                    if (count == 3)
                        newgame[i][j] = 'X';
                }
            }
        }
        //copy newgame back to game
        memcpy(game,newgame,N*M);

        std::cout << "Press Enter for the next generation, or type \"E\"xit: " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("E")!=0);
    
    return 0;
}
