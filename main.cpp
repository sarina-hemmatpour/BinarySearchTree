#include<iostream>
using namespace std;

struct node {
    int data;
    int key;
    node* left;
    node* right;
    node*parent;
};
class BST {

    node* root;


    node* insert(int data, int key, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            node* n=new node;
            n->data = data;
            n->key=key;
            n->left = n->right = NULL;
            t=n;
        }
        else if(key < t->key)
        {
            t->left = insert(data,key, t->left);
            t->left->parent=t;
        }
        else if(key > t->key)
        {
            t->right = insert(data,key, t->right);
            t->right->parent=t;
        }

        else
        {
            t->data=data;
        }
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }


    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            return find(t->left, x);
        else if(x > t->key)
            return find(t->right, x);
        else
            return t;
    }

    int greater(node* n ,  int key)
    {
        if (n==NULL)
        {
            return 0;
        }

        int count=0;

        if (n->key>key)
        {
            count++;
        }

        count+=greater(n->right,key);
        count+=greater(n->left,key);

        return count;

    }

    int smaller(node* n ,  int key)
    {
        if (n==NULL)
        {
            return 0;
        }

        int count=0;

        if (n->key<key)
        {
            count++;
        }

        count+=smaller(n->right,key);
        count+=smaller(n->left,key);

        return count;
    }

public:
    BST() {
        root = NULL;
    }


    void insert(int data,int key) {
        root = insert(data , key, root);
    }


    void display() {
        inorder(root);
        cout << endl;
    }
    node* findSecMax()
    {
        node* n=findMax(root);
        if (n!=NULL)
        {
            if (n->parent!=NULL)
            {
                cout<<"(key="<<n->parent->key<<" , data="<<n->parent->data<<")"<<endl;
                return n->parent;
            } else
            {
                cout<<"Theres only one element in the tree!!!"<<endl;
            }

        } else
        {
            cout<<"the tree is null"<<endl;
        }
    }
    node* findSecMin()
    {
        node* n=findMin(root);
        if (n!=NULL)
        {
            if (n->parent!=NULL)
            {
                cout<<"(key="<<n->parent->key<<" , data="<<n->parent->data<<")"<<endl;
                return n->parent;
            } else
            {
                cout<<"Theres only one element in the tree!!!"<<endl;
            }

        } else
        {
            cout<<"the tree is null"<<endl;
        }
    }

    void findNodesGreaterThan(int key)
    {
        int c=greater(root,key);
        cout<<"The number of graeter elements is: "<<c<<endl;
    }

    void findNodesSmallerThan(int key)
    {
        int c=smaller(root,key);
        cout<<"The number of smaller elements is: "<<c<<endl;
    }

};

int main() {
    BST t;
    t.insert(20,20);
    t.insert(25,25);
    t.insert(15,15);
    t.insert(10,10);
    t.insert(30,30);
    t.findNodesGreaterThan(15);
    t.findNodesSmallerThan(15);
    t.findSecMax();
    t.display();
    t.display();
    t.display();
    t.display();
    return 0;
}