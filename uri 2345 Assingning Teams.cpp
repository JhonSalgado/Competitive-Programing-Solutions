#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b ,&c, &d);
	int min=abs((a+b)-(c+d));
	if(abs((a+c)-(b+d))<min)min=abs((a+c)-(b+d));
	if(abs((a+d)-(b+c))<min) min=abs((a+d)-(b+c));
	printf("%d\n", min);
}