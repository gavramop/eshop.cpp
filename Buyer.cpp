#include "Buyer.h"

	std::vector<std::string> Buyer::getUsernameData()
	{
		return usernameData;
	}
	void Buyer::LoadUsernameData(std::vector<std::string> _usernameData)
	{
		usernameData = _usernameData;
	}
	void Buyer::SetUsername(std::string u)
	{
		username = u;
	}
	std::string Buyer::getUsername()
	{
		return username;
	}
	void Buyer::SetEmail(std::string e)
	{
		email = e;
	}

	std::string Buyer::GetEmail()
	{
		return email;
	}
	
	void Buyer::SetCategory(std::string c)
	{
		category = c;
	}

	std::string Buyer::getCategory()
	{
		return category;
	}
	void Buyer::SetPoints(int p)
	{
		points = p;
	}

	int Buyer::getPoints()
	{
		return points;
	}
