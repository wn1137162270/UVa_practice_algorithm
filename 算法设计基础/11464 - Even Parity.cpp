#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 

const int maxn=15+2;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};

int mat[maxn][maxn],tmp[maxn][maxn],origin[maxn],n,minn;

int judge(int num)
{
	int cnt,flag=0,tx,ty;
	memcpy(tmp,mat,sizeof(mat));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cnt=0;
			for(int k=0;k<3;k++)
			{
				tx=i+dx[k];ty=j+dy[k];
				if(tx>=0&&tx<n&&ty>=0&&ty<n)
					cnt+=tmp[tx][ty];
			}
			if(i==n-1)
			{
				if(cnt%2==1)
				{
					flag=1;
					break;
				}
			}
			else
			{
				tx=i+dx[3];ty=j+dy[3];
				if(cnt%2==0)
				{
					if(tmp[tx][ty]==1)
					{
						flag=1;
						break;
					}
				}
				else
				{
					if(tmp[tx][ty]==0)
					{
						tmp[tx][ty]=1;
						num++;
					}
				}
			}
		}
		if(flag)
			break;
	}
	if(flag)
		return -1;
	else
		return num;
} 

void enumerate(int x,int num)
{
	if(x>=n)
	{
		num=judge(num);
		if(num>=0)
			minn=min(minn,num);
		return;
	}
	if(origin[x]==1)
		enumerate(x+1,num);
	else
	{
		mat[0][x]=0;
		enumerate(x+1,num);
		mat[0][x]=1;
		enumerate(x+1,num+1);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				scanf("%d",&mat[j][k]);
		memcpy(origin,mat[0],sizeof(mat[0]));
		minn=maxn*maxn;
		enumerate(0,0);
		printf("Case %d: ",i+1);
		if(minn<maxn*maxn)
			printf("%d\n",minn);
		else
			printf("-1\n"); 
	}
	return 0;
}
