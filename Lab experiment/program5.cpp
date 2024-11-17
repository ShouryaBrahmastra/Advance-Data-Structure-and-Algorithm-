/**
 * 
 * Write a program for tree traversing
 *
 * (a) Inorder
 *
 * (b) Preorder
 *
 * (c) Postorder
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include<iostream>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;   
    
};

struct tree *createnode(int data)
{
    struct tree *t;
    t=(struct tree *)malloc(sizeof(struct tree));
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    return t;
};

class TreeFunc
{
    public:
        void PreOrder(struct tree *r)
        {
            if(r!=NULL)
            {
                printf(" %d ",r->data);
                PreOrder(r->left);
                PreOrder(r->right);
            }
        }

        void PostOrder(struct tree *r)
        {
            if(r!=NULL)
            {
                PostOrder(r->left);
                PostOrder(r->right);
                printf(" %d ",r->data);
            }
        }

        void InOrder(struct tree *r)
        {
            if(r!=NULL)
            {
                InOrder(r->left);
                printf(" %d ",r->data);
                InOrder(r->right);
            }
        }

};

int main()
{
    /*
                  5[p]
            /             \
           3[p2]           6[p5]
         /      \        /      \ 
       2[p3]     4[p1]  7[p6]    8[p7]
     /
    1[p4]
    */
    struct tree *p=createnode(5);
    struct tree *p1=createnode(4);
    struct tree *p2=createnode(3);
    struct tree *p3=createnode(2);
    struct tree *p4=createnode(1);
    struct tree *p5=createnode(6);
    struct tree *p6=createnode(7);
    struct tree *p7=createnode(8);

    p->left=p2;
    p->right=p5;
    p2->left=p3;
    p2->right=p1;
    p3->left=p4;
    p5->left=p6;
    p5->right=p7;

    cout<<endl;
    TreeFunc obj;

    cout << "\nPreOrder Traversal: "; obj.PreOrder(p); 
    cout << "\nPostOrder Traversal: "; obj.PostOrder(p); 
    cout << "\nInOrder Traversal: "; obj.InOrder(p);

    return 0;
}