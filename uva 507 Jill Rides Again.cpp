#include<bits/stdc++.h>
using namespace std;

 int TCs, s, r[20005];
 int TC=1;

int main(){
	scanf("%d", &TCs);
	while(TCs--){
		scanf("%d", &s);
		for(int i=0; i<=s-2; i++){
			scanf("%d", &r[i]);
		}
		int sum=0, ans=0;
		int curi=1, curj=2;
		int besti=1, bestj=2;

		for (int i = 0; i <= s-2; i++){
			
			sum+=r[i];

			if(sum==ans){
				curj=i+2;
				if(curj-curi>bestj-besti){
					besti=curi;
					bestj=curj;
				}
			}
			if(sum>ans){
				besti=curi;
				curj=i+2;
				bestj=curj;
				ans=sum;
			}

			if(sum<0){
				sum=0;
				curi=i+2;
			} 
		}
		if(ans<=0){
			printf("Route %d has no nice parts\n", TC++);
			continue;
		}
		printf("The nicest part of route %d is between stops %d and %d\n", TC++, besti, bestj);
	}
	return 0;
}