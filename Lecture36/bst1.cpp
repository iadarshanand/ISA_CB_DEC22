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

node* insertNodeToBST(node* root, int val)
{
	//Base Case
	if(!root)return new node(val);

	//Recursive Case
	if(root->data<val)root->right=insertNodeToBST(root->right,val);
	else root->left=insertNodeToBST(root->left,val);
	 

	return root;
}

node* buildBST()
{
	int n;
	cin>>n;

	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		int input;
		cin>>input;

		root=insertNodeToBST(root,input);
	}
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

void KthSmallestELementHelper(node* root, int k, int &cnt, int &ans)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	//inorder traversal
	KthSmallestELementHelper(root->left,k,cnt,ans);
	if(ans!=INT_MAX)return;
	//still kth smallest did not found
	cnt++;
	if(cnt==k)
	{
		ans=root->data;
		return;
	}
	KthSmallestELementHelper(root->right,k,cnt,ans);
}

int KthSmallestELement(node* root, int k)
{
	int ans=INT_MAX;
	int cnt=0;
	KthSmallestELementHelper(root,k,cnt,ans);
	return ans;
}

void KthLargestELementHelper(node* root, int k, int &cnt, int &ans)
{
	//Base Case
	if(!root)return;

	//Recursive Case
	// reverse inorder traversal
	KthLargestELementHelper(root->right,k,cnt,ans);

	if(ans!=INT_MAX)return;
	//still kth smallest did not found
	cnt++;
	if(cnt==k)
	{
		ans=root->data;
		return;
	}	

	KthLargestELementHelper(root->left,k,cnt,ans);	
}

int KthLargest(node* root, int k)
{
	int ans=INT_MAX;
	int cnt=0;
	KthLargestELementHelper(root,k,cnt,ans);
	return ans;	
}

bool searchInBSTIteratively(node* root, int key)
{
	node* p=root;
	while(p)
	{
		if(p->data==key)return true;
		//compare
		if(p->data<key)p=p->right;
		else p=p->left;
	}
	return false;
}

bool searchInBSTRecursively(node* root, int key)
{
	//Base Case
	if(!root)return false;
	if(root->data==key)return true;

	//Recursive Case
	//compare
	if(root->data<key)return searchInBSTRecursively(root->right,key);
	else return searchInBSTRecursively(root->left,key);

}

node* findNode(node* root, int val)
{
	//Base Case
	if(!root)return NULL;
	if(root->data==val)return root;

	//Recursive Case
	//compare
	if(root->data<val)return findNode(root->right,val);
	else return findNode(root->left,val);
}

node* inorderSuccessor(node* root, node* tarNode)
{
	//If right child exist
	cout<<tarNode<<" "<<tarNode->right->data<<endl;
	if(tarNode->right)
	{
		node* p=tarNode->right;
		while(p->left)p=p->left;
		return p;
	}

	//Right child does not exist
	// inorder succesor will be from root to node(if exist)
	node* inSucc=NULL;
	node* p=root;

	while(p!=tarNode)
	{
		if(p->data>=tarNode->data)
		{
			inSucc=p;
			p=p->left;
		}
		else p=p->right;
	}

	return inSucc;
}

int main()
{
	node* root=buildBST();

	printPreOrder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;

	//KthSmallest Element
	int k;
	cin>>k;

	cout<<KthSmallestELement(root,k)<<endl;

	//Kth Largest Element
	int k1;
	cin>>k1;

	cout<<KthLargest(root,k1)<<endl;

	//search Element
	int num;
	cin>>num;

	bool chk=searchInBSTIteratively(root,num);
	if(chk)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	bool chk1=searchInBSTRecursively(root,num);
	if(chk1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	//Inorder Successor
	int val;
	cin>>val;

	node* valAddress=findNode(root,val);
	cout<<valAddress<<" "<<root<<endl;
	if(!valAddress)cout<<"Node does not exist"<<endl;
	else
	{
		node* inSucc=inorderSuccessor(root,valAddress);
		if(!inSucc)cout<<"inorderSuccessor does not exist"<<endl;
		else cout<<"inorderSuccessor is "<<inSucc->data<<endl;
	}

}