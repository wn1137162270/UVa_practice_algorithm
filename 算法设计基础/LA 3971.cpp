#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;

const int maxn=1000+10;
const int maxl=20+2;
const int maxq=1e9;
const int maxp=1e6+10;

struct assembly
{
	int p,q;
};

vector<assembly> ass[maxn];
map<string,int> types;
int id=0,b;

int get_id(char *ch)
{
	string str(ch);
	if(types.count(str))
		return types[str];
	else
	{
		types.insert(pair<string,int>(str,id++));
		return id-1;
	}
}

bool check(int x)
{
	int cnt=0,minn,len;
	for(int i=0;i<id;i++)
	{
		minn=maxp;
		len=ass[i].size();
		for(int j=0;j<len;j++)
			if(ass[i][j].q>=x)
				minn=min(minn,ass[i][j].p);
		if(minn==maxp)
			return false; 
		cnt+=minn;
		if(cnt>b)
			break;
	}
	return cnt<=b;
}

int divide(int l,int r)
{
	int m;
	if(l==r)
		return l;
	m=(r+l+1)/2;
	if(check(m))
		return divide(m,r);
	else
		return divide(l,m-1);
}

int main()
{
	int t,n,price,quality,temp,ans;
	char type[maxl],name[maxl];
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&n,&b);
		for(int i=0;i<id;i++)
			ass[i].clear();
		types.clear();
		id=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s %s %d %d",type,name,&price,&quality);
			//printf("%s %s %d %d\n",type,name,price,quality);
			temp=get_id(type);
			ass[temp].push_back((assembly){price,quality});
		}
		ans=divide(0,maxq);
		printf("%d\n",ans);
	}
	return 0;	
} 
