#include<bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    float total = 0, q, y;
    cin >> n;
    while(n--)
    {
        cin >> q >> y;
        total += q*y;
    }
    printf("%.3f",total);
}
