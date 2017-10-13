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
	map<char,char> ex;
	string s1,s2;
	cin >> s1 >> s2;
	forar(i,26){
		ex[s1[i]] = s2[i];
		ex[char(toupper(s1[i]))] = char(toupper(s2[i]));
	}
	fori(i,'0','9'+1){
		ex[i] = i;
	}
	string t;
	cin >> t;
	forar(i,t.length()){
		cout << ex[t[i]];
	}
}