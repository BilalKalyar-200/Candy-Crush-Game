# Candy Crush Game (Console-Based in C++)

This is a console-based implementation of the popular **Candy Crush** game, developed as a Programming Fundamentals project. It features interactive gameplay, real-time scoring, two difficulty modes, and a leaderboard system.

---

## 🎮 Game Overview

This C++ game simulates Candy Crush using a text-based interface. Players select candies using coordinates and move them using the **W, A, S, D** keys. If three or more candies match (in a row, column, diagonal, or L-shape), they're destroyed and replaced with new ones. The game runs for **60 seconds** or until **15 moves** are used.

At the end, the player's name and score are saved if it ranks in the top 3.

---

## ✅ Features

* **Difficulty Modes**

  * **Easy** (8x8 board with 5 candy types)
  * **Hard** (10x10 board with 7 candy types)

* **Match Types and Points**

  * Horizontal or Vertical: **+10 points**
  * Diagonal: **+20 points**
  * L-shape: **+25 points**

* **Game Rules**

  * Timer: 60 seconds
  * Move limit: 15
  * Candy fall-down mechanism
  * Score saved if in top 3

* **Leaderboard**

  * Scores saved in `score_file.txt`
  * Top 3 scores displayed after each game

* **Visual Enhancements**

  * Color-coded candy display (Windows console only)
  * Real-time board updates

---

## ⚙️ Technologies Used

* **C++** (core language)
* **Windows-specific libraries**: `windows.h`, `conio.h`
* **Timers**: `chrono`, `thread`
* **File Handling**: `fstream`

---

## 📁 File Structure

* `main.cpp` – Full source code of the game
* `score_file.txt` – Stores player scores (auto-created on first run)

---

## 🛠️ How to Compile and Run

```bash
g++ main.cpp -o candy_crush
./candy_crush
```

> Note: The game is designed for Windows. On Linux/Mac, you may need to remove or replace `conio.h` and `windows.h` features.

---

## 📝 Instructions

* Match 3 or more candies in **a row, column, diagonal**, or **L-shape**.
* Use **W (up), A (left), S (down), D (right)** to move selected candies.
* Each valid match scores points depending on type.
* Game ends when:

  * Timer reaches 0 seconds
  * Player uses all 15 moves

---

## 📊 Use Cases

* **Educational**: Helps understand arrays, conditionals, file handling, and basic game logic in C++.
* **Beginner Projects**: Great practice for console applications and working with timers, input, and real-time updates.

---

## 🙌 Credits

Developed by **Bilal** and **Ali** as part of their Programming Fundamentals course project.
