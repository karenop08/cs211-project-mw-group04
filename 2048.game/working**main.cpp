#include <iostream>
#include <random>
#include <ctime>
#include <2048_helper_fixed.h>

using namespace std;

int main()
{
  
const int size = 5;
    int score = 0;
    int moves = 0;

    // Creates a 5-row by 5-column board and starts it with zeros.
    int board[5][5] = {};

    // Starts the random number generator.
    srand(static_cast<unsigned int>(time(0)));

    // Start a new game with two 2 tiles.
    new_game(board, score, moves, size);

    char choice;

    while (true)
    {
        cout << "\n===== 2048 GAME =====" << endl;
        cout << "U - Up" << endl;
        cout << "D - Down" << endl;
        cout << "L - Left" << endl;
        cout << "R - Right" << endl;
        cout << "N - New Game" << endl;
        cout << "S - Save Game" << endl;
        cout << "O - Load Game" << endl;
        cout << "H - Help" << endl;
        cout << "E - Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        // Change an uppercase letter to lowercase.
        if (choice >= 'A' && choice <= 'Z')
        {
            choice = choice + 32;
        }

        bool changed = false;

        if (choice == 'u')
        {
            changed = move_up(board, size, score);
        }
        else if (choice == 'd')
        {
            changed = move_down(board, size, score);
        }
        else if (choice == 'l')
        {
            changed = move_left(board, size, score);
        }
        else if (choice == 'r')
        {
            changed = move_right(board, size, score);
        }
        else if (choice == 'n')
        {
            new_game(board, score, moves, size);
            cout << "New game started!" << endl;
        }
        else if (choice == 's')
        {
            if (save_game(board, score, moves, size))
                cout << "Game saved!" << endl;
            else
                cout << "Unable to save game." << endl;
        }
        else if (choice == 'o')
        {
            if (load_game(board, score, moves, size))
                cout << "Game loaded!" << endl;
            else
                cout << "Unable to load game." << endl;
        }
        else if (choice == 'h')
        {
            help_menu();
        }
        else if (choice == 'e')
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        // Only add a new tile after a successful movement.
        if (choice == 'u' || choice == 'd' ||
            choice == 'l' || choice == 'r')
        {
            if (changed)
            {
                moves++;
                insert_random(board, size);
            }
            else
            {
                cout << "Nothing moved!" << endl;
            }
        }

        cout << "Score: " << score << endl;
        cout << "Moves: " << moves << endl;
        cout << "Highest Tile: " << highest_tile(board, size) << endl;

        print_board(board, size);

        if (check_win(board, size))
        {
            cout << "Congratulations! You reached 2048!" << endl;
        }

        if (game_over(board, size))
        {
            cout << "GAME OVER! No more moves available." << endl;
            break;
        }
    }
    return 0;
}
