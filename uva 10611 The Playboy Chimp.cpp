#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	scanf("%d", &m);
	int h[m];
	for(int i=0; i<m; i++) scanf("%d", &h[i]);
	scanf("%d", &n);
	int p[n];
	for(int i=0; i<n; i++) scanf("%d", &p[i]);
	for(int i=0; i<n; i++){
		int A=0, B=m, mid;
		if(m==1){
			if(p[i]>h[0])printf("%d %c\n", h[0], 'X');
			else if(p[i]<h[0])printf("%c %d\n", 'X', h[0]);
			else printf("%c %c\n", 'X', 'X');
			continue;
		}
		while(A<B){
			mid=A+(B-A)/2;
			if(p[i]>h[mid]){
				if(mid==m-1){
					printf("%d %c\n", h[mid], 'X');
					break;
				}
				if(p[i]==h[mid+1]){
					int aux1=mid;
					int aux2;
					mid++;
					while(p[i]==h[mid++] && mid<m){
						aux2=mid;
					}
					if (p[i]<h[aux2]) printf("%d %d\n", h[aux1], h[aux2]);
					else printf("%d %c\n", h[aux1], 'X');
					break;
				}
				else if(p[i]<h[mid+1]){
					printf("%d %d\n", h[mid], h[mid+1]);
					break;
				}
				else{
					A=mid+1;
					if(A<m-1)continue;
				}
			}
			else{
				B=mid;
				if(B>0)continue;
			}
			if(B==0) {
				if(p[i]>h[0])printf("%c %d\n", 'X', h[0]);
				else if(p[i]<h[0])printf("%d %c\n", h[0], 'X');
				else{
					int aux;
					while(p[i]==h[mid++] && mid<m){
						aux=mid;
					}
					if(p[i]<h[aux])printf("%c %d\n", 'X', h[aux]);
					else printf("%c %c\n", 'X', 'X');
				}
			}
		}
	}
}