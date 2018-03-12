#include <iostream>
#include "AVL.h"
#include<fstream>
#include <graphviz/gvc.h>

using namespace std;

    // Test program


void makefile(AvlTree<int> t){

    //This Function redirects stdout to a file. 
    freopen("Treez.dot","w",stdout);
    
    cout << "graph{" << endl;
    
    t.makeGraph();

    cout << 4 << endl;
    
    cout << "}" << endl;

};



int main( )
{
    AvlTree<int> t;
    int NUMS [5] = {1,2,3,5,8};
    int i;
    ofstream Treephile;

    for (i = 0; i < 5; i++)
        t.insert(NUMS[i]);

    
    //This Function redirects stdout to a file. 
    //freopen("Treez.dot","w",stdout);
    
    cout << "graph{" << endl;
    
    t.makeGraph();

    cout << 4 << endl;
    
    cout << "}" << endl;

    makefile(t);



    return 0;
}