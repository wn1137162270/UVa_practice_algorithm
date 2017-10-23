#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;

int a[maxn],n;

bool check(int x)
{
	int left,right,al,ar;
	al=a[0];ar=x-a[0];   
	left=al;right=0;
	for(int i=1;i<n;i++)
	{
		if(i%2==0)
		{
			right=min(a[i],ar-right);
			left=a[i]-right;
		}
		else
		{
			left=min(a[i],al-left);
			right=a[i]-left;
		}
	}
	return left==0;
}

int main()
{
	int ans,maxx,l,r,m;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		maxx=0;
		for(int i=0;i<n;i++)
			maxx=max(maxx,a[i]+a[(i+1)%n]);
		if(n%2==0)
			ans=maxx;
		else
		{
			if(n==1)
				ans=a[0];
			else
			{
				l=maxx;r=3*maxn;
				while(l<r)
				{
					m=(l+r)/2;
					if(!check(m))
						l=m+1;
					else
						r=m;
				}
				ans=l;
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
