//In The Name of Allah
//Mon 18/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 500;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,ans;
struct circle
{
	ll x,y,r;
} circs[M];
vector<int> adj[M];
bool mark[M];
int match[M];

bool isInscribed(circle a,circle b){ //is b in a
	ll odist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	ll dif = (a.r-b.r)*(a.r-b.r);
	return dif>odist && a.r>b.r;
}

bool dfs(int v){
	if(mark[v])
		return false;
	mark[v] = 1;
	for(int neib : adj[v]){
		if(match[neib] == -1 || dfs(match[neib])){
			match[neib] = v;
			return true;
		}
	}
	return false;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> circs[i].x >> circs[i].y >> circs[i].r;
	}
	forar(i,n){
		forar(j,n){
			if(isInscribed(circs[i],circs[j])){
				adj[i].pb(j);
			}
		}
	}
	fill(match,match+n,-1);
	forar(i,n){
		memset(mark,0,sizeof mark);
		dfs(i);
	}
	forar(i,n){
		if(match[i] == -1)
			++ans;
	}
	cout << ans << endl;
}
