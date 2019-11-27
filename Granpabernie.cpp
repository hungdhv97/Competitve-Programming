#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    map<string, vector<int>> mapCountry;
    string country;
    int year, n,q, query;

    cin >> n;
    while(n--)
    {
        cin >> country >> year;
        mapCountry[country].push_back(year);
    }
    for(map<string, vector<int>>::iterator it = mapCountry.begin(); it != mapCountry.end() ; it++)
    {
        sort(it->second.begin(), it->second.end());
    }

    cin >> q;
    while(q--)
    {
        cin >> country >> query;
        cout << mapCountry[country][query - 1] << endl;
    }

}
