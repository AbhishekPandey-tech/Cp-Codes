#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node* newNode(int data)
{
    struct node* ne=new node;
    ne->data=data;
    ne->left=ne->right=NULL;
    return ne;
};
void inorder(struct node* root)
{
    if(!root)
        return;

    inorder(root->right);

    inorder(root->left);
    cout<<root->data<<" ";
}
void inorder1(struct node* root)
{
    if(!root)
        return;

    inorder(root->left);

    inorder(root->right);
    cout<<root->data<<" ";
}
struct node* insertLevelOrder(struct node* root,int data)
{
  struct node* ne=newNode(data);
    if(root==NULL)
        root=ne;
    else
    {
        queue<struct node*> qu;
        qu.push(root);
        while(!(qu.empty()))
        {
            struct node* temp=qu.front();
            qu.pop();
            if(!(temp->left))
            {
                temp->left=ne;
                break;
            }
            else
                qu.push(temp->left);

            if(!(temp->right))
            {
                temp->right=ne;
                break;
            }
            else
                qu.push(temp->right);

        }
    }
    return root;
}
struct node* deleteNode(struct node* root,int key)
{
    struct node* tmp;
    struct node* rep;
    queue<struct node*> qu;
    qu.push(root);
    while((qu.empty()==false))
    {
        struct node* temp=qu.front();
        qu.pop();
        if((temp->data)==key)
            tmp=temp;
        if(temp->left)
        {
            qu.push(temp->left);
            if(temp->right)
               rep=temp;
        }
        if(temp->right)
        {
            qu.push(temp->right);
           if(temp->right)
               rep=temp;
        }

    }
    tmp->data=rep->right->data;
    rep->right=NULL;
    return root;
}
int main()
{
    struct node* root=NULL;
     int c=1;
     cout<<"press 1 to enter data and 0 to exit"<<endl;
    cin>>c;
     while(c==1)
     {
         int data;
         cout<<"enter the number"<<endl;
         cin>>data;
        root=insertLevelOrder(root,data);
    cout<<"press 1 to enter data and 0 to exit"<<endl;
    cin>>c;

     }
     inorder(root);
     cout<<endl;
     inorder1(root);
        cout<<"enter the node to be deleted"<<endl;
        int data;
        cin>>data;
        root=deleteNode(root,data);
     inorder(root);
}
