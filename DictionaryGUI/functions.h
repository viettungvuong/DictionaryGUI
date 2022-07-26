#pragma once

#include "ternary.h"
#include <string.h>


class ProgramData {
public :static TernarySearchTree currentTree;

	   static TernarySearchTree listOfTree[3];
};

void deletetree(TernaryTreeNode* root);

void createSet(TernarySearchTree* istOfTree);
int childOfNode(TernaryTreeNode* node);
void saveTree(TernaryTreeNode* root, int index);
void saveAllTree(TernarySearchTree* listOfTree);
void resetAllDictionary(TernarySearchTree* listOfTree);
void changeSet(int& currentSet);
std::string convertTo(System::String^ input);
System::String^ convertFrom(std::string input);
void v2ListView(std::vector<WordAndDef> v, System::Windows::Forms::ListBox^ lb);
std::vector<WordAndDef> suggestWords(std::string soFar);

bool fileExists(const std::string& name);