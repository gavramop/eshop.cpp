#pragma once
#include <iostream>
#include <vector>
#include <fstream>



class Notebook {
public:

	int notevolume;
	
	std::string name = "Notebook";
	int id = 3;
	int stock = 15;
	int quantity=0;
	std::string description = "If you want to keep notes ";
	double price = 4.99;

	
	int getDetails();
	void setDetails(int notev);
	void placeOrder();
	void modifyCard();
