#include <cstdio>
using namespace std;

int main() {	
	int nCuotas, deval, mes; 
	double pie, loan, per, carValue, cuotaValue;
	while (scanf("%d %lf %lf %i", &nCuotas, &pie, &loan, &deval) && (nCuotas>0)) {
	    carValue=pie+loan;
	    cuotaValue=loan/nCuotas;
	    float devals[nCuotas];
	    for(int j=0; j<nCuotas; j++)devals[j]=0.0;
    	while(deval--){
    	    scanf("%d %lf",&mes, &per);
    	    devals[mes]=per;
        }
        double dev=devals[0];
        for(int i=0; i<=nCuotas; i++){
            if(devals[i]!=dev && devals[i]>0)dev=devals[i];
            carValue=carValue-carValue*dev;
            if(carValue>loan-i*cuotaValue){
                if(i==1)printf("%d month\n", i);
                else printf("%d months\n", i);
                break;
                }
        }
	}
}
