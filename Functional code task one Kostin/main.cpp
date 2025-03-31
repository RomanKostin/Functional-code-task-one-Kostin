#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <functional>

bool Compare(std::string a,std::string b);

int main()
{
	std::ifstream file1_i("name1.txt");
	std::ifstream file2_i("name2.txt");
	std::ofstream file_o("output.txt");
	std::merge(std::istream_iterator<std::string>(file1_i), std::istream_iterator<std::string>(), std::istream_iterator<std::string>(file2_i),
		std::istream_iterator<std::string>(), std::ostream_iterator<std::string>(file_o, " "), Compare);
	return 0;
}

bool Compare(std::string a, std::string b)
{
	return a.size()<b.size()||(a.size()==b.size()&&a<b);
}
