#include <iostream>
#include "Stack.h"


int main(){

	stack <int> s1;
	
	s1.peek();
	s1.push(10);
	s1.push(9);
	s1.push(8);
	s1.push(7);
	s1.push(6);
	s1.peek();
	s1.pop();
	s1.display();
	

	
	return 0;	
}
		


	
	
	
	


