/*CANDY CRUSH GAME:
    The program takes row and column as input to select the candy.
    It then takes input from the keyboard (W/A/S/D) as cases of a switch statement.
    It swaps candies in the input direction.
    It uses if statements to check if 3 candies are equal or not.
    If they are equal, they are destroyed and candies from above fall down in their place with the top row generating new candies using a loop.
    The program continues for 60 seconds and offers a total of 15 moves, after which the name and score of the player is stored in a file if it is in the top 3.
*/

#include<iostream>      //for input and output
#include<cstdlib>       //for random generation
#include<ctime>         //to link randoms with time
#include<conio.h>       //console inp/out
#include<windows.h>     //console colours
#include<string>        //to use string functions
#include<fstream>       //file handling
#include<chrono>        //for timer
#include<thread>        //for timer
using namespace std;


const int Easy_board = 8;                   //board sizes
const int Hard_board = 10;
const int timer = 60;
const int total_moves = 15;
int score = 0;
int board_size;
char board[10][10];
const int max_players = 100;


void scores()
{                             //function to store and display 3 highest scores
    string names[max_players];
    int scores[max_players];

    ifstream in("score_file.txt");          //opening score file
    if (!in.is_open()) {
        cout << "Error opening the file." << endl;
        return;                     //return nothing if file cannot open
    }

    int player_count = 0;
    while (!(in.eof())) {           //end-of-file controlled loop
        player_count++;
        in >> names[player_count] >> scores[player_count];
    }

    for (int i = 0; i < player_count - 1; ++i)          //sorting using bubble sorting tecnique
    {
        for (int j = 0; j < player_count - i - 1; ++j) {
            if (scores[j] < scores[j + 1])
            {
                int temp = scores[j];                   //swapping scores
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;

                string temp1 = names[j];                //swapping names
                names[j] = names[j + 1];
                names[j + 1] = temp1;
            }
        }
    }
    cout << "Top 3 scores are given below with names:" << endl;
    cout << "Names\t\tScores" << endl;
    const int displayCount = 3;
    for (int i = 0; i < displayCount && i < player_count; ++i)
    {
        cout << names[i] << "\t\t" << scores[i] << endl;
    }
}


void func_board_fill_easy()
{                                                        //function to fill the board for easy mode
    srand(time(0));     //random seed

    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            do {
                board[i][j] = "~@#$%"[rand() % 5];      //five candies for easy mode
            } while (
                (i >= 2 && board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j]) ||     //vertically checking
                (j >= 2 && board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2]) ||     //horizontally checking
                (i >= 2 && j >= 2 && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2]) || //diagonal checking from top left to right
                (i >= 2 && j < board_size - 2 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) //vice versa
                );      //ending while
        }
    }
}


void func_board_fill_hard()
{                                                        //function to fill the board for hard mode
    srand(time(0));     //random seed

    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            do {
                board[i][j] = "~@#$%&*"[rand() % 7];    //seven candies for hard mode
            } while (
                (i >= 2 && board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j]) ||     //vertically checking
                (j >= 2 && board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2]) ||     //horizontally checking
                (i >= 2 && j >= 2 && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2]) || //diagonal checking from top left to right
                (i >= 2 && j < board_size - 2 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) //vice versa
                );      //ending while
        }
    }
}


