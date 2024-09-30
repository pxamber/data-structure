#include <iostream>
#define MAXLENGTH 100

using ElemType = int;

// defined sequenatial stack
typedef struct {
	ElemType data[MAXLENGTH];
	int top;	// -1 while is a empty stack
}SqStack;

// insert a element to top of stack
bool PushStack( SqStack &S, const ElemType e ) {
	// stack is full
	if( S.top == MAXLENGTH - 1 )
		return false;

	++S.top;
	S.data[S.top] = e;

	return true;
}

// pop the top
bool PopStack( SqStack &S, ElemType* const e ) {
	// stack is empty
	if( S.top == - 1 )
		return false;

	*e = S.data[S.top];
	--S.top;

	return true;
}

void PrintStack( const SqStack &S ) {
	if( -1 == S.top )
		return;

	for( int i = 0; i <= S.top; ++i ) 
		std::cout << S.data[i] << ' ';

	std::cout << std::endl;
}

int main() {
	SqStack S;
	S.top = -1;
	PushStack( S, 1 );
	PushStack( S, 2 );
	PushStack( S, 3 );

	PrintStack( S );

	ElemType e;
	PopStack( S, &e );
	std::cout << e << std::endl;

	PrintStack( S );

	return 0;
}
