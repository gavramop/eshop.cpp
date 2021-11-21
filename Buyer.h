#pragma once


#include <vector>
#include <fstream>

#include "User.h"

class Buyer {
private:
	std::string username;
	std::string email;
	std::vector<std::string> usernameData;
	std::string category;
	
public:
	int points;
	int bonus = 0;
	std::vector<std::string> getUsernameData();
	void LoadUsernameData(std::vector<std::string> _usernameData);
	void SetUsername(std::string u);
	std::string getUsername();
	void SetEmail(std::string e);
	std::string GetEmail();
	void SetCategory(std::string c);
     std::string getCategory();
    void SetPoints(int p);
    int getPoints();
};
