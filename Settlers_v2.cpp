#include<bits/stdc++.h>
using namespace std;

const int Size = 200;
const int N = 20000;
int cell[N];
int value[2*Size][2*Size];
int cnt[6];

int smallest(int x, int y)
{
    bool used[6];
    for(int i = 0; i <= 5; i++) used[i] = false;
    used[value[x + 1][y]] = true;
    used[value[x - 1][y]] = true;
    used[value[x + 1][y + 1]] = true;
    used[value[x][y + 1]] = true;
    used[value[x][y - 1]] = true;
    used[value[x - 1][y - 1]] = true;
    int minCnt = 0;
    for(int i = 1; i <= 5; i++)
    {
        if((used[i] == false) && (cnt[i] < cnt[minCnt])) minCnt = i;
    }
    cnt[minCnt]++;
    return minCnt;
}


void solve()
{
    int dim = 1;
    int x = Size, y = Size;
    int t = 1;
    value[x][y] = smallest(x,y);
    cell[t] = value[x][y];
    t++;
    while(t <= 10000)
    {
        for(int i = 1;i <= dim; i++)
        {
            x++;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        for(int i = 1;i <= dim - 1; i++)
        {
            x++;
            y++;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        for(int i = 1;i <= dim; i++)
        {
            y++;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        for(int i = 1;i <= dim; i++)
        {
            x--;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        for(int i = 1;i <= dim; i++)
        {
            x--;
            y--;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        for(int i = 1;i <= dim; i++)
        {
            y--;
            value[x][y] = smallest(x, y);
            cell[t] = value[x][y];
            t++;
        }
        dim++;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(cnt, 0 ,sizeof(cnt));
    for(int i = 0;i < Size; i++)
    {
        for(int j = 0; j < Size ; j++)
        {
            value[i][j] = 0;
        }
    }
    memset(cell, 0 ,sizeof(cell));
    cnt[0] = 20000;
    int c, n;
    cin >> c;
    solve();
    while(cin >> n)
    {
        cout << cell[n] << endl;
    }
}
