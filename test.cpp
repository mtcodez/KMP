#include "M_KMP.h"

int main()
{
	M_KMP kmp;
	kmp.Input();
	if(kmp.Search())
		kmp.Output();
	else
		std::cout << "No Match Found!" << std::endl;
	return 0;			 
}
	
