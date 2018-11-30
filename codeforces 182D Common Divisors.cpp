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

int main()
{
	Zpow[0] = 1; for(int i = 1; i <= maxlen; ++i) Zpow[i] = z*Zpow[i-1]%MOD;

	string str;
	string str2;
	cin >> str >> str2;
	RollingHash roll(str);
	RollingHash roll2(str2);
	int len= str.length();
	int len2= str2.length();
	int min = len;
	if(len2 < min) min =len2;
	int contador=0;
	for(int i= 1; i<=min; i++){
		int p= len/i;
		int p2= len2/i;
		if(i*p!=len || i*p2!=len2)continue;
		ll h= roll.hash(0, i);
		ll h2= roll2.hash(0, i);
		bool cd=true;
		if(h!=h2){
			cd=false;
		}
		for(int j= 1; j<p && cd; j++){
			if(h!=roll.hash(j*i, i)){
				cd=false;
			}
		}
		for(int j= 1; j<p2 && cd; j++){
			if(h2!=roll2.hash(j*i, i)){
				cd=false;
			}
		}
		if(cd){
			contador++;
		}
	}
	printf("%d\n", contador);

	return 0;
}