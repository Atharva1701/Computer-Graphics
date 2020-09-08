#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
class bresc
{
	int xc,yc,xi,yi,limit,delta,del,del1,R;
	public:
		bresc(){}
		void read();
		void draw();
		void mh(int,int,int);
		void mv(int,int,int);
		void md(int,int,int);
};
void bresc::read()
{
	cout<<"\nEnter the co-ordinates of the centre of the circle(x and y) :";
	cin>>xc>>yc;
	cout<<"\nEnter the radius R:";
	cin>>R;
}
void bresc::draw()
{
	limit=0;
	delta=2*(1-R);
	xi=0;
	yi=R;
	while(yi>=limit)
	{
		putpixel(xc+xi,yc+yi,RED);
		delay(5);
		putpixel(xc+xi,yc-yi,GREEN);
		delay(5);
		putpixel(xc-xi,yc-yi,YELLOW);
		delay(5);
		putpixel(xc-xi,yc+yi,BLUE);
		delay(5);
		if(delta<0)
		{
			del=(2*delta)+(2*yi)-1;
			if(del<=0)
				mh(xi,yi,delta);
			else
				md(xi,yi,delta);
		}
		else if(delta>0)
		{
			del1=(2*delta)-(2*xi)-1;
			if(del1<=0)
				md(xi,yi,delta);
			else 
				mv(xi,yi,delta);
		}
		else if(delta==0)
			md(xi,yi,delta);
	}
	delay(100);
	int g=getchar();
	closegraph();
}
void bresc::mh(int x,int y,int delta1)
{
	xi=x+1;
	delta=delta1+2*xi+1;
}
void bresc::mv(int x,int y,int delta1)
{
	yi=y-1;
	delta=delta1-2*yi+1;
}
void bresc::md(int x,int y,int delta1)
{
	xi=x+1;
	yi=y-1;
	delta=delta1+2*xi-2*yi+2;
}
int main()
{
	bresc b;
	b.read();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	b.draw();
}
