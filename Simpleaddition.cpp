#include <bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s1, s2, ss = "";
    cin >> s1 >> s2;
    int carry = 0;
    int l1 = s1.length(), l2 = s2.length(), lmax = max(l1,l2);
    if(l1 < l2) while(s1.length() < l2) s1 = '0' + s1;
    if(l2 < l1) while(s2.length() < l1) s2 = '0' + s2;
    for(int i = lmax - 1; i >= 0 ; i--)
    {
        int val1 = s1[i] - '0';
        int val2 = s2[i] - '0';
        int sum = val1 + val2 + carry;
        ss = char(sum%10 + 48) + ss;
        carry = sum/10;
    }
    if(carry == 1) ss = '1' + ss;
    cout << ss;
}
