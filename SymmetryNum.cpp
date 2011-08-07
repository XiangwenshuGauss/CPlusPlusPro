#include<iostream>
#include<math.h>
using namespace std;

struct Flag
{
	int toc,x,y;
};

Flag Divisible2(int num)
{
	Flag f;
	f.toc = 0;
	f.x = 0;
	f.y = 0;
	for(int i=999;i>=100;i--)
	{
		if((num%i==0)&&(num/i<1000)&&(num/i>99))
		{
			f.toc = 1;
			f.x = i;
			f.y = num/i;
			return f;
		}
	}
	return f;
}

int main()
{
	int a,b,c;
	Flag g_F;
	g_F.toc = 0;
	for(a=9;a>=0;a--)
		for(b=9;b>=0;b--)
			for(c=9;c>=0;c--)
			{
				g_F = Divisible2(a*100001+b*10010+c*1100);
				if(g_F.toc == 1)
				{
					cout<<a<<b<<c<<c<<b<<a;
					cout<<"="<<g_F.x<<"*"<<g_F.y<<endl;
					system("pause");
					return 1;
				}
			}
}