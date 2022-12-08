#include "lab-cpp_8-10_class.h"
#include <iostream>
#include <string>
#include <vector>

Instrument_Node::Instrument_Node() {
	this->Brand = "NoN";
	this->Type = "NoN";
	this->Limit[0] = 0;
	this->Limit[1] = 0;
	this->Year = 1990;

	this->Right = 0;
	this->Left = 0;
}

Instrument_Node::Instrument_Node(std::string Brand, std::string Type, float Limit_min, float Limit_max, int Year) {
	this->Brand = Brand;
	this->Type = Type;
	this->Limit[0] = Limit_min;
	this->Limit[1] = Limit_max;
	this->Year = Year;

	this->Right = 0;
	this->Left = 0;
}

Instrument_binaryTree::Instrument_binaryTree() {
	this->root = 0;
}

void Instrument_binaryTree::add_Instrument(std::string Brand, std::string Type, float Limit_min, float Limit_max, int Year) {
	if (this->root == 0) {
		this->root = new Instrument_Node(Brand, Type, Limit_min, Limit_max, Year);
		std::cout << "root is defined" << std::endl;
	}
	else {
		Instrument_Node* thisInstrument = this->root;
		while (true) {
			if (thisInstrument->Brand < Brand) {
				if (thisInstrument->Right == 0) {
					thisInstrument->Right = new Instrument_Node(Brand, Type, Limit_min, Limit_max, Year);
					return;
				}
				thisInstrument = thisInstrument->Right;
			}
			else if (thisInstrument->Brand > Brand) {
				if (thisInstrument->Left == 0) {
					thisInstrument->Left = new Instrument_Node(Brand, Type, Limit_min, Limit_max, Year);
					return;
				}
				thisInstrument = thisInstrument->Left;
			}
			else {
				return;
			}
		}
	}
}

void Instrument_binaryTree::del_Instrument(int Year) {
	if (this->root == 0) {
		std::cout << "Tree is empty" << std::endl;
	}
	else {
		del_Instrument(this->root, 0, Year);
	}
}
void Instrument_binaryTree::del_Instrument(Instrument_Node* Node, Instrument_Node* lastNode, int Year) {
	//if (lastNode != 0) std::cout << "last Node: " << lastNode->Brand << "\tNode: " << Node->Brand << std::endl;
	if (Node->Left != 0) del_Instrument(Node->Left, Node, Year);

	if (Node->Year == Year) {
		//std::cout << Node->Brand << " Year_del" << std::endl;
		if (Node->Right != 0) {
			move_Instrument(Node->Right, Node, lastNode);
		}
		else {
			move_Instrument(Node, Node, lastNode);
		}
	}

	if (Node->Right != 0) del_Instrument(Node->Right, Node, Year);
}
void Instrument_binaryTree::move_Instrument(Instrument_Node* Node, Instrument_Node* saveNode, Instrument_Node* lastNode) {
	//if (lastNode != 0) std::cout << "Node: " << Node->Brand << "\tsaveNode: " << saveNode->Brand << "\tlastNode: " << lastNode->Brand << std::endl;
	if (Node->Left !=0) {
		move_Instrument(Node->Left, saveNode, Node);
	}
	else if (Node->Right != 0) {
		saveNode->Brand = Node->Brand;
		saveNode->Type = Node->Type;
		saveNode->Limit[0] = Node->Limit[0];
		saveNode->Limit[1] = Node->Limit[1];
		saveNode->Year = Node->Year;

		if (Node->Right->Right != 0) {
			move_Instrument(Node->Right->Right, Node->Right, Node->Right);
		}
		else {
			Node->Brand = Node->Right->Brand;
			Node->Type = Node->Right->Type;
			Node->Limit[0] = Node->Right->Limit[0];
			Node->Limit[1] = Node->Right->Limit[1];
			Node->Year = Node->Right->Year;

			delete Node->Right;
			Node->Right = 0;
		}
	}
	else {
		if (saveNode != Node) {
			saveNode->Brand = Node->Brand;
			saveNode->Type = Node->Type;
			saveNode->Limit[0] = Node->Limit[0];
			saveNode->Limit[1] = Node->Limit[1];
			saveNode->Year = Node->Year;
		}

		if (lastNode != 0) {
			delete lastNode->Left;
			lastNode->Left = 0;
		}
		else {
			delete this->root;
			this->root = 0;
		}
	}
}

void Instrument_binaryTree::print_Instrument() {
	if (this->root == 0) {
		std::cout << "Tree is empty" << std::endl;
	}
	else {
		print_Instrument(this->root);
	}
}
void Instrument_binaryTree::print_Instrument(Instrument_Node* Node) {
	static int tabs = 0;
	tabs++;
	if (Node->Left != 0) print_Instrument(Node->Left);

	for (int i = 1; i < tabs; i++) std::cout << "\t";
	std::cout << "Brand: " << Node->Brand << std::endl;
	for (int i = 1; i < tabs; i++) std::cout << "\t";
	std::cout << "Type: " << Node->Type << std::endl;
	for (int i = 1; i < tabs; i++) std::cout << "\t";
	std::cout << "Limit: " << Node->Limit[0] << "-" << Node->Limit[1] << std::endl;
	for (int i = 1; i < tabs; i++) std::cout << "\t";
	std::cout << "Year: " << Node->Year << std::endl;

	if (Node->Right != 0) print_Instrument(Node->Right);
	tabs--;
}

void Instrument_binaryTree::print_Instrument(float Limit_min) {
	if (this->root == 0) {
		std::cout << "Tree is empty" << std::endl;
	}
	else {
		print_Instrument(this->root, Limit_min);
	}
}
void Instrument_binaryTree::print_Instrument(Instrument_Node* Node, float Limit_min) {
	if (Node->Left != 0) print_Instrument(Node->Left, Limit_min);

	if (Node->Limit[0] >= Limit_min) {
		std::cout << std::endl;
		std::cout << "Brand: " << Node->Brand << std::endl;
		std::cout << "Type: " << Node->Type << std::endl;
		std::cout << "Limit: " << Node->Limit[0] << "-" << Node->Limit[1] << std::endl;
		std::cout << "Year: " << Node->Year << std::endl;
	}

	if (Node->Right != 0) print_Instrument(Node->Right, Limit_min);
}
