#include<cstdio>
#include<queue>
using namespace std;

const int maxl=10+2;

struct event
{
	int num,period,time;
	bool operator <(const event &et)const
	{
		return time>et.time||(time==et.time&&num>et.num);	
	}  
};

char s[maxl];
priority_queue<event> pq; 

int main()
{
	int num,period,k;
	event et;
	scanf("%s",s);
	while(s[0]=='R')
	{
		scanf("%d %d",&num,&period);
		pq.push((event){num,period,period});
		scanf("%s",s);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		et=pq.top();
		pq.pop();
		printf("%d\n",et.num);
		et.time+=et.period;
		pq.push(et);
	}
	return 0;	
} 
