//In The Name of Allah
//Thu 31/2/97
#pragma GCC optimize "-Ofast"
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

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int n;
	cin >> n;
	int suma=0,sumb=0;
	vector<int> lst;
	forar(i,n/2){
		int a;
		cin >> a;
		lst.pb(--a);
	}
	sort(lst.begin(),lst.end());
	forar(i,n/2){
		int a = lst[i];
		suma += abs(a-2*i);
		sumb += abs(a-2*i-1);
	}
	cout << min(suma,sumb) << endl;
}
