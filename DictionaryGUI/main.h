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
	private: System::Windows::Forms::ListView^ listView1;
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->def = (gcnew System::Windows::Forms::Label());
			this->word = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1477, 950);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->panel2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1461, 903);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Search";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1435, 787);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Can you guess it!\?";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(6, 266);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(341, 521);
			this->listView1->TabIndex = 8;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(819, 197);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(257, 63);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(364, 266);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1054, 542);
			this->panel1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1054, 542);
			this->label1->TabIndex = 0;
			this->label1->Text = L"test";
			// 
			// def
			// 
			this->def->AutoSize = true;
			this->def->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->def->Location = System::Drawing::Point(34, 64);
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
			this->word->Location = System::Drawing::Point(308, 14);
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
			this->label2->Location = System::Drawing::Point(34, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(297, 34);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Some random word:";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->def);
			this->panel2->Controls->Add(this->word);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(6, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1416, 174);
			this->panel2->TabIndex = 10;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 198);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(776, 49);
			this->textBox1->TabIndex = 6;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1471, 974);
			this->Controls->Add(this->tabControl1);
			this->Name = L"main";
			this->Text = L"Dictionary";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
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
	}



	};
}
