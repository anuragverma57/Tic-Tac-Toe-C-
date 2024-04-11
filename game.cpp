#include <iostream>
using namespace std;
char winner = '0';

void printBoard(char board[3][3])
{
    cout << "\n\t\t\t   TIC TAC TOE\n\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t" << board[i][0] << "\t"
             << "|"
             << "\t" << board[i][1] << "\t"
             << "|"
             << "\t" << board[i][2] << "\t" << endl;
        if (i == 2)
            continue;
        cout << "\t------------------------------------------------" << endl;
    }
    cout << "\b\n\n\nPLAYER 1 = [ X ]\n";
    cout << "\b\nPLAYER 2 = [ 0 ]\n";
}

bool checkWinner(char board[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][2] == board[i][1])
        {
            winner = board[i][0];
            return true;
        }
        if (board[0][i] == board[1][i] && board[2][i] == board[1][i])
        {
            winner = board[0][i];
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[2][2] == board[1][1])
    {
        winner = board[0][0];
        return true;
    }

    if (board[0][2] == board[1][1] && board[2][0] == board[1][1])
    {
        winner = board[0][2];
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3])
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                return false;
            }
        }
    }
    return true;
}

char fillBoard(char board[3][3], int row, int col, char player)
{
    if (board[row][col] == 'X' || board[row][col] == '0')
    {
        return player;
    }

    board[row][col] = player;
    printBoard(board);
    player = (player == 'X') ? 'O' : 'X';
    return player;
}

int main()
{
    char player = 'X';
    bool gameOver = false;
    int spot;
    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
    printBoard(board);

    while (!gameOver)
    {
        cout << "chance of player " << player << " say a spot to fill your move  : ";
        cin >> spot;
        int row = (spot - 1) / 3;
        int col = (spot - 1) % 3;
        player = fillBoard(board, row, col, player);
        gameOver = checkWinner(board);
        if (checkDraw(board))
        {
            cout << "\n\n\n\t\t\tGame Draw";
            return 0;
        }
    }

    cout << "\n\n\nWinner is " << winner;

    return 0;
}