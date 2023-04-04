#include <iostream>
#include <ctime>
#include "cell.hpp"

using std::cin;
using std::cout;
void pause(int sec);
void act(int x, int y);
bool is_real(int x, int y);

T_cell board[20][20];
int main()
{
    // wczytywanie
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        board[x][y].change_act_state(1);
    }
    while (true)
    {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                act(i,j);
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                board[i][j].change_act_state(board[i][j].check_next_state());

        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
                cout << board[i][j].check_state() << " ";
            cout << "\n";
        }
        pause(1);
        //cin.get();
    }
}
void pause(int sec)
{
    time_t prev_time = time(NULL);
    while (time(NULL) - prev_time < sec)
    {
    }
}
void act(int x, int y)
{
    int on = 0;
    if (is_real(x - 1, y))
        on += board[x - 1][y].check_state();
    if (is_real(x - 1, y - 1))
        on += board[x - 1][y - 1].check_state();
    if (is_real(x - 1, y + 1))
        on += board[x - 1][y + 1].check_state();
    if (is_real(x, y - 1))
        on += board[x][y - 1].check_state();
    if (is_real(x, y + 1))
        on += board[x][y + 1].check_state();
    if (is_real(x + 1, y - 1))
        on += board[x + 1][y - 1].check_state();
    if (is_real(x + 1, y))
        on += board[x + 1][y].check_state();
    if (is_real(x + 1, y + 1))
        on += board[x + 1][y + 1].check_state();
    if (board[x][y].check_state())
    {
        if (on == 2 || on == 3)
            board[x][y].change_state(1);
        else
            board[x][y].change_state(0);
    }
    else
    {
        if (on == 3)
            board[x][y].change_state(1);
        else
            board[x][y].change_state(0);
    }
}
bool is_real(int x, int y)
{
    if (x >= 0 && x < 20 && y >= 0 && y < 20)
        return 1;
    else
        return 0;
}