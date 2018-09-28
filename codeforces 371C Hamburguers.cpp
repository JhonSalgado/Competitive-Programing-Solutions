#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int B=0, C=0, S=0; //how many ingredients i need
int nB, nS, nC; //ingredients that i have
int pB, pS, pC; //prices
long long money;

long long dif(long long m){
  long long diferencia= money - ((0<(m*B-nB)*pB?(m*B-nB)*pB:0) + (0<(m*C-nC)*pC?(m*C-nC)*pC:0) + (0<(m*S-nS)*pS?(m*S-nS)*pS:0));
  return diferencia;
}

int main(){
	char ham[101];
	cin >> ham >> nB >> nS >> nC;
	cin >> pB >> pS >> pC >> money;
	int len= strlen(ham);
	for(int i=0; i<len; i++){
		if(ham[i]=='B')B++;
		if(ham[i]=='S')S++;
		if(ham[i]=='C')C++;
	}
	long long A=0;
	long long Z=10e12;
	long long m;
  	int min=B*pB + S*pS + C*pC;
  	long long ans=0;
	for(int i=0; i<50; i++){
    if(A>=Z)break;
		m=(A+Z)/2;
    	long long d=dif(m);
		if(d>=0 && d<min) {ans=m; A=m+1;} 
    	else if(d>=0)A=m+1;
		else Z=m;
	}
  cout << ans;
}