#pragma once
#include "main.h"
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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ def;
	private: System::Windows::Forms::Label^ word;






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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->word = (gcnew System::Windows::Forms::Label());
			this->def = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(57, 214);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(750, 49);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(870, 213);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(231, 63);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main::button1_Click);
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(57, 282);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(315, 521);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(415, 282);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1028, 542);
			this->panel1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1028, 542);
			this->label1->TabIndex = 0;
			this->label1->Text = L"test";
			this->label1->Click += gcnew System::EventHandler(this, &main::label1_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->def);
			this->panel2->Controls->Add(this->word);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(57, 22);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1390, 174);
			this->panel2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(34, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(247, 34);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Word of the Day:";
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
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 858);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"main";
			this->Text = L"Dictionary";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		std::string input = context.marshal_as<std::string>(textBox1->Text);
		std::string def = *(listOfTree[2].search4keyword(input))->definition;
		System::String^ strConverted = gcnew System::String(def.c_str());
		label1->Text = strConverted;
	}
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL)); //khoi tao random//Tung dang test cai nay
		createSet(listOfTree);//khoi tao
		int currentSet = 2;//mac dinh set se bang 2-dictionary 
	}

	};
}
