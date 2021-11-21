#pragma once
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

#include "Buyer.h"
#include "Owner.h"
#include "Pen.h"
#include "ShoppingCart.h"
#include "Paper.h"
#include "Pencil.h"
#include "Notebook.h"
class Menu
{
private:
	
	double sum;
	double coucost;
	double total;
	Pen pen;
	Buyer buyer;
	Owner owner;
	Paper paper = Paper();
	Pencil pencil = Pencil();
	Notebook notebook = Notebook();
	ShoppingCard shoppingcard;
	std::vector <std::string> usernames;
	std::vector <std::string> emails;
	std::vector <std::string> ousernames;
	std::vector <std::string> oemails;
	std::vector <std::string> category;
	std::vector <int> penvec;
	std::vector <int> pencilvec;
	std::vector <int> notebookvec;
	std::vector <int> papervec;

	std::vector <int> points;


public:
	int num;
	std::vector<std::string> getUsernames();
	
	void PrintLogin();
	void CreateUser();
	void MainMenu();
	void BuyerMenu();
	void StandarOwners();
	void StandarBuyers();
	void Standarcategory();
	void StandarItems();
	void OwnerMenu();
	void print();
	void ItemMenu();
	void PenMenu();
	void PencilMenu();
	void NotebookMenu();
	void PaperMenu();
	void getCode();
	void checkout();
	void viewCard();
	void calculate();
	void calculatecourier();
	void calculateBonus();
	void addBonus();
	void removeUser();
	void saveitems(); 
	void clearCard();
	void editItem();

};
