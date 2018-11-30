#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll z = 127, MOD = 1e9+7;
const int maxlen = 1e6;
ll Zpow[maxlen+1];

struct RollingHash
{
	vector<ll> suffixHash;

	RollingHash(string &S)
	{
		int N = S.length();
		suffixHash.resize(N+1,0);
		for(int i = N-1; i >= 0; --i)
			suffixHash[i] = (z*suffixHash[i+1]+S[i])%MOD;
	}

	ll hash(int i, int len)
	{
		return (suffixHash[i]-Zpow[len]*suffixHash[i+len]%MOD+MOD)%MOD;
	}
};

string rev(string str){
	string ret;
	int len = str.length();
	ret.resize(len);
	for(int i=0; i<len; i++){
		ret[i]=str[len-1-i];
	}
	return ret;
}

int main()
{
	Zpow[0] = 1; for(int i = 1; i <= maxlen; ++i) Zpow[i] = z*Zpow[i-1]%MOD;
	int k;
	string str;
	cin >> k >> str;
	int len = str.length();
	int contador=0;
	string re= rev(str);
	RollingHash roll(str);
	RollingHash roll2(re);
	for (int i = 0; i <= len-k; ++i)
	{		
		if(roll.hash(i,k)==roll2.hash(len-i-k,k)) contador++;
	}
	cout << contador << endl;;

	return 0;
}