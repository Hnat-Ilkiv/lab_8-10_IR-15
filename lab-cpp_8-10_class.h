#include <string>

class Instrument_Node {
	public:
		std::string Brand;
		std::string Type;
		float Limit[2];
		int Year;

		Instrument_Node* Right;
		Instrument_Node* Left;

		Instrument_Node();
		Instrument_Node(std::string Brand, std::string Type, float Limit_min, float Limit_max, int Year);
};

class Instrument_binaryTree {
	public:
		Instrument_Node* root;

		Instrument_binaryTree();

		void add_Instrument(std::string Brand, std::string Type, float Limit_min, float Limit_max, int Year);
		void del_Instrument(int Year);
		void del_Instrument(Instrument_Node* Node, Instrument_Node* lastNode, int Year);
		void move_Instrument(Instrument_Node* Node, Instrument_Node* saveNode, Instrument_Node* lastNode);
		void print_Instrument();
		void print_Instrument(Instrument_Node* Node);
		void print_Instrument(float Limit_min);
		void print_Instrument(Instrument_Node* Node, float Limit_min);
};
