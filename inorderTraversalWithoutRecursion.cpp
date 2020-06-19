#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node
{
    public:
    int data;
    node* left,*right;
};
node* createNewNode(node* root)
{
    node* ne=new node();
    cout<<"enter the data\n";
    cin>>ne->data;
    ne->left=NULL;
    ne->right=NULL;
    queue <node*> qu;
    qu.push(root);
    if(!root)
    {
        root=ne;
        return root;
    }
    else
    {
    while(!qu.empty())
    {
        node* temp=qu.front();
        qu.pop();
        if(!temp->left)
        {
            temp->left=ne;
            break;
        }
        else
            qu.push(temp->left);
        if(!temp->right)
        {
            temp->right=ne;
            break;
        }
        else
            qu.push(temp->right);
    }
    return root;
    }
}
void inorder(node* root)
{
   stack<node *> s;
    node *curr = root;
   while (curr != NULL || s.empty() == false)
    {
      
        while (curr !=  NULL)
        {
          
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

     
        curr = curr->right;

    } 
   }

int main()

{
    node* root=NULL;
    int t=5;
    while(t--)
    {
        root=createNewNode(root);
    }
    inorder(root);

}
