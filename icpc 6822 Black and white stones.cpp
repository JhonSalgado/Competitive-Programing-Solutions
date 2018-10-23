#include<bits/stdc++.h>
using namespace std;

char sec[100001];
int p, r;


int main(){
	while(scanf("%d %d", &p, &r)!=EOF){
		scanf("%s", sec);
		int len=strlen(sec);
		int dif=0;
		if(r>0) dif=p/(p-r);
		int total=0;
		int nB=0;
		for (int i = 0; i < len; ++i)
		{
			if(sec[i]=='B')nB++;
		}
		int i=nB-1;
		int j=nB;
		while(i>=0 && j<len){
			if(sec[i]=='B'){i--; continue;}
			if(sec[j]=='W'){j++; continue;}
			if(j-i>dif){
				total+=p;
				i--;
				j++;
				continue;
			}
			else{
				total+=(p-r)*(j-i);
				i--;
				j++;
				continue;
			}
		}
		printf("%d\n", total);
	}
}