#include<cstdio>
#include <stdio.h>
#include<string.h>
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){
    char state='0';
    int sum=0;
    char tiro[2];
    int k=0;
    bool first=true;
    while(scanf("%s", tiro)&& tiro[0]!='G'){
      if(tiro[0]=='X'){
        if(state=='3'){
          sum+=10;
          state='2';
        }
        if(state=='X'){
          state='2';
        }
        if(state=='2'){
          sum+=20;
          state='3';
        }
        else if(state=='/'){
          sum+=20;
          state='X';
        }
        else {
          state='X';
          sum+=10;
        }
        k++;
        if(k==10){
          scanf("%s", tiro);
          if(tiro[0]=='X'){
            if(state=='3')sum+=10;
            sum+=10;
            scanf("%s", tiro);
            if(tiro[0]=='X')sum+=10;
            else sum+=atoi(tiro);
          }
          else{
            int aux=atoi(tiro);
            if(state=='3')sum+=aux;
            scanf("%s", tiro);
            if(tiro[0]=='/')sum+=10;
            else sum+=atoi(tiro)+aux;
          }
        }
      }
      else{
        int aux=atoi(tiro);
        if(state=='/'){
          sum+=aux;
          state='0';
        }
        if(state=='2' ||state=='3'){
          sum+=aux;
          state='X';
        }
        if(state=='X'){
          sum+=aux;
          state='/';
        }
        sum+=aux;
        scanf("%s", tiro);
        if(tiro[0]=='/'){
          if(state=='/')sum+=(10-aux);
          sum+=(10-aux);
          k++;
          state='/';
          if(k==10){
            scanf("%s", tiro);
            if(tiro[0]=='X')sum+=10;
            else sum+=atoi(tiro);
          }
        }
        else{
          if(state=='/'){
            sum+=atoi(tiro);
            state=0;
          }
          sum+=atoi(tiro);
          k++;
        }
      }
      if(k==10){
        printf("%d\n", sum);
        sum=0;
        k=0;
        state='0';
      }
    }
}
