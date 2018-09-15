#include<bits/stdc++.h>

using namespace std;


int main() {
	int cycle;
	int min;
	while(true){
		scanf("%d", &cycle);
		if(cycle==0)break;
    		min=91;
		vector<int> cycles;
		vector<int> timers;
		vector<char> lights;
		cycles.push_back(cycle);
		if(cycle<min)min=cycle;
		while(scanf("%d", &cycle) && cycle!=0){
      		if(cycle<min)min=cycle;
			cycles.push_back(cycle);
		}
		int len=cycles.size();
		for(int i=0; i<len; i++){
			lights.push_back('G');
			timers.push_back(0);
		}
		int time=0;
		while(true){
			time++;
			if(time>18000){
				printf("Signals fail to synchronise in 5 hours\n");
				break;
				}
			bool all=true;
			for(int i=0; i<len; i++){
				timers.at(i)++;
				if(lights.at(i)=='G' && timers.at(i)>=cycles.at(i)-5){
					lights.at(i)='O';
				}
				if(lights.at(i)=='O' && timers.at(i)==cycles.at(i)){
					lights.at(i)='R';
					timers.at(i)=0;
				}
				if(lights.at(i)=='R' && timers.at(i)==cycles.at(i)){
					lights.at(i)='G';
					timers.at(i)=0;
				}
				all=all && lights.at(i)=='G' && time>min;
			}
			if(all){
				int hours=time/3600;
				int minutes=(time%3600)/60;
				int seconds=(time%3600)%60;
				printf("0");
				printf("%d:", hours);
				if(minutes<10)printf("0");
				printf("%d:", minutes);
				if(seconds<10)printf("0");
				printf("%d\n", seconds);
				break;
			}
		}
	}
  return 0;
}
