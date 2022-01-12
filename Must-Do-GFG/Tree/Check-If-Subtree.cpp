/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Solution:                                                                                                                                                    */

    bool check(Node* t, Node* s){
        if(t==NULL && s==NULL)  return true;
        if(t==NULL || s==NULL)  return false;
        
        if(t->data != s->data) return false;
        return (check(t->left,s->left) && check(t->right,s->right));    
    }

    bool isSubTree(Node* t, Node* s) 
    {
       // Your code here
        if(t==NULL && s==NULL)  return true;
        if(t==NULL)  return false;
        return (check(t,s)) || isSubTree(t->left,s) || isSubTree(t->right,s);  
    }
