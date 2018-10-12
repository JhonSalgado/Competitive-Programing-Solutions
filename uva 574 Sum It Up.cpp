#include <bits/stdc++.h>
using namespace std;

int t, n;
int li[15];
bool sol;

int backtrack(int pos, vector<int> num){
	int sum=0;
	for(int i=0; i<num.size(); i++){
		sum+=num[i];
	}
	if(sum==t){
		for(int i=0; i<num.size(); i++){
			printf("%d", num[i]);
			if(i<num.size()-1) printf("+");
		}
		printf("\n");
		sol=true;
		return 0;
	}
	else if(sum>t){
		return 0;
	}
  else{
	  if(pos==n-1) return 0;
    for(int i=pos+1; i<n; i++){
      if(i==pos+1){
        num.push_back(li[i]);
      }
      else{
        if(num[num.size()-1]==li[i]){
          continue;
        }
        else{
          num[num.size()-1]=li[i];
        }
      }
      backtrack(i, num);
    }
  }
  return 0;
}

int main(){
	while(scanf("%d %d", &t, &n) && n!=0){
		for(int i=0; i<n; i++){
			scanf("%d", &li[i]);
		}
		printf("Sums of %d:\n", t);
		sol=false;
		vector <int>v;
		backtrack(-1, v);
		if(!sol) printf("NONE\n");
	}
	return 0;
}