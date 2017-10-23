#include<cstdio>

const int maxn=10+2;

int pos[6][maxn][maxn];
char appear[maxn][maxn][maxn];
char color[6][maxn][maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			scanf("%s",color[j][i]);
	
} 
