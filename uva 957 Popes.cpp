#include<bits/stdc++.h>
using namespace std;

long Y, N, P[100000];

int main() {
  while(scanf("%ld", &Y)!=EOF){
    scanf("%ld", &N);
    for(long i=0; i<N; i++){
      scanf("%ld", &P[i]);
    }
    /*for(long i=0; i<N; i++){
      printf("%ld ", P[i]);
    }*/
    long max=0, fs, ls;
    for(long year=0; year<=1000000; year++){
      long first=100000, last=0;
			long lo=0, hi=N-1, mid=0;
			for(int i=0; i<20; i++){
				mid=(hi+lo)/2;
				if(P[mid]>=year){if(P[mid]>year+Y-1)break; hi=mid; first=mid;}
				else(lo=mid+1);
			}
      //printf("first: %ld %ld\n", first, P[first]);
      lo=first, hi=N-1, mid=0;
      for(int i=0; i<20; i++){
				mid=(hi+lo)/2;
				if(P[mid]<=year+Y-1){lo=mid+1; last=mid;}
				else(hi=mid);
			}
      //printf("last: %ld %ld\n", last, P[last]);
      if(last-first+1>max){
        max=last-first+1;
        fs=first;
        ls=last;
      }
      //printf("%ld %ld %ld\n", max, fs, ls);
    }
    printf("%ld %ld %ld\n", max, P[fs], P[ls]);
  }
}