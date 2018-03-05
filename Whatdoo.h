//A MemoryCell template

#include<iostream>

template<typename Object>

class MemoryCell {

public:

	explicit MemoryCell( const Object & initalValue = Object { } )
		: storedValue{ initalValue } { }
	const Object & read ( ) const {

		return storedValue;
	}

	void write (const Object & x ) {

		storedValue = x; 
	}

	private:

		Object storedValue;
};

