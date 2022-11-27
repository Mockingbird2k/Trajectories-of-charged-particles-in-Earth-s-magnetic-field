#include<cstdio>
#include<conio.h>
#include<fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
//--------------Program Name--------------------------------//
using namespace std;
int main()
{
	ofstream myfile;
  	myfile.open ("data.txt");
	long double b0,re,m0,gammaX,gammaY,gammaZ,vx,vy,vz,x,y,z,r,t,c,cte,mp,cmr,i=0,k=0;
	cout<<"Welcome to the particle trajectory simulation"<<endl<<endl;
//--------------Constant Values--------------------------------//
	b0=0.0000307;
	re=6378.137;
	c=299792.458;
	t=1;
//--------------Printing C.V.s--------------------------------//
	cout<<"Your constant values are : "<<endl;
	cout<<setprecision(numeric_limits<long double>::digits10 + 1)<<b0<<" T"<<" is the field strength"<<endl;
	cout<<setprecision(numeric_limits<long double>::digits10 + 1)<<re<<" Km"<<" is the earth radius"<<endl;
	cout<<setprecision(numeric_limits<long double>::digits10 + 1)<<c<<" Km/s"<<" is the light speed"<<endl;	
	cout<<endl;
//--------------Getting Data--------------------------------//	
	cout<<"Please give me your particles initial location in cartesian coordinates (considering earth is the Origin): "<<endl;
	cout<<"X (Km) ";
	cin>>x;
	cout<<"Y (Km) ";
	cin>>y;
	cout<<"Z (Km) ";
	cin>>z;
	cout<<endl;
	cout<<"Please give me your particles initial velocity in cartesian coordinates: "<<endl;
	cout<<"Vx (Km/s) ";
	cin>>vx;
	cout<<"Vy (Km/s) ";
	cin>>vy;
	cout<<"Vz (Km/s) ";
	cin>>vz;
	cout<<endl;
	cout<<"We make this simulation by considering the desired particle is Proton"<<endl;
	cmr=95777772.609577813132782728720699;
//---------------------------------------------------------//
	myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<x<<"	";
	myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<y<<"	";
	myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<z<<endl;
//--------------calculation--------------------------------//	
	while (i==0) 
	{
		cte=-1*cmr*b0*re*re*re;
		r=sqrt(x*x+y*y+z*z);
		cte=cte/(r*r*r*r*r);
		gammaX=sqrt(1/(1-(vx*vx)/(c*c)));
		gammaY=sqrt(1/(1-(vy*vy)/(c*c)));
		gammaZ=sqrt(1/(1-(vz*vz)/(c*c)));
		vx=vx+(cte/gammaX)*(vy*(2*z*z-x*x-y*y)-3*vz*y*z);
		vy=vy+(cte/gammaY)*((-1)*vx*(2*z*z-x*x-y*y)+3*vz*x*z);
		vz=vz+(cte/gammaZ)*(3*z*(vx*y-vy*x));
		x=x-vx*t;
		y=y-vy*t;
		z=z-vz*t;
	//	k=k+1;
		//while (k==5)
		//{
			myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<x<<"	";
			myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<y<<"	";
			myfile <<setprecision(numeric_limits<long double>::digits10 + 1)<<z<<endl;
		//	k=0;
		//}
		//if (x<=re) i=1;
		//if (y<=re) i=1;
		//if (z<=re) i=1;		
	}
  	myfile.close();
  	return 0;
}
