#include <iostream>
#include <string>
using namespace std;



int main()
{
    int gameboard[3][3];
    int player1;
    int player2;
    int target;
    char replace;
    int player1score = 0;
    int player2score = 0;
    int emptySpaces = 9;

// pls stop taking board inputs from user 

    cout << "Enter 9 elements in the game board (1-9): ";
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> gameboard[i][j];
        }
    }

    cout << "Gameboard elements are: ";
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << gameboard[i][j] << " ";
        }
        cout << endl;
    }

    for (int p = 1; p <= 9; p++)
    {
        emptySpaces = 0;

        if (p % 2 != 0)
        {
            cout << "1st term player one (player one only use 1-9 numbers): ";
            cin >> player1;
            if (player1 < 1 || player1 > 9)
            {
                cout << "Please enter numbers between 1-9." << endl;
                break;
            }
            cout << "Enter target element: ";
            cin >> target;
            cout << "Enter replace element: ";
            cin >> replace;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (gameboard[i][j] == target)
                    {
                        gameboard[i][j] = replace;
                    }
                    if (gameboard[i][j] != 'X' && gameboard[i][j] != 'O')
                    {
                        emptySpaces++;
                    }
                }
            }
        }
        else 
        {
            cout << "2nd term player two (player two only use 1-9 numbers): ";
            cin >> player2;
            if (player2 < 1 || player2 > 9)
            {
                cout << "Please enter numbers between 1-9." << endl;
                break;
            }
            cout << "Enter target element: ";
            cin >> target;
            cout << "Enter replace element: ";
            cin >> replace;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (gameboard[i][j] == target)
                    {
                        gameboard[i][j] = replace;
                    }
                    if (gameboard[i][j] != 'X' && gameboard[i][j] != 'O')
                    {
                        emptySpaces++;
                    }
                }
            }
        }

        cout << "Updated gameboard is: ";
        cout << endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (gameboard[i][j] >= 65 && gameboard[i][j] <= 90)
                {
                    cout << char(gameboard[i][j]) << " ";
                }
                else
                {
                    cout << gameboard[i][j] << " ";
                }
            }
            cout << endl;
        }

        
        for (int i = 0; i < 3; i++)
        {
            if (gameboard[i][0] == 'X' && gameboard[i][1] == 'X' && gameboard[i][2] == 'X')
            {
                player1score++;
                cout << "ROW: Player 1 wins a point!" << endl;
                cout << "Player 1 wins!" << endl;
                return 0; 
            }

            if (gameboard[0][i] == 'X' && gameboard[1][i] == 'X' && gameboard[2][i] == 'X')
            {
                player1score++;
                cout << "COL: Player 1 wins a point!" << endl;
                cout << "Player 1 wins!" << endl;
                return 0;
            }
        }
        if ((gameboard[0][0] == 'X' && gameboard[1][1] == 'X' && gameboard[2][2] == 'X') || (gameboard[0][2] == 'X' && gameboard[1][1] == 'X' && gameboard[2][0] == 'X'))
           
        {
            player1score++;
            cout << "DIAGONAL: Player 1 wins a point!" << endl;
            cout << "Player 1 wins!" << endl;
            return 0;
        }

        
        for (int i = 0; i < 3; i++)
        {
            if (gameboard[i][0] == 'O' && gameboard[i][1] == 'O' && gameboard[i][2] == 'O')
            {
                player2score++;
                cout << "ROW: Player 2 wins a point!" << endl;
                cout << "Player 2 wins!" << endl;
                return 0; 
            }

            if (gameboard[0][i] == 'O' && gameboard[1][i] == 'O' && gameboard[2][i] == 'O')
            {
                player2score++;
                cout << "COL: Player 2 wins a point!" << endl;
                cout << "Player 2 wins!" << endl;
                return 0; 
            }
        }
        if ((gameboard[0][0] == 'O' && gameboard[1][1] == 'O' && gameboard[2][2] == 'O') || (gameboard[0][2] == 'O' && gameboard[1][1] == 'O' && gameboard[2][0] == 'O'))
           
        {
            player2score++;
            cout << "DIAGONAL: Player 2 wins a point!" << endl;
            cout << "Player 2 wins!" << endl;
            return 0; 
        }

       
        if (emptySpaces == 0)
        {
            cout << "Game over. It's a draw!" << endl;
            break;
        }
    }

   
    cout << "Final Scores: Player 1: " << player1score << ", Player 2: " << player2score << endl;

    return 0;
}