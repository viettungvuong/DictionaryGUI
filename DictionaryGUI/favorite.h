#pragma once
#include <vector>
#include "ternary.h"

class Favorite {
public:
	std::vector<WordAndDef> words;
	std::vector<int> dictionaryNo;
	void initDefinition(); //ham de them def khi load
	void saveToFile();
	void loadFromFile();
};

