/* Design a data structure that has worst case time for searching for an item of 
O(log n) and also has a worst case time for selecting the k'th element of O(log n).
So the first part is an AVL tree. We just need a search algoritem that can remember
the element we are searhing for and then retun K. Since we can traverse the tree in
O(log(n)) time. Then we should also beable to retun K in O log n aswell.

//My findK is not working right :/

*/



#include"AvlTreemod.h"



int main ( ) {

	AvlTree<int> t;

	for( int i = 0; i !=10; i++){

		t.insert(i);


	}


	t.findK(5);

	return 0;

};