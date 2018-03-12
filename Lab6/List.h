
/*
 * Changed nullptr to NULL for ada compilation on ada
 * also removed refs to auto
 */

/*
 * This file has several implementations of reverse,
 * as examples of different implementation choices
 * 
 * One note on two major differences of implementations.
 * You can swap the data in the nodes OR
 * you can reverse the pointers.
 *
 * In a list the implementation OWNS the pointers but does not OWN
 * the data. So you can always change the pointers (which are just
 * about the traversal and hidden from the user of the list) but
 * swapping the data may have an impact. Swapping the data may be
 * affected by overloaded operator= (copy or move) and choices of
 * deep or shallow copy. Consider if the data in your list
 * were itself a large data structure. You could have a list of lists.
 * Then doing a swap with a deep copy would involve significant data
 * copying. This could happen implicitly with the use of operator=
 *
 * Note also that there are other choices you might make in your
 * implementation that also would be just fine.
 */

#ifndef LIST_H
#define LIST_H

#include <algorithm>
#include <iostream>

using namespace std;

template <typename Object>
class List
{
  private:    
    // The basic doubly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node
    {
        Object  data;
        Node   *prev;
        Node   *next;
        int min = 0;

        Node( const Object & d = Object{ }, Node * p = NULL, Node * n = NULL )
          : data{ d }, prev{ p }, next{ n } { }
        
        Node( Object && d, Node * p = NULL, Node * n = NULL )
          : data{ std::move( d ) }, prev{ p }, next{ n } { }
    };

  public:
    class const_iterator
    {
      public:
  
        // Public constructor for const_iterator.
        const_iterator( ) : current{ NULL }
          { }

        // Return the object stored at the current position.
        // For const_iterator, this is an accessor with a
        // const reference return type.
        const Object & operator* ( ) const
          { return retrieve( ); }
        
        const_iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }

        const_iterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }

        const_iterator operator-- ( int )
        {
            const_iterator old = *this;
            --( *this );
            return old;
        }
            
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }

        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }

      protected:
        Node *current;

        // Protected helper in const_iterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object & retrieve( ) const
          { return current->data; }

        // Protected constructor for const_iterator.
        // Expects a pointer that represents the current position.
        const_iterator( Node *p ) :  current{ p }
          { }
        
        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
      public:

        // Public constructor for iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        iterator( )
          { }

        Object & operator* ( )
          { return const_iterator::retrieve( ); }

        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object & operator* ( ) const
          { return const_iterator::operator*( ); }
        
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }

        iterator & operator-- ( )
        {
            this->current = this->current->prev;
            return *this;
        }

        iterator operator-- ( int )
        {
            iterator old = *this;
            --( *this );
            return old;
        }

      protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator( Node *p ) : const_iterator{ p }
          { }

        friend class List<Object>;
    };

  public:
    List( )
      { init( ); }

    ~List( )
    {
        clear( );
        delete head;
        delete tail;
    }

/*
    List( const List & rhs )
    {
        init( );
        for( auto & x : rhs )
            push_back( x );
    }
*/
    List( const List & rhs )
    {
        init( );
		Node *px = rhs.head->next;

		while (px) {
            push_back( px->data );
		}
    }

    List & operator= ( const List & rhs )
    {
        List copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    
    List( List && rhs )
      : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = NULL;
        rhs.tail = NULL;
    }
   
    List & operator= ( List && rhs )
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        
        return *this;
    }
    
    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )
      { return iterator( head->next ); }

    const_iterator begin( ) const
      { return const_iterator( head->next ); }

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end( )
      { return iterator( tail ); }

    const_iterator end( ) const
      { return const_iterator( tail ); }

    // Return number of elements currently in the list.
    int size( ) const
      { return theSize; }

    // Return true if the list is empty, false otherwise.
    bool empty( ) const
      { return size( ) == 0; }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }
 
    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( )
      { return *begin( ); }

    const Object & front( ) const
      { return *begin( ); }

    Object & back( )
      { return *--end( ); }

    const Object & back( ) const
      { return *--end( ); }

    void push_front( const Object & x )
      { insert( begin( ), x ); }

    void push_back( const Object & x )
      { insert( end( ), x ); }

    void push_front( Object && x )
      { insert( begin( ), std::move( x ) ); }

    void push_back( Object && x )
      { insert( end( ), std::move( x ) ); }

    void pop_front( )
      { erase( begin( ) ); }

    void pop_back( )
      { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
    }

    // Insert x before itr.
    iterator insert( iterator itr, Object && x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
    }
    
    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;

        return retVal;
    }

    iterator erase( iterator from, iterator to )
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );

        return to;
    }

/*
 * add an exchange method to exchange two values without
 * copies
 * Note: should really make sure to use operator= move
 * and not operator= copy, but for this case (with ints)
 * it is the same.
 */

  void exchange(iterator l1, iterator l2) {
	Object tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
  }

