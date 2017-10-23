#include<cstdio>
#include<cstring> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=4;
const int maxl=24+4;
const int left[6]={4,0,2,3,5,1};
const int up[6]={2,1,5,0,4,3};

int r[maxn],pose[24][6],n,cube[maxn][6],temp[maxn][6],ans;
char name[maxl];
vector<string> names;
 
void turn_left(int a[],int b[])
{
	for(int i=0;i<6;i++)
		b[i]=left[a[i]];
}

void turn_up(int a[],int b[])
{
	for(int i=0;i<6;i++)
		b[i]=up[a[i]]; 
}

int check()
{
	int t,tb[maxn*6],maxx,res=0;
	for(int i=0;i<n;i++)
	{
		t=r[i];
		for(int j=0;j<6;j++)
			temp[i][pose[t][j]]=cube[i][j];
	}
	for(int i=0;i<6;i++)
	{
		memset(tb,0,sizeof(tb));
		maxx=0;
		for(int j=0;j<n;j++)
			maxx=max(maxx,++tb[temp[j][i]]);
		res+=n-maxx;
	}
	return res;
}

void dfs(int d)
{
	int res;
	if(d==n)
	{
		res=check();
		ans=min(ans,res);
	}
	else
	{
		for(int i=0;i<24;i++)
		{
			r[d]=i;
			dfs(d+1);
		}
	}
}

int main()
{
	int t,len,flag;
	for(int i=0;i<6;i++)
	{
		t=4*i;
		if(i==0)
			for(int j=0;j<6;j++)	pose[t][j]=j;
		else if(i==1)
			turn_up(pose[0],pose[t]);
		else if(i==2)
			turn_up(pose[1],pose[t]);    
		else if(i==3)
			turn_up(pose[2],pose[t]);
		else if(i==4)
			turn_up(pose[3],pose[t]);
		else
			turn_up(pose[4],pose[t]);   
		turn_left(pose[t],pose[t+1]);
		turn_left(pose[t+1],pose[t+2]);
		turn_left(pose[t+2],pose[t+3]);
	}
	scanf("%d",&n);
	while(n!=0)
	{
		names.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<6;j++)
			{
				scanf("%s",name);
				string str(name);
				flag=0;
				len=names.size();
				for(int k=0;k<len;k++)
					if(str==names[k])
					{
						flag=1;
						cube[i][j]=k;
					}
				if(!flag)
				{
					cube[i][j]=len;
					names.push_back(str);	
				} 
			}
		ans=n*6;
		r[0]=0;
		dfs(1);
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
