#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int check[200],w,p, a[200];
    memset(check, 0, sizeof(p));
    cin >> w >> p;
    for(int i = 1;i <= p ; i++)
    {
        cin >> a[i];
    }
    p++;
    a[p] = w;
    a[0] = 0;
    for(int i = 0; i <= p-1 ; i++)
    {
        for(int j = 1; j <= p ; j++)
        {
            if(i + j <= p) check[a[i + j] - a[i]] = 1;
            else break;
        }
    }
    for(int i = 1 ; i <= w ; i++)
    {
        if(check[i] == 1) cout << i << " ";
    }
}
