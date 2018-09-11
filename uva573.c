#include <cstdio>
using namespace std;

int main() {	
	float H, U, D, F, hActual;
	while(scanf("%f %f %f %f", &H, &U, &D, &F) && (H!=0)){
	    hActual=0;
        for(int i=0;;i++){
          float aux=1-(i)*F/100;
          if(aux<0)aux=0;
	        hActual=hActual+U*aux;
	        if(hActual>H){
	           printf("success on day %d\n", i+1);
	           break;
            }
            hActual=hActual-D;
            if(hActual<0){
                printf("failure on day %d\n", i+1);
                break;
            }
        }
	}
}