void func_disp_board()
{                                    //function to display game board at start
    cout << "\t\t\t\t\t";            //to display in middle
    if (board_size == 8)
    {
        cout << "    0   1   2   3   4   5   6   7" << endl;                  //column number display for ez mode
    }
    else cout << "    0   1   2   3   4   5   6   7   8   9" << endl;         //column number display for hard mode
    for (int i = 0; i < board_size; ++i) {
        cout << "\t\t\t\t\t";

        cout << " " << i << " ";                                              //row number display

        for (int j = 0; j < board_size; ++j) {
            if (board[i][j] == '*')
            {
                cout << "\033[1;31m" << "|" << board[i][j] << "|" << "\033[0m "; //red colour
            }
            else if (board[i][j] == '@')
            {
                cout << "\033[1;32m" << "|" << board[i][j] << "|" << "\033[0m "; //green colour
            }
            else if (board[i][j] == '#') {
                cout << "\033[1;33m" << "|" << board[i][j] << "|" << "\033[0m "; //yellow colour
            }
            else if (board[i][j] == '$')
            {
                cout << "\033[1;34m" << "|" << board[i][j] << "|" << "\033[0m "; //blue colour
            }
            else if (board[i][j] == '%')
            {
                cout << "\033[1;35m" << "|" << board[i][j] << "|" << "\033[0m "; //magenta colour
            }
            else if (board[i][j] == '&')
            {
                cout << "\033[1;36m" << "|" << board[i][j] << "|" << "\033[0m "; //cyan colour
            }
            else if (board[i][j] == '~')
            {
                cout << "\033[1;37m" << "|" << board[i][j] << "|" << "\033[0m "; //white colour
            }
            else {
                cout << "|" << board[i][j] << "| ";
            }
        }

        cout << endl;
        cout << "\t\t\t\t\t";
        if (board_size == 8) {                              //if ez mode then less lines
            cout << "------------------------------------" << endl;
        }
        else cout << "-------------------------------------------" << endl;
    }
}


void func_welcome()                                         //function for welcome board
{
    system("Color 3");

    cout << endl;
    cout << "\t\t\t\t\t===================================" << endl;
    cout << "         \t\t\t\t\tWelcome to Candy Crush              " << endl;
    cout << "\t\t\t\t\t===================================" << endl;
    cout << "           \t\t\t\t\t   Choose Your Mode        " << endl;
    cout << "\t\t\t\t\t===================================" << endl;
    cout << "  \t\t\t\t\t         1. Play Game                    " << endl;
    cout << "  \t\t\t\t\t         2. Instructions                     " << endl;
    cout << "  \t\t\t\t\t         3. Credits                     " << endl;
    cout << "  \t\t\t\t\t         4. Score                     " << endl;
    cout << "  \t\t\t\t\t         5. Exit                     " << endl;
    cout << "\t\t\t\t\t===================================" << endl;
}


bool func_check_match()                                     //function checks 3 same candies and puts them = ' '
{
    bool matchFound = false;

    // Check for upper-left L matches
    for (int i = 0; i < board_size - 2; ++i) {
        for (int j = board_size - 1; j > 1; --j)
        {
            if (board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j] && board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2])
            {
                board[i][j] = ' ';
                board[i - 1][j] = ' ';
                board[i - 2][j] = ' ';
                board[i][j - 1] = ' ';
                board[i][j - 2] = ' ';
                matchFound = true;
                score = score + 25;
            }
        }
    }

    // Check for upper-right L matches
    for (int i = 0; i < board_size - 2; ++i) {
        for (int j = board_size - 1; j > 1; --j)
        {
            if (board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                board[i][j] = ' ';
                board[i - 1][j] = ' ';
                board[i - 2][j] = ' ';
                board[i][j + 1] = ' ';
                board[i][j + 2] = ' ';
                matchFound = true;
                score = score + 25;
            }
        }
    }

    // Check for lower-left L matches
    for (int i = 0; i < board_size - 2; ++i) {
        for (int j = board_size - 1; j > 1; --j)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2])
            {
                board[i][j] = ' ';
                board[i + 1][j] = ' ';
                board[i + 2][j] = ' ';
                board[i][j - 1] = ' ';
                board[i][j - 2] = ' ';
                matchFound = true;
                score = score + 25;
            }
        }
    }

    // Check for lower-right L matches
    for (int i = 0; i < board_size - 2; ++i) {
        for (int j = board_size - 1; j > 1; --j)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                board[i][j] = ' ';
                board[i + 1][j] = ' ';
                board[i + 2][j] = ' ';
                board[i][j + 1] = ' ';
                board[i][j + 2] = ' ';
                matchFound = true;
                score = score + 25;
            }
        }
    }

    // Check for horizontal matches
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size - 2; ++j)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                board[i][j] = ' ';
                board[i][j + 1] = ' ';
                board[i][j + 2] = ' ';
                matchFound = true;
                score = score + 10;
            }
        }
    }

    // Check for vertical matches
    for (int j = 0; j < board_size; ++j)
    {
        for (int i = 0; i < board_size - 2; ++i)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
            {

                board[i][j] = ' ';
                board[i + 1][j] = ' ';
                board[i + 2][j] = ' ';
                matchFound = true;
                score = score + 10;

            }
        }
    }
    // Check diagonal from  top left to bottom right
    for (int i = 0; i < board_size - 2; i++)
    {
        for (int j = 0; j < board_size - 2; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
            {

                board[i][j] = ' ';
                board[i + 1][j + 1] = ' ';
                board[i + 2][j + 2] = ' ';
                matchFound = true;
                score = score + 20;
            }
        }
    }
    // Check diagonal from top right to bottom left
    for (int i = 0; i < board_size - 2; ++i) {
        for (int j = board_size - 1; j > 1; --j)
        {
            if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2])
            {
                board[i][j] = ' ';
                board[i + 1][j - 1] = ' ';
                board[i + 2][j - 2] = ' ';
                matchFound = true;
                score = score + 20;
            }
        }
    }
    return matchFound;
}


