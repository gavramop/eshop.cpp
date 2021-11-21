#pragma once

#include <iostream>
#include <vector>
#include <fstream>



class Paper {
public:

	int papervolume;
	int pages;
	std::string name = "Paper";
	int id = 4;
	int stock = 50;
	int quantity=0;
	std::string description = "Your classic A4 papers ";
	double price = 1.99;

	
	int getDetails();
	void setDetails(int papv);
	void placeOrder();
	void modifyCard();
