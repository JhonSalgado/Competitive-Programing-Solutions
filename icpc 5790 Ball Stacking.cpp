#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int balls[1005][1005];
ll sum[1005];
ll best[1005];
int main(){

  while(scanf("%d", &n) && n!=0){
    memset(balls, 0, sizeof(balls));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            scanf("%d", &balls[i][j]);
        }
    }
    sum[1]=balls[1][1];
    for(int i=2; i<=n; i++){
        sum[i]=sum[i-1]+balls[i][1];
    }
    best[n]=sum[n];
    for (int i = n-1; i>=1; i--){
        best[i]=max(best[i+1], sum[i]);
    }
    for (int j = 2; j<=n; ++j){   
        int added=0;
        for (int i=j; i<=n; ++i){
            sum[i]=best[i-1]+balls[i][j]+added;
            added+=balls[i][j];
        }
        best[n]=sum[n];
        for (int i=n-1; i>=j; i--){
            best[i]=max(best[i+1], sum[i]);
        }
    }
    ll ans=0;
    for (int i=1; i<=n ; ++i){
        if(best[i]>ans)ans=best[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}