void func_swap_candies(int inp_row, int inp_col, int row2, int col2)              //function to swap selected candies
{
    char temp = board[inp_row][inp_col];
    board[inp_row][inp_col] = board[row2][col2];
    board[row2][col2] = temp;
}


void func_destroyed_easy()                                      //function to move down candies and generate random ones at top row for easy mode
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; ++j)
        {
            if (board[i][j] == ' ')
            {
                for (int k = i; k >= 0; --k)
                {                                 //loop for moving down candies
                    if (k == 0)
                    {
                        board[k][j] = "~@#$%"[rand() % 5];
                    }
                    else
                    {
                        board[k][j] = board[k - 1][j];           //moves down candies
                    }
                }
            }
        }
    }
}


void func_destroyed_hard()                                       //function to move down candies and generate random ones at top row for hard mode
{
    for (int i = 0; i < board_size; ++i)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (board[i][j] == ' ')
            {
                for (int k = i; k >= 0; k--)
                {                  //loop for moving down candies
                    if (k == 0)
                    {
                        board[k][j] = "~@#$%&*"[rand() % 7];
                    }
                    else
                    {
                        board[k][j] = board[k - 1][j];         //moves down candies
                    }
                }
            }
        }
    }
}

void testing()
{
    cout << "Hello World";
}
void instruction();         //body at last
void credits();


