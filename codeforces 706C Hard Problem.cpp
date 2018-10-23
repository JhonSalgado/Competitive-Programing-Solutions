#include<bits/stdc++.h>
using namespace std;

int n, c[100001];

string revertir(string s){
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	cin>>n;

	for(int i=0; i<n; i++){
		cin>> c[i];
	}
	vector <string> words(n);
	for(int i=0; i<n; i++){
		cin>>words[i];
	}

	long long dp[n+1][2];
	dp[0][0]=0;
	dp[0][1]=c[0];

	for(int i=1; i<n; i++){
		dp[i][0]=1e16;
		dp[i][1]=1e16;

		//si no necesito revertir:
		if(words[i]>=words[i-1]){
			dp[i][0]=dp[i-1][0];
		}

		//si necesito revertir:
		if(revertir(words[i])>= words[i-1]){
			dp[i][1]=dp[i-1][0]+c[i];
		}
		
		//por si era mejor revertir el anterior:
		if(words[i]>=revertir(words[i-1])){
			dp[i][0]=min(dp[i-1][1], dp[i][0]);
		}

		//si es mejor revertir ambos:
		if(revertir(words[i])>= revertir(words[i-1])){
			dp[i][1]=min(dp[i-1][1]+c[i], dp[i][1]);
		}
	}
	long long ans=min(dp[n-1][0], dp[n-1][1]);
	if(ans<1e16){
		cout<<ans<<endl; 
	}
	else{
		cout<<-1<<endl;
	}
}
