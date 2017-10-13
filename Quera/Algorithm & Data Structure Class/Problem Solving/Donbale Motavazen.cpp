//In The Name of Allah
//Sat 28/5/96
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
	string s;
	cin >> s;
	int open = 0,close = 0,change = 0;
	forar(i,s.length()){
		if(s[i] == '(')
			open++;
		else
			close++;
		if(open - close < 0){
			s[i] = '(';
			close--;
			open++;
			change++;
		}
	}
	open = close = 0;
	forar(i,s.length()){
		if(s[s.length() - i - 1] == ')')
			open++;
		else
			close++;
		if(open - close < 0){
			s[s.length() - i] = ')';
			close--;
			open++;
			change++;
		}
	}
	cout << change << endl;
}

