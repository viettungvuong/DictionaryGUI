#pragma once

#include "ternary.h"
#include <string.h>


void deletetree(TernaryTreeNode* root);

void createSet(TernarySearchTree* listOfTree);
int childOfNode(TernaryTreeNode* node);
void saveTree(TernaryTreeNode* root, int index);
void saveAllTree(TernarySearchTree* listOfTree);
void resetAllDictionary(TernarySearchTree* listOfTree);
void changeSet(int& currentSet);
std::string convertTo(System::String^ input);
System::String^ convertFrom(std::string input);