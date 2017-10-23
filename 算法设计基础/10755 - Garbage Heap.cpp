#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxn=20+2;

ll s[maxn][maxn][maxn];

void expand(int x,int &b0,int &b1,int &b2)
{
	b0=x&1;x>>=1;
	b1=x&1;x>>=1;
	b2=x&1;
}

int sign(int b0,int b1,int b2)
{
	return (b0+b1+b2)%2==1?1:-1;
}

int main()
{
	int t,a,b,c,b0,b1,b2;
	ll x;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d %d",&a,&b,&c);
		memset(s,0,sizeof(s));
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
					scanf("%lld",&s[i][j][k]);
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
					for(int h=1;h<=7;h++)
					{
						expand(h,b0,b1,b2);
						s[i][j][k]+=s[i-b0][j-b1][k-b2]*sign(b0,b1,b2);
					}	   		
	return 0;	
} 