int main()
{
    string Name;
    cout << "Enter your name: ";
    cin >> Name;

    while (true)
    {
        func_welcome();                     //displaying welcome board

        char ch;
        cout << "Enter your choice: ";
        cin >> ch;                          //getting choice from welcome board

        if (ch == '1')
        {
            char ch2;
            cout << "Choose game mode (1 for Easy, 2 for Hard): ";
            cin >> ch2;                                             //getting choice for easy or hard

            if (ch2 == '1')
            {
                board_size = Easy_board;                     //iniatializing it with const integer
            }
            else if (ch2 == '2')
            {
                board_size = Hard_board;
            }
            else {
                cout << "Invalid choice. Exiting." << endl;
                return 1;
            }
            system("cls");                                   //clearing welcome board

            if (ch2 == '1') {
                func_board_fill_easy();                      //sending command to this function to initialize board with current time
            }
            else func_board_fill_hard();

            cout << "Initial Board" << endl;                 //displaying initial board
            func_disp_board();

            auto startTime = chrono::system_clock::now();    //timer started
            chrono::seconds duration(timer);

            int moves;
            moves = total_moves;

            while (chrono::system_clock::now() - startTime < duration && moves > 0) {
                auto remainingTime = chrono::duration_cast<chrono::seconds>(duration - (chrono::system_clock::now() - startTime));
                cout << "Time remaining: " << remainingTime.count() << " seconds" << endl;

                int inp_row, inp_col;
                if (board_size == 8)
                {
                    cout << "Enter the row and column of the candy to select (0-7): ";      //for ez mode
                }
                else
                {
                    cout << "Enter the row and column of the candy to select (0-9): ";      //for hard mode
                }

                cin >> inp_row >> inp_col;                              //getting row and col from user


                char direction;
                cout << "Enter the direction to move the candy by using (W/A/S/D): ";
                cin >> direction;                                       //getting direction for the candy


                switch (direction)
                {                                    //checking which key was pressed for direction
                case 'W':
                case 'w':
                    if (!(inp_row == 0))
                    {
                        func_swap_candies(inp_row, inp_col, inp_row - 1, inp_col);
                    }
                    else moves++;
                    break;
                case 'S':
                case 's':
                    if (!(inp_row == board_size - 1)) {
                        func_swap_candies(inp_row, inp_col, inp_row + 1, inp_col);
                    }
                    else moves++;
                    break;
                case 'A':                                                               //if conditions to restrict invalid movements
                case 'a':
                    if (!(inp_col == 0)) {
                        func_swap_candies(inp_row, inp_col, inp_row, inp_col - 1);
                    }
                    else moves++;
                    break;
                case 'D':
                case 'd':
                    if (!(inp_col == board_size - 1)) {
                        func_swap_candies(inp_row, inp_col, inp_row, inp_col + 1);
                    }
                    else moves++;
                    break;
                default:
                    cout << "Invalid direction! Try again.\n";
                    continue;
                }
                system("cls");                                                           //clearing screen

                cout << "Board after the move" << endl;                                  //board after move
                func_disp_board();

                while (func_check_match()) {                                //checking if match function returned true or not?
                    cout << "SWEET" << endl;                                //sweet if YES

                    this_thread::sleep_for(chrono::milliseconds(500));      //delay for visibility

                    cout << "Board after destroying candies:\n";
                    func_disp_board();                                      //board after move

                    if (ch2 == '1') {
                        func_destroyed_easy();                              //calling function to generate candies at destoryed places
                    }
                    else func_destroyed_hard();

                    this_thread::sleep_for(chrono::milliseconds(500));      //delay for visibility

                    cout << "Board after generating new candies:\n";        //updated board display
                    func_disp_board();
                }
                moves--;
                cout << "Moves Left = " << moves << endl;                   //display moves
            }
            if (!(chrono::system_clock::now() - startTime < duration)) {    //timer ended
                cout << "Game over! Time's up" << endl;
            }
            else if (moves == 0) {                                          //no moves left
                cout << "Game over! No Moves left!" << endl;
            }
            cout << "Your score is: " << score << endl;

        }
        else if (ch == '2')                                                 //choice to get instructions  
        {
            instruction();
        }

        else if (ch == '3')                                                     //choice to check credits                                                          
        {
            credits();
        }
        else if (ch == '4')                                                     //choice to check score
        {
            scores();
        }
        else if (ch == '5')
        {
            cout << "Quitting the game. Goodbye " << Name << "!" << endl;      //choice to exit
            break;
        }
        else
        {
            cout << "Invalid choice. Try again" << endl;
        }


        ofstream name1;
        name1.open("score_file.txt", name1.app);         //using append to keep prevous data
        name1 << Name << " " << score << endl;
        name1.close();
    }


    system("pause");
    return 0;
}


void instruction()              //function for instruction
{
    cout << "Instructions:" << endl;

    cout << "Match three candies of the same type in a row, column, diagonal or L shape to score points.\n";
    cout << "You have 60 seconds to make moves. The game ends when the time runs out or moves left are 0.\n";
    cout << "Horizontal and Vertical matches grant 10 points.\n";
    cout << "Diagonal matches grant 20 points. \n";
    cout << "L shape matchees grant 25 points. \n";
}


void credits()                  //function for credits
{
    cout << "Credits:" << endl;
    cout << "Game developed by Bilal and Ali as their Programming Fundamentals project." << endl;
}
