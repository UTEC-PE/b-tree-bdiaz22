#include <iostream>

#include "btreea.h"

using namespace std;

int main(int argc, char *argv[]) {
    BTreea t(3); 
    t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12); 
    t.insert(30); 
    t.insert(7); 
    t.insert(17); 
    t.insert(22);
    
    int k = 6; 
    (t.search(k) != NULL)? cout << "Se encontró" <<"\n" : cout << "No se encontró" << "\n"; 
  
    k = 22; 
    (t.search(k) != NULL)? cout << "Se encontró" <<"\n" : cout << "No se encontró" <<"\n"; 
    
    return 0; 
} 