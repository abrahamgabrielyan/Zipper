#include "Zipper.h"

void Zipper::compress(std::string fileName)
{
	std::ofstream fileZipped("zipped.txt", std::ios::app);

	std::ifstream file;

	std::string line;

	std::vector<int>repeats;

	file.open(fileName);

	if(!file)
	{
		std::cout << "File " << fileName << " doesn't exist." << std::endl;
		exit(1);
	}
		
	if(file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Provided file is empty." << std::endl;
		exit(1);
	}

	while(std::getline(file, line))
	{	
		std::stringstream ssLine(line);
		std::string word;

		int counter = 1;

		while(ssLine >> word)
		{
			for(size_t i = 0;i < word.length(); ++i)
			{
				if(word[i] == word[i + 1])
				{
					counter++;
				}
				else
				{
					repeats.push_back(counter);
					counter = 1;
				}
			}

			word.erase(std::unique (word.begin(), word.end()), word.end());

			int index = 0;
		
			for(size_t i = 0;i < word.length(); ++i)
			{	
				if(std::isdigit(word[i]) == 0)
				{
					word.insert(i + 1, std::to_string(repeats[index]));
					++index;
				}
			}
			
			repeats.clear();
			
			fileZipped << word << std::endl;
		}
	}

	file.close();
}

void Zipper::decompress(std::string fileName)
{
	std::ofstream fileUnzipped("unzipped.txt", std::ios::app);

	std::ifstream file;

	std::vector<std::string>repeatsCount;
	
	std::string line;

	file.open(fileName);

	if(!file)
	{
		std::cout << "File" << fileName << " doesn't exist." << std::endl;
		exit(1);
	}

	if(file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Provided file is empty." << std::endl;
		exit(1);
	}

	while(std::getline(file, line))
	{
		std::stringstream ssLine(line);
		std::string word;

		static int index = 0;

		while(ssLine >> word)
		{
			std::ostringstream repeats;
			std::ostringstream unzippedString;		

			for(size_t i = 0; i < word.length() + 1; ++i)
			{
				if(std::isdigit(word[i]) == 1)
				{
					repeats << word[i];
				}
				else
				{
					if(!(repeats.str()).empty())			
					{
						repeatsCount.push_back(repeats.str());
						repeats.str("");
						repeats.clear();
					}
				}
			}

   			for (size_t i = 0; i < word.size(); ++i) 
			{
			    	if (std::isdigit(word.at(i))) 
			    	{
        				word.erase(i,1);
        				--i;
    				}
			}			

			for(size_t i = 0;i < word.length();++i)
			{
				for(int j = 0;j < stoi(repeatsCount[index]);++j)
				{
					unzippedString << word[i];
				}
				++index;
			}

			fileUnzipped << unzippedString.str() << std::endl;
		}	
	}
	file.close();
}
