#include<cstdio>
#include<string.h>
#include<iostream> 
using namespace std;

int main(){
  int L;
  char order[3], ans[3];
  while(scanf("%d", &L)&&L!=0){
    strcpy(ans, "+x");
    for(int i=L-1; i>=1; i--){
        scanf("%s", order);
        if(strcmp(order, "No")==0)continue;
        else if(strcmp(order, "+y")==0){
          if(strcmp(ans, "+x")==0)strcpy(ans,"+y");
          else if(strcmp(ans, "-x")==0)strcpy(ans,"-y");
          else if(strcmp(ans, "+y")==0)strcpy(ans,"-x");
          else if(strcmp(ans, "-y")==0)strcpy(ans,"+x");
          else if(strcmp(ans, "+z")==0)strcpy(ans,"+z");
          else if(strcmp(ans, "-z")==0)strcpy(ans,"-z");
        }
        else if(strcmp(order, "-y")==0){
          if(strcmp(ans, "+x")==0)strcpy(ans,"-y");
          else if(strcmp(ans, "-x")==0)strcpy(ans,"+y");
          else if(strcmp(ans, "+y")==0)strcpy(ans,"+x");
          else if(strcmp(ans, "-y")==0)strcpy(ans,"-x");
          else if(strcmp(ans, "+z")==0)strcpy(ans,"+z");
          else if(strcmp(ans, "-z")==0)strcpy(ans,"-z");
        }
        else if(strcmp(order, "+z")==0){
          if(strcmp(ans, "+x")==0)strcpy(ans,"+z");
          else if(strcmp(ans, "-x")==0)strcpy(ans,"-z");
          else if(strcmp(ans, "+y")==0)strcpy(ans,"+y");
          else if(strcmp(ans, "-y")==0)strcpy(ans,"-y");
          else if(strcmp(ans, "+z")==0)strcpy(ans,"-x");
          else if(strcmp(ans, "-z")==0)strcpy(ans,"+x");
        }
        else{
          if(strcmp(ans, "+x")==0)strcpy(ans,"-z");
          else if(strcmp(ans, "-x")==0)strcpy(ans,"+z");
          else if(strcmp(ans, "+y")==0)strcpy(ans,"+y");
          else if(strcmp(ans, "-y")==0)strcpy(ans,"-y");
          else if(strcmp(ans, "+z")==0)strcpy(ans,"+x");
          else if(strcmp(ans, "-z")==0)strcpy(ans,"-x");
        }
    }
    printf("%s\n", ans);
  }
}