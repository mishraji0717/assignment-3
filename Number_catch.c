#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int score = 0;
int lives = 3;
int timeLimit = 350;         
int highScore = 0;
int reverseMode = 0;        

void loadHighScore() {
    FILE *f = fopen("highscore.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", &highScore);
        fclose(f);
    } else {
        highScore = 0;
    }
}

void saveHighScore() {
    if (score > highScore) {
        FILE *f = fopen("highscore.txt", "w");
        if (f != NULL) {
            fprintf(f, "%d", score);
            fclose(f);
        }
    }
}

int getRandomNumber() {
    return (rand() % 9) + 1;
}

void showProgress(int t, int max) {
    int totalBars = 20;
    int filled = (t * totalBars) / max;

    printf("[");
    for (int i = 0; i < filled; i++) printf("#");
    for (int i = filled; i < totalBars; i++) printf("-");
    printf("]");
}

void drawUI(int num) {
    system("cls");

    color(11);
    printf("Number Catch Game (Assignment 3)\n");
    color(7);

    printf("Score: %d    Lives: %d    High Score: %d\n\n", score, lives, highScore);

    if (reverseMode == 0) {
        printf("Catch this number:\n\n");
        color(10);
        printf("            [%d]\n\n", num);
        color(7);
        printf("Press the SAME number before time runs out.\n\n");
    } else {
        printf("REVERSE MODE ACTIVE!\n\n");
        color(12);
        printf("       DO NOT PRESS [%d]\n\n", num);
        color(7);
    }
}

int main() {

    int num, key;
    int timePassed = 0;

    srand(time(NULL));
    loadHighScore();

    system("cls");
    printf("Select Difficulty:\n\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n\n");
    printf("Enter choice: ");

    char diff = getch();
    if (diff == '1') timeLimit = 450;
    else if (diff == '2') timeLimit = 350;
    else timeLimit = 250;

menuStart:
    system("cls");
    printf("=== MAIN MENU ===\n\n");
    printf("1. Start Game\n");
    printf("2. Help\n");
    printf("3. Rules\n");
    printf("4. Exit\n\n");
    printf("Enter choice: ");

    char menu = getch();

    if (menu == '4') {
        return 0;
    }

    else if (menu == '2') {
        system("cls");
        printf("Help / Instructions:\n\n");
        printf("- A random number from 1 to 9 will appear on the screen.\n");
        printf("- Press the SAME number before the timer ends.\n");
        printf("- In reverse mode, DO NOT press the shown number.\n");
        printf("- Score increases with correct input.\n");
        printf("- Wrong key or slow reaction reduces your lives.\n\n");
        printf("Press any key to go back...");
        getch();
        goto menuStart;
    }

    else if (menu == '3') {
        system("cls");
        printf("Game Rules:\n\n");
        printf("1. You start with 3 lives.\n");
        printf("2. A number (1 to 9) will appear each round.\n");
        printf("3. If reverse mode is ON, avoid pressing the shown number.\n");
        printf("4. Lives decrease if:\n");
        printf("   - You press the wrong number\n");
        printf("   - You run out of time\n");
        printf("5. Every 5 points the timer becomes a bit faster.\n");
        printf("6. High score is saved automatically.\n");
        printf("7. Game ends when all lives are used.\n\n");
        printf("Press any key to return...");
        getch();
        goto menuStart;
    }

    else if (menu != '1') {
        goto menuStart;
    }

    while (1) {

        num = getRandomNumber();
        reverseMode = (rand() % 7 == 0);
        timePassed = 0;

        while (1) {

            drawUI(num);

            printf("Time Left: ");
            showProgress(timePassed, timeLimit);
            printf("\n\n(Press q to quit)\n");

            
            if (kbhit()) {
                key = getch();

                if (key == 'q') {
                    saveHighScore();
                    system("cls");
                    printf("You quit the game.\n");
                    return 0;
                }

                int pressed = key - '0';

                
                if (reverseMode) {
                    if (pressed != num) {
                        score++;
                        color(10);
                        Beep(1500, 80);
                        color(7);
                    } else {
                        lives--;
                        color(12);
                        Beep(300, 200);
                        color(7);
                    }
                }

                
                else {
                    if (pressed == num) {
                        score++;
                        color(10);
                        Beep(900, 60);
                        color(7);
                    } else {
                        lives--;
                        color(12);
                        Beep(300, 200);
                        color(7);
                    }
                }
                break;
            }

            Sleep(15);
            timePassed += 15;

            
            if (timePassed >= timeLimit) {
                lives--;
                color(12);
                Beep(200, 200);
                color(7);
                break;
            }
        }

        
        if (score % 5 == 0 && timeLimit > 120) {
            timeLimit -= 10;
        }

        if (lives <= 0) {
            saveHighScore();
            system("cls");
            printf("\nGame Over!\n");
            printf("Your Score: %d\n", score);
            printf("High Score: %d\n", highScore);
            Beep(200, 400);
            break;
        }
    }

    return 0;
}
