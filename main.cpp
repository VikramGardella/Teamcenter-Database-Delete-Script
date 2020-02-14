#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "Item.h"

using namespace std;


vector<Item> mockTCDBData;
vector<string> itemPublications;

//Initializing a mock Teamcenter Database for testing purposes using vectors and the Item class
void initializeMockDB(string fileName){
	string line;
	ifstream inFile (fileName);
	if(inFile.is_open()){
		while(getline(inFile, line)){
			Item tmp = Item(line);
			mockTCDBData.push_back(tmp);
			itemPublications.push_back(line);
		}
		inFile.close();
		cout << "Successfully initialized Item Objects for the mock TC DB." << endl;
	}

	else{
		cout << "Unable to open file with Item names to initialize Items in mock TC DB data." << endl;
	}

	for(int k=0; k<mockTCDBData.size(); k++){
		cout << endl << "ID: " << mockTCDBData[k].getID() << endl;
		cout << "POM References:" << endl;

		for(int h=0; h<mockTCDBData[k].getPOMs().size(); h++){
			cout << "\t" << mockTCDBData[k].getPOMs()[h] << endl;
		}

		cout << endl;
	}
}


Item& findItemByPubRec(string itemPubID){//returning a reference so actual Item will be altered rather than a copy
	for(int i=0; i<mockTCDBData.size(); i++){
		if(mockTCDBData[i].getID()==itemPubID){
			return mockTCDBData[i];
		}
	}
}


int main(int argc, char* argv[]){
	if(argc==2){
		initializeMockDB(argv[1]);
		//should establish connection to the Teamcenter servers here and verify credentials,
		//this part would need to be added by L3

		string line;
		vector<string> itemNames;
		ifstream inFile (argv[1]);
		
		if(inFile.is_open()){
			while(getline(inFile, line)){
				itemNames.push_back(line);
			}
			inFile.close();
			cout << "IDs of Items to be deleted successfully read from file." << endl << endl;
		}
		
		else{
			cout << "Unable to open the file with IDs of Items to be deleted." << endl << endl;
		}

		cout << "These are the Items to be deleted:" << endl;

		for(int i=0; i<itemNames.size(); i++){
			cout << itemNames[i] << endl;
			vector<string> POMReferences;
		}

		cout << endl;

		for(int i=0; i<itemNames.size(); i++){
			vector<int> ind;
			auto found = find(itemPublications.begin(), itemPublications.end(), itemNames[i]);

			if(found != itemPublications.end()){
				cout << itemNames[i] << " was found in the mock TC database." << endl;
				auto index = distance(itemPublications.begin(), found);
				//will continue the delete below
				cout << "Deleting the POM References..." << endl;
				/*getting reference to memory location where the appropriate Item is stored on TC Database
				by searching by ID in the publication records via the 'findItemByPubRec' function*/
				Item *itemRef = &findItemByPubRec(itemPublications[index]);
				
				//deleting POM References for each item
				while(itemRef->getPOMs().size()!=0){
					string POMRefID = itemRef->getPOMs()[0];
					itemRef->deletePOMRef(POMRefID);
					//replace with deletePOMRef with correct command
				}

				//deleting publication records for each Item as well
				itemPublications.erase(remove(itemPublications.begin(), itemPublications.end(), itemNames[i]));
				//replace itemPublications.erase(...) with correct command ^
				cout << "Publication Record for " << itemNames[i] << " deleted." << endl << endl << endl;

				//deleting the item itself
				//(will need to be changed to the real TC shell command)

			//	itemRef->~Item();

			}

			else{
				cout << itemNames[i] << " was not found in the mock TC database; skipping this Item." << endl;
			}
		}
	}

	else{
		cout << "No command line argument for the input text file was found or too many arguments exist." << endl;
	}

	//close connection to the Teamcenter servers here and exit the script

	return 0;
}
