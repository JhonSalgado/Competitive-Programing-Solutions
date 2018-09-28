#include<bits/stdc++.h>
using namespace std;

long n, pl=-1, pr=500000, p[500001][2];

bool can(double mid){
  double rr=p[pr][0], lr=p[pl][0];
  long w;
  for(long i=pr; i<=pl; i++){
    if (p[i][1]>0){
      double aux=p[i][0]+p[i][1]*mid;
      if(aux>rr){rr=aux; w=i; lr=p[pl][0];}
    }
    else{
      double aux=p[i][0]+p[i][1]*mid;
      if(aux<lr)lr=aux;
    }
    if(lr<=rr){
      pr=w;
      return true;
    }
  }
  return false;
}

int main(){
	scanf("%ld", &n);
	for(int i=0; i<n; i++){
    scanf("%ld %ld", &p[i][0], &p[i][1]);
	}
	for(long i=0; i<n ;i++){
		if(p[i][1]>0){
      pr=i;
			break;
		}
	}
	for(long j=n-1; j>=0 ; j--){
		if(p[j][1]<0){
		  pl=j;
			break;
		}
	}
	if(pr>pl){
		cout<<"-1";
		return 0;
	}
	double ans=0;
	double lo=0.0, hi=1e9, mid=0.0;
	for(int i=0; i<70; i++){
		mid=(lo+hi)/2.0;
		if(can(mid)){ans=mid; hi=mid;}
		else lo=mid;
  }
	printf("%.10lf", ans);
}