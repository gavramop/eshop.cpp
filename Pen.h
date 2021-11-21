#pragma once

#include <iostream>
#include <vector>
#include <fstream>



class Pen {
public:
	
	int penvolume;
	double tipSize;
	std::string name = "Pen";
	int id = 1;
	int stock = 20000;
	int quantity=0;
	std::string description = "Just a pen to be honest...";
	double price = 0.99;
    
	
	int getDetails();
	void setDetails(int penv);
	void placeOrder();
	void modifyCard();
};
