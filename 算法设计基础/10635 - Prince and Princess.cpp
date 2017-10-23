#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=250+5;
const int maxl=maxn*maxn;
const int INF=1<<30;

int a[maxl],b[maxl],indexx[maxl],s[maxl],g[maxl],d[maxl];

int main()
{
	int t,n,p,q,j,k,ans;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d %d",&n,&p,&q);
		for(int i=0;i<=p;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=q;i++)
			scanf("%d",&b[i]);
		memset(indexx,0,sizeof(indexx));
		for(int i=0;i<=p;i++)
			indexx[a[i]]=i+1;
		j=0;
		for(int i=0;i<=q;i++)
			if(indexx[b[i]])
				s[j++]=indexx[b[i]];
		for(int i=1;i<=j;i++)
			g[i]=INF;
		for(int i=0;i<j;i++)
		{
			k=lower_bound(g+1,g+j+1,s[i])-g;
			d[i]=k;
			g[k]=s[i];
		}
		ans=0;
		for(int i=0;i<j;i++)
			ans=max(ans,d[i]);
		printf("Case %d: %d\n",kase+1,ans);
	}
	return 0;
}
