#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n1, n2, cof;
    cin >> t;
    while(t--)
    {
        cin >> n1;
        int pol1[n1 + 1];
        for(int i = 0 ; i <= n1; i++)cin >> pol1[i];
        cin >> n2;
        int pol2[n2 + 1];
        for(int i = 0 ; i <= n2; i++)cin >> pol2[i];
        cout << n1 + n2 << endl;
        for(int i = 0; i <= n1 + n2 ; i++)
        {
            cof = 0;
            for(int j = 0 ; j <= min(i, n1); j++)
            {
                if(i - j > n2) continue;
                cof += pol1[j]*pol2[i-j];
            }
            cout << cof << " ";
        }
        cout << endl;

    }
}
