#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    map<string, int> var;
    string s, ss;
    int n, calc;
    while(cin >> s)
    {
        if(s == "clear")
        {
            var.clear();
        }
        if(s == "def")
        {
            cin >> ss >> n;
            var[ss] = n;
        }
        if(s == "calc")
        {
            calc = 0;
            string op = "", ans = "";
            map<string, int>::iterator it;
            while(cin >> ss)
            {
                it = var.find(ss);
                cout << ss << " ";
                if(ss == "+" || ss == "-")  op = ss;
                else if(ss == "=")
                {
                    if(ans == "unknown") cout << "unknown" << endl;
                    else
                    {
                        bool check = false;
                        for(it = var.begin(); it != var.end(); it++)
                        {
                            if(it->second == calc)
                            {
                                cout << it->first << endl;
                                check = true;
                            }
                        }
                        if(check == false) cout << "unknown" << endl;
                    }
                    break;
                }
                else
                {
                    if(it != var.end())
                    {
                        if(op == "+")
                        {
                            calc = calc + var[ss];
                        }
                        else if(op == "-")
                        {
                            calc = calc - var[ss];
                        }
                        else
                        {
                            calc = var[ss];
                        }
                    }
                    else ans = "unknown";
                }
            }
        }
    }
}
