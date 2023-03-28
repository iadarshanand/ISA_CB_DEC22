#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	//constructor
	Node(int data)
	{
		this->data=data;
		Node* left=NULL;
		Node* right=NULL;
	}
};

Node* buildBTPreOrderWise()
{
	int d;
	cin>>d;

	if(d==-1)return NULL;

	//Node exist
	Node* root=new Node(d);
	root->left=buildBTPreOrderWise();
	root->right=buildBTPreOrderWise();

	return root;
}

void printPreOrderWise(Node* root)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	cout<<root->data<<" ";
	printPreOrderWise(root->left);
	printPreOrderWise(root->right);
}

void printInorderWise(Node* root)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	printInorderWise(root->left);
	cout<<root->data<<" ";
	printInorderWise(root->right);
}

void printPostOrderWise(Node* root)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	printPostOrderWise(root->left);
	printPostOrderWise(root->right);
	cout<<root->data<<" ";
}

int heightOfBT(Node* root)
{
	//Base Case
	if(!root)return 0;

	//Recursive Case
	int leftHeight=heightOfBT(root->left);
	int rightHeight=heightOfBT(root->right);

	return 1+max(leftHeight,rightHeight);
}

void printLevelOrderWise(Node* root)
{
	if(!root)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}

	//tree exist
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		int sz=q.size();
		for(int i=0;i<sz;i++)
		{
			Node* currNode=q.front();
			q.pop();

			cout<<currNode->data<<" ";

			if(currNode->left)q.push(currNode->left);
			if(currNode->right)q.push(currNode->right);
		}
	}
	cout<<endl;
}

void printRowWise(Node* root)
{
	if(!root)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}

	//tree exist
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		int sz=q.size();
		for(int i=0;i<sz;i++)
		{
			Node* currNode=q.front();
			q.pop();

			cout<<currNode->data<<" ";

			if(currNode->left)q.push(currNode->left);
			if(currNode->right)q.push(currNode->right);
		}
		cout<<endl;
	}
	// cout<<endl;
}

void printZigZag(Node* root)
{
	if(!root)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}

	//Tree exist
	queue<Node*>q;
	q.push(root);
	int level=0;
	while(!q.empty())
	{
		vector<int>ans;
		int sz=q.size();
		for(int i=0;i<sz;i++)
		{
			Node* currNode=q.front();
			q.pop();
			ans.push_back(currNode->data);

			if(currNode->left)q.push(currNode->left);
			if(currNode->right)q.push(currNode->right);
		}

		if(level%2==1)reverse(ans.begin(),ans.end());
		level++;

		for(auto x:ans)cout<<x<<" ";
	}
	cout<<endl;	
}

void leftViewHelper(Node* root, int level, vector<int>&ans)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	if(level==ans.size())ans.push_back(root->data);

	leftViewHelper(root->left,level+1,ans);
	leftViewHelper(root->right,level+1,ans); 

}

void leftView(Node* root)
{
	vector<int>ans;
	leftViewHelper(root,0,ans);
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;	
}

void rightViewHelper(Node* root, int level, vector<int>&ans)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	if(level==ans.size())ans.push_back(root->data);

	rightViewHelper(root->right,level+1,ans);
	rightViewHelper(root->left,level+1,ans);
}

void rightView(Node* root)
{
	vector<int>ans;
	rightViewHelper(root,0,ans);
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
}

void topView(Node* root)
{
	if(!root)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}

	queue<pair<Node*,int>>q; //queue<currNode,currLevel>
	q.push({root,0});

	map<int,int>mp; //map<level,topMostNode>

	while(!q.empty())
	{
		auto temp=q.front();
		q.pop();
		Node* currNode=temp.first;
		int currLevel=temp.second;

		if(!mp.count(currLevel))mp[currLevel]=currNode->data;

		if(currNode->left)q.push({currNode->left,currLevel-1});
		if(currNode->right)q.push({currNode->right,currLevel+1});
	}

	for(auto x:mp)
	{
		cout<<x.second<<" ";
	}
	cout<<endl;
}

void bottomView(Node* root)
{
	queue<pair<Node*, int>>q;
	q.push({root,0});
	map<int,int>mp;

	while(!q.empty())
	{
		auto temp=q.front();
		q.pop();
		Node* currNode=temp.first;
		int level=temp.second;

		mp[level]=currNode->data;

		if(currNode->left)q.push({currNode->left,level-1});
		if(currNode->right)q.push({currNode->right,level+1});
	}

	for(auto x:mp)cout<<x.second<<" ";
	cout<<endl;


}

int main()
{
	Node* root=buildBTPreOrderWise();

	printPreOrderWise(root);
	cout<<endl;
	printInorderWise(root);
	cout<<endl;
	printPostOrderWise(root);
	cout<<endl;

	cout<<"Height of BT is "<<heightOfBT(root)<<endl;

	printLevelOrderWise(root);
	printRowWise(root);
	printZigZag(root);

	//Left View
	leftView(root);
	rightView(root);
	topView(root);
	bottomView(root);
}

