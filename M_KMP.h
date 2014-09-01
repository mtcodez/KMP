#include <iostream>
#include <string>
#include <vector>
// Matt Luo <mante.luo@gmail.com>

class M_KMP
{
public:
	M_KMP();
	~M_KMP();
	
	void Preprocessor();
	bool Search();
	void Input();
	void Output();	
private:
	int t_len; // Text Length
	int p_len; // Pattern Length
	std::string text, pattern;
	std::vector<int> boarder; // a widest boarder width array
	char *matched;
};

