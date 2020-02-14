#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Item.h"

Item::Item(std::string i, std::vector<std::string> poms){
	     ID = i;

	     for(int j=0; j<poms.size(); j++){
		     POMRefs.push_back(poms[j]);
	     }
     }

Item::Item(std::string i){
	     ID = i;
	     POMRefs.push_back("Audit");
	     POMRefs.push_back("Targets1");
	     POMRefs.push_back("Targets2");
	     POMRefs.push_back("GE_ECT_license_cache");
	     POMRefs.push_back("Project Object Relation");
	     POMRefs.push_back("Reference Documents");
	     POMRefs.push_back("Drawing");
	     POMRefs.push_back("Specifications");
	     POMRefs.push_back("Change Report");
	     POMRefs.push_back("Item Masters");
     }

std::string Item::getID(){return ID;}
std::vector<std::string> Item::getPOMs(){return POMRefs;}

void Item::deletePOMRef(std::string POMID){
	POMRefs.erase(std::remove(POMRefs.begin(), POMRefs.end(), POMID));
	std::cout << "\t'" << POMID << "' deleted." << std::endl;
}

/* something's not right here
Item::~Item(){
	delete[] &POMRefs;
	delete &ID;
}*/
