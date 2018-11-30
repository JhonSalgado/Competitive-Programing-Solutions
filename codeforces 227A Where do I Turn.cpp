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
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 ;
	PT A, B, C;
	A.x=a1, A.y=a2;
	B.x=b1, B.y=b2;
	C.x=c1, C.y=c2;
	int ret = sideSign(A, B, C);
	if (ret==1) cout << "LEFT" << endl;
	else if(ret==0) cout << "TOWARDS" <<endl;
	else cout << "RIGHT" << endl;
	return 0;
}