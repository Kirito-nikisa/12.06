#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int secretNumber;
int attempts = 0;


void generateSecretNumber() {
    srand(time(nullptr)); 
    secretNumber = 1000 + rand() % 9000; 
}
void checkGuess(int guess) {
    int bulls = 0, cows = 0;
    int secretCopy = secretNumber;
    int guessCopy = guess;

    for (int i = 0; i < 4; i++) {
        int secretDigit = secretCopy % 10;
        int guessDigit = guessCopy % 10;
        if (secretDigit == guessDigit) {
            bulls++;
        }
        else {
        
            int tempSecretCopy = secretCopy / 10;
            int tempGuessCopy = guessCopy;
            bool found = false;
            for (int j = 0; j < 4; j++) {
                int tempSecretDigit = tempSecretCopy % 10;
                if (tempSecretDigit == guessDigit) {
                    cows++;
                    found = true;
                    break;
                }
                tempSecretCopy /= 10;
            }
            if (!found) {
                tempGuessCopy /= 10;
                for (int j = 0; j < 4; j++) {
                    int tempGuessDigit = tempGuessCopy % 10;
                    if (tempGuessDigit == secretDigit) {
                        cows++;
                        break;
                    }
                    tempGuessCopy /= 10;
                }
            }
        }
        secretCopy /= 10;
        guessCopy /= 10;
    }

 
    cout << "Бики: " << bulls << ", Корови: " << cows << endl;


    if (bulls == 4) {
        cout << "Ви вгадали число " << secretNumber << " за " << attempts << " спроб." << endl;
        return;
    }
    else {
        int nextGuess;
        cout << "Спробуйте ще раз: ";
        cin >> nextGuess;
        attempts++;
        checkGuess(nextGuess);
    }
}

int main() {
    cout << "Гра 'Бики та корови'" << endl;
    cout << "Загадано чотирицифрове число. Спробуйте вгадати його." << endl;

    generateSecretNumber(); 

    int firstGuess;
    cout << "Введіть своє перше число: ";
    cin >> firstGuess;
    attempts++;

    checkGuess(firstGuess); 

    return 0;
}
