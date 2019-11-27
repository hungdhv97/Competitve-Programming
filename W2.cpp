#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int bus[2000];
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin >> bus[i];
    }
    sort(bus + 1, bus + 1 + n);
    int s,t;
    for(int i = 1; i <= n ;i++)
    {
        s = 1;
        t = i;
        while(bus[t+1] == bus[t] + 1)
        {
            t++;
            s++;
        }
        if(s <= 2)cout << bus[i] << " ";
        else
        {
            cout << bus[i] << "-" << bus[i+s-1] << " ";
            i = i + s - 1;
        }
    }
}

