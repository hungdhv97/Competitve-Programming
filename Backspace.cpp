#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char ch;
    char a[1000005];
    int i = 0;
    while(cin >> ch)
    {
        if(ch != '<')  a[i++] = ch;
        else i--;
    }
    for(int j = 0; j <= i-1; j++)
    {
        cout << a[j];
    }
}
