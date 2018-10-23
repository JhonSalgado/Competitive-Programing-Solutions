#include <bits/stdc++.h>
using namespace std;

char braile[10][3][3]= {

	{".*",
	 "**",
	 ".."	
	},
	{"*.",
	 "..",
	 ".."	
	},
	{"*.",
	 "*.",
	 ".."	
	},
	{"**",
	 "..",
	 ".."	
	},
	{"**",
	 ".*",
	 ".."	
	},
	{"*.",
	 ".*",
	 ".."	
	},
	{"**",
	 "*.",
	 ".."	
	},
	{"**",
	 "**",
	 ".."	
	},
	{"*.",
	 "**",
	 ".."	
	},
	{".*",
	 "*.",
	 ".."	
	}

};

int n;
char l[2];
char digS[120];

int main(){
	while(scanf("%d", &n) &&n!=0){
		scanf("%s", l);
		if(l[0]=='S'){
			scanf("%s", digS);
			for (int row = 0; row < 3; row++)
			{
				for(int i=0; i<n; i++)
				{
					for (int col = 0; col < 2; ++col){
						printf("%c", braile[digS[i]-48][row][col]);
						if(i<n-1 && col==1) printf(" ");
					}
				}
				printf("\n");
			}
		}
		else{
			char leido [n][3][3];
			for (int row = 0; row < 3; row++)
			{
				for(int i=0; i<n; i++)
				{
					scanf("%s", leido[i][row]);
				}
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if(strcmp(leido[i][0], braile[j][0])==0
						&& strcmp(leido[i][1], braile[j][1])==0
						&& strcmp(leido[i][2], braile[j][2])==0){
						printf("%d", j);
					}
				}
			}
			printf("\n");
		}

	}
	return 0;
}