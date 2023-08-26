#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    char playAgain;

    do
    {
        int randomNumber = rand() % 100 + 1;
        int userGuess, attempts = 0;

        cout <<endl<< "Welcome to the Number Guessing Game!"<<endl;
        cout << "Try to guess the number between 1 and 100."<<endl;

        do
        {
            cout << "Enter your guess: ";
            cin >> userGuess;

            attempts++;

            if (userGuess < randomNumber)
            {
                cout << "Too low! Try again."<<endl;
            }
            else if (userGuess > randomNumber)
            {
                cout << "Too high! Try again."<<endl;
            }
            else
            {
                cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts."<<endl;
            }

        } while (userGuess != randomNumber);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout <<endl<< "Thanks for playing! Goodbye."<<endl;

    return 0;
}
