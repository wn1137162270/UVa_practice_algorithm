#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int ans;

bool find(int x,set<int> &record)
{
	if(record.count(x))
		return true;
	record.insert(x);
	ans=max(ans,x);
	return false;
}

int main()
{
	int t,n;
	long long k,d;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		d=1;ans=-1;
		scanf("%d %lld",&n,&k);
		set<int> record;
		while(n--)
			d*=10;
		while(!find((int)k,record))
		{
			k=k*k;
			while(k/d!=0)   
				k/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
