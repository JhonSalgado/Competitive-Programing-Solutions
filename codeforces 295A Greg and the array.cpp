#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lefto=0, righto=1, value=2;

int main(){
	int n, ops, qrs;
	cin >> n >> ops >> qrs;
	
	ll nums[n+1]={};
	for (int i=1; i<=n; i++){
		cin >> nums[i];
	}
	
	ll op[ops+5][3];
	for(int i=1; i<=ops; i++){
		cin >> op[i][lefto] >> op[i][righto] >> op[i][value];
	}

	ll op_at[ops+5]={};
	while(qrs--){
		int l, r;
		cin >> l >> r;

		op_at[l]++;
		op_at[r+1]--;
	} 

	ll uses[ops+1]={};
	for (int i=1; i <=ops; i++)
	{
		uses[i]=uses[i-1]+op_at[i];
	}

	ll updates[n+5]={};
	for (int i=1;i<=ops; i++){
		updates[op[i][lefto]]+=uses[i] * 1LL * op[i][value];
		updates[ op[i][righto]+1 ]-=uses[i] * 1LL * op[i][value];
	}

	ll add[n+5]={};
	for(int i=1; i<=n; i++){
		add[i]= add[i-1] + updates[i];
	}

	for(int i=1; i<=n; i++){
		nums[i]+=add[i];
	}

	for(int i=1; i<=n; i++){
		cout << nums[i] <<" ";
	}
	return 0;
}