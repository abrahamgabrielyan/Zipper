#ifndef _ZIPPER_H_
#define _ZIPPER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Zipper
{
public:
	void compress(std::string fileName);
	void decompress(std::string fileName);	
};

#endif //_ZIPPER_H_
