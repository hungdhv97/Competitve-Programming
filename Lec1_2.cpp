#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    string l;
    cin >> n;
    while(cin >> l)
    {
        int len = l.length(), w;
        w = sqrt(len);
        if(w*w != len) w++;
        for(int i = 0; i <= w-1; i ++)
        {
            for(int j = w*w - w + i; j >= i; j = j - w)
            {
                if(j <= len - 1) cout << l[j];
            }
        }
        cout << endl;
    }

}
