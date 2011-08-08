//N皇后问题
#include<iostream>
using namespace std;
#define N 8
int X[N+1]; //X[1]代表第一行的皇后所在的列数，X[1]~X[8]
static int count=0;
int count2 = 0;

bool Place(int k)			//判断第k行的皇后放在X[k]是否可行
{
	int i;
	i=1;
	while(i<k)
	{
		if((X[i]==X[k])||(i+X[i]==k+X[k])||(i-X[i]==k-X[k]))
			return false;
		i++;
	}
	return true;
}

void Print(int X[N+1])		//打印函数
{
	count++;		//计数可行解的数量
	if(count==1)
	{
		cout<<"本程序求解"<<N<<"皇后问题:"<<endl;
	}
	cout<<"第"<<count<<"种可能为："<<endl;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<X[i];j++)
		{
			cout<<"- ";
		}
		cout<<"Q ";
		for(int j=1;j<=N-X[i];j++)
		{	
			cout<<"- ";
		}
		cout<<endl;
	}
	cout<<endl;
	//system("pause");
}

void NQueens()				//求解皇后问题
{
	int k;
	X[1]=0;
	k=1;
	while(k>0)				
	{
		X[k]=X[k]+1;
		while((X[k]<=N) && (Place(k)==false))
		{
			X[k]=X[k]+1;
		}
		
		if(X[k]<=N)
		{
			if(k==N)
			{
				Print(X);		//打印函数，搜到一个打印一个。
				count2++;
			}
			else
			{	
				k++;
				X[k]=0;		//初始都站在0位置
			}
		}
		else
		{	
			k--;
		}
	}
}

void main()
{
	NQueens();
	cout<<"共有可行解数为："<<count2<<endl;
	system("pause");
}