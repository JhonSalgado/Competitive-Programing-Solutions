#include <bits/stdc++.h>
using namespace std;

int nSec;
int indices[100003];
int inicios[100003];
int arbol[100003];

void CrearArbol(int nodo, int ini, int fin){
	if(ini + 1 == fin){
		arbol[nodo] = inicios[ini + 1] - inicios[ini];
		return;
	}

	int hijo1 = nodo*2;
	int hijo2 = hijo1+1;
	int m = (ini+fin)/2;

	CrearArbol(hijo1, ini, m);
	CrearArbol(hijo2, m, fin);

	arbol[nodo] = max(arbol[hijo1], arbol[hijo2]);
}

int Consulta(int nodo, int ini, int fin, int cstini, int cstfin){
	if( ini >= cstfin || fin <= cstini) return 0;
	if( ini >= cstini && fin <= cstfin) return arbol[nodo];

	int hijo1 = nodo*2;
	int hijo2 = hijo1+1;
	int m = (ini+fin)/2;	

	return max(Consulta(hijo1,  ini, m, cstini, cstfin), 
			   Consulta(hijo2, m, fin, cstini, cstfin));
}

int main(){
	int n, c;
	while (cin >> n >> c, n){
		int secster = 0;
		int previo;
		indices[1]=0;
		inicios[0]=1;
		cin >> previo;
		for (int i = 2; i <= n; ++i)
		{
			int actual;
			cin >> actual;
			
			if(previo != actual){
				secster++;
				inicios[secster] = i;
				previo = actual;
			}
			indices[i] = secster;
		}
		secster++;
		inicios[secster]=n+1;
		nSec = secster;

		CrearArbol(1, 0, nSec);

		while(c--){
			int ini, fin;
			cin >> ini >> fin;
			int primera = indices[ini];
			int ultima = indices[fin];
			int mejor = min(inicios[primera + 1], fin +1) - 
						max(inicios[primera], ini);
			if(primera != ultima){
				mejor = max(mejor, min(inicios[ultima + 1], fin +1) - inicios[ultima]);
				int q= Consulta(1, 0, nSec, primera+1, ultima);
				//cout <<"consulta: " <<q << endl;
				mejor = max(mejor, q); 
			}
			cout << mejor << endl;
		}
	}
}