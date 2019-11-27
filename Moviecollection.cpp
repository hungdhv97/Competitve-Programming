#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int F[2*MAXN];
int pos[MAXN];

int sum(int idx)
{
    int res = 0;
    for(int i = idx; i >= 0 ; i = (i&(i+1)) -1)
    {
        res += F[i];
    }
    return res;
}



void updateTree(int idx, int delta)
{
    for(int i = idx; i < 2*MAXN; i = i|(i+1))
    {
        F[i] += delta;
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, m,r,a;
    cin >> test;
    while(test--)
    {
        cin >> m >> r;
        memset(F, 0, sizeof(F));
        memset(pos, 0, sizeof(pos));
        for(int i = 1; i <= m; i++)
        {
            updateTree(i,1);
            pos[i] = m - i + 1;
        }
        for(int i = m + 1; i <= m + r ;i++)
        {
            cin >> a;
            cout << m - sum(pos[a]) << " ";
            updateTree(pos[a], -1);
            updateTree(i, 1);
            pos[a] = i;
        }
        cout << endl;
    }

}

