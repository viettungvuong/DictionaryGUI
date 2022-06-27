#pragma once

#include "main.h"
#include "ternary.h"


void deletetree(TernaryTreeNode* root);

void createSet(TernarySearchTree* listOfTree);
int childOfNode(TernaryTreeNode* node);
void saveTree(TernaryTreeNode* root, int index);
void saveAllTree(TernarySearchTree* listOfTree);
void resetAllDictionary(TernarySearchTree* listOfTree);
void changeSet(int& currentSet);