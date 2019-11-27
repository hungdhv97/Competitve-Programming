#include<bits/stdc++.h>
using namespace std;


map<string, int> net;

void combineNet(string f1, string f2)
{
    for(map<string, int>::iterator it = net.begin(); it != net.end(); it++)
    {
        if(it->second == net[f2]) net[it->first] = net[f1];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, f ;
    string f1,f2;
    cin >>t;

    while(t--)
    {
        net.clear();
        vector<int> totalF;
        cin >> f;
        totalF.resize(100005);
        int idx = 0;
        while(f--)
        {
            cin >> f1 >> f2;
            if(net.find(f1) == net.end() && net.find(f2) == net.end())
            {
                totalF[idx] = 2;
                net[f1] = idx;
                net[f2] = idx;
                cout << totalF[idx] << endl;
                idx++;
            }
            else if(net.find(f1) != net.end() && net.find(f2) == net.end())
            {
                net[f2] = net[f1];
                totalF[net[f1]]++;
                cout << totalF[net[f1]] << endl;
            }
            else if(net.find(f2) != net.end() && net.find(f1) == net.end())
            {
                net[f1] = net[f2];
                totalF[net[f2]]++;
                cout << totalF[net[f2]] << endl;
            }
            else
            {
                if(net[f1] == net[f2]) cout << totalF[net[f1]] << endl;
                else
                {
                    if(totalF[net[f1]] < totalF[net[f2]])
                    {
                        totalF[net[f2]] += totalF[net[f1]];
                        combineNet(f2,f1);
                    }
                    else
                    {
                        totalF[net[f1]] += totalF[net[f2]];
                        combineNet(f1,f2);
                    }
                    cout << totalF[net[f1]] << endl;
                }
            }
        }
    }
}
