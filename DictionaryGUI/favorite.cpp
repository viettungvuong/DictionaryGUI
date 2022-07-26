#include "favorite.h"
#include "functions.h"
#include <fstream>
void Favorite::initDefinition(WordAndDef wad) {
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
	while (ifs.is_open()) {
		std::getline(ifs, words[i].word);
		ifs >> dictionaryNo[i++];
	}
	ifs.close();
}