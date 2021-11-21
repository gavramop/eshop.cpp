#include "Menu.h"




	std::vector<std::string> Menu::getUsernames()
	{
		return usernames;
	}
	void Menu::StandarBuyers() {
		usernames.push_back("peter");
		usernames.push_back("makis");
		emails.push_back("gede");
		emails.push_back("kles");
	}
	void Menu::StandarOwners() {
		ousernames.push_back("1");
		ousernames.push_back("2");
		oemails.push_back("3");
		oemails.push_back("4");
     }
	void Menu::StandarItems() {
		penvec.push_back(10);
		pencilvec.push_back(25);
		notebookvec.push_back(40);
		papervec.push_back(420);
		penvec.push_back(18);
		pencilvec.push_back(35);
		notebookvec.push_back(5);
		papervec.push_back(80);
	}
	void Menu::Standarcategory() {
		category.push_back("Gold");
		category.push_back("Silver");
		points.push_back(350);
		points.push_back(160);
		
	}
	void Menu::MainMenu()
	{
		PrintLogin();
		
	}
	void Menu::PrintLogin()
	{
		std::cout << "Email:" << std::endl;
		std::string email = "";
		std::cin >> email;
		buyer.SetEmail(email);
		owner.SetoEmail(email);

		int a = 0;
		while (a == 0)
		{
			for (int k = 0; k < oemails.size(); k++)
			{
				if (owner.GetoEmail() == oemails[k])
				{
					std::cout << "---------------------------------" << std::endl;
					std::cout << "-----Owner of Makis's Shop-------" << std::endl;
					std::cout << "Welcome " << owner.GetoEmail() << std::endl;
					owner.SetOwnername(ousernames[k]);
					std::cout << "Username: " << owner.getOwnername() << std::endl;
					std::cout << "-------------------------" << std::endl; 
					num = k;
					a = 1;
					owner.isOwner = true;

					OwnerMenu();
					break;
				}
			}
			
			
			for (int i = 0; i<emails.size(); i++)
			{
				if (buyer.GetEmail() == emails[i])
				{
					std::cout << "-------------------------"<<std::endl;
					std::cout << "Welcome " << buyer.GetEmail() << std::endl;
					buyer.SetUsername(usernames[i]);
					std::cout << "Username: " << buyer.getUsername() << std::endl;
					buyer.SetCategory(category[i]);
					std::cout << "Category: " << buyer.getCategory() << std::endl;
					buyer.SetPoints(points[i]);
					std::cout << "Points: " << buyer.getPoints() << std::endl;
					std::cout << "-------------------------" << std::endl;
					pen.setDetails(penvec[i]);
					pencil.setDetails(pencilvec[i]);
					notebook.setDetails(notebookvec[i]);
					paper.setDetails(papervec[i]);


					std::cout << "You have items in your card " <<"Pen "<<pen.getDetails() << " Pencil " <<pencil.getDetails()<<" Notebook "<< notebook.getDetails()<<" Paper "<<paper.getDetails()<< std::endl;
					a = 1;
					num = i;
					owner.isOwner = false;
					BuyerMenu();
					break;
				}
			}
			if (a == 0)
			{
				std::cout << "This user is not registered" << std::endl;
				std::cout << "Would you like to register?y/n " << std::endl;
				char c;
				std::cin >> c;
				if (c == 'y')
				{
					CreateUser();
				}
				if (c == 'n')
				{
					std::cout << "Let's head back to Login page: " << std::endl;
					MainMenu();
				}
				if (c != 'y' && c != 'n')
				{
					std::cout << "Wrong input let's head back to Login page: "<<std::endl;
						MainMenu();
				}
			}
		}
		std::cout << "Your email address: " << buyer.GetEmail() << std::endl;
		buyer.LoadUsernameData(usernames);
	}
	void Menu::CreateUser() {
		bool alreadytaken = false;

		


		std::string newUser = "";
		std::cout << "Welcome!Please type your desired username: " << std::endl;


		while (true)
		{
			std::cin >> newUser;
				alreadytaken = false;
			for (int i = 0; i < usernames.size(); i++)
			{
				if (usernames[i].compare(newUser) == 0 )
				{
					std::cout << "This username is already take please choose another one: "<<std::endl;
					alreadytaken = true;
				}
			}
			for (int k = 0; k < ousernames.size(); k++)
			{
				if (ousernames[k].compare(newUser) == 0)
				{
					std::cout << "This username is already take please choose another one: " << std::endl;
					alreadytaken = true;
				}
			}
			if (!alreadytaken)
			{
				std::cout << "This username is available!" << std::endl;
				break;
			}
		}
		alreadytaken = false;
		std::string newEmail = "";
		std::cout << "Type the email you would like to use: " << std::endl;
		while (true)
		{
			std::cin >> newEmail;
			alreadytaken = false;
			for (int i = 0; i < emails.size(); i++)
			{
				if (emails[i].compare(newEmail) == 0)
				{
					std::cout << "This email is already taken please choose another one: " << std::endl;
					alreadytaken = true;
				}
			}
				for (int k = 0; k < oemails.size(); k++)
				{
					if (oemails[k].compare(newEmail) == 0)
					{
						std::cout << "This email is already take please choose another one: " << std::endl;
						alreadytaken = true;
					}
				}
			
			if (!alreadytaken)
			{
				std::cout << "Your email has been registered: "<<std::endl;
				emails.push_back(newEmail);
				break;
			}
		}
		std::cout << "You are now a member" << std::endl;
		Buyer newUserInstance;
		newUserInstance.SetUsername(newUser);
		newUserInstance.SetEmail(newEmail);
		newUserInstance.LoadUsernameData(usernames);
		category.push_back("Bronze");
		points.push_back(0);
		penvec.push_back(0);
		pencilvec.push_back(0);
		notebookvec.push_back(0);
		papervec.push_back(0);
        usernames.push_back(newUser);
		if (owner.isOwner == true)
		{
			OwnerMenu();
		}
		MainMenu();



	}
	void Menu::BuyerMenu() {
		char i;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "Welcome to Makis's Shop " << std::endl;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "1.Browse Store " << std::endl;
		std::cout << "2.View Card " << std::endl;
		std::cout << "3.Checkout " << std::endl;
		std::cout << "4.Back " << std::endl;
		std::cout << "5.Logout" << std::endl;
		std::cout << "6.Exit" << std::endl;
		std::cin >> i;
		while (true)
		{
			
			if (i == '6')
			{
				exit(0);
			}
			if (i == '4')
			{
				std::cout << "You are at the home page if you want to logout please type 5 " << std::endl;
				BuyerMenu();
			}
			if (i == '5')
			{
				saveitems();
				pen.quantity = 0;
				pencil.quantity = 0;
				notebook.quantity = 0;
				paper.quantity = 0;
				MainMenu();
				break;
			}
			if (i == '3')
			{
				checkout();
				break;
			}
			if (i == '1')
			{
				ItemMenu();
				break;
			}
			if (i == '2')
			{
				char k;
				viewCard();
				std::cout << "Do you want to modify an item?y/n" << std::endl;
				std::cout << "3.Checkout " << std::endl;
					std::cin >> k;
					if (k == 'y')
					{
						std::string t;
						std::cout << "Which item would you like to modify?" << std::endl;
						std::cin >> t;
						while (true)
						{
							if (t == "Pen")
							{
								pen.quantity = penvec[num];
								pen.modifyCard();
								penvec[num] = pen.quantity;
								pen.quantity = 0;
								BuyerMenu();
								break;
							}
							if (t == "Pencil")
							{
								pencil.quantity = pencilvec[num];
								pencil.modifyCard();
								pencilvec[num] = pencil.quantity;
								pencil.quantity = 0;
								BuyerMenu();
								break;
							}
							if (t == "Notebook")
							{
								notebook.quantity = notebookvec[num];
								notebook.modifyCard();
								notebookvec[num] = notebook.quantity;
								notebook.quantity = 0;
								BuyerMenu();
								break;
                             }
							if (t == "Paper")
							{
								paper.quantity = papervec[num];
								paper.modifyCard();
								papervec[num] = paper.quantity;
								paper.quantity = 0;
								BuyerMenu();
								break;
							}
							else
							{
								std::cout << "Type the first letter in caps or there is not such item " << std::endl;
								BuyerMenu();
								break;
							}
						}
						break;
				    }


					if (k == 'n')
					{
						BuyerMenu();
						break;
					}
					if (k == '3')
					{
						checkout();
					}
				}
			if (i != '6' && i != '5' && i!='1' && i!='2' && i!='3' && i!='4')
			{
				std::cout << "Wrong input" << std::endl;
				BuyerMenu();
			}
		}
	}
	
	void Menu::print() {
		char o;
		std::cout << "The users are : " << std::endl;;

		for (int i = 0; i < usernames.size(); i++)
		{
			std::cout << usernames[i] << " " << category[i] << " " << points[i] << std::endl;
			std::cout << "Items:  Pen " << penvec[i] << " Pencil " << pencilvec[i] << " Notebook " << notebookvec[i] << " Paper " << papervec[i] << std::endl;
		}
		std::cout << "1.Add user "<<std::endl;
		std::cout << "2.Remove user " << std::endl;
		std::cout << "3.Back " << std::endl;
		std::cin >> o;
		if (o == '1')
		{
			CreateUser();
		}
		if (o == '2')
		{
			removeUser();
		}
		if (o == '3')
		{
			OwnerMenu();
		}
		if (o != '1' && o != '2' && o != '3')
		{
			std::cout << "Wrong input " << std::endl;
			print();
		}
	}
	void Menu::OwnerMenu() {
		char o;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "Welcome to Makis's Shop " << std::endl;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "1.Browse Store " << std::endl;
		std::cout << "2.Check status " << std::endl;
		std::cout << "3.Back " << std::endl;
		std::cout << "4.Logout" << std::endl;
		std::cout << "5.Exit" << std::endl;
		std::cin >> o;
		while (true)
		{
			if (o == '5')
			{
				exit(0);
			}
			if (o == '4')
			{
				MainMenu();
			}
			if (o == '3')
			{
				MainMenu();
			}
			if (o == '2')
			{
				print();
				
				OwnerMenu();
			}
			if (o == '1')
			{
				ItemMenu();
			}
			if (o != '5' && o != '4' && o!='3' && o!='2' && o!='1')
			{
				std::cout << "Wrong input" << std::endl;
				OwnerMenu();
			}
		}
	}
	void Menu::ItemMenu() {
		char i;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "Product List List " << std::endl;
		std::cout << "------------------------------- " << std::endl;
		std::cout << "1.Pen " << std::endl;
		std::cout << "2.Pencil " << std::endl;
		std::cout << "3.Notebook " << std::endl;
		std::cout << "4.Paper" << std::endl;
		std::cout << "5.Back" << std::endl;
		std::cout << "6.Search by id" << std::endl;
		std::cin >> i;
		while (true)
		{

			if (i == '1')
			{
				if (owner.isOwner == true)
				{
					
					editItem();
					OwnerMenu();
					break;
				}
				else {
					PenMenu();
					break;
				     }
				}
			if (i == '2')
			{
				if (owner.isOwner == true)
				{
					editItem();
					OwnerMenu();
					break;
				}
				else {
					PencilMenu();
					break;
				}
			}
			if (i == '3')
			{
				if (owner.isOwner == true)
				{
					editItem();
					OwnerMenu();
					break;
				}
				else {
					NotebookMenu();
					break;
				}
			}
			if (i == '4')
			{
				if (owner.isOwner == true)
				{
					editItem();
					OwnerMenu();
					break;
				}
				else {
					PaperMenu();
					break;
				}
			}
			if (i == '5')
			{
				BuyerMenu();
			}
			if (i == '6')
			{
				getCode();
			}
			if (i != '5' && i!='2' && i !='1'  )
			{
				std::cout << "Wrong input" << std::endl;
				BuyerMenu();
			}
		}
	}
	void Menu::PenMenu() {
		char i;
		std::cout << "Product: " << pen.name<< std::endl;
		std::cout << "ID: " <<pen.id<< std::endl;
		std::cout << "Stock: " <<pen.stock<< std::endl;
		std::cout << "Description: " <<pen.description<< std::endl;
		std::cout << "Price: : " <<pen.price<< std::endl;
		std::cout << "1.Buy " << std::endl;
		std::cout << "0.Back " << std::endl;
		std::cin >> i;
		while (true)
		{
			if (i != '0'&& i !='1')
			{
				std::cout << "This is under work or you pressed wrong button" << std::endl;
				PenMenu();
			}
			if (i == '0')
			{
				ItemMenu();
			}
			if (i == '1')
			{
				if (owner.isOwner == true)
				{
					std::cout << "Owner can't buy from his own shop" << std::endl;
					OwnerMenu();
				}
				else
				{
					pen.placeOrder();
					penvec[num] = penvec[num] + pen.quantity;
					pen.quantity=0;
                    BuyerMenu();
				}
				
            }
		}
		
		
	}
	void Menu::PencilMenu() {
		char i;
		std::cout << "Product: " << pencil.name << std::endl;
		std::cout << "ID: " << pencil.id << std::endl;
		std::cout << "Stock: " << pencil.stock << std::endl;
		std::cout << "Description: " << pencil.description << std::endl;
		std::cout << "Price: : " << pencil.price << std::endl;
		std::cout << "1.Buy " << std::endl;
		std::cout << "0.Back " << std::endl;
		std::cin >> i;
		while (true)
		{
			if (i != '0' && i != '1')
			{
				std::cout << "This is under work or you pressed wrong button" << std::endl;
				PencilMenu();
			}
			if (i == '0')
			{
				ItemMenu();
			}
			if (i == '1')
			{
				if (owner.isOwner == true)
				{
					std::cout << "Owner can't buy from his own shop" << std::endl;
					OwnerMenu();
				}
				else
				{
					pencil.placeOrder();
					pencilvec[num] = pencilvec[num] + pencil.quantity;
					pencil.quantity = 0;
					BuyerMenu();
				}
			}
		}


	}
	void Menu::NotebookMenu() {
		char i;
		std::cout << "Product: " << notebook.name << std::endl;
		std::cout << "ID: " << notebook.id << std::endl;
		std::cout << "Stock: " << notebook.stock << std::endl;
		std::cout << "Description: " << notebook.description << std::endl;
		std::cout << "Price: : " << notebook.price << std::endl;
		std::cout << "1.Buy " << std::endl;
		std::cout << "0.Back " << std::endl;
		std::cin >> i;
		while (true)
		{
			if (i != '0' && i != '1')
			{
				std::cout << "This is under work or you pressed wrong button" << std::endl;
				NotebookMenu();
			}
			if (i == '0')
			{
				ItemMenu();
			}
			if (i == '1')
			{
				if (owner.isOwner == true)
				{
					std::cout<< "Owner can't buy from his own shop" << std::endl;
					OwnerMenu();
				}
				else
				{
					notebook.placeOrder();
					notebookvec[num] = notebookvec[num] + notebook.quantity;
					notebook.quantity = 0;
					BuyerMenu();
				}
			}
		}


	}
	void Menu::PaperMenu() {
		char i;
		std::cout << "Product: " << paper.name << std::endl;
		std::cout << "ID: " << paper.id << std::endl;
		std::cout << "Stock: " << paper.stock << std::endl;
		std::cout << "Description: " << paper.description << std::endl;
		std::cout << "Price: : " << paper.price << std::endl;
		std::cout << "1.Buy " << std::endl;
		std::cout << "0.Back " << std::endl;
		std::cin >> i;
		while (true)
		{
			if (i != '0' && i != '1')
			{
				std::cout << "This is under work or you pressed wrong button" << std::endl;
				PaperMenu();
			}
			if (i == '0')
			{
				ItemMenu();
			}
			if (i == '1')
			{
				if (owner.isOwner == true)
				{
					std::cout << "Owner can't buy from his own shop" << std::endl;
					OwnerMenu();
				}
				else
				{
					paper.placeOrder();
					papervec[num] = papervec[num] + paper.quantity;
					paper.quantity = 0;
					BuyerMenu();
				}

			}
		}


	}
	
	
	void Menu::getCode() {
		char a;
		std::cout << "Type the id of the product: ";
		std::cin >> a;
		std::cout << "\n";
		while (true)
		{
			if (a == '1')
			{
				PenMenu();
			}
			if (a == '2')
			{
				PencilMenu();
			}
			if (a == '3')
			{
				NotebookMenu();
			}
			if (a == '4')
			{
				PaperMenu();
			}
			if (a != '1' && a!='2' && a!='3' && a!='4')
			{
				std::cout << "This id doesn't exist.Go to Browse Store and pick an item to see their id. " << std::endl;
				BuyerMenu();
			}
		}
	}
	void Menu::viewCard() {

		std::cout << "You card items are : " << std::endl;
		std::cout << "You have " << penvec[num] << " pen in your card" << std::endl;
		std::cout << "You have " << pencilvec[num] << " pencil in your card" << std::endl;
		std::cout << "You have " << notebookvec[num] << " notebook in your card" << std::endl;
		std::cout << "You have " << papervec[num]<< " paper in your card" << std::endl;
	}
	void Menu::checkout() {
		calculate();
		calculatecourier();
		calculateBonus();
        viewCard();
       char k; 
	   std::cout << "Price: " << sum << std::endl;
	   std::cout << "Courier Cost: " << coucost << std::endl;
	   std::cout << "Total: " <<total<< std::endl;
	   std::cout << "Complete checkout?y/n"<<std::endl;
	   std::cin >> k;
		if (k == 'y')
		{
			std::cout << "Order succesful " << std::endl;
			addBonus();
			clearCard();
			BuyerMenu();
		}
		if (k == 'n')
		{
			std::cout << "Ok then,let's head back to main menu" << std::endl;
			BuyerMenu();
		}
		if (k != 'y' && k != 'n')
		{
			std::cout << "Not valid answer please type y or n " << std::endl;
			checkout();
		}
	
	}
	void Menu::calculate() {
		sum = (penvec[num] * pen.price) + (pencilvec[num]* pencil.price) + (notebookvec[num] * notebook.price) + (papervec[num] * paper.price);

		
	}
	void Menu::calculatecourier() {
		coucost = sum * 0.02;
		if (coucost < 3) {
			coucost = 3;
		}
		if (buyer.points >= 100 && buyer.points < 200)
		{
			coucost = coucost * 0.5;
		}
		if (buyer.points >= 200)
		{
			coucost = 0;
		}
		total = sum + coucost;
	}
	void Menu::calculateBonus() {
		buyer.bonus = (sum * 0.1);
		std::cout << "The points you will get after the checkout are " << buyer.bonus << std::endl;


	}
	void Menu::addBonus() {
		
		points[num] = points[num] + buyer.bonus;
		std::cout << "Your points went to " << points[num] << std::endl;
		if (points[num] < 100)
		{
			category[num] = "Bronze";
		}
		if (points[num] >= 100 && points[num] < 200)
		{
			std::cout << "You are Silver Category.You get now 50% shipping " << std::endl;
			category[num] = "Silver";
		}
		else
		{
			std::cout << "You are Gold Category.You now get free shipping" << std::endl;
			category[num] = "Gold";
		}
	}
	void Menu::removeUser() {
		std::string k;
		std::cout << "Which user would you like to remove?" << std::endl;
		while (true)
		{
			std::cin >>k;
			for (int i = 0; i < usernames.size(); i++)
			{
				if (usernames[i].compare(k) == 0 )
				{
					std::cout << "User " << usernames[i]<<" deleted"<< std::endl;
					pen.stock = pen.stock + penvec[num];
					pencil.stock = pencil.stock + pencilvec[num];
					notebook.stock = notebook.stock + notebookvec[num];
					paper.stock = paper.stock + papervec[num];
					usernames.erase(usernames.begin() + i);
					emails.erase(emails.begin() + i);
					category.erase(category.begin() + i);
					points.erase(points.begin() + i);
					penvec.erase(penvec.begin() + i);
					pencilvec.erase(pencilvec.begin() + i);
					notebookvec.erase(notebookvec.begin() + i);
					papervec.erase(papervec.begin() + i);
					
					OwnerMenu();

				}
			}

			
		}
		
		}
	void Menu::saveitems() {
		std::cout << "Items saved " <<" Pen: " <<penvec[num] <<" Pencil: "<< pencilvec[num] <<" Notebook: "<< notebookvec[num] <<" Paper: "<< papervec[num] << std::endl;
	}
	void Menu::clearCard() {
		pen.quantity = 0;
		pencil.quantity = 0;
		notebook.quantity = 0;
		paper.quantity = 0;
		penvec[num] = 0;
		pencilvec[num] = 0;
		notebookvec[num] = 0;
		papervec[num] = 0;

	}
	
	void Menu::editItem() {
		std::string p;
		std::cout << "Which item would you like to change?" << std::endl;
	    std::cin >> p;
		
		
		int k;
		std::cout << "Type the new quantity of the item: " << std::endl;
		std::cin >> k;
		if (p == "Pen")
		{
			pen.stock = k;
		}
		if (p == "Pencil")
		{
			pencil.stock = k;
		}
		if (p == "Notebook")
		{
			notebook.stock = k;
		}
		if (p == "Paper")
		{
			paper.stock = k;
		}
		else
		{
			std::cout << "The first letter should be in caps or non existing item " << std::endl;
		}
	}
