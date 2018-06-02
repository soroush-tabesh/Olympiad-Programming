//In The Name of Allah
//Tue 8/3/97
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

const ll mod = 1e9+7,M = 1e6+100;

void Solution();

int n,cmp;
int arr[M];
bool mark[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	fori(i,1,n+1){
		cin >> arr[i];
	}
	fori(i,1,n+1){
		if(!mark[i]){
			int x = i;
			do{
				mark[x] = 1;
				x = arr[x];
			}while(x != i);
			cmp++;
		}
	}
	int chn = n-cmp;
	if((n%2 == 0) ^ (chn % 2 == 0))
		cout << "Um_nik" << endl;
	else
		cout << "Petr" << endl;
}
