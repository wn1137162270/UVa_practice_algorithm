#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=750+10;

struct item
{
	int s,index;
	item(int s,int index):s(s),index(index){}
	bool operator <(const item &it)const 
	{
		return s>it.s;
	}
};

int a[maxn][maxn]; 

void merge(int *a,int *b,int *c,int n)
{
	int index;
	item it(0,0);
	priority_queue<item> pq;
	for(int i=0;i<n;i++)
		pq.push(item(a[i]+b[0],0));
	for(int i=0;i<n;i++)
	{
		it=pq.top();
		pq.pop();
		c[i]=it.s;
		index=it.index;
		if(index<n-1)
		{
			it.s=it.s-b[index]+b[index+1];
			it.index++;
			pq.push(it);
		}
	}
}

int main()
{
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
				scanf("%d",&a[i][j]);
			sort(a[i],a[i]+k);
		}
		for(int i=1;i<k;i++)
			merge(a[0],a[i],a[0],k);
		printf("%d",a[0][0]);
		for(int i=1;i<k;i++)
			printf(" %d",a[0][i]);
		printf("\n");
	} 
	return 0;
}
