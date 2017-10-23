#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;

int a[maxn];

int main()
{
	int n,s,ans,sum,cnt;
	while(scanf("%d %d",&n,&s)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(s<=0)
			ans=1;
		else
		{
			int j=0;
			ans=maxn;sum=0;cnt=0;
			for(int i=0;i<n;i++)
			{
				if(i>0)
				{
					sum-=a[i-1];
					cnt--;
				}
				while(sum<s&&j<n)
				{
					sum+=a[j++];
					cnt++;
				}
				if(sum>=s)
					ans=min(ans,cnt);
			}
		}
		printf("%d\n",ans==maxn?0:ans);
	}
	return 0; 
}
