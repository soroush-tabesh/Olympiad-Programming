//In The Name of Allah
//Tue 3/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(4)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef __int128 lll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	int _t;
	cin >> _t;
	while(_t--)
		Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

struct dsu{
	int par[M],sz[M],n;
	void init(int tn){
		n = tn;
		forar(i,tn){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return (x == par[x] ? x : par[x] = find(par[x]));
	}
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b)
			return false;
		if(sz[a] < sz[b])
			swap(a,b);
		sz[a] += sz[b];
		par[b] = a;
		return true;
	}
};

int n,k;
vector<pair<ld,pii> > edges;
dsu cmps;

pair<ll,ll> check(ld bias){
	auto cp = edges;
	forar(i,n){
		cp[i].F += bias;
	}
	sort(all(cp));
	cmps.init(n+1);
	ll ccn = 0;
	ld res = 0;
	for(auto x : cp){
		if(cmps.join(x.S.F,x.S.S)){
			res += x.F;
			if(x.S.S == n)
				ccn++;
		}
	}
	cout << "Log " << res-ccn*bias << " " << ccn << " " << bias << " " << res << endl;
	return {llround(res-k*bias),ccn};
}

inline void Solution(){
	cin >> n >> k;
	edges.clear();
	forar(i,n){
		int w;
		cin >> w;
		edges.pb({w,{i,n}});
	}
	vector<pair<ll,pii> > tlist;
	forar(i,n){
		forar(j,n){
			int w;
			cin >> w;
			if(i < j)
				tlist.pb({w,{i,j}});
		}
	}
	sort(all(tlist));
	cmps.init(n+1);
	for(auto x : tlist)
		if(cmps.join(x.S.F,x.S.S))
			edges.pb(x);
	ld l = 0,r = 3e2;
	while(r-l>1e-3){
		ll mid = (l+r)/2;
		if(check(mid).S <= k)
			r = (2*r+l)/3;
		else
			l = (2*l+r)/3;
	}
	cout << check(l).F << endl;
}
