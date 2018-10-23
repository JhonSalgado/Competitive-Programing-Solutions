#include <bits/stdc++.h>
using namespace std;

int c1, c2, c3;

int main(){

	while(scanf("%d %d %d", &c1, &c2, &c3) && c1!=0){
		if(c1==c2 && c2==c3){
			if(c1==13){
				printf("*\n");
			}
			else{
				printf("%d %d %d\n", c1+1, c2+1, c3+1);
			}
		}

		else if(c1==c2){
			if(c1==13){
				if(c3==12){
					printf("1 1 1\n");
				}
				else{
					printf("%d %d %d\n", c3+1, c1, c2);
				}
			}
			else{
				if(c3==c1-1){
					if(c3+2>c1){
						printf("%d %d %d\n", c1, c2, c3+2);
					}
					else{
						printf("%d %d %d\n", c3+2, c1, c2);
					}
				}
				else if(c3==13){
					printf("1 %d %d\n", c1+1, c2+1);
				}
				else{
					if(c3>c1) printf("%d %d %d\n", c1, c2, c3+1);
					else printf("%d %d %d\n", c3+1, c1, c2);
				}
			}
		}
		else if(c1==c3){
			if(c1==13){
				if(c2==12){
					printf("1 1 1\n");
				}
				else{
					printf("%d %d %d\n", c2+1, c1, c3);
				}
			}
			else{
				if(c2==c1-1){
					if(c2+2>c1){
						printf("%d %d %d\n", c1, c3, c2+2);
					}
					else{
						printf("%d %d %d\n", c2+2, c1, c3);
					}
				}
				else if(c2==13){
					printf("1 %d %d\n", c1+1, c3+1);
				}
				else{
					if(c2>c1) printf("%d %d %d\n", c1, c3, c2+1);
					else printf("%d %d %d\n", c2+1, c1, c3);
				}
			}
		}

		else if(c3==c2){
			if(c3==13){
				if(c1==12){
					printf("1 1 1\n");
				}
				else{
					printf("%d %d %d\n", c1+1, c3, c2);
				}
			}
			else{
				if(c1==c3-1){
					if(c1+2>c3){
						printf("%d %d %d\n", c3, c2, c1+2);
					}
					else{
						printf("%d %d %d\n", c1+2, c1, c3);
					}
				}
				else if(c1==13){
					printf("1 %d %d\n", c3+1, c2+1);
				}
				else{
					if(c1>c3) printf("%d %d %d\n", c3, c2, c1+1);
					else printf("%d %d %d\n", c1+1, c3, c2);
				}
			}
		}

		else{
			printf("1 1 2\n");
		}
	}
	return 0;

}