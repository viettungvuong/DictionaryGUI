#pragma once
#include <stdlib.h>
#include "ternary.h"
#include "Screen.h"
#include "functions.h"
#include <string>
#include "edit.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "favorite.h"
#include "history.h"

namespace DictionaryGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	std::vector<WordAndDef> v;
	std::vector<WordAndDef> suggesting;
	int selected1=-1, selected2=-1; //bien de biet radio button nao dang dc chon
	int chooseWord1, chooseWord2;
	int currentSet;
	History history;
	Favorite favorite;
	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		bool fileExists(const std::string& name) {
			struct stat buffer;
			return (stat(name.c_str(), &buffer) == 0);
		}
		void load() {
			//load history va favorite
			
			srand(time(NULL)); //khoi tao random//Tung dang test cai nay
			currentSet = 2;
			if (fileExists("currentSet.txt")) {
				std::ifstream ifs;
				ifs.open("currentSet.txt");
				ifs >> currentSet;
				ifs.close();
			}
			else {
				std::ofstream ofs;
				ofs.open("currentSet.txt");
				ofs << currentSet;
				ofs.close();
			}
			comboBox1->SelectedIndex = currentSet;
			ProgramData::listOfTree[2].import_dictionary(2);
			if (currentSet!=2)
			   ProgramData::listOfTree[currentSet].import_dictionary(currentSet);
			ProgramData::currentTree = ProgramData::listOfTree[currentSet];
			wordOfTheDay();
			history.loadFromFile();
			favorite.loadFromFile();
			if (history.words.size() > 0) {
				v2ListView(history.words, historyList);
			}
			if (favorite.words.size() > 0) {
				v2ListView(favorite.words, favoriteList);
			}

		}
		void wordOfTheDay() {
			TernaryTreeNode* t;
            t = ProgramData::listOfTree[2].getRandomWord();
			word->Text = convertFrom(t->word);
			def->Text = convertFrom(*t->definition);
		}
		main(void)
		{
			InitializeComponent();
			load();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	public: System::Windows::Forms::Label^ def;
	private:
	public: System::Windows::Forms::Label^ word;
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TabPage^ tabPage2;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ guessDef;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ guessWord;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton7;
	private: System::Windows::Forms::RadioButton^ radioButton8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;


	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ defOfWord;
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ switchData;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ result1;
	private: System::Windows::Forms::Label^ result2;
private: System::Windows::Forms::ListBox^ suggestedWords;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::ListBox^ favoriteList;

private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::Button^ button14;
private: System::Windows::Forms::Button^ button13;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::ListBox^ historyList;
private: System::Windows::Forms::Button^ button15;













	protected:







	private:


	private:







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->suggestedWords = (gcnew System::Windows::Forms::ListBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->def = (gcnew System::Windows::Forms::Label());
			this->word = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->defOfWord = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->result2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->guessWord = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->result1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->guessDef = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->favoriteList = (gcnew System::Windows::Forms::ListBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->historyList = (gcnew System::Windows::Forms::ListBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->switchData = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(6, 6);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(738, 494);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button15);
			this->tabPage1->Controls->Add(this->suggestedWords);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->panel2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(730, 468);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Search by word";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(642, 103);
			this->button15->Margin = System::Windows::Forms::Padding(2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(69, 33);
			this->button15->TabIndex = 13;
			this->button15->Text = L"Add to favorite";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &main::button15_Click);
			// 
			// suggestedWords
			// 
			this->suggestedWords->FormattingEnabled = true;
			this->suggestedWords->Location = System::Drawing::Point(4, 135);
			this->suggestedWords->Margin = System::Windows::Forms::Padding(2);
			this->suggestedWords->Name = L"suggestedWords";
			this->suggestedWords->Size = System::Drawing::Size(200, 329);
			this->suggestedWords->TabIndex = 10;
			this->suggestedWords->SelectedIndexChanged += gcnew System::EventHandler(this, &main::suggestedWords_SelectedIndexChanged);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(527, 102);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(111, 33);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Edit current word";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &main::button8_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(468, 102);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 33);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(208, 138);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(503, 328);
			this->panel1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(503, 328);
			this->label1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->def);
			this->panel2->Controls->Add(this->word);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(708, 90);
			this->panel2->TabIndex = 10;
			// 
			// def
			// 
			this->def->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->def->Location = System::Drawing::Point(17, 33);
			this->def->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->def->Name = L"def";
			this->def->Size = System::Drawing::Size(675, 47);
			this->def->TabIndex = 2;
			this->def->Text = L"Definition";
			// 
			// word
			// 
			this->word->AutoSize = true;
			this->word->Font = (gcnew System::Drawing::Font(L"Arial", 10.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->word->Location = System::Drawing::Point(168, 7);
			this->word->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->word->Name = L"word";
			this->word->Size = System::Drawing::Size(50, 17);
			this->word->TabIndex = 1;
			this->word->Text = L" Word";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(17, 7);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 18);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Some random word:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(4, 103);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(450, 28);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &main::textBox1_TextChanged);
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->button7);
			this->tabPage6->Controls->Add(this->panel3);
			this->tabPage6->Controls->Add(this->listBox1);
			this->tabPage6->Controls->Add(this->button6);
			this->tabPage6->Controls->Add(this->textBox2);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Margin = System::Windows::Forms::Padding(2);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(730, 468);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Search by definition";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(587, 23);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(127, 33);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Edit current word";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &main::button7_Click_1);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->defOfWord);
			this->panel3->Location = System::Drawing::Point(226, 67);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(488, 392);
			this->panel3->TabIndex = 10;
			// 
			// defOfWord
			// 
			this->defOfWord->Dock = System::Windows::Forms::DockStyle::Fill;
			this->defOfWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->defOfWord->Location = System::Drawing::Point(0, 0);
			this->defOfWord->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->defOfWord->Name = L"defOfWord";
			this->defOfWord->Size = System::Drawing::Size(488, 392);
			this->defOfWord->TabIndex = 0;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 67);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(200, 394);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &main::listBox1_SelectedIndexChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(496, 23);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(84, 33);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Search";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &main::button6_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(13, 24);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(469, 28);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &main::textBox2_TextChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(730, 468);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Can you guess it!\?";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->result2);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->guessWord);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->radioButton5);
			this->groupBox3->Controls->Add(this->radioButton6);
			this->groupBox3->Controls->Add(this->radioButton7);
			this->groupBox3->Controls->Add(this->radioButton8);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(360, 14);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(359, 452);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Can you guess its meaning\?";
			// 
			// result2
			// 
			this->result2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result2->ForeColor = System::Drawing::Color::IndianRed;
			this->result2->Location = System::Drawing::Point(10, 376);
			this->result2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->result2->Name = L"result2";
			this->result2->Size = System::Drawing::Size(345, 72);
			this->result2->TabIndex = 12;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(124, 347);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 27);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Confirm";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &main::button5_Click);
			// 
			// guessWord
			// 
			this->guessWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->guessWord->Location = System::Drawing::Point(10, 121);
			this->guessWord->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->guessWord->Name = L"guessWord";
			this->guessWord->Size = System::Drawing::Size(345, 52);
			this->guessWord->TabIndex = 9;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(10, 106);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(44, 15);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Word:";
			// 
			// radioButton5
			// 
			this->radioButton5->Location = System::Drawing::Point(13, 175);
			this->radioButton5->Margin = System::Windows::Forms::Padding(2);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(329, 39);
			this->radioButton5->TabIndex = 7;
			this->radioButton5->TabStop = true;
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->Location = System::Drawing::Point(13, 218);
			this->radioButton6->Margin = System::Windows::Forms::Padding(2);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(329, 42);
			this->radioButton6->TabIndex = 6;
			this->radioButton6->TabStop = true;
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->Location = System::Drawing::Point(13, 264);
			this->radioButton7->Margin = System::Windows::Forms::Padding(2);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(329, 41);
			this->radioButton7->TabIndex = 5;
			this->radioButton7->TabStop = true;
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton7_CheckedChanged);
			// 
			// radioButton8
			// 
			this->radioButton8->Location = System::Drawing::Point(13, 309);
			this->radioButton8->Margin = System::Windows::Forms::Padding(2);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(329, 34);
			this->radioButton8->TabIndex = 1;
			this->radioButton8->TabStop = true;
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton8_CheckedChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 38);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(235, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Let\'s pick the correct definition from four options.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 20);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(179, 13);
			this->label10->TabIndex = 3;
			this->label10->Text = L"So now you\'re given a random word.";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(13, 66);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 27);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &main::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->result1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->guessDef);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(8, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(330, 452);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Can you guess its word\?";
			// 
			// result1
			// 
			this->result1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result1->ForeColor = System::Drawing::Color::IndianRed;
			this->result1->Location = System::Drawing::Point(4, 376);
			this->result1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->result1->Name = L"result1";
			this->result1->Size = System::Drawing::Size(322, 72);
			this->result1->TabIndex = 11;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(122, 347);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 27);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Confirm";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &main::button4_Click);
			// 
			// guessDef
			// 
			this->guessDef->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->guessDef->Location = System::Drawing::Point(10, 121);
			this->guessDef->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->guessDef->Name = L"guessDef";
			this->guessDef->Size = System::Drawing::Size(305, 52);
			this->guessDef->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(10, 106);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 15);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Definition:";
			// 
			// radioButton4
			// 
			this->radioButton4->Location = System::Drawing::Point(13, 309);
			this->radioButton4->Margin = System::Windows::Forms::Padding(2);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(290, 34);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Location = System::Drawing::Point(13, 264);
			this->radioButton3->Margin = System::Windows::Forms::Padding(2);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(290, 41);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Location = System::Drawing::Point(13, 218);
			this->radioButton2->Margin = System::Windows::Forms::Padding(2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(302, 42);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->Location = System::Drawing::Point(13, 175);
			this->radioButton1->Margin = System::Windows::Forms::Padding(2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(290, 39);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &main::radioButton1_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 38);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Your objective is to guess that word";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 20);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(293, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"You will be given a definition from an unknown random word.";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 66);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 27);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &main::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(349, 0);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(362, 452);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button12);
			this->tabPage3->Controls->Add(this->panel4);
			this->tabPage3->Controls->Add(this->favoriteList);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(730, 468);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Favorites";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(594, 419);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(118, 36);
			this->button12->TabIndex = 12;
			this->button12->Text = L"Remove";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &main::button12_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(242, 10);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(478, 397);
			this->panel4->TabIndex = 11;
			// 
			// label12
			// 
			this->label12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(0, 0);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(478, 397);
			this->label12->TabIndex = 0;
			// 
			// favoriteList
			// 
			this->favoriteList->FormattingEnabled = true;
			this->favoriteList->Location = System::Drawing::Point(19, 10);
			this->favoriteList->Margin = System::Windows::Forms::Padding(2);
			this->favoriteList->Name = L"favoriteList";
			this->favoriteList->Size = System::Drawing::Size(213, 446);
			this->favoriteList->TabIndex = 10;
			this->favoriteList->SelectedIndexChanged += gcnew System::EventHandler(this, &main::favoriteList_SelectedIndexChanged);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->button14);
			this->tabPage4->Controls->Add(this->button13);
			this->tabPage4->Controls->Add(this->panel5);
			this->tabPage4->Controls->Add(this->historyList);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(730, 468);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"History";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(596, 421);
			this->button14->Margin = System::Windows::Forms::Padding(2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(95, 36);
			this->button14->TabIndex = 14;
			this->button14->Text = L"Clear all";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &main::button14_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(484, 421);
			this->button13->Margin = System::Windows::Forms::Padding(2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(95, 36);
			this->button13->TabIndex = 13;
			this->button13->Text = L"Remove";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &main::button13_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(240, 7);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(475, 406);
			this->panel5->TabIndex = 12;
			// 
			// label13
			// 
			this->label13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(0, 0);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(475, 406);
			this->label13->TabIndex = 0;
			// 
			// historyList
			// 
			this->historyList->FormattingEnabled = true;
			this->historyList->Location = System::Drawing::Point(12, 7);
			this->historyList->Margin = System::Windows::Forms::Padding(2);
			this->historyList->Name = L"historyList";
			this->historyList->Size = System::Drawing::Size(213, 446);
			this->historyList->TabIndex = 11;
			this->historyList->SelectedIndexChanged += gcnew System::EventHandler(this, &main::historyList_SelectedIndexChanged);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->button11);
			this->tabPage5->Controls->Add(this->label11);
			this->tabPage5->Controls->Add(this->groupBox5);
			this->tabPage5->Controls->Add(this->groupBox4);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Margin = System::Windows::Forms::Padding(2);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(730, 468);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Settings";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(293, 389);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(116, 28);
			this->button11->TabIndex = 7;
			this->button11->Text = L"Reset dictionaries";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &main::button11_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::IndianRed;
			this->label11->Location = System::Drawing::Point(216, 436);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(280, 26);
			this->label11->TabIndex = 6;
			this->label11->Text = L"PROJECT CS163 - KPLT";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->switchData);
			this->groupBox5->Controls->Add(this->comboBox1);
			this->groupBox5->Location = System::Drawing::Point(12, 249);
			this->groupBox5->Margin = System::Windows::Forms::Padding(2);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(2);
			this->groupBox5->Size = System::Drawing::Size(707, 103);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Switch dataset:";
			// 
			// switchData
			// 
			this->switchData->Location = System::Drawing::Point(576, 61);
			this->switchData->Margin = System::Windows::Forms::Padding(2);
			this->switchData->Name = L"switchData";
			this->switchData->Size = System::Drawing::Size(116, 28);
			this->switchData->TabIndex = 6;
			this->switchData->Text = L"Switch";
			this->switchData->UseVisualStyleBackColor = true;
			this->switchData->Click += gcnew System::EventHandler(this, &main::switchData_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Slang", L"Emoji", L"English word" });
			this->comboBox1->Location = System::Drawing::Point(18, 24);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(510, 25);
			this->comboBox1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button10);
			this->groupBox4->Controls->Add(this->textBox4);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Controls->Add(this->textBox3);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(12, 14);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(707, 219);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Add new word to dictionary";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(521, 158);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(116, 28);
			this->button10->TabIndex = 5;
			this->button10->Text = L"Add";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(18, 124);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(451, 63);
			this->textBox4->TabIndex = 4;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 105);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Its definition:";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(521, 45);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(116, 28);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Check";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(18, 49);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(451, 25);
			this->textBox3->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 28);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Word to add:";
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 501);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"main";
			this->Text = L"Dictionary";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TernaryTreeNode* find = ProgramData::currentTree.search4keyword(convertTo(textBox1->Text));
		if (!find || !find->definition) {
			label1->Text = "Not found";
			return;
		}

		std::string def = *find->definition;
		label1->Text = convertFrom(def);
		button8->Enabled = true;
		button15->Enabled = true;

		suggestedWords->Items->Clear();
		std::vector<WordAndDef> v = suggestWords(convertTo(textBox1->Text));
		for (auto s : v) {
			suggestedWords->Items->Add(convertFrom(s.word));
		}
		suggesting = v;

		WordAndDef wad;
		wad.word = convertTo(textBox1->Text);
		wad.definition = def;
		history.addToHistory(wad, currentSet); //them vao history
				v2ListView(history.words, historyList);
	}

	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
		button8->Enabled = false;
		button7->Enabled = false;
		button4->Enabled = false;
		button5->Enabled = false;
		button15->Enabled = false;
		button12->Enabled = false;
		button13->Enabled = false;
		button14->Enabled = false;
		//mac dinh set se bang 2-dictionary 
		/*wordOfTheDay();*/

		radioButton1->Enabled = false;
		radioButton2->Enabled = false;
		radioButton3->Enabled = false;
		radioButton4->Enabled = false;
		radioButton5->Enabled = false;
		radioButton6->Enabled = false;
		radioButton7->Enabled = false;
		radioButton8->Enabled = false;

	}



	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		v = (ProgramData::currentTree).search4Definition(convertTo(textBox2->Text));
		v2ListView(v, listBox1);
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (v.size() > 0) {
			defOfWord->Text = convertFrom(v[listBox1->SelectedIndex].definition); //xuat definition khi dc chon
		}
		if (listBox1->SelectedIndex != -1)
			button7->Enabled = true;
		else
			button7->Enabled = false;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		button4->Enabled = true;
		radioButton1->Enabled = true;
		radioButton2->Enabled = true;
		radioButton3->Enabled = true;
		radioButton4->Enabled = true;
		guessRandomWord(ProgramData::listOfTree[2], false);
	}


		   void guessRandomWord(TernarySearchTree& tree, bool nonWord) {
			   for (int i = 0; i < 4; i++) {
				   if (nonWord)
					   tree.getRandomWord2(false, i);
				   else
					   tree.getRandomWord(false, i);
			   }
			   chooseWord1 = rand() % 4;
			   std::string show = tree.wordAndDefinition[chooseWord1].second;
			   guessDef->Text = convertFrom(show);
			   for (int i = 0; i < 4; i++) {
				   RadioButton^ selected;
				   switch (i) {
				   case 1: {
					   selected = radioButton1;
					   break; }
				   case 2: {
					   selected = radioButton2;
					   break; }
				   case 3: {
					   selected = radioButton3;
					   break;
				   }
				   default: {
					   selected = radioButton4;
					   break;
				   }
				   }
				   selected->Text = convertFrom(tree.wordAndDefinition[i].first);
			   }
			  
			   //tu dung la wordAndDefinition[chooseWord].first
			  
		   }
		   void guessRandomDefinition(TernarySearchTree& tree, bool nonWord) {
			   for (int i = 0; i < 4; i++) {
				   if (nonWord)
					   tree.getRandomWord2(false, i);
				   else
					   tree.getRandomWord(false, i);
			   }
			   chooseWord2 = rand() % 4;
			   std::string show = tree.wordAndDefinition[chooseWord2].first;
			   guessWord->Text = convertFrom(show);
			   for (int i = 0; i < 4; i++) {
				   RadioButton^ selected;
				   switch (i) {
				   case 1: {
					   selected = radioButton5;
					   break; }
				   case 2: {
					   selected = radioButton6;
					   break; }
				   case 3: {
					   selected = radioButton7;
					   break;
				   }
				   default: {
					   selected = radioButton8;
					   break;
				   }
				   }
				   selected->Text = convertFrom(tree.wordAndDefinition[i].second);
			   }
			   
			   //tu dung la wordAndDefinition[chooseWord].second
		
		   }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		button5->Enabled = true;
		radioButton5->Enabled = true;
		radioButton6->Enabled = true;
		radioButton7->Enabled = true;
		radioButton8->Enabled = true;
		guessRandomDefinition(ProgramData::listOfTree[2], false);
		//se them tgian countdown
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (selected1 != -1 && selected1 == chooseWord1) //dung
		{
			result1->ForeColor = System::Drawing::Color::Green; //chinh thanh mau xanh
			result1->Text = "Correct answer!";
		}
		else {
			result1->ForeColor = System::Drawing::Color::Red; //chinh thanh mau do
			result1->Text = convertFrom("Wrong answer. The correct answer is " + ProgramData::currentTree.wordAndDefinition[chooseWord1].first);
		}
		button4->Enabled = false;
		selected1 = -1;
	}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	Form^ rgForm = gcnew edit(textBox1->Text);
	rgForm->Show();

}
private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Form^ rgForm = gcnew edit(listBox1->SelectedItem->ToString());
	rgForm->Show();

}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->Text->Length != 0)
		button6->Enabled = true;
	else
		button6->Enabled = false;
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	resetAllDictionary(ProgramData::listOfTree);
	saveAllTree(ProgramData::listOfTree);
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button4->Enabled = true;
	selected1 = 0;
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button4->Enabled = true;
	selected1 = 1;
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button4->Enabled = true;
	selected1 = 2;
}
private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button4->Enabled = true;
	selected1 = 3;
}
private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button5->Enabled = true;
	selected2 = 0;
}
private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button5->Enabled = true;
	selected2 = 1;
}
private: System::Void radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button5->Enabled = true;
	selected2 = 2;
}
private: System::Void radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button5->Enabled = true;
	selected2 = 3;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (selected2 != -1 && selected2 == chooseWord2) //dung
	{
		result2->ForeColor = System::Drawing::Color::Green; //chinh thanh mau xanh
		result2->Text = "Correct answer!";
	}
	else {
		result2->ForeColor = System::Drawing::Color::Red; //chinh thanh mau do
		result2->Text = convertFrom("Wrong answer. The correct answer is " + ProgramData::currentTree.wordAndDefinition[chooseWord2].second);
	}
	button5->Enabled = false;
	selected2 = -1;
}
private: System::Void switchData_Click(System::Object^ sender, System::EventArgs^ e) {
	currentSet = comboBox1->SelectedIndex; //2 la index cua listOfTree
	/*ProgramData::listOfTree[currentSet].import_dictionary(currentSet);*/
	ProgramData::currentTree = ProgramData::listOfTree[currentSet];
	wordOfTheDay();
	std::ofstream ofs;
	ofs.open("currentSet.txt");
	ofs << currentSet;
	ofs.close();
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	suggestedWords->Items->Clear();
	std::vector<WordAndDef> v = suggestWords(convertTo(textBox1->Text));
	for (auto s : v) {
		suggestedWords->Items->Add(convertFrom(s.word));
	}
	suggesting = v;
}
private: System::Void suggestedWords_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (suggestedWords->SelectedIndex != -1) {
		int i = suggestedWords->SelectedIndex;
		label1->Text = convertFrom(suggesting[i].definition); //xuat definition khi dc chon
		textBox1->Text = convertFrom(suggesting[i].word);
		//la do suggesting hay sao
		WordAndDef wad;
		wad.word = convertTo(textBox1->Text);
		wad.definition = convertTo(label1->Text);
		history.addToHistory(wad, currentSet); //them vao history
		v2ListView(history.words, historyList);
		button8->Enabled = true;
		button15->Enabled = true;
	}
	else
	{
		button8->Enabled = false;
		button15->Enabled = false;
	}

}
private: System::Void favoriteList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (favorite.words.size() > 0) {
		label12->Text = convertFrom(favorite.words[favoriteList->SelectedIndex].definition); //xuat definition khi dc chon
	}
	if (favoriteList->SelectedIndex != -1)
		button12->Enabled = true;
	else
		button12->Enabled = false;
}
private: System::Void historyList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (history.words.size() > 0) {
		label13 ->Text = convertFrom(history.words[historyList->SelectedIndex].definition); //xuat definition khi dc chon
	}
	if (historyList->SelectedIndex != -1) {
		button13->Enabled = true;
		button14->Enabled = true;
	}
	else
	{
		button13->Enabled = false;
		button14->Enabled = false;
	}
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	if (favoriteList->SelectedIndex != -1) {
		int i = favoriteList->SelectedIndex;
		favoriteList->Items->RemoveAt(i);
		favorite.words.erase(favorite.words.begin() + i);
		favorite.dictionaryNo.erase(favorite.dictionaryNo.begin() + i);
		favorite.saveToFile();
		v2ListView(favorite.words, favoriteList);
	}
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	if (historyList->SelectedIndex != -1) {
		int i = historyList->SelectedIndex;
		historyList->Items->RemoveAt(i);
		history.words.erase(history.words.begin() + i);
		history.dictionaryNo.erase(history.dictionaryNo.begin() + i);
		history.saveToFile();
		v2ListView(history.words, historyList);
	}
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	history.words.clear();
	historyList->Items->Clear();
	history.dictionaryNo.clear();
	history.saveToFile();
	v2ListView(history.words, historyList);
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	bool found = false;
	for (int i = 0; i < favorite.words.size(); i++) {
		if (favorite.words[i].word == convertTo(textBox1->Text)) {
			found = true;
			break;
		}
	}
	if (!found) {
		WordAndDef wad;
		wad.word = convertTo(textBox1->Text);
		wad.definition = convertTo(label1->Text);
		favorite.words.push_back(wad);
		favorite.dictionaryNo.push_back(currentSet); //them vao danh sach favorite va luu no thuoc tu dien nao
		favorite.saveToFile();
		v2ListView(favorite.words, favoriteList);
	}
}
};
}
