#include<bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, k, r, i = 1, dreamPos, realPos;
    cin >> n;
    string code, event;
    string tmp[50005];
    map<string, int> ele;
    while(cin >> code)
    {
        if(code == "E")
        {
            cin >> tmp[i];
            ele[tmp[i]] = i;
            i++;
        }
        if(code == "D")
        {
            cin >> r;
            while(r--)
            {
                i--;
                ele.erase(tmp[i]);
            }
        }
        if(code == "S")
        {
            cin >> k;
            realPos = -1;
            dreamPos = i;
            bool check = false;
            for(int j = 1 ; j <= k; j++)
            {
                cin >> event;
                if(event[0] ==  '!')
                {
                    event = event.substr(1);
                    if(ele.find(event) != ele.end() && dreamPos > ele[event]) dreamPos = ele[event];
                }
                else
                {
                    if(ele.find(event) == ele.end()) check = true;
                    else if(realPos < ele[event]) realPos = ele[event];
                }
            }
            if(check == false && dreamPos == i) cout << "Yes" << endl;
            else if(check == false && dreamPos > realPos) cout << i - dreamPos << " Just A Dream" << endl;
            else cout << "Plot Error" << endl;
        }

    }



}
