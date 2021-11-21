#pragma once


#include <vector>
#include <fstream>

#include "User.h"

class Owner {
private:
	std::string oname;
	std::string oemail;
	
	std::vector<std::string> ownernameData;
public:
	
	

	bool isOwner;

	std::vector<std::string> getOwnerData();

	void LoadOwnernameData(std::vector<std::string> _ownernameData);

	void SetOwnername(std::string n);

	std::string getOwnername();

	void SetoEmail(std::string o);

	std::string GetoEmail();
