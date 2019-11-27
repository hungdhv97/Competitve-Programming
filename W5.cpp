#include<bits/stdc++.h>
using namespace std;

struct Time
{
    int hour,minute,second;
};




int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    struct Time time[2];
    string s;
    int t = 0, time_second[2], subtime;
    while(cin >> s)
    {
        time[t].hour = (s[0] - 48)*10 + s[1] - 48;
        time[t].minute = (s[3] - 48)*10 + s[4] - 48;
        time[t].second = (s[6] - 48)*10 + s[7] - 48;
        time_second[t] = time[t].hour*3600 + time[t].minute*60 + time[t].second;
        t++;
    }
    subtime = time_second[1] - time_second[0];
    if(subtime <= 0) subtime += 86400;
    int ex_time[3];
    ex_time[0] = subtime/3600;
    ex_time[1] = (subtime - subtime/3600*3600)/60;
    ex_time[2] = subtime - subtime/3600*3600 - (subtime - subtime/3600*3600)/60*60;
    for(int i = 0 ;i <= 2 ;i++)
    {
        if(ex_time[i] < 10) cout << '0';
        cout << ex_time[i];
        if(i < 2) cout << ":";
    }
}
