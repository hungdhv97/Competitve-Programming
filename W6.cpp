#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a[2002][2002];
    memset(a, 0, sizeof(a));
    a[601][601] = 2;
    int i = 601, j = 601 ;
    int left = 601, right = 601, up = 601, down = 601;
    string mov;
    while(cin >> mov)
    {
        if(mov == "down")i = i + 1;
        if(mov == "up")i = i - 1;
        if(mov == "left")j = j - 1;
        if(mov == "right")j = j + 1;
        if(a[i][j] == 0) a[i][j] = 1;
        down = max(down, i);
        up = min(up, i);
        left = min(left, j);
        right = max(right, j);
    }
    a[i][j] = 3;
    for(int i = up - 1; i <= down + 1; i++)
    {
        for(int j = left - 1; j <= right + 1 ;j++)
        {
            if(i == up - 1 || i == down + 1 || j == left - 1 || j == right + 1)
            {
                cout << "#";
            }
            else if(a[i][j] == 0) cout << ' ';
            else if(a[i][j] == 2) cout << 'S';
            else if(a[i][j] == 1) cout << '*';
            else cout << 'E';
        }
        cout<<endl;
    }
}

