#include<bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,a,s=0;
    cin >> n;
    while(cin >> a)
    {
        if(a < 0) s++;
    }
    cout << s;
}
