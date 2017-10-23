#include<cstdio>
#include<cstring>
#include<string> 
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=200+10;
const int maxl=100+10;

int id,d[maxn];
bool uniqu[maxn];
char name1[maxl],name2[maxl];
map<string,int> name_id;
vector<int> sons[maxn];

int get_id(char *name)
{
	string str(name);
	if(name_id.count(str))
		return name_id[str];
	else
		return name_id[str]=id++;
}

int dp(int u)
{
	int f=0,gf=0,q=1,gq=1,len=sons[u].size(),len1,v;
	if(d[u]!=-1)
		return d[u];
	for(int i=0;i<len;i++)
	{
		f+=dp(sons[u][i]);
		if(!uniqu[sons[u][i]])
			q=0;
	}
	for(int i=0;i<len;i++)
	{
		v=sons[u][i];
		len1=sons[v].size();
		for(int j=0;j<len1;j++)
		{
			gf+=dp(sons[v][j]);
			if(!uniqu[sons[v][j]])
				gq=0;
		}
	}
	if(1+gf>f)
		uniqu[u]=gq;
	else if(1+gf<f)
		uniqu[u]=q;
	else
		uniqu[u]=0;
	return d[u]=max(1+gf,f);
}

int main()
{
	int n,u,v,ans;
	scanf("%d",&n);
	while(n!=0)
	{
		name_id.clear();
		for(int i=0;i<n;i++)
			sons[i].clear();
		id=0;
		scanf("%s",name1);
		name_id[name1]=id++;
		for(int i=0;i<n-1;i++)
		{
			scanf("%s %s",name1,name2);
			sons[get_id(name2)].push_back(get_id(name1));
		}
		memset(d,-1,sizeof(d));
		ans=dp(0);
		printf("%d %s\n",ans,uniqu[0]?"Yes":"No");//×¢ÒâprintfµÄÖ´ÐÐË³Ðò 
		scanf("%d",&n);	
	} 
	return 0;	
} 
