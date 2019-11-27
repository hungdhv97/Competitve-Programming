#include<bits/stdc++.h>
using namespace std;


int main()
{
    int h, t, cnt;
    while(cin >> h >> t)
    {
        if(h + t == 0)break;
        if(t == 0)
        {
            if(h%2 == 0) cout << h/2 << endl;
            else cout << -1 << endl;
        }
        else
        {
            cnt = 0;
            while(t%2 != 0 || (h + t/2)%2 != 0)
            {
                t++;
                cnt++;
            }
            cout << cnt + t/2 + (h + t/2)/2 << endl;
        }
    }
}
