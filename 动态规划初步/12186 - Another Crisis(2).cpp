#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
const int INF=1<<30;

int t;
vector<int> sons[maxn];
vector<int> persons[maxn];

int dp(int x)
{
	int c,ans=0,len=sons[x].size();
	if(len==0)
		return 1;
	for(int i=0;i<len;i++)
		persons[x].push_back(dp(sons[x][i]));
	sort(persons[x].begin(),persons[x].end());
	c=(len*t-1)/100+1;
	for(int i=0;i<c;i++)
		ans+=persons[x][i];
	return ans;
}

int main()
{
	int n,fa;
	scanf("%d %d",&n,&t);
	while(n!=0||t!=0)
	{
		for(int i=0;i<=n;i++)
		{
			sons[i].clear();
			persons[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&fa);
			sons[fa].push_back(i);
		}
		printf("%d\n",dp(0));
		scanf("%d %d",&n,&t);
	}
	return 0;
}
