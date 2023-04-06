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
		left=NULL;
		right=NULL;
	}
};

node* buildMinHtBST(int s, int e, vector<int>&a)
{
	//Base Case
	if(s>e)return NULL;

	int mid=(s+e)/2;
	node* root=new node(a[mid]);
	root->left=buildMinHtBST(s,mid-1,a);
	root->right=buildMinHtBST(mid+1,e,a);

	return root;	
}

void printPreOrder(node* root)
{
	//base Case
	if(!root)return;

	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInorder(node* root)
{
	//base Case
	if(!root)return;

	
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int heightOfBST(node* root)
{
	//Base Case
	if(!root)return 0;

	//Recursive Case
	int left=heightOfBST(root->left);
	int right=heightOfBST(root->right);

	return 1+max(left,right);
}

int main()
{
	//given sorted array
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	node* root=buildMinHtBST(0,n-1,a);

	printInorder(root);
	cout<<endl;
	printPreOrder(root);
	cout<<endl;

	cout<<heightOfBST(root)<<endl;

	

}