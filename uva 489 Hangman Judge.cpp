#include<iostream>
#include<string.h>
#include<cstdio>
#include <cstring>
using namespace std;

int main(){
  int round; 
  uint c, er;
  char correct[256];
  char input[256];
  int checked[30];
  while(scanf("%d", &round) && round!=-1){
    printf("Round %d\n", round);
    for(int l=0; l<30; l++)checked[l]=0;
    er=0;
    c=0;
    scanf("%s", correct);
    scanf("%s", input);
    bool b=false;
    for(uint i=0; i<strlen(input);){
        if(checked[input[i]-'a']){
            i++;
            continue;
        }
        char* is=strchr(correct, input[i]);
        if(is==NULL && !b){
            checked[input[i]-'a']=1;
            er++;
            i++;
            if(er>=7){
                printf("You lose.\n");
                break;
            }
        }
        else if(is==NULL && b){
            checked[input[i]-'a']=1;
            b=false;
            i++;
        }
        else{
            c++;
            if(c>=strlen(correct)){
                printf("You win.\n");
                break;
            }
            is[0]='X';
            b=true;
        }
    }
    if(er<7 && c<strlen(correct))printf("You chickened out.\n");
  }
}