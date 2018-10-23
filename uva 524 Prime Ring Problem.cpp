#include <bits/stdc++.h>
using namespace std;

int n;
int ring [17];

bool can(int a, int pos){
	for (int i = 1; i < pos; ++i)
	{
		if(a==ring[i])return false;
	}
	int c=a+ ring[pos-1];
	for (int i = 2; i < c; ++i)
	{
		if(c%i==0) return false;
	}
	if(pos==n){
		c=a+1;
		for (int i = 2; i < c; ++i)
		{
			if(c%i==0) return false;
		}
	}
	return true;
}

void backtrack(int pos){
	if(pos==n+1){
		for (int i = 1; i <= n; ++i)
		{
			printf("%d", ring[i]);
			if(i<n) printf(" ");
		}
		printf("\n");
	}
	for(int i=2; i<=n; i++){
		if(can(i, pos)){
			ring[pos]=i;
			backtrack(pos+1);
		}
	}
}

int main(){
	int c=1;
	while(scanf("%d", &n)!=EOF){
		if(n==1){printf("1\n"); continue;}
		memset(ring, 0, sizeof(ring));
		ring[1]=1;
		if(c>1)printf("\n");
		printf("Case %d:\n", c);
		backtrack(2);
		c++;
	}
	return 0;
}