#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int n;
ll ans;

int f(string &s) {
	int tot = 0;
	for(int i = 0; i < (int) s.length(); i++) {
		tot ^= ((int) s[i]);
	}
	return tot;
}

int main() {
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	while(cin >> n)
    {
		if(n == 0) break;
		ans = 0;
        int u = 0;
		cin.ignore();
		unordered_map<string,int> C;
		unordered_map<int,int> M;
		for(int i = 0; i < n; i++) {
			getline(cin, s);
			int h = f(s);
            if(C[s]++ == 0) u++;
			M[h]++;
			ans += M[h] - C[s];
		}
		cout << u << " " << ans << "\n";
	}
}
