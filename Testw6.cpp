#include <bits/stdc++.h>
using namespace std;

char buf[2005][2005];

void solve()
{
    string move;
    int i = 505, j = 505;
    int imax = 505, imin = 505, jmax = 505, jmin = 505;
    while (getline(cin, move))
    {
        if (move.compare("left") == 0)
        {
            j -= 1;
            jmin = min(j, jmin);
        }
        else if (move.compare("right") == 0)
        {
            j += 1;
            jmax = max(j, jmax);
        }
        else if (move.compare("down") == 0)
        {
            i += 1;
            imax = max(i, imax);
        }
        else if (move.compare("up") == 0)
        {
            i -= 1;
            imin = min(i, imin);
        }
        else
        {
            break;
        };
        buf[i][j] = '*';
    };
    buf[i][j] = 'E';
    buf[505][505] = 'S';
    imax += 1;
    jmax += 1;
    imin -= 1;
    jmin -= 1;
    for (int i = imin; i <= imax; i++)
    {
        for (int j = jmin; j <= jmax; j++)
        {
            if ((i == imin) or (i == imax) or (j == jmin) or (j == jmax))
            {
                cout << '#';
            }
            else
            {
                cout << buf[i][j];
            }
        }
        cout << "\n";
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            buf[i][j] = ' ';
        }
    }
    solve();
}
