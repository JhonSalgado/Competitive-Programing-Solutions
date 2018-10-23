#include<bits/stdc++.h>
using namespace std;

int main(){
	int p, c, s;
	scanf("%d %d %d", &p, &c ,&s);
	int pos=1;
	int con=0;
	if(s==1) con++;
	for(int i=0; i<c; i++){
		int com;
		scanf("%d", &com);
		if(com==1){ 
			if(pos<p)pos++;
			else pos=1;
		}
		else { 
			if(pos>1) pos--;
			else pos=p;
		}
		if(pos==s) con++;
	}
	printf("%d\n", con);
}