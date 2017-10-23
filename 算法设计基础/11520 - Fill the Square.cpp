#include<cstdio>

const int maxn=10+2;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};

char grid[maxn][maxn];

int main()
{
	int t,n,flag,tx,ty;
	char ch;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",grid[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{	
				if(grid[i][j]=='.')
				{
					for(int k=0;k<26;k++)
					{
						flag=0;  
						ch=k+'A';
						for(int h=0;h<4;h++)
						{
							tx=i+dx[h];ty=j+dy[h];
							if(tx>=0&&tx<n&&ty>=0&&ty<n&&grid[tx][ty]==ch)
							{
								flag=1;
								break;
							}
						}
						if(!flag)
						{
							grid[i][j]=ch;
							break;
						}
					}
				} 
			}
		printf("Case %d:\n",kase+1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1;j++)
				printf("%c",grid[i][j]);
			printf("\n");
		}
	}
	return 0;		
} 
