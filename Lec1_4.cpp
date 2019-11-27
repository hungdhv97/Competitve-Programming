#include<bits/stdc++.h>
using namespace std;

vector<long long> collatz(long long n)
{
    vector<long long> v;
    v.push_back(n);
    while(n != 1)
    {
        if(n%2 == 0) n = n/2;
        else n = 3*n + 1;
        v.push_back(n);
    }

    return v;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long a,b,stepa,stepb,check;
    vector<long long> cola,colb;
    while(cin >> a >> b)
    {
        check = 0;
        if(a == 0 && b == 0)
        {
            break;
        }
        cola = collatz(a);
        colb = collatz(b);
        for(int i = 0 ; i < cola.size() ; i++)
        {
            for(int j = 0 ; j < colb.size(); j++)
            {
                if(cola[i] == colb[j])
                {
                    check = 1;
                    stepa = i;
                    stepb = j;
                    break;
                }
            }
            if(check == 1)break;
        }
        cout << a << " needs " << stepa << " steps, "
             << b << " needs " << stepb << " steps, they meet at "
             << cola[stepa] << endl;
    }
}
