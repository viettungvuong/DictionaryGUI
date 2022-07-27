#include "favorite.h"
#include "functions.h"
#include <fstream>
void Favorite::initDefinition() {
	for (int i = 0; i < words.size(); i++) {
		words[i].definition = *ProgramData::listOfTree[dictionaryNo[i]].search4keyword(words[i].word)->definition;
	}
} //ham de them def khi load
void Favorite::saveToFile() {
	std::ofstream ofs;
	ofs.open("favorite.txt");
	for (int i = 0; i < words.size(); i++) {
		ofs << words[i].word << "\n" << dictionaryNo[i] << "\n";
	}
	ofs.close();
}
void Favorite::loadFromFile() {
	if (!fileExists("favorite.txt"))
		return;
	std::ifstream ifs;
	ifs.open("favorite.txt");
	int i = 0;
	while (!ifs.eof()) {
		std::string temp;
		std::getline(ifs, temp);
		WordAndDef wad;
		wad.word = temp;
		words.push_back(wad);
		int temp2;
		ifs >> temp2;
		dictionaryNo.push_back(temp2);
	}
	words.pop_back();
	ifs.close();
	initDefinition();
}