#include<bits/stdc++.h>
using namespace std;

int a[20005];
int b[7];
int d[7];

int choose_num(int b1, int b2, int b3)
{
    memset(d, 0 ,sizeof(d));
    d[b1] = 1;
    d[b2] = 1;
    d[b3] = 1;
    int minn = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(d[i] == 0 && b[i] < b[minn])minn = i;
    }
    return minn;

}


void solve()
{
    a[1] = 1;
    b[1] = 1;
    int i = 2, j = 1;
    while(i <= 10000 && a[10001] == 0)
    {
        int m = 1;
        for(int k = i; k <= i + j - 1;k++)
        {
            if(k == i) a[k] = choose_num(a[k-1], a[k - 6*(j-1)], 6);
            else if(k < i + j -1) a[k] = choose_num(a[k-1], a[k - 6*(j-1) - 1], a[k - 6*(j-1)]);
            else a[k] = choose_num(a[k-1], a[k - 6*(j-1) - 1], 6);
            b[a[k]]++;
        }
        for(int k = i + j; k <= i + 5*j - 1;k++)
        {
            if((k-i+1)%j !=0) a[k] = choose_num(a[k-1], a[k - m*j- (6-m)*(j-1) - 1], a[k - m*j- (6-m)*(j-1)]);
            else
            {
                a[k] = choose_num(a[k-1], a[k - m*j - (6-m)*(j-1) - 1], 6);
                m++;
            }
            b[a[k]]++;
        }
        for(int k = i + 5*j; k <= i + 6*j - 1;k++)
        {
            a[k] = choose_num(a[k-1], a[k - 6*j], a[k - 6*j + 1]);
            b[a[k]]++;
        }
        i = i + 6*j;
        j++;
    }
}



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int c, n;
    memset(b, 0, sizeof(b));
    memset(a, 0, sizeof(a));
    b[0] = 20000;
    solve();

    cin >> c;
    while(cin >> n)
    {
        cout << a[n] << endl;
    }
}
