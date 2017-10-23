#include<cstdio>

const int maxn=1e5+10;

int p[maxn];

int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}

int main()
{
	int a,b,ga,gb,cnt;
	while(scanf("%d",&a)!=EOF)
	{
		cnt=0;
		for(int i=0;i<maxn;i++)
			p[i]=i;
		while(a!=-1)
		{
			scanf("%d",&b);
			ga=find(a);
			gb=find(b);
			if(ga==gb)
				cnt++;
			else
				p[ga]=gb;
			scanf("%d",&a);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
