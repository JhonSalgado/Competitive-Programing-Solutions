#include<cstdio>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    int nReq, n;
    float price, comp, max, lowerPrice, nProp, cump;
    char trash[100], propName[100], ans[100];
    n=1;
    while(scanf("%d %f", &nReq, &nProp) && nReq!=0 && nProp!=0){
      max=0;
      lowerPrice=10000000;
      for(int i=0; i<=nReq; i++){
          fgets(trash, 100, stdin);
      }
      while(nProp--){
          fgets(propName, 100, stdin);
          scanf("%f %f", &price, &cump);
          for(int j=0; j<=cump; j++){
              fgets(trash, 100, stdin);
          }
          comp=cump/nReq;
          if(comp>max){
            max=comp;
            lowerPrice=price;
            strcpy(ans, propName);
          }
          if(comp==max){
            if(price<lowerPrice)strcpy(ans,propName);
          }
      }
      if(n>1)printf("\n");
      printf("RFP #%d\n", n++);
      printf("%s", ans);     
    }
}