#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100000+10;

int a[maxn],cnt[maxn],num[maxn],l[maxn],r[maxn],d[maxn][18];

void sparse_table(int len)
{
	for(int i=0;i<len;i++)
		d[i][0]=cnt[i];
	for(int j=1;(1<<j)<=len;j++)
		for(int i=0;i+(1<<j)-1<len;i++)
			d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int get_max(int l,int r)
{
	int k=0;
	while((1<<(k+1))<=r-l+1)
		k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
	int n,q,j,k,count,ql,qr,ans;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&q);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(cnt,0,sizeof(cnt));
		j=0;
		cnt[j]=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
				j++;
			cnt[j]++;
		}
		k=0;
		count=0;
		num[0]=0;
		l[0]=count;
		r[0]=count+cnt[0]-1; 
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				count+=cnt[k];
				k++;
			}
			num[i]=k;
			l[i]=count;
			r[i]=count+cnt[k]-1; 
		}
		sparse_table(j+1); 
		for(int i=0;i<q;i++)
		{
			scanf("%d %d",&ql,&qr);
			ql--;qr--;
			if(num[ql]==num[qr])
				ans=qr-ql+1;
			else if(num[ql]+1==num[qr])
				ans=max(r[ql]-ql+1,qr-l[qr]+1);
			else
			{
				ans=get_max(num[ql]+1,num[qr]-1);
				ans=max(ans,r[ql]-ql+1);
				ans=max(ans,qr-l[qr]+1);
			}
			printf("%d\n",ans);
		}
		scanf("%d",&n);
	}
	return 0;
}
