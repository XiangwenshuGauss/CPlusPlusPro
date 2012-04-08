// Interpolation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

const int N = 1000;
const double Radius = 10;
const double pi = acos(-1.0);

double weight(double x)		//权值计算
{
	double W;
	if(x < Radius)
		W = 0.5*cos(x*pi/Radius) + 0.5;
	else
		W = 0;
	return W;
}

double distance(double r[],double p[])	//计算两点之间的距离
{
	double d = sqrt(pow(r[0] - p[0],2) + pow(r[1] - p[1],2) + pow(r[2] - p[2],2));
	return d;
}

void positioning()		//计算我们要确定浓度的点的位置
{
	//
	
}
void approximation(double Sampled[][4],double Approximated[][4],int sample_num,int approx_num) //采用近似算法估计的一些点的浓度值
{
	/*
		sample_num代表采样点的个数，approx_num代表需要近似点的个数
	*/
	double weight_sum = 0;
	for(int i = 0;i < approx_num;++i)
	{
		for(int j = 0;j < sample_num;++j)
		{
			Approximated[i][3] += weight(distance(Approximated[i],Sampled[j]))*Sampled[j][3];
			weight_sum += weight(distance(Approximated[i],Sampled[j]));
		}
		Approximated[i][3] = Approximated[i][3]/weight_sum;
		weight_sum = 0;
	}
}

int main()
{

	//测试
	double glb_sample[3][4] = {{0,0,0,20},{0,0,5,8},{5,0,0,23}};
	double glb_approx[2][4] = {{5,0,5,0},{0,5,0,0}};
	cout<<glb_approx[0][3]<<" "<<glb_approx[1][3]<<endl;
	approximation(glb_sample,glb_approx,3,2);
	cout<<setprecision(8)<<glb_approx[0][3]<<" "<<glb_approx[1][3];
	int x;
	cin>>x;
	
	
}

