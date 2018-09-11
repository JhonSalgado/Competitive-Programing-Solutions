#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;

int main(){
    int k, n ,m;
    char p[2];
    scanf("%d", &k);
    while(k--){
        scanf("%s %d %d", p, &n, &m);
        int corto;
        int largo;
        if(n<=m){corto=n;largo=m;}
        else {corto=m;largo=n;}
        if(p[0]=='r' || p[0]=='Q'){
            printf("%d\n",corto);
        }
        else if(p[0]=='k'){
            printf("%d\n", ((largo+1)/2)*((corto+1)/2)+(largo/2)*(corto/2));
        }
        else if(p[0]=='K'){
            printf("%d\n", ((m+1)/2)*((n+1)/2));
        }
    }
}