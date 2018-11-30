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
	cin >> str ;
	RollingHash roll(str);
	int len= str.length();
	bool b;
	int ward=-1;
	for(int i= 1; i<len; i++){
		ll hp= roll.hash(0, i);
		ll hs= roll.hash(len-i, i);
		b=true;
		if(hp!=hs){
			b=false;
		}
		if(b){
			b=false;
			for(int j = len-i-1; j>0; j--){
				b = b || hp==roll.hash(j, i);
				if (b){
					ward=i;
					break;
				}
			}
		}
	}
	if(ward>0) cout << str.substr(0,ward) <<endl;
	else cout << "Just a legend" <<endl;
	return 0;
}