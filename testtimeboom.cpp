#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxt = 0;
    cin >> n;
    int t[n + 1];
    for(int i = 1; i <= n ; i++) cin >> t[i];
    sort(t + 1, t + 1 + n, greater<int>());
    for(int i = 1; i <= n; i++)
    {
        maxt = max(maxt, t[i] + i + 1);
    }
    cout << maxt;
}
