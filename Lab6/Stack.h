#include "List.h"

/*
 * This is a minimal stack, no iterator (which doesn't make sense
 * for a stack!)
 * This version assumes the user "owns" the objects, so no new
 * or deletes done.
 */

template <typename Object>
class Stack {

public:
   Stack( ) : elements{new List<Object>()} {
      
   }

   ~Stack( ) {
	delete elements;
    }

   Stack( const Stack & rhs ) {		// copy constructor
	elements = new List<Object>(rhs.elements);
   }

   Stack & operator= ( const Stack & rhs ) {// copy operator=
	Stack copy = rhs;
	std::swap( *this, copy );
	return *this;
   }


   Stack( Stack && rhs )		// move constructor
	: elements{ rhs.elements } {
		rhs.elements = NULL;
   }

   Stack & operator= (    Stack && rhs ) {	// move operator=
	std::swap( elements, rhs.elements );

	return *this;
   }

   void push(const Object & o) {
	
   if (elements->empty()){
   elements->push_front(o);
   }
   else{

      if ( o < elements->front()) {
         elements->push_front(o);

      }
      else{
         List<Object> * Copy;
         Copy->push_front(elements->front());
         elements->push_front(o);
         elements->push_front(Copy->front());         

      }

   }

   }

   void pop() {
	elements->pop_front();
   }

   const Object & top() const {
	return elements->front();
   }

   bool isEmpty() const {
	return elements->empty();
   }

   Object getMin() const {
      return elements->front();
   }

private:
   List<Object> * elements;

};


	

