#include "functions.h"
#include <msclr\marshal_cppstd.h>
TernarySearchTree ProgramData::listOfTree[3];
TernarySearchTree ProgramData::currentTree = ProgramData::listOfTree[2]; //mac dinh



void deletetree(TernaryTreeNode* root)
{
	if (!root)
		return;
	deletetree(root->left);
	deletetree(root->mid);
	deletetree(root->right);
	delete root->definition;
	delete root;
}

void createSet(TernarySearchTree* listOfTree)
{
	for (int i = 0; i < NUMofSET; ++i)
	{
		ProgramData::listOfTree[i].import_dictionary(i);
	}
}

int childOfNode(TernaryTreeNode* node)//return number of child
{
	int i = 0;
	if (node->left)
		++i;
	if (node->mid)
		++i;
	if (node->right)
		++i;
	return i;
}

void helper_saveTree(TernaryTreeNode* root, std::string str, int index)
{
	if (!root)
		return;
	if (root->definition)
	{
		str.push_back(root->ch);
		std::ofstream fout;
		switch (index)
		{
		case 0://slang
			fout.open("Library\\slang.txt", std::ios::app);
			break;
		case 1://emotion
			fout.open("Library\\emotional.txt", std::ios::app);
			break;
		case 2://dictionary
			fout.open("Library\\dictionary.txt", std::ios::app);
			break;
		default:
			break;
		}
		fout << str << "  " << *root->definition << "\n";
		fout.close();
		str.pop_back();
	}
	helper_saveTree(root->left, str, index);
	str.push_back(root->ch);
	helper_saveTree(root->mid, str, index);
	str.pop_back();
	helper_saveTree(root->right, str, index);
}

void saveTree(TernaryTreeNode* root, int index)
{
	std::string str = "";
	helper_saveTree(root, str, index);
}

void saveAllTree(TernarySearchTree* listOfTree)
{
	std::ofstream fA("Library\\slang.txt");
	fA << "";
	fA.close();
	std::ofstream fB("Library\\emotional.txt");
	fB << "";
	fB.close();
	std::ofstream fC("Library\\dictionary.txt");
	fC << "";
	fC.close();
	for (int i = 0; i < NUMofSET; ++i)
	{
		saveTree(ProgramData::listOfTree[i].getRoot(), i);
	}
}

void resetAllDictionary(TernarySearchTree* listOfTree)
{
	for (int i = 0; i < NUMofSET; ++i)
	{
		ProgramData::listOfTree[i].deleteTree();
		ProgramData::listOfTree[i].import_dictionary(i, 1);
	}
	saveAllTree(ProgramData::listOfTree);
}

void changeSet(int& currentSet)
{
	std::cout << "1.Slang set\n2.Emotion set\n3.Dictionary set\nPls Choose your set:";
	int i;
	std::cin >> i;
	if (1 <= i && i <= 3)
	{
		currentSet = i - 1;
		return;
	}
	else
	{
		currentSet = 2;
	}
}
std::string convertTo(System::String^ input) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(input);
}
System::String^ convertFrom(std::string input) {
	return gcnew System::String(input.c_str());
}

void v2ListView(std::vector<WordAndDef> v, System::Windows::Forms::ListBox^ lb) {
	lb->Items->Clear();
	for (WordAndDef wad : v) {
		lb->Items->Add(convertFrom(wad.word));
	}
}