#include "history.h"
#include "functions.h"
#include <fstream>
void History::initDefinition() {
	for (int i = 0; i < words.size(); i++) {
		words[i].definition = *ProgramData::listOfTree[dictionaryNo[i]].search4keyword(words[i].word)->definition;
	}
} //ham de them def khi load
void History::saveToFile() {
	std::ofstream ofs;
	ofs.open("history.txt");
	for (int i = 0; i < words.size(); i++) {
		ofs << words[i].word << "\n" << dictionaryNo[i] << "\n";
	}
	ofs.close();
}
void History::loadFromFile() {
	if (!fileExists("history.txt"))
		return;
	std::ifstream ifs;
	ifs.open("history.txt");
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
	ifs.close();
	initDefinition();
}
void History::addToHistory(WordAndDef wad, int dictionaryNo) {
	words.push_back(wad);
	this->dictionaryNo.push_back(dictionaryNo); //luu la thuoc tu dien nao
	saveToFile();


}