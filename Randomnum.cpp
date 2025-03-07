#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Seed random number generator
    int randomNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    std::cout << "Guess a number between 1 and 100: ";
    
    while (true) {
        std::cin >> guess;
        
        if (guess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            break;
        }
    }
    
    return 0;
}
