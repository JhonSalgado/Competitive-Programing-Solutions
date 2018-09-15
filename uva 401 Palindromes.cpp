#include<cstdio>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
using namespace std;

char rev(char c){
	if(c=='A' || c=='H' || c=='M' || c=='O' || c=='T' || c=='U' || c=='V' || c=='W'|| c=='X' || c=='Y' || c=='1' || c=='8')return c;
	else if(c=='E')return '3';
	else if(c=='J')return 'L';
	else if(c=='L')return 'J';
	else if(c=='S')return '2';
	else if(c=='Z')return '5';
	else if(c=='2')return 'S';
	else if(c=='3')return 'E';
	else if(c=='5')return 'Z'; 
	else return 0;
}

int main(){
	char word[22];
	bool pal, mir;
	while(scanf("%s",word)!=EOF){
		pal=true;
		mir=true;
		int l=strlen(word);
		for(int i=0; i<=l/2; i++){
			pal=pal && word[i]==word[l-(i+1)];
			mir=mir && word[l-(i+1)]==rev(word[i]);
		}
		if(pal && mir)printf("%s -- is a mirrored palindrome.\n", word);
		else if(mir)printf("%s -- is a mirrored string.\n", word);
		else if(pal)printf("%s -- is a regular palindrome.\n", word);
		else printf("%s -- is not a palindrome.\n", word);
		printf("\n");
	}
}
