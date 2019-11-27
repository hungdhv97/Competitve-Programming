#include<bits/stdc++.h>
using namespace std;



int main()
{
    int i = 0, a[4],b[4],c[2000],d[2000];
    memset(c, 0 ,sizeof(c));
    memset(d, 0 ,sizeof(d));
    while(++i <= 3)
    {
        cin >> a[i] >> b[i];
        c[a[i]]++;
        d[b[i]]++;
    }
    for(int i = 1; i <= 3 ; i++)
    {
        if(c[a[i]] == 1) cout << a[i];
    }
    cout << " ";
    for(int i = 1; i <= 3 ; i++)
    {
        if(d[b[i]] == 1) cout << b[i];
    }
}

