#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,T,a,s = 0;
    cin >> n >> T;
    while(cin >> a)
    {
        if(T - a >= 0)
        {
            s++;
            T -= a;
        }
        else break;
    }
    cout << s;
}
