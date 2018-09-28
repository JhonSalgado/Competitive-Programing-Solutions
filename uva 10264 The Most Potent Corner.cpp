#include <bits/stdc++.h>
using namespace std;

void calcularPotencia(int e1, int p[], int w[], int n){
	for(int j= 0; j<n; j++){
		int m1= 1 <<j;
		int e2= (e1 & ~m1) | ( ~(e1 & m1) & m1);
		p[e1]+=w[e2];
	}
}

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		int cantidadEsquinas= 1<<n;
		int w[cantidadEsquinas];
		int p[cantidadEsquinas];
		for(int i= 0; i< cantidadEsquinas; i++){
			scanf("%d", &w[i]);
			p[i]= 0;
		}
		int e1, e2, mejorSuma=0;
		for(e1= 0; e1< cantidadEsquinas; e1++){
			if(p[e1]==0)calcularPotencia(e1, p, w, n);
			for(int j= 0; j<n; j++){
				int m1= 1 <<j;
				e2= (e1 & ~m1) | ( ~(e1 & m1) & m1);
				if(p[e2]==0)calcularPotencia(e2, p, w, n);
				int sum= p[e1]+p[e2];
				if(sum>mejorSuma)mejorSuma= sum;
			}
		}

		printf("%d\n", mejorSuma);
	}

	return 0;
}