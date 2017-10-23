#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=24+2;
const int maxl=1e6+10;

int a[maxn];
char s[maxl];
map<int,int> table;

int bitcount(int x)
{
	return x==0?0:bitcount(x>>1)+(x&1);
}

int main()
{
	int n,m,v,ans,len;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=0;
			scanf("%s",s);
			len=strlen(s);
			for(int j=0;j<len;j++)
				a[i]^=1<<(s[j]-'A');
		}
		table.clear();
		m=n/2;
		for(int i=0;i<(1<<m);i++)
		{
			v=0;
			for(int j=0;j<m;j++)
				if(i&(1<<j))
					v^=a[j];
			if(!table.count(v)||bitcount(table[v])<bitcount(i))
				table[v]=i;
		}
		ans=0;
		for(int i=0;i<(1<<(n-m));i++)
		{
			v=0;
			for(int j=0;j<n-m;j++)
				if(i&(1<<j))
					v^=a[j+m];
			if(table.count(v)&&bitcount(ans)<bitcount(table[v])+bitcount(i))
				ans=(i<<m)^table[v];
		}
		printf("%d\n",bitcount(ans));
		for(int i=0;i<n;i++)
			if(ans&(1<<i))
				printf("%d ",i+1);
		printf("\n");
	} 
	return 0;	
} 
