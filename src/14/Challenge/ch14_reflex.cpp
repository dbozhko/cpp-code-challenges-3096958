// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    std::srand(std::time(nullptr));
    do{
        // Write your code here
        // Generate a random delay between 4 and 10 seconds
        int delay = std::rand() % 10 + 4; // Random delay between 4 and 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(delay));
        // Select a random word from the list
        std::string selected_word = words[std::rand() % 10];
        std::cout << "Type the word: " << selected_word << std::endl;
        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();
        // Get user input
        std::string user_input;
        std::getline(std::cin, user_input);
        // Stop the timer
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the time taken
        std::chrono::duration<double> elapsed = end - start;
        // Check if the input is correct and within 2 seconds
        std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
        if (user_input == selected_word && elapsed.count() <= 2.0) {
            std::cout << "Success! You typed the word correctly in " << elapsed.count() << " seconds." << std::endl;
        } else {
            std::cout << "Failure! ";
            if (user_input != selected_word) {
                std::cout << "The correct word was \"" << selected_word << "\". ";
            }
            if (elapsed.count() > 2.0) {
                std::cout << "You took " << elapsed.count() << " seconds, which is too long." << std::endl;
            }
        }

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
