/*
ID: soroosh4
LANG: C++11
TASK: milk2
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("milk2.in","r",stdin),freopen("milk2.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

int dp[1000*1000+5];
int n;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	int m = 1;
	int m2 = 1000*1000;
	forar(i,n){
		int a,b;
		cin >> a >> b;
		dp[a]++;
		dp[b]--;
		m = max(m,b);
		m2 = min (m2,a);
	}
	int tempidle = 0,tempwork = 0,idle = 0,work = 0,farmer = 0;
	fori(i,m2,m){
		farmer += dp[i];
		if(farmer > 0){
			tempwork++;
			tempidle = 0;
		}else{
			tempidle++;
			tempwork = 0;
		}
		work = max(work,tempwork);
		idle = max(idle,tempidle);
	}
	cout << work << ' ' << idle << '\n';
	
}
