#pragma once

#include "XandY.h"

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SizeForm
	/// </summary>
	public ref class SizeForm : public System::Windows::Forms::Form
	{
	public:
		SizeForm(void)
		{
			InitializeComponent();
			
			//TODO: Add the constructor code here
			
		}
		Variables *varieble = new Variables();
 //створення об'єкту Variables для збереження зчитаних параметрів пошуку
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SizeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_apply;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_apply = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			 
			// button_apply
			 
			this->button_apply->Location = System::Drawing::Point(205, 292);
			this->button_apply->Name = L"button_apply";
			this->button_apply->Size = System::Drawing::Size(249, 75);
			this->button_apply->TabIndex = 0;
			this->button_apply->Text = L"Apply";
			this->button_apply->UseVisualStyleBackColor = true;
			this->button_apply->Click += gcnew System::EventHandler(this, &SizeForm::button_apply_Click);
			 
			// label1
			 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(146, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Width ( x )";
			 
			// label2
			 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(435, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Length ( y )";
			 
			// label3
			 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(94, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"from";
			 
			// label4
			 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(112, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"to";
			 
			// textBox1
			 
			this->textBox1->Location = System::Drawing::Point(150, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 5;
			 
			// textBox2
			 
			this->textBox2->Location = System::Drawing::Point(150, 178);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 6;
			 
			// textBox3
			 
			this->textBox3->Location = System::Drawing::Point(439, 124);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 10;
			 
			// textBox4
			 
			this->textBox4->Location = System::Drawing::Point(439, 175);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 9;
			 
			// label5
			 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(401, 178);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"to";
			 
			// label6
			 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(383, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"from";
			 
			// SizeForm
			 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 420);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_apply);
			this->Name = L"SizeForm";
			this->Text = L"SizeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_apply_Click(System::Object^ sender, System::EventArgs^ e) { // функція для зчитування введених параметрів пошуку(від х1 до х2, а також від у1 до у2)
		int x = 0;
		int xsec = 0; // змінні для зпдпння введених параметрів у клас Variables
		int y = 0;
		int ysec = 0;
		Int32::TryParse(textBox1->Text, x); 
		Int32::TryParse(textBox2->Text, xsec); // приведення типів до int 
		Int32::TryParse(textBox3->Text, y);
		Int32::TryParse(textBox4->Text, ysec);
		varieble->SetVariable(x, xsec, y, ysec); // запис параметрів пошуку до класу Variables
		this->Close(); // закриття форми
	}
};
}
