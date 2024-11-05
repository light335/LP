#include<iostream>
#include<queue>
using namespace std;

struct node{

    char data;
    int freq;
    node * left;
    node *right;

    node(char data,int freq)
    {
        left=right=NULL;

        this->data=data;
        this->freq=freq;
    }


};

struct compare{
    bool operator()(node* left,node *right)
    {
        return left->freq>right->freq;
    }
};

void printCodes(node *root,string str)
{
    if(!root)
    {
        return;
    }
    if(root->data!='$')
    {
        cout<<root->data<<":"<<str<<endl;
    }

    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");


}
void Huffmancodes(char data[],int freq[],int size)
{
    node *left ,*right,*top;
    priority_queue<node *,vector<node *>,compare>minheap;

    for(int i=0;i<size;i++)
    {
        minheap.push(new node(data[i],freq[i]));
    }

    while (minheap.size()!=1)
    {
        left=minheap.top();
        minheap.pop();
        right=minheap.top();
        minheap.pop();
         

         top=new node('$',left->freq+right->freq);
         top->left=left;
         top->right=right;
         minheap.push(top);
    }
    
    printCodes(top,"");
}

int main()
{
    char arr[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};

    Huffmancodes(arr,freq,6);

    return 0;

}