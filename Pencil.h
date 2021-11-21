#pragma once
#include <iostream>
#include <vector>
#include <fstream>



class Pencil {
public:

	int pencvolume;
	double tipSize;
	std::string name = "Pencil";
	int id = 2;
	int stock = 30;
	int quantity=0;
	std::string description = "Like a pen but not that good ";
	double price = 0.50;

	
	int getDetails();
	void setDetails(int pencv);
	void placeOrder();
	void modifyCard();

