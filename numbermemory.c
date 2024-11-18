#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int startMenu();
int newNumber(int level);
int loadingBar();
int takeInput();
int checkInput(int number, int input);
int gameState(bool won);

int main() {
    int level = 1;
    bool gotoNextLevel;
    int score = -1;
    do {
        startMenu();
        int number = newNumber(level);
        loadingBar();
        system("cls");
        startMenu();
        int input = takeInput();
        bool won = checkInput(number, input);
        gotoNextLevel = gameState(won);
        level++;
        score++;
    } while (gotoNextLevel);
    printf("\n\n\nYour final score is: %d", score);
}

int startMenu() {
    printf(" _________________________\n");
    printf("|                         |\n");
    printf("|     Human Benchmark     |\n");
    printf("|      Number Memory      |\n");
    printf("|_________________________|");
}

int newNumber(int level) {
    int number = 0;
    srand(time(NULL));
    for (int i = 1; i <= level; i++) {
        int N = 10;
        int r = rand() % (N + 1);
        number = (number * 10) + r;
    }
    printf("\n\n\nRemember:  %d", number);
    return number;
}

int loadingBar() {
    system("color 0A");
    char a = 177, b = 219;
    printf("\n\n");

    for (int i = 0; i < 27; i++) {
        printf("%c", a);
    }
    printf("\r");

    for (int i = 0; i < 27; i++) {
        printf("%c", b);
        Sleep(250);
    }
}

int takeInput() {
    int input;
    printf("\n\nEnter the number: ");
    scanf("%d", &input);
    return input;
}

int checkInput(int number, int input) {
    if (number == input) {
        printf("\n\nCongratulations! You've guessed the number correctly.\n");
        return true;
    }
    else {
        printf("\n\nSorry, the number you entered is incorrect. The correct number is %d.\n", number);
        return false;
    }
}

int gameState(bool won) {
    if (won) {
        printf("\n\nProcced to next level(y/n)");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            return true;
        }
        else {
            printf("\n\nThanks for playing!");
            return false;
        }
    }
}