#include<cstdio>
#include<string.h>
#include<iostream> 
using namespace std;

int main()
{
    char card[3];
    int mazo[20];
    int n=13, p;
    while(scanf("%s", card)!=EOF){
        for(int j=0; j<20; j++)mazo[j]=0;
        int S=0;
        int H=0;
        int D=0;
        int C=0;
        while(n--){
            int i=0;
            if(card[0]=='J')i=1;
            else if(card[0]=='Q')i=2;
            else if(card[0]=='K')i=3;
            else if(card[0]=='A')i=4;
            if(card[1]=='S')S++;
            else if(card[1]=='H'){i+=5; H++;}
            else if(card[1]=='D'){i+=10; D++;}
            else if(card[1]=='C'){i+=15; C++;}
            mazo[i]=1;
            if(n>0)scanf("%s", card);
        }
        int J=mazo[1]+mazo[6]+mazo[11]+mazo[16];
        int Q=2*(mazo[2]+mazo[7]+mazo[12]+mazo[17]);
        int K=3*(mazo[3]+mazo[8]+mazo[13]+mazo[18]);
        int A=4*(mazo[4]+mazo[9]+mazo[14]+mazo[19]);
        p=J+Q+K+A;
        if(mazo[3] && S<=1)p--;
        if(mazo[8] && H<=1)p--;
        if(mazo[13] && D<=1)p--;
        if(mazo[18] && C<=1)p--;
        if(mazo[2] && S<=2)p--;
        if(mazo[7] && H<=2)p--;
        if(mazo[12] && D<=2)p--;
        if(mazo[17] && C<=2)p--;
        if(mazo[1] && S<=3)p--;
        if(mazo[6] && H<=3)p--;
        if(mazo[11] && D<=3)p--;
        if(mazo[16] && C<=3)p--;
        bool bS=mazo[4]||(mazo[3]&&S>=2)||(mazo[2]&&S>=3);
        bool bH=mazo[9]||(mazo[8]&&H>=2)||(mazo[7]&&H>=3);
        bool bD=mazo[14]||(mazo[13]&&D>=2)||(mazo[12]&&D>=3);
        bool bC=mazo[19]||(mazo[18]&&C>=2)||(mazo[17]&&C>=3);
        if(bS&&bH&&bD&&bC&&p>=16)printf("BID NO-TRUMP\n");
        else{
            if(S==0)p+=2;
            if(S==1)p+=2;
            if(S==2)p++;
            if(H==0)p+=2;
            if(H==1)p+=2;
            if(H==2)p++;
            if(D==0)p+=2;
            if(D==1)p+=2;
            if(D==2)p++;
            if(C==0)p+=2;
            if(C==1)p+=2;
            if(C==2)p++;
            if(p>=14){
                char suit[2];
                int best=S;
                strcpy(suit, "S");
                if(best<H){best=H;strcpy(suit, "H");}
                if(best<D){best=D;strcpy(suit, "D");}
                if(best<C){best=C;strcpy(suit, "C");}
                printf("BID %s\n", suit);
            }
            else printf("PASS\n");
        }
        n=13;
    } 
}
