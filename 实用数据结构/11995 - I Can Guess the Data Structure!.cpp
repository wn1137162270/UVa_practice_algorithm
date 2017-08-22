#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

const int maxn=1000+10;

stack<int> st;
queue<int> qu;
priority_queue<int> pq;

int main()
{
	int n,type[maxn],x[maxn],flag[3];
	while(scanf("%d",&n)!=EOF)
	{
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
			scanf("%d %d",&type[i],&x[i]);
		for(int i=0;i<n;i++)
		{
			if(type[i]==1)
				st.push(x[i]);
			else
			{
				if(!st.empty()&&st.top()==x[i])
					st.pop();
				else
				{
					flag[0]=1;
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(type[i]==1)
				qu.push(x[i]);
			else
			{
				if(!qu.empty()&&qu.front()==x[i])
					qu.pop();
				else
				{
					flag[1]=1;
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(type[i]==1)
				pq.push(x[i]);
			else
			{
				if(!pq.empty()&&pq.top()==x[i])
					pq.pop();
				else
				{
					flag[2]=1;
					break;
				}
			}
		}
		while(!st.empty())
			st.pop();
		while(!qu.empty())
			qu.pop();
		while(!pq.empty())
			pq.pop();
		if(flag[0]&&flag[1]&&flag[2])
			printf("impossible\n");
		else if(!flag[0]&&flag[1]&&flag[2])
			printf("stack\n");
		else if(flag[0]&&!flag[1]&&flag[2])
			printf("queue\n");
		else if(flag[0]&&flag[1]&&!flag[2])
			printf("priority queue\n");
		else
			printf("not sure\n");
	}
	return 0;	
} 
