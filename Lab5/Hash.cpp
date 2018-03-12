/* This is heavily based upon the code from the website plus some of Sheri's fixes.
* I finally got it all to compile and add employees so thats fun. Uses the const_iterator from the 
*bult in list type. I added a timer to the main program to see the running time.
*/

#include <list>
#include <vector>
#include <iterator>
#include <string>




// Separate Chaining version
template <typename HashedObj>


class HashTable
{

  private:
    std::vector<std::list<HashedObj> > theLists;   // The array of Lists
    int  currentSize;

	bool find(const std::list<HashedObj> &l, const HashedObj &x) const {
		typename std::list<HashedObj>::const_iterator itr = l.begin();
		while (itr != l.end())
			if (*itr == x)
				return true;
		return false;
			
	}


	

    
    /**
     * Rehashing for separate chaining hash table.
     */
    void rehash( )
    {
        std::vector<std::list<HashedObj> > oldLists = theLists;
    
            // Create new double-sized, empty table
			// use array double + 1 instead of nextPrime
		theLists.resize(  2 * theLists.size( ) +1) ;
        for( int j = 0; j < theLists.size( ); j++ )
            theLists[ j ].clear( );
    
            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldLists.size( ); i++ )
        {
		// prepend that iterator is a type name C++ problem recognizing
		// it as a type when it is dependent on the template arg
            typename std::list<HashedObj>::iterator itr = oldLists[ i ].begin( );
            while( itr != oldLists[ i ].end( ) )
                insert( *itr++ );
        }
    }

    int myhash( const HashedObj & x ) const
    {
        int hashVal = hash( x );		// call the user provided hash
	
        hashVal %= theLists.size( );
        if( hashVal < 0 )
            hashVal += theLists.size( );
	
        return hashVal;
    }
  public:
    explicit HashTable( int size = 101 ) : theLists(size), currentSize(0) {
		// allocate an empty list with default constructor for each bucket
/*
		for (int i=0; i<size; i++) {
			theLists[i] = *new list<HashedObj>();
		}
*/
	}

    bool contains( const HashedObj & x ) const
    {
        const std::list<HashedObj> & whichList = theLists[ myhash( x ) ];
        return find( whichList, x );
    }

    void makeEmpty( )
    {
        for( int i = 0; i < theLists.size( ); i++ )
            theLists[ i ].clear( );
    }

    bool insert( const HashedObj & x )
    {
        std::list<HashedObj> & whichList = theLists[ myhash( x ) ];
        if( find( whichList, x))
            return false;
        whichList.push_back( x );
    
            // Rehash; see Section 5.5
        if( ++currentSize > theLists.size( ) )
            rehash( );
    
        return true;
    }

    bool remove( const HashedObj & x )
    {
        std::list<HashedObj> & whichList = theLists[ myhash( x ) ];
		// prepend that iterator is a type name C++ problem recognizing
		// it as a type when it is dependent on the template arg
        //typename list<HashedObj>::iterator itr = find( whichList.begin( ), whichList.end( ), x );
		// His implementation passes an iterator. 
		// but uses it as a bool, which I thought was ugly.
    
		/*
        if( itr == whichList.end( ) )
            return false;
		*/

		if (!find(whichList, x))
			return false;
    
        //whichList.erase( itr );
		whichList.remove(x);
        --currentSize;
        return true;
    }

};


//I couldnt understand what the point of this function is other than to hash strings.
// You are right, this is very round-about. So I added it to the insert function for fun.



/*
 * Expect the HashedObj to provide the hash functions
 * It should return a const string &
 * then a generic hash function takes the string and returns an int.
 * then myhash adjusts the int to the tablesize. Seems a little round-about
 * to me. ... all to avoid the template dependency.
 * like double dispatch.
 */

int hash (const std::string &key) {
	// based on fig 5.4

    int hashVal = 0;

    for( int i = 0; i < key.length( ); i++ )
        hashVal = 37 * hashVal + key[ i ];

    return hashVal;
}


