#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

struct PT {
	double x,y;
	double length() {return sqrt(x*x+y*y);}
	int normalize()
// normalize the vector to unit length; return -1 if the vector is 0
	{
		double l = length();
		if(fabs(l)<EPS) return -1;
		x/=l; y/=l;
		return 0;
	}
	PT operator-(PT a)
	{
		PT r;
		r.x=x-a.x; r.y=y-a.y;
		return r;
	}
	PT operator+(PT a)
	{
		PT r;
		r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	PT operator*(double sc)
	{
		PT r;
		r.x=x*sc; r.y=y*sc;
		return r;
	}
};

int sideSign(PT& p1, PT& p2, PT& p3)
// which side is p3 to the line p1->p2? returns: 1 left, 0 on, -1 right
{
	double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
	if(fabs(sg)<EPS) return 0;
	if(sg>0)return 1;
	return -1;
}

int main(){
	vector<PT> v;
	int n, q;
	cin >> n >> q ;
	for(int i=0; i<n; i++){
		int a,b;
		PT pt;
		cin >> a >> b;
		pt.x=a;
		pt.y=b;
		v.push_back(pt);
	}
	for(int i=0; i<q; i++){
		int a, b;
		PT pt;
		cin >> a >> b;
		pt.x=a;
		pt.y=b;
		bool dentro=true;
		for(int j=0; j<n; j++){
			dentro=true;
			int p2;
			if(j==n-1) p2=0;
			else p2=j+1;
			if (sideSign(v[j], v[p2], pt)<0){
				dentro=false;
				break;
			}
		}
		if(dentro) cout<< "D" <<endl;
		else cout<<"F"<<endl;
	}
	return 0;
}