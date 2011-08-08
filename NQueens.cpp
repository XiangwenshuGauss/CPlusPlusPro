#include<iostream>
using namespace std;
#define N 8
int X[N+1]; 
static int count=0;
int count2 = 0;

bool Place(int k)			
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

void Print(int X[N+1])		
{
	count++;		
	if(count==1)
	{
		cout<<"This Program solves "<<N<<" Queens problem"<<endl;
	}
	cout<<"the"<<count<<"situation:"<<endl;
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

void NQueens()				//Solution for N Queens
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
				Print(X);		//Find one print one
				count2++;
			}
			else
			{	
				k++;
				X[k]=0;		//for every x[i],initial to zero
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
	cout<<"The total number of the solutions is£º"<<count2<<endl;
	system("pause");
}