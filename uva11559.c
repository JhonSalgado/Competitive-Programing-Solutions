#include <cstdio>
using namespace std;

int main() {	
	int p, b, h, w, price, t;
	while (scanf("%d %d %d %d", &p, &b, &h, &w)!=EOF) {
	    t=b+1;
	    int rooms[w+1];
	    while(h--){
	        bool c=false;
	        scanf("%d",&price);
	        for(int i=0; i<w; i++){
	            scanf("%d", &rooms[i]);
	            c=c||(rooms[i]>=p);
	        }
	        if(c && p*price<t)t=p*price;
        }
        if(t<b)printf("%d\n",t);
        else printf("stay home\n");
	}
}
