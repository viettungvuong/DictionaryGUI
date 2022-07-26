#include "history.h"
#include "functions.h"
#include <fstream>
void History::initDefinition(WordAndDef wad) {
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
	int i = 0;
	while (ifs.is_open()) {
		std::getline(ifs, words[i].word);
		ifs >> dictionaryNo[i++];
	}
	ifs.close();
}