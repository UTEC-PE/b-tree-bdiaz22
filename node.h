#ifndef NODE_H
#define NODE_H

#include <iostream> 
using namespace std; 
 
class Node 
{
public: 
    int *keys;   
    int degree;       
    Node **child; 
    int n;      
    bool leaf;  
 
    Node(int size, bool isleaf)  
    { 
        degree = size; 
        leaf = isleaf; 
        keys = new int[2*degree-1]; 
        child = new Node *[2*degree]; 
        n = 0; 
    }
    void insertNonFull(int k) 
    { 
        int i = n-1; 
        if (leaf == true) 
        { 
            while (i >= 0 && keys[i] > k) 
            { 
                keys[i+1] = keys[i]; 
                i--; 
            } 
            keys[i+1] = k; 
            n = n+1; 
        } 
        else 
        { 
            while (i >= 0 && keys[i] > k) 
                i--; 
            if (child[i+1]->n == 2*degree-1) 
            { 
                splitChild(i+1, child[i+1]); 
                if (keys[i+1] < k) 
                    i++; 
            } 
            child[i+1]->insertNonFull(k); 
        } 
    } 
  
    void splitChild(int i, Node *y)  
    { 
        Node *z = new Node(y->degree, y->leaf); 
        z->n = degree - 1; 
      
        for (int j = 0; j < degree-1; j++) 
            z->keys[j] = y->keys[j+degree]; 
      
        if (y->leaf == false) 
        { 
            for (int j = 0; j < degree; j++) 
                z->child[j] = y->child[j+degree]; 
        } 
      
        y->n = degree - 1; 
      
        for (int j = n; j >= i+1; j--) 
            child[j+1] = child[j]; 
      
        child[i+1] = z; 
      
        for (int j = n-1; j >= i; j--) 
            keys[j+1] = keys[j]; 
      
        keys[i] = y->keys[degree-1]; 
      
        n = n + 1; 
    } 
  
    Node *search(int k)    
    {  
        int i = 0; 
        while (i < n && k > keys[i]) 
            i++; 
      
        if (keys[i] == k) 
            return this; 
      
        if (leaf == true) 
            return NULL; 
      
        return child[i]->search(k); 
    }
  
    friend class BTreea; 
}; 
#endif