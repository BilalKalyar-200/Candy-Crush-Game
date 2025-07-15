````markdown
# 🍬 Candy Crush Game (Console-Based | C++)

A terminal-based implementation of the classic Candy Crush game developed in C++ as a Programming Fundamentals project. The game includes two difficulty levels (Easy & Hard), visual feedback using console colors, timer and move limits, match detection (including L-shapes), score tracking, and leaderboard management using file I/O.

---

## 🎮 Gameplay Overview

- Choose between **Easy (8x8)** or **Hard (10x10)** board.
- You have **60 seconds** and a total of **15 moves**.
- Match **3 or more candies** (horizontally, vertically, diagonally, or in L-shapes) to score points.
- Swap candies using `W`, `A`, `S`, `D` for movement directions.
- Destroyed candies fall and are replaced by new ones.
- Your score is saved to a leaderboard if it's in the top 3.

---

## ✨ Game Features

- **Colorful Terminal UI:** Candies are color-coded using ANSI escape codes.
- **Multiple Match Types:**
  - Horizontal & Vertical Match → +10 pts
  - Diagonal Match → +20 pts
  - L-Shaped Match → +25 pts
- **Game Timer:** Real-time countdown (60 seconds).
- **Move Limitation:** Maximum of 15 moves per game.
- **Score Tracking:** Top 3 high scores saved in `score_file.txt`.
- **Mode Selection:** Easy (5 candy types) and Hard (7 candy types).
- **User-Friendly Navigation:** Welcome screen with menu options:
  - Play Game
  - Instructions
  - Credits
  - View Top Scores
  - Exit

---

## 🛠 Technologies Used

- **C++**: Core logic and gameplay
- **Windows.h / conio.h**: Console control and interaction
- **ANSI Escape Codes**: Colorful game board display
- **File I/O**: Leaderboard storage
- **Chrono + Thread**: Timing and delays

---

## 🔧 How to Run

### ✅ Requirements
- Windows OS
- C++ compiler (e.g., `g++`, Code::Blocks, Dev C++)

### ▶️ Compile & Run
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/candy-crush-cpp.git
   cd candy-crush-cpp
````

2. **Compile the Code:**

   ```bash
   g++ -o candycrush main.cpp
   ```

3. **Run the Game:**

   ```bash
   ./candycrush
   ```

---

## 📂 Project Structure

```
.
├── main.cpp               # Main game logic
├── score_file.txt         # Stores top player scores
└── README.md              # Project documentation
```

---

## 🧠 How Scoring Works

| Match Type          | Points Earned |
| ------------------- | ------------- |
| Horizontal/Vertical | +10 points    |
| Diagonal            | +20 points    |
| L-Shape             | +25 points    |

---

## 📜 Instructions

* Use **W** = Up, **S** = Down, **A** = Left, **D** = Right to swap candies.
* Match at least **3 same candies** to score.
* **Game ends** when time runs out or all moves are used.
* **Top 3 scores** are displayed and saved at the end of each session.

---

## 🧾 Sample Output

```
|@| |#| |$| |%| |*|
|#| |#| |@| |~| |$|
...
Moves Left: 14
Time Remaining: 45 seconds
```

---

## 🧑‍💻 Credits

Developed by **Bilal** and **Ali** as part of their university project for the *Programming Fundamentals* course.

---

## 🏁 Future Improvements (Optional)

* Add sound effects or music.
* Implement UI using a GUI library like SFML or SDL.
* Introduce power-ups or special candies.
* Multiplayer support via sockets or local scoreboard expansion.

---

## 📩 Feedback & Contributions

Feel free to fork this repository, suggest improvements, or raise issues. Contributions are welcome!
