#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	vector <int> a(n);
	for(int i=0; i<n; i++){ 
		int aux;
		scanf("%d", &aux);
		a[i]=aux;
	}
	sort(a.begin(), a.end());

	double max=(double)a[0];
	int prev=a[0];
	for(int i=1; i<n; i++){
		double aux;
		aux=(a[i]-prev)/2.0;

		if(aux>max) max=aux;

		prev=a[i];
	}
	int aux=(l-a[n-1]);
	if(aux>max) max=aux;
	printf("%.9lf\n", max);
}