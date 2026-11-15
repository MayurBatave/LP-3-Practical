#include <iostream>
#include <vector>
using namespace std;
int n, solutions = 0;
bool safe(const vector<int> &q, int row, int col)
{
    for (int r = 0; r < row; r++)
        if (q[r] == col || abs(q[r] - col) == abs(r - row))
            return false;
    return true;
}
void place(vector<int> &q, int row)
{
    if (row == n)
    {
        solutions++;
        cout << "Solution " << solutions << ":\n";
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
                cout << (q[r] == c ? "Q " : " . ");
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for (int c = 0; c < n; c++)
        if (safe(q, row, c))
        {
            q[row] = c;
            place(q, row + 1);
        }
}
int main()
{
    cout << "Enter N (1 to 15): ";
    cin >> n;
    if (n < 1 || n > 15)
    {
        cout << "Invalid N.\n";
        return 1;
    }
    vector<int> q(n, -1);
    place(q, 0);
    cout << "Total solutions = " << solutions << '\n';
}

#include <iostream>
using namespace std;

int board[20][20];
int n, count = 0;

// Check whether queen can be placed
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Solve N-Queens using backtracking
void solve(int row)
{
    if (row == n)
    {
        count++;

        cout << "\nSolution " << count << ":\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            solve(row + 1);

            board[row][col] = 0; // Backtracking
        }
    }
}

int main()
{
    cout << "Enter number of Queens: ";
    cin >> n;

    solve(0);

    cout << "\nTotal number of ways: " << count;

    return 0;
}
