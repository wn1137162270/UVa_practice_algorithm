#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;

const int maxn=10000+10;
const double pi=acos(-1);
const double eps=1e-6;

int a[maxn],n,f;
double s[maxn];

bool check(double x)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=floor(s[i]/x);
	return cnt>=f+1;
}

int main()
{
	int t;
	double l,r,m,maxs;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&n,&f);
		maxs=0.0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=a[i]*a[i]*pi;
			maxs=max(maxs,s[i]);
		}
		l=0;r=maxs;
		while(r-l>=eps)
		{
			m=(l+r)/2;
			if(check(m))
				l=m;
			else
				r=m;
		}
		printf("%.6lf\n",l); 
	}
	return 0;
}
