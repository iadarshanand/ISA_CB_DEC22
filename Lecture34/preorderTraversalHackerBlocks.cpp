#include <bits/stdc++.h>
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

node* buildPreOrder()
{
    string s;
    cin>>s;
    if(s=="true")
    {
        int d;
        cin>>d;

        node* root=new node(d);
        root->left=buildPreOrder();
        root->right=buildPreOrder();
        return root;
    }
    else return NULL;
    
}

void printPreOrder(node* root)
{
    if(!root)return;

    cout<<root->data<<endl;
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    int d;
    cin>>d;
    node* root=new node(d);
    root->left=buildPreOrder();
    root->right=buildPreOrder();

    printPreOrder(root);
    return 0;

}
