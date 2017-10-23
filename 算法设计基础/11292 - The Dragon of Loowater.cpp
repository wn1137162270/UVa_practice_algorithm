#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=20000+10;

int a[maxn],b[maxn];

int main()
{
	int n,m,j,cost,flag;
	scanf("%d %d",&n,&m);
	while(n!=0||m!=0)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		j=0;cost=0;flag=0;
		for(int i=0;i<n;i++)
		{
			while(j<m&&b[j]<a[i])
				j++;
			if(j==m)
			{
				flag=1;
				break;
			}
			cost+=b[j];       
			j++;
		}
		if(flag)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",cost);
		scanf("%d %d",&n,&m);
	}
	return 0;
}
