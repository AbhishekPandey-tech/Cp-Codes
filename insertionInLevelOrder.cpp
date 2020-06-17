#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node *left,*right;
};
node* create_node(int key)
{
    node *ne=new node();
    ne->data=key;
    ne->left=ne->right=NULL;
    return ne;
}
void inorder(node* temp)
{
    if(!temp)
        return;
    inorder(temp->left);
    cout<<(temp->data)<<" ";
    inorder(temp->right);
}
void insertNode(node* root,int key)
{
    queue <node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        node* t=qu.front();
        qu.pop();
        if(!t->left)
        {
            t->left=create_node(key);
            break;
        }
        else
            qu.push(t->left);
        if(!t->right)
        {
            t->right=create_node(key);
            break;
        }
        else
            qu.push(t->right);
    }
}
int main()
{
    node* root=create_node(10);
    root->left=create_node(11);
    root->left->left=create_node(7);
    root->right=create_node(9);
    root->right->left=create_node(15);
    root->right->right=create_node(8);
    inorder(root);
    cout<<endl;
    insertNode(root,12);
    insertNode(root,6);
    insertNode(root,98);
    inorder(root);
    return 0;

}
