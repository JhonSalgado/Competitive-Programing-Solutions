#include <iostream>
#include <string>

int main()
{
  int n;
  int i=0;
  while(scanf("%d", &n) && n!=0){
    if(i>0)printf("\n");
    i++;
    int c=0;
    for(int b=1234; b<=98765/n; b++){
        int a=b*n;
        int aux, used=(b<10000);
        aux=a;
        while(aux){
            used |= 1 << (aux%10);
            aux/=10;
        }
        aux=b;
        while(aux){
            used |= 1 << (aux%10);
            aux/=10;
        }
        if(used==(1<<10)-1){ 
            printf("%0.5d / %0.5d = %d\n", a, b, n);
            c++;}
    }
    if(c==0)printf("There are no solutions for %d.\n",n);
  }
}
