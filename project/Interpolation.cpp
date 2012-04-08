// Interpolation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

const int N = 1000;
const double Radius = 10;
const double pi = acos(-1.0);

double weight(double x)		//Ȩֵ����
{
	double W;
	if(x < Radius)
		W = 0.5*cos(x*pi/Radius) + 0.5;
	else
		W = 0;
	return W;
}

double distance(double r[],double p[])	//��������֮��ľ���
{
	double d = sqrt(pow(r[0] - p[0],2) + pow(r[1] - p[1],2) + pow(r[2] - p[2],2));
	return d;
}

void positioning()		//��������Ҫȷ��Ũ�ȵĵ��λ��
{
	//
	
}
void approximation(double Sampled[][4],double Approximated[][4],int sample_num,int approx_num) //���ý����㷨���Ƶ�һЩ���Ũ��ֵ
{
	/*
		sample_num���������ĸ�����approx_num������Ҫ���Ƶ�ĸ���
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

	//����
	double glb_sample[3][4] = {{0,0,0,20},{0,0,5,8},{5,0,0,23}};
	double glb_approx[2][4] = {{5,0,5,0},{0,5,0,0}};
	cout<<glb_approx[0][3]<<" "<<glb_approx[1][3]<<endl;
	approximation(glb_sample,glb_approx,3,2);
	cout<<setprecision(8)<<glb_approx[0][3]<<" "<<glb_approx[1][3];
	int x;
	cin>>x;
	
	
}

