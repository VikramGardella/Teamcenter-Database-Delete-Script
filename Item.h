#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <cstdlib>

class Item
{

	private:
		std::string ID;
		std::vector<std::string> POMRefs;

	public:
		Item(std::string i, std::vector<std::string> poms);
		Item(std::string i);
		std::string getID();
		std::vector<std::string> getPOMs();
		void deletePOMRef(std::string POMID);
	//	~Item();
};

#endif
