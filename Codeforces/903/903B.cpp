//In The Name of Allah
//Tue 21/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int h1,a1,c1;
int h2,a2;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<bool>ans;
	while(h2 > 0){
		if(a1 >= h2){
			h2-=a1;
			ans.pb(1);
			continue;
		}
		if(a2 >= h1){
			ans.pb(0);
			h1 += c1;
			h1 -= a2;
			continue;
		}
		ans.pb(1);
		h2 -= a1;
		h1 -= a2;
	}
	cout << ans.size() << endl;
	for(bool x : ans){
		cout << (x?"STRIKE":"HEAL") << endl;
	}
}
