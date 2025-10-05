#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessNumber(int secret, int player, int totalPlayers) {
    int guess;
    do {
        cout << "Player " << player << ", please enter your guess (1 to 100): ";
        cin >> guess;
    } while (guess < 1 || guess > 100);

    switch ((guess > secret) - (guess < secret)) {
        case 1:
            cout << "Your guess is too high." << endl;
            break;
        case -1:
            cout << "Your guess is too low." << endl;
            break;
        case 0:
            cout << "Well done, Player " << player << "! You guessed correctly!" << endl;
            return;
    }

    int nextPlayer = (player % totalPlayers) + 1;
    guessNumber(secret, nextPlayer, totalPlayers);
}

int main() {
    srand(time(NULL));  

    int secretNumber = rand() % 100 + 1;

    int players;
    cout << "How many players are participating? ";
    cin >> players;

    cout << "Game started! Guess the secret number between 1 and 100." << endl;
    guessNumber(secretNumber, 1, players);

    return 0;
}
