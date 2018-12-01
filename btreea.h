#ifndef BTREEA_H
#define BTREEA_H

#include "node.h"
#include <iostream> 
using namespace std; 
     
class BTreea 
{ 
    Node *root;  
    int degree;   
public:  
    BTreea(int size) 
    {   
        root = NULL;  
        degree = size;
    }   
   
    Node* search(int k) 
    {   
        if(!root)
            throw "No se encontró";
        else
            return root->search(k);
    } 
 
    void insert(int k)
    { 
        if (root == NULL) 
        {   
            root = new Node(degree, true); 
            root->keys[0] = k;  
            root->n = 1;  
        } 
        else  
        { 
            if (root->n == 2*degree-1) 
            { 
                Node * new_node = new Node(degree, false); 
                new_node->child[0] = root; 
                new_node->splitChild(0, root); 
                int i = 0; 
                if (new_node->keys[0] < k) 
                    i++; 
                new_node->child[i]->insertNonFull(k);
                root = new_node; 
            } 
            else  
                root->insertNonFull(k); 
        } 
    } 

};

#endif