#include <iostream>
#include <cstring>

// defined sequenatial list length
#define MAX_LENGTH 100
// defined element type
#define ElemType int

using uint = unsigned int;

// defined sequenatial the list
typedef struct {
    ElemType data[MAX_LENGTH];
    unsigned int length;
}SqList;

// get element from the list
bool GetElem( const SqList &L, const int index, ElemType* const out ) {
	// identify squenatial list
	if( index > L.length || index < 1)
		return false;

	*out = L.data[index - 1];
	
	return true;
} 

// insert a element to the list
bool InsertElem( SqList &L, const int index, const ElemType elem ) {
	// less fist or list is full or greater last
	if( index < 1 || L.length ==  MAX_LENGTH || index > L.length + 1 )
		return false;

	// if the inserted index is not last
	if( index <= L.length )
		// move the list
		for( int i = L.length; i > index - 1; --i )
			L.data[i] = L.data[i-1];

	// insert
	L.data[index-1] = elem;
	++L.length;

	return true;
}

// delete a element from the list
bool DeleteElem( SqList &L, const int index ){
	// identify list
	if( index < 1 || index > L.length )
		return false;

	for(int i = index - 1; i < L.length - 1; ++i )
		L.data[i] = L.data[i+1];

	--L.length;
	
	return true;
}

bool ModifyElem( SqList &L, const int index, const ElemType new_val ) {
	if( index < 1 || index > L.length )
		return false;

	L.data[index - 1] = new_val;

	return true;
}

// for test
void PrintList( const SqList &L ) {
	for( int i = 0; i < L.length; ++i)
		std::cout << L.data[i] << ' ';
	std::cout << std::endl;
}

int main(void) {
	SqList L;
	memset( &L, 0, sizeof(SqList) );
	InsertElem(L, 1, 1);
	InsertElem(L, 2, 2);
	InsertElem(L, 3, 3);

	ElemType e;
	GetElem( L, 2, &e );
	std::cout << e << std::endl;

	DeleteElem(L, 2);
	GetElem( L, 2, &e );
	std::cout << e << std::endl;

	ModifyElem( L, 1, 3 );


	PrintList(L);

	return 0;
}
