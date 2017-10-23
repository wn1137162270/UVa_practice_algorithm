#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
const int INF=1<<30;

int fa[maxn];
vector<int> persons[maxn];

int main()
{
	int n,t,len,ans,flag,x,j;
	scanf("%d %d",&n,&t);
	while(n!=0||t!=0)
	{
		for(int i=0;i<=n;i++)
			persons[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&fa[i]);
		for(int i=n;i>=0;i--)
		{
			len=persons[i].size();
			if(len!=0)
			{
				x=0;flag=0;
				sort(persons[i].begin(),persons[i].end());
				for(j=0;j<len;j++)
					if((double)(j+1)/len<=(double)t/100)
						x+=persons[i][j];
					else
					{   
						flag=1;break;
					}
				j--;
				if(flag&&(double)(j+1)/len<(double)t/100)
					x+=persons[i][j+1];
				if(i==0)
					ans=x;
				else
					persons[fa[i]].push_back(x);
			}
			else
				persons[fa[i]].push_back(1);
		}
		printf("%d\n",ans);
		scanf("%d %d",&n,&t);
	}
	return 0;
}
