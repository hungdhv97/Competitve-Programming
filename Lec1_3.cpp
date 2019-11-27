#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, a[30];
    string s;
    while(cin >> n)
    {
        if(n == 0) break;
        for(int i = 1; i <= n ; i++)
        {
            cin >> a[i];
        }
        cin.ignore();
        getline(cin, s);
        int len = s.length();
        cout << "'";
        for(int i = 0; i <= len - 1; i = i + n)
        {
            for(int j = 1; j <= n ; j++)
            {
                if(i + a[j] <= len) cout << s[i + a[j] - 1];
                else cout << ' ';
            }
        }
        cout << "'" << endl;
    }
}
