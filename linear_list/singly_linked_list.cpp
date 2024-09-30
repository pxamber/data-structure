#include <iostream>
#include <cstring>

using ElemType = int;

// defined singly linked list
typedef struct Node {
	ElemType data;
	Node *next;
}Node, *LinkList;

// make a empty list
LinkList MakeList( void ) {
	LinkList p = new Node;
	memset( p, 0, sizeof( Node ) );
	return p;
}

// get element from the list
bool GetElem( LinkList p, int index, ElemType *out ) {
	if( !index ) 
		return false;

	LinkList t = p;
	// traversal list
	while( t && index ) {
		--index;
		t = t->next;
	}

	if( !t || index  > 0 ) 
		return false;

	*out = t->data;
	return true;
}

// insert a element to list
bool InsertElem( LinkList p, int index, const ElemType elem ) {
	if( 0 >= index )
		return false;

	LinkList t = p;
	// find previous position of the index
	while( t && index != 1 ) {
		t = t->next;
		--index;
	}

	if( !t || index != 1 )
		return false;

	// initialize
	LinkList new_node = MakeList();
	new_node->data = elem;
	
	// insert
	new_node->next = t->next;
	t->next = new_node;

	return true;

}

bool DeleteElem( LinkList p, int index ) {
	if( 0 >= index )
		return false;

	LinkList t = p;
	// find previous position of the index
	while( p && index != 1 ) {
		t = t->next;
		--index;
	}

	if( t->next ) {
		LinkList node = t->next;
		t->next = node->next;
		delete node;
	}

	return true;
}

bool ModifyElem( LinkList p, int index, const ElemType new_val ) {
	if( 0 >= index )
		return false;

	LinkList t = p;
	while( t && index ) {
		t = t->next;
		--index;
	}

	if( !t || index )
		return false;

	t->data = new_val;

	return true;
}

// test
void PrintList( const LinkList p ) {
	LinkList t = p->next;
	while( t ) {
		std::cout << t->data << ' ';	
		t = t->next;
	}
	std::cout << std::endl;
}

int main( void ) {
	LinkList p = MakeList();
	InsertElem(p, 1, 1);
	InsertElem(p, 2, 2);
	InsertElem(p, 3, 3);

	ElemType e;
	GetElem( p, 1, &e );
	std::cout << e << std::endl;

	ModifyElem( p, 1, 3 );
	DeleteElem( p, 2 );

	PrintList( p );

	return 0;
}
