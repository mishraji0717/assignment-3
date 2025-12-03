# Number Catch Game – Assignment 3 (C Programming)

---

## About This Game

For Assignment 3, I extended my earlier number-matching idea and added more features to make it feel like a proper small game.  
The goal is still to press the number shown on the screen quickly, but now it includes difficulty modes, colors, reverse mode, and a progress bar.

I also added a high-score system using file handling, which was something I wanted to practice.

---

## Features I Added

### ✔ 1. High Score System  
The game now saves the highest score in a `highscore.txt` file and loads it each time the game starts.

### ✔ 2. Difficulty Levels  
Before the game starts, the player can select:
- Easy  
- Medium  
- Hard  

This affects how fast the time bar runs out.

### ✔ 3. Text Colors  
I used simple Windows console colors:
- Green → correct  
- Red → wrong  
- Blue → headers  
It makes the game less dull.

### ✔ 4. Time Progress Bar  
Each round shows a small bar like:
[#########-----]

markdown
Copy code
that shrinks as time runs out.

### ✔ 5. Different Sounds  
- Different beep for correct input  
- Different beep for wrong  
- Lower tone for time-out  
- Alert sound during reverse mode sometimes

### ✔ 6. Reverse Mode  
Sometimes instead of “Press 5”, the game shows:
DO NOT PRESS [5]

So the player must press anything *except* that number.

This increases variety and reaction challenge.

---

## Controls

1–9 : enter the number
q : quit the game

---

## How the Game Works

1. A random number between 1–9 is shown.  
2. You must press the correct number before the timer bar depletes.  
3. In reverse mode, you must *avoid* pressing the shown number.  
4. Score goes up on correct input, lives decrease on mistake or slow reaction.  
5. Timer becomes faster as score increases.

You start with **3 lives**.  
Game ends when all lives are gone.

---

## What I Learned

This assignment helped me practice:
- File handling (`fopen`, `fprintf`, `fscanf`)  
- Non-blocking input with `kbhit()` and `getch()`  
- Using colors in Windows console  
- Using beeps to add feedback  
- Managing a timer inside a loop  
- Structuring a small game with multiple features  

It definitely improved my understanding of real-time user input.

---

## How to Run

Compile and run using GCC:

gcc Number_Catch.c -o game
game.exe

Works best on Windows CMD or PowerShell.

---

## Note
All basic features + optional improvements for Assignment 3 are included.  
The game is simple but feels much better with the added effects.

Made by: Minakshi mishra(B.Tech CSE)
