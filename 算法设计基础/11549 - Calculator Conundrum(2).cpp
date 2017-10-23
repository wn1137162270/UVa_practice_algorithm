#include<cstdio>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

int ans;

int next(int n,int k)
{
	int x;
	stringstream ss1;
	ss1<<(long long)k*k;
	string s=ss1.str();
	if(s.length()>n)
		s=s.substr(0,n);
	stringstream ss2(s);
	ss2>>x;
	return x;
}

int main()
{
	int t,n,k;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		ans=-1;
		scanf("%d %d",&n,&k);
		set<int> record;
		while(!record.count(k))
		{
			record.insert(k);
			ans=max(ans,k);
			k=next(n,k);
		}
		printf("%d\n",ans);
	}
	return 0;
}
