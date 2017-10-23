#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;

int a[maxn];

int main()
{
	int n,t,first;
	scanf("%d",&n);
	while(n!=0)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			a[t]++;
		}
		first=1;
		for(int i=1;i<=100;i++)
		{
			t=a[i];
			for(int j=0;j<t;j++)
			{
				if(first)
				{
					printf("%d",i);
					first=0;
				}
				else
					printf(" %d",i);
			}
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;	
} 
