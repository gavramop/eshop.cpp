#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>




class ShoppingCard {
public:
	std::string item;
	int cards;
	std::vector <std::string> items;
	void SetItem(std::string i);
	std::string getItem();
	
};
