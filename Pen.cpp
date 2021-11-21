#include "Pen.h"




void Pen::setDetails(int penv) {
	penvolume=penv;
	
}
int Pen::getDetails() {
	return penvolume;
}

void Pen::placeOrder() {
	int q;
	std::cout << "0.Back " << std::endl;
	std::cout << "Type how many times you would like to buy the product: " << std::endl;
	std::cin >> q;
	while (true)
	{
		if (q == 0)
		{
			break;
		}
		if (q > stock)
		{
			std::cout << ("We don't have that ammount. ") << name << " stock: " << stock << std::endl;
			break;
		}
		if (q <= stock)
		{
			for (int i = 1; i <= q; i++)
			{
				stock--;
				quantity++;
			}
			break;
		}
		
		else
		{
			std::cout << "Wrong input" << std::endl;
			
		}
	}
}

void Pen::modifyCard() {
	int c;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Type any letter to go back " << std::endl;
	std::cout << "Type the new quantity of the item: " << std::endl;
	std::cin >> c;
	while (true)
	{
		try
		{
			if (c <= quantity && c >= 0)
			{
				int g = (quantity - c);
				for (int i = 0; i < g; i++)
				{
					stock++;
					quantity--;
				}
				break;
			}
			if (c > quantity)
			{
				std::cout << "Go to browse store to buy an item " << std::endl;
				break;
			}
		}
			catch (int c) {
				std::cout << "Exception Caught!" << std::endl;
				c = 0;
				break;

			}
	}
