#pragma once
#include <vector>
#include "ternary.h"

class History {
public:
	std::vector<WordAndDef> words;
	void initDefinition(WordAndDef wad); //ham de them def khi load
	void saveToFile();
	void loadFromFile();
};


