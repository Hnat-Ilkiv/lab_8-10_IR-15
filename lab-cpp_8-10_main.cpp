#include <iostream>
#include "lab-cpp_8-10_class.h"

int main() {
	Instrument_binaryTree* tree = new Instrument_binaryTree;
	tree->add_Instrument("Hello", "World", 0, 1, 1990);
	tree->add_Instrument("Dell", "Computer", 12, 24, 2015);
	tree->add_Instrument("HP", "Computer", 2, 9, 2007);
	tree->add_Instrument("Apple", "Computer", 6, 16, 2022);
	tree->add_Instrument("VM-S", "Voltmeter", -2000, 2000, 2004);
	tree->add_Instrument("VM-D", "Voltmeter", -450, 450, 2002);

	std::cout << "Print binary tree" << std::endl;
	tree->print_Instrument();
	std::cout << "Print Instruments Limit_min > 4" << std::endl;
	tree->print_Instrument(4);
	std::cout << "Delete Instruments 1990 Year" << std::endl;
	tree->del_Instrument(1990);
	std::cout << "Print binary tree" << std::endl;
	tree->print_Instrument();

	return 0;
}
