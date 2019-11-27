#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,m;
    string s;
    while(cin >> n)
    {
        if(n == 0) break;
        int d1 = 0, d2 = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> s >> m;
            if(s == "DROP")
            {
                d2 += m;
                cout << "DROP 2 " << m << endl;
            }
            else
            {
                if(d1 == 0)
                {
                    cout << "MOVE 2->1 " << d2 << endl;
                    cout << "TAKE 1 " << m << endl;
                    d1 = d2 - m;
                    d2 = 0;
                }
                else if(d1 < m)
                {
                    cout << "TAKE 1 " << d1 << endl;
                    cout << "MOVE 2->1 " << d2 << endl;
                    cout << "TAKE 1 " << m - d1 << endl;
                    d1 = d1 + d2 - m;
                    d2 = 0;
                }
                else
                {
                    cout << "TAKE 1 " << m << endl;
                    d1 = d1 - m;
                }
            }
        }
        cout << endl;
    }
}
