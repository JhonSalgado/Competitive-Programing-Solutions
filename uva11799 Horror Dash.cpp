#include <cstdio>
using namespace std;

int main() {	
	int TC, N, v, c, max;
	scanf("%d", &TC); // number of test cases
	c=1;
	while (TC--) { // shortcut to repeat until 0
	    max=0;
		scanf("%d", &N); // point
		for(int i=0; i<N; i++){
		    scanf("%d", &v);
		    if(v>max)max=v;
		}
		printf("Case %d: %d\n", c++, max);
	}
}
