#include "history.h"
#include "functions.h"
#include <fstream>
#include <sstream>
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
		std::string temp2;
		std::getline(ifs, temp2);
		int a;
		std::stringstream ss;
		ss << temp2; ss >> a;
		dictionaryNo.push_back(a);
	}
	words.pop_back();
	ifs.close();
	initDefinition();
}
void History::addToHistory(WordAndDef wad, int dictionaryNo) {
	words.push_back(wad);
	this->dictionaryNo.push_back(dictionaryNo); //luu la thuoc tu dien nao
	saveToFile();


}