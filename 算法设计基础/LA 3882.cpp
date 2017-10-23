#include<cstdio>

const int maxn=10000+10;

int f[maxn];

int main()
{
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	while(n!=0||k!=0||m!=0)
	{
		f[1]=0;
		for(int i=2;i<n;i++)
			f[i]=(f[i-1]+k)%i;
		printf("%d\n",(f[n-1]+m)%n+1);    
		scanf("%d %d %d",&n,&k,&m);
	}
	return 0;	
} 
