#include <iostream>
#include <cstdlib>
using namespace std;



template < class Object>
	class BST {

	public:	

		BST( ) : root(NULL) { 
    }

		bool empty( ) const {
		return root == NULL;
    	}

    	void insert( const Object & x ) {
		insert(x, root);
    }



	private:
		struct BSTNode {
			Object value;
			struct BSTNode *left;
			struct BSTNode	*right;

			BSTNode( const Object & theElement, BSTNode *lt, BSTNode *rt )
         : value( theElement ), left( lt ), right( rt ) { }

		};

		struct BSTNode *root;

	};

	    void insert( const Object & x, BSTNode * & t )
    {

        if( t == NULL ) 
            t = new BSTNode( x, NULL, NULL );
        else if( x < t->value )
            insert( x, t->left );
        else if( t->value < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }

int main()
	{
		BST<int> Tree;
		cout << Tree.empty();

	}