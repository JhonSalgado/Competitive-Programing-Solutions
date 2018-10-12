#include <bits/stdc++.h>
using namespace std;

int n, k, c[10005];

int moda(int* a){
	if(k==3 && a[1]!=a[2] && a[1]!=c[3] && a[2]!=a[3]){
		return (a[1]+a[2]+a[3])/3;
	}
	int rep[n+5];
	int max=0;
	int m=0;
	memset(rep, 0, sizeof(rep));
	for(int i=1; i<=k; i++){
		rep[a[i]]++;
		if(rep[a[i]]>max){ max=rep[a[i]]; m= a[i];}
	}
	return m;
}

int main(){
	while(scanf("%d %d", &k, &n)!=EOF){
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; ++i)
		{
			int aux;
			scanf("%d", &aux);
			c[aux]++;
		}
		//for(int i=1; i<=k; i++){ printf("%d", c[i]);}
		int m=moda(c);
		//printf("moda: %d\n", m);
		char sol[2];
		int sol1=-1, sol2=-1;
		bool b=true;
		for(int i=1; i<=k && b; i++){
			if(c[i]==m){
				continue;
			}
			else if(c[i]==m+1){
				sol[0]='-';
				sol1=i;
				if(i==k){
					printf("%c%d\n",sol[0], sol1);
					b=false;
					break;
				}
				for (int j = i+1; i <= k && b; ++j)
				{
					if(c[j]==m){
						if(j==k){
							printf("%c%d\n",sol[0], sol1);
							b=false;
						}
						continue;
					}
					else if (c[j]==m-1){
						sol[1]='+';
						sol2=j;
						if(j==k){
							printf("%c%d %c%d\n", sol[0], sol1, sol[1], sol2);
							b=false;
							continue;
						}
						for(int h=j+1; h<=k && b; h++){
							if(c[h]!=m){
								printf("*\n");
								b=false;
							}
						}
						if(b) printf("%c%d %c%d\n", sol[0], sol1, sol[1], sol2);
						b=false;
					}
					else{
						printf("*\n");
						b=false;
					}
				}
			}
			else if(c[i]==m-1){
				sol[0]='+';
				sol1=i;
				if(i==k){
					printf("%c%d\n",sol[0], sol1);
					b=false;
					break;
				}
				for (int j = i+1; i <= k && b; ++j)
				{
					if(c[j]==m){
						if(j==k){
							printf("%c%d\n",sol[0], sol1);
							b=false;
						}
						continue;
					}
					else if (c[j]==m+1){
						sol[1]='+';
						sol[0]='-';
						sol2=sol1;
						sol1=j;
						if(j==k){
							printf("%c%d %c%d\n", sol[0], sol1, sol[1], sol2);
							b=false;
							continue;
						}
						for(int h=j+1; h<=k && b; h++){
							if(c[h]!=m){
								printf("*\n");
								b=false;
							}
						}
						if(b) printf("%c%d %c%d\n", sol[0], sol1, sol[1], sol2);
						b=false;
					}
					else{
						printf("*\n");
						b=false;
					}
				}
			}
			else{
				printf("*\n");
				b=false;
			}
		}
	}
	return 0;
}