#include "M_KMP.h"

M_KMP::M_KMP(): t_len(0), p_len(0)
{ }

M_KMP::~M_KMP()
{
	if(matched != NULL)
		delete []matched;
}

void M_KMP::Preprocessor()
{
	int b = -1, p = 0; // b for boarder, p for pattern

	boarder[p] = b;
	while(p < p_len)
	{
		/*
		 *  If they doesn't match, p just keep going forward.
		 */
		while(b >= 0 && pattern[b] != pattern[p])
			b = boarder[b];
		b++;
		p++;
		boarder[p] = b;  // b is the current widest board length.
	}
	
}

bool  M_KMP::Search()
{
	Preprocessor();
	int p = 0, t = 0;
	while(t < t_len)
	{
		while(p >= 0 && pattern[p] != text[t])
			p = boarder[p];
		p++;
		t++;
		if(p == p_len)
		{
			matched[t -p] = '^';
			return true;
		}
	}
	return false;
	
}

void M_KMP::Input()
{
	std::cout << "Input Text:" << std::endl;
	std::cin >> text;
	std::cout << "Pattern:" << std::endl;
	std::cin >> pattern;
	t_len = text.length();
	p_len = pattern.length();

	// initialize boarder array
	for(int i = 0; i < p_len + 1; ++i)
	{		
		boarder.push_back(0);
	}
	matched = new char[t_len];
	for(int i = 0; i < t_len; ++i)
		matched[i] = ' ';
	
}

void M_KMP::Output()
{
	std::cout << "The boader:"<< std::endl;
	for(unsigned int i = 0; i < boarder.size(); ++i)
		std::cout << boarder[i] << " ";
	std::cout << std::endl;
	std::cout << text << std::endl;	
	std::cout << matched << std::endl;

}
     