/*
 * see the comment on revSwap ... this is the function referred to there.
 * Using an iterator and std::swap we can get a very compact
 * reverse that would work the same both as a member function
 * and as a non-member function
 *
 * The only problem is that on an even list the iterators
 * move past each other and iterators don't support anything
 * beyond == testing.
 */

 void reverse_it() {
	iterator it1 = this->begin();
	iterator it2 = this->end();
	--it2;

	if (empty())
		return;
	while (it1 != it2) {
		std::swap(*it1, *it2);
		it1++;
		if (it1 != it2)		// check for even!
			--it2;
	}
}


/*
 * Member reverse -- this just reverses the pointers
 * iterative solution
 * See reverse1 just below.
 * reverse uses the pointers explicitly
 * reverse1 below uses std::swap to swap the pointers.
 * the 2 versions are really identical,
 * but using std::swap makes for more compact code (and
 * this more verbose comment!)
 *
 */

  void reverse() {
	Node * current = head;
	Node * next = NULL;
	head = tail;
	tail = current;

	// Note the way the List was defined
	// that head->next is the first element and
	// tail->prev is the last so thast
	// head and tail point to the node before
	// the first and after the last, respectively
	// I'll just swap all pointers, including the head and tail

	while  (current != NULL) {
		next = current->next;
		current->next = current->prev;
		current->prev = next;
		current = next;
	}
	
	
  }

/*
 * This reverse is the same as the one above but using  std::swap for
 * the exchange and advancing the pointer in the for header.
 * Note that since we swapped current->next and current->prev
 * that current = current->prev is really the same
 * as current = current->next in the "original" node and the code above.
 * and the final swap of the head and the tail below was done 
 * explicitly in the initialization above. 
 * Because swap does the actual swapping work, reverse1 doesn't need
 * to use a next variable.
 */
void reverse1() {
    for (auto current = head; current; current = current->prev)
      std::swap(current->next, current->prev);
    std::swap(head, tail);
}

/*
 * Here is a reverse with swaps
 * Done with direct nodes; could use iterators
 * Also could use std::swap
 * See note at the start of this file.
 */

  void revSwap () {
	Node *current = head;
	Node *last = tail;
	Object data;

	if (empty())
		return;

	while (current != last && current->prev != last) {
		data = current->data;
		current->data = last->data;
		last->data = data;
		current=current->next;
		last=last->prev;
	}
	
}

/*
 * Here is a recursive version 
 * in innerRev We expect to have current at the first real node.
 * prev will initially be head
 * base case when current == tail
 * innerRev returns with head pointint at the new tail,
 * and tail at the new head.
 * ONly does the next reversals (Ie singly linked list)
 */

/*
void rec_reverse() {
	if (empty())
		return;
	innerRev(head->next, head);
        std::swap( head, tail);
	tail->prev = tail->next;
	tail->next = NULL;
	head->next = head->prev;
	head->prev = NULL;
}

void innerRev(Node *curr, Node * prev) {
	if (curr == tail) {
		return;
	} else {
		Node *next = curr->next; // original next
		curr->next = prev;	// new next
		return innerRev(next, curr);
	}
}
*/

/*
 * This version handles both next and prev
 * Recursive doubly linked list version
 */
void rec_reverse() {
	if (empty())
		return;
	innerRev(head->next, head, head->next->next);
	// Note that in a non-empty list, head->next points to an
	// actual data item, so that head->next->next is guaranteed
	// to exist.
        std::swap( head, tail);
	tail->prev = tail->next;
	tail->next = NULL;
	head->next = head->prev;
	head->prev = NULL;
}

void innerRev(Node *curr, Node * prev, Node * next) {
	if (!next) {
		return;
	} else {
		curr->next = prev;
		curr->prev = next;
		return innerRev(next, curr, next->next);
	}
}

/*
 * This reverse rebuilds the list.
 * It is the style used in functional programming
 * but would not be used in an objecct-oriented or
 * state based language because of the overhead of building
 * the list over again.
 * But it has a very clean semantics and is easy to prove
 * correct.
 */

List reverse2 () {
        List l;
        clean_reverse(l);
        return l;
}

void clean_reverse(List &l) {
        if (!empty()) {
           Object o = front();
           pop_front();
           clean_reverse(l);
           l.push_back(o);
		   return;
        }
		return;

}

/*
 * I would never really do this!
 * relying on an interator when the data structure is changing. 
 * but ...
 */

void itr_reverse() {
	iterator it1 = this->begin();
	iterator it2 = this->end();

	for (int i=0; i<theSize; i++) {
		Object val = front();
		insert(it2, val);
		erase(it1++);
		--it2;
	}


}



  private:
    int   theSize;
    Node *head;
    Node *tail;

    void init( )
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

#endif
