#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left, *right;

	node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

node* buildLevelOrderBT()
{
	int d;
	cin>>d;

	if(d==-1)return NULL;
	//tree exist

	node* root=new node(d);
	queue<node*>q;
	q.push(root);

	while(!q.empty())
	{
		node* curr=q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1)
		{
			//left child exist
			curr->left=new node(c1);
			q.push(curr->left);
		}

		if(c2!=-1)
		{
			//right child exist
			curr->right=new node(c2);
			q.push(curr->right);
		}
	}
	return root;
}

void printLevelOrder(node* root)
{
	if(!root)
	{
		cout<<"tree is empty"<<endl;
		return;
	}

	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* curr=q.front();
		q.pop();
		cout<<curr->data<<" ";

		if(curr->left)q.push(curr->left);
		if(curr->right)q.push(curr->right);
	}
}

void printInorder(node* root)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPreOrder(node* root)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void verticalOrderTraversing(node* root)
{
	if(!root)
	{
		cout<<"tree is empty"<<endl;
		return;
	}

	//tree exist
	queue<pair<node*,int>>q; //q<node*,Verticallevel>
	q.push({root,0});

	map<int,vector<int>>mp; //mp<level,nodes from top to down of that level>


	while(!q.empty())
	{
		auto temp=q.front();
		q.pop();
		node* currNode=temp.first;
		int verticalLevel=temp.second;

		mp[verticalLevel].push_back(currNode->data);

		if(currNode->left)q.push({currNode->left,verticalLevel-1});
		if(currNode->right)q.push({currNode->right,verticalLevel+1});
	}

	for(auto x:mp)
	{
		for(auto y:x.second)
		{
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

int countNodeOfBT(node* root)
{
	//Base Case
	if(!root)return 0;

	//Recursive Case
	int left=countNodeOfBT(root->left);
	int right=countNodeOfBT(root->right);

	return 1+left+right;
}

void printKthLevelHelper(node* currNode, int currLevel, int k, vector<int>&ans)
{
	//Base Case
	if(!currNode)return;
	if(currLevel==k)
	{
		ans.push_back(currNode->data);
		return;
	}

	//Recursive Case
	printKthLevelHelper(currNode->left,currLevel+1,k,ans);
	printKthLevelHelper(currNode->right,currLevel+1,k,ans);
}

void printKthLevel(node* root, int k)
{
	vector<int>ans;
	printKthLevelHelper(root,0,k,ans);

	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
}

int main()
{
	node* root=buildLevelOrderBT();
	printLevelOrder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPreOrder(root);
	cout<<endl;
	verticalOrderTraversing(root);
	cout<<countNodeOfBT(root)<<endl;
	printKthLevel(root,3);
}
