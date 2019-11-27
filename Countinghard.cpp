#include<bits/stdc++.h>
using namespace std;




int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, number, idx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<long long, int> sub;
        sub[0] = 1;
        long long sum = 0, a, total = 0, tmp;
        while(n--)
        {
            cin >> a;
            sum +=a;
            tmp = sum - 47;
            if(sub.find(tmp) != sub.end()) total += sub[tmp];
            if(sub.find(sum) == sub.end()) sub[sum] = 0;
            sub[sum]++;
        }
        cout << total << endl;
    }
}
