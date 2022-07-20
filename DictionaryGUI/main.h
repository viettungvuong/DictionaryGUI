#pragma once
#include <stdlib.h>
#include "ternary.h"
#include "Screen.h"
#include "functions.h"
#include <string>

#include <msclr\marshal_cppstd.h>
TernarySearchTree listOfTree[3];
namespace DictionaryGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	std::vector<WordAndDef> v;
	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		void wordOfTheDay(TernarySearchTree tree) {
			TernaryTreeNode* t = tree.getRandomWord();
			word->Text = convertFrom(t->word);
			def->Text = convertFrom(*t->definition);
		}
		main(void)
		{
			InitializeComponent();
			srand(time(NULL)); //khoi tao random//Tung dang test cai nay
			createSet(listOfTree);//khoi tao
			int currentSet = 2;//mac dinh set se bang 2-dictionary k
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
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->defOfWord = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
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
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->switchData = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
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
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1476, 950);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->panel2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(1460, 903);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Search by word";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1200, 196);
			this->button8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(254, 63);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Edit current word";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(936, 196);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(256, 63);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(6, 265);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1416, 631);
			this->panel1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1416, 631);
			this->label1->TabIndex = 0;
			this->label1->Text = L"test";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->def);
			this->panel2->Controls->Add(this->word);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(6, 6);
			this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1416, 173);
			this->panel2->TabIndex = 10;
			// 
			// def
			// 
			this->def->AutoSize = true;
			this->def->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->def->Location = System::Drawing::Point(34, 63);
			this->def->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->def->Name = L"def";
			this->def->Size = System::Drawing::Size(112, 27);
			this->def->TabIndex = 2;
			this->def->Text = L"Definition";
			// 
			// word
			// 
			this->word->AutoSize = true;
			this->word->Font = (gcnew System::Drawing::Font(L"Arial", 10.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->word->Location = System::Drawing::Point(336, 13);
			this->word->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->word->Name = L"word";
			this->word->Size = System::Drawing::Size(96, 34);
			this->word->TabIndex = 1;
			this->word->Text = L" Word";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(34, 13);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(297, 34);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Some random word:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 198);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(898, 49);
			this->textBox1->TabIndex = 6;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->button7);
			this->tabPage6->Controls->Add(this->panel3);
			this->tabPage6->Controls->Add(this->listBox1);
			this->tabPage6->Controls->Add(this->button6);
			this->tabPage6->Controls->Add(this->textBox2);
			this->tabPage6->Location = System::Drawing::Point(8, 39);
			this->tabPage6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(1460, 903);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Search by definition";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->defOfWord);
			this->panel3->Location = System::Drawing::Point(452, 129);
			this->panel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(976, 754);
			this->panel3->TabIndex = 10;
			// 
			// defOfWord
			// 
			this->defOfWord->Dock = System::Windows::Forms::DockStyle::Fill;
			this->defOfWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->defOfWord->Location = System::Drawing::Point(0, 0);
			this->defOfWord->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->defOfWord->Name = L"defOfWord";
			this->defOfWord->Size = System::Drawing::Size(976, 754);
			this->defOfWord->TabIndex = 0;
			this->defOfWord->Text = L"test";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 25;
			this->listBox1->Location = System::Drawing::Point(26, 129);
			this->listBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(396, 754);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &main::listBox1_SelectedIndexChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(992, 45);
			this->button6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(168, 63);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Search";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &main::button6_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(26, 46);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(934, 49);
			this->textBox2->TabIndex = 7;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(1460, 903);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Can you guess it!\?";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
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
			this->groupBox3->Location = System::Drawing::Point(720, 27);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(718, 869);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Can you guess its meaning\?";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(248, 667);
			this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(180, 52);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Confirm";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// guessWord
			// 
			this->guessWord->AutoSize = true;
			this->guessWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->guessWord->Location = System::Drawing::Point(20, 233);
			this->guessWord->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->guessWord->MaximumSize = System::Drawing::Size(600, 69);
			this->guessWord->Name = L"guessWord";
			this->guessWord->Size = System::Drawing::Size(102, 29);
			this->guessWord->TabIndex = 9;
			this->guessWord->Text = L"def here";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(20, 204);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(131, 29);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Definition:";
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(26, 594);
			this->radioButton5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(165, 29);
			this->radioButton5->TabIndex = 7;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"radioButton5";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(26, 508);
			this->radioButton6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(165, 29);
			this->radioButton6->TabIndex = 6;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"radioButton6";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(26, 419);
			this->radioButton7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(165, 29);
			this->radioButton7->TabIndex = 5;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"radioButton7";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(26, 337);
			this->radioButton8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(165, 29);
			this->radioButton8->TabIndex = 1;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"radioButton8";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(20, 73);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(476, 25);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Let\'s pick the correct definition from four options.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(20, 38);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(359, 25);
			this->label10->TabIndex = 3;
			this->label10->Text = L"So now you\'re given a random word.";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(26, 127);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(180, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &main::button3_Click);
			// 
			// groupBox1
			// 
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
			this->groupBox1->Location = System::Drawing::Point(16, 27);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(660, 869);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Can you guess its word\?";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(244, 667);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(180, 52);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Confirm";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &main::button4_Click);
			// 
			// guessDef
			// 
			this->guessDef->AutoSize = true;
			this->guessDef->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->guessDef->Location = System::Drawing::Point(20, 233);
			this->guessDef->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->guessDef->MaximumSize = System::Drawing::Size(600, 69);
			this->guessDef->Name = L"guessDef";
			this->guessDef->Size = System::Drawing::Size(102, 29);
			this->guessDef->TabIndex = 9;
			this->guessDef->Text = L"def here";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(20, 204);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(131, 29);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Definition:";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(26, 594);
			this->radioButton4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(165, 29);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(26, 508);
			this->radioButton3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(165, 29);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(26, 419);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(165, 29);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(26, 337);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(165, 29);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 73);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(354, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Your objective is to guess that word";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 38);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(592, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"You will be given a definition from an unknown random word.";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(26, 127);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(180, 52);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &main::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(698, 0);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(724, 869);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(8, 39);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1460, 903);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Favorites";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(8, 39);
			this->tabPage4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1460, 903);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"History";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label11);
			this->tabPage5->Controls->Add(this->groupBox5);
			this->tabPage5->Controls->Add(this->groupBox4);
			this->tabPage5->Location = System::Drawing::Point(8, 39);
			this->tabPage5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1460, 903);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Settings";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button10);
			this->groupBox4->Controls->Add(this->textBox4);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Controls->Add(this->textBox3);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(25, 27);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(1414, 422);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Add new word to dictionary";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 54);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 25);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Word to add:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(37, 94);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(898, 45);
			this->textBox3->TabIndex = 1;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(1042, 86);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(231, 53);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Check";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(32, 201);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 25);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Its definition:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(37, 239);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(898, 117);
			this->textBox4->TabIndex = 4;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(1042, 303);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(231, 53);
			this->button10->TabIndex = 5;
			this->button10->Text = L"Add";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->switchData);
			this->groupBox5->Controls->Add(this->comboBox1);
			this->groupBox5->Location = System::Drawing::Point(25, 478);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(1414, 198);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Switch dataset:";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"English words", L"Slangs", L"Emojis" });
			this->comboBox1->Location = System::Drawing::Point(37, 47);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(1017, 39);
			this->comboBox1->TabIndex = 0;
			// 
			// switchData
			// 
			this->switchData->Location = System::Drawing::Point(1152, 118);
			this->switchData->Name = L"switchData";
			this->switchData->Size = System::Drawing::Size(231, 53);
			this->switchData->TabIndex = 6;
			this->switchData->Text = L"Switch";
			this->switchData->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::IndianRed;
			this->label11->Location = System::Drawing::Point(430, 756);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(530, 51);
			this->label11->TabIndex = 6;
			this->label11->Text = L"PROJECT CS163 - KPLT";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1174, 45);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(254, 63);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Edit current word";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1492, 973);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string def = *(listOfTree[2].search4keyword(convertTo(textBox1->Text)))->definition;
		label1->Text = convertFrom(def);
	}
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL)); //khoi tao random//Tung dang test cai nay
		createSet(listOfTree);//khoi tao
		int currentSet = 2;//mac dinh set se bang 2-dictionary 
		/*wordOfTheDay();*/
		wordOfTheDay(listOfTree[2]);
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
		v = (listOfTree[2].search4Definition(convertTo(textBox2->Text)));
		v2ListView(v, listBox1);
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (v.size() > 0) {
			defOfWord->Text = convertFrom(v[listBox1->SelectedIndex].definition); //xuat definition khi dc chon
		}

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		radioButton1->Enabled = true;
		radioButton2->Enabled = true;
		radioButton3->Enabled = true;
		radioButton4->Enabled = true;
		guessRandomWord(listOfTree[2], false);
	}


		   void guessRandomWord(TernarySearchTree tree, bool nonWord) {
			   for (int i = 0; i < 4; i++) {
				   if (nonWord)
					   tree.getRandomWord2(false, i);
				   else
					   tree.getRandomWord(false, i);
			   }
			   int chooseWord = rand() % 4;
			   std::string show = tree.wordAndDefinition[chooseWord].second;
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
		   void guessRandomDefinition(TernarySearchTree tree, bool nonWord) {
			   for (int i = 0; i < 4; i++) {
				   if (nonWord)
					   tree.getRandomWord2(false, i);
				   else
					   tree.getRandomWord(false, i);
			   }
			   int chooseWord = rand() % 4;
			   std::string show = tree.wordAndDefinition[chooseWord].first;
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
		radioButton5->Enabled = true;
		radioButton6->Enabled = true;
		radioButton7->Enabled = true;
		radioButton8->Enabled = true;
		guessRandomDefinition(listOfTree[2], false);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
