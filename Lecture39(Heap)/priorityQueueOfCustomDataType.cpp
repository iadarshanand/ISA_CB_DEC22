#include<bits/stdc++.h>
using namespace std;

class selfDT{
public:
	int a;
	int b;
	string s;

	selfDT(int a, int b, string s)
	{
		this->a=a;
		this->b=b;
		this->s=s;
	}
};

class cmp{
public:
	bool operator()(selfDT obj1, selfDT obj2)
	{
		// compare on base of obj.a
		//minHeap
		return obj1.a>obj2.a;
	}
};

int main()
{
	priority_queue<selfDT,vector<selfDT>,cmp>pq;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		string s;
		cin>>a>>b>>s;

		//static object creation
		selfDT temp(a,b,s);
		pq.push(temp);
	}

	while(!pq.empty())
	{
		selfDT temp=pq.top();
		pq.pop();

		cout<<temp.a<<" "<<temp.b<<" "<<temp.s<<endl;
	}

	return 0;

}