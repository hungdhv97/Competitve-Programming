#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    float x,y;
    int t = 1, r;
    while(cin >> x >> y >> r)
    {
        float z_a = 0, z_b = 0, s = 0, tmp1, tmp2;
        for(int i = 1; i <= r ; i++)
        {
            tmp1 = z_a*z_a - z_b*z_b + x;
            tmp2 = 2*z_a*z_b + y;
            z_a = tmp1;
            z_b = tmp2;
            if(sqrt(z_a*z_a + z_b*z_b) > 2)
            {
                s = 1;
                break;
            }
        }
        cout << "Case " << t << ": ";
        if(s == 0) cout << "IN\n";
        else cout << "OUT\n";
        t++;
    }
}
