//N�ʺ�����
#include<iostream>
using namespace std;
#define N 8
int X[N+1]; //X[1]�����һ�еĻʺ����ڵ�������X[1]~X[8]
static int count=0;
int count2 = 0;

bool Place(int k)			//�жϵ�k�еĻʺ����X[k]�Ƿ����
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

void Print(int X[N+1])		//��ӡ����
{
	count++;		//�������н������
	if(count==1)
	{
		cout<<"���������"<<N<<"�ʺ�����:"<<endl;
	}
	cout<<"��"<<count<<"�ֿ���Ϊ��"<<endl;
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

void NQueens()				//���ʺ�����
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
				Print(X);		//��ӡ�������ѵ�һ����ӡһ����
				count2++;
			}
			else
			{	
				k++;
				X[k]=0;		//��ʼ��վ��0λ��
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
	cout<<"���п��н���Ϊ��"<<count2<<endl;
	system("pause");
}