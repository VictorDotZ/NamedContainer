#include <NamedContainer/NamedContainer.hpp>
#include <iostream>

int main()
{
	NamedContainer myC { "field1", "field2", "field3" };

	auto c1 = myC.create();

	c1["field1"] = "abc"; // OK
	std::cout << c1["field1"] << std::endl; // abc
	std::cout << c1["field2"] << std::endl; // Пустая строка по умолчанию

	try {
		c1["XXX"] = "cdr"; // Exception - unknown name
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << c1["XXX"] << std::endl; // Exception - unknown name

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	for (auto it = c1.begin(); it != c1.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}

	for (auto it = c1.begin(); it != c1.end(); ++it) {
		std::cout << it->first << ":" << c1[it->first] << std::endl;
	}
}