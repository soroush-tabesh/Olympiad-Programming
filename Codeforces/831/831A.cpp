//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	ll n;
	cin >> n;
	string s;
	char state = '-';
	ll last = 0;
	cin >> last;
	forar(i,n-1){
		ll cur;
		cin >> cur;
		char curst;
		if(cur>last)
			curst = 'i';
		else if(cur == last)
			curst = 'c';
		else
			curst = 'd';
		if(state != curst){
			s+=curst;
			state = curst;
		}
		last = cur;
	}
	//cout << s << endl;
	if(s == "icd" || s == "cd" || s == "ic" || s == "c" || s=="id" || s == "i" || s == "d" || s=="")
		cout << "YES";
	else
		cout << "NO";
}