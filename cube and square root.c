//program to compute the square and cube of one number
#include <stdio.h>
#include <math.h>
int x,cube,square,s,c;
int sqr(int x);
int cubee(int x);
int main()
{
	printf("Input the value of x: ");
	scanf("%d",&x);
	s=sqr(x);
	c=cubee(x);
	printf("x=%d\n",x);
	printf("s=%d\n",s);
	printf("c=%d\n",c);
		return 0;
}
int sqr(int x)
{
	int p;
	p=pow(x,2);
	return (p);
}
int cubee(int x)
{
	int r;
	r=x*x*x;
	return (r);
}