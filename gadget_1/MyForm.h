#pragma once

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <msclr/marshal_cppstd.h>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "SizeForm.h" // нова форма для зчитування параметрів розміру гаджету(для пошуку гаджету по розміру)

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::IO;


	#include "gadget.h" // відокремлений користувацький клас гаджет для роботи з таблицею гаджетів
	#include "exception.h"

	std::vector<Gadget> GadgetList;

	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//TODO: Add the constructor code here
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ writeCtrlWToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exiteAltF4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::CheckBox^ check_type_watch;
	private: System::Windows::Forms::CheckBox^ check_type_tablet;
	private: System::Windows::Forms::CheckBox^ check_type_phone;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::CheckBox^ check_monitor;
	private: System::Windows::Forms::CheckBox^ check_gps;
	private: System::Windows::Forms::CheckBox^ check_camera;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ price_inpt;
	private: System::Windows::Forms::TextBox^ comp_inpt;
	private: System::Windows::Forms::TextBox^ capt_inpt;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_modify;
	private: System::Windows::Forms::Button^ button_find;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::NumericUpDown^ sizey_inpt;

	private: System::Windows::Forms::NumericUpDown^ sizex_inpt;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::ToolStripMenuItem^ sortPricequickToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ findSizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ groupByCompanyToolStripMenuItem;



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
			System::Windows::Forms::Label^ label5;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->writeCtrlWToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupByCompanyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exiteAltF4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortPricequickToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findSizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->sizey_inpt = (gcnew System::Windows::Forms::NumericUpDown());
			this->sizex_inpt = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->check_type_watch = (gcnew System::Windows::Forms::CheckBox());
			this->check_type_tablet = (gcnew System::Windows::Forms::CheckBox());
			this->check_type_phone = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->check_monitor = (gcnew System::Windows::Forms::CheckBox());
			this->check_gps = (gcnew System::Windows::Forms::CheckBox());
			this->check_camera = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->price_inpt = (gcnew System::Windows::Forms::TextBox());
			this->comp_inpt = (gcnew System::Windows::Forms::TextBox());
			this->capt_inpt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_modify = (gcnew System::Windows::Forms::Button());
			this->button_find = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizey_inpt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizex_inpt))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			label5->ForeColor = System::Drawing::Color::White;
			label5->Location = System::Drawing::Point(35, 295);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(37, 19);
			label5->TabIndex = 8;
			label5->Text = L"size";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->tableToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(15, 11);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(243, 33);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->readToolStripMenuItem,
					this->writeCtrlWToolStripMenuItem, this->groupByCompanyToolStripMenuItem, this->exiteAltF4ToolStripMenuItem
			});
			this->fileToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fileToolStripMenuItem.Image")));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(78, 29);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readToolStripMenuItem
			// 
			this->readToolStripMenuItem->Name = L"readToolStripMenuItem";
			this->readToolStripMenuItem->Size = System::Drawing::Size(268, 34);
			this->readToolStripMenuItem->Text = L"Read";
			this->readToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::readToolStripMenuItem_Click);
			// 
			// writeCtrlWToolStripMenuItem
			// 
			this->writeCtrlWToolStripMenuItem->Name = L"writeCtrlWToolStripMenuItem";
			this->writeCtrlWToolStripMenuItem->Size = System::Drawing::Size(268, 34);
			this->writeCtrlWToolStripMenuItem->Text = L"Write";
			this->writeCtrlWToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::writeCtrlWToolStripMenuItem_Click);
			// 
			// groupByCompanyToolStripMenuItem
			// 
			this->groupByCompanyToolStripMenuItem->Name = L"groupByCompanyToolStripMenuItem";
			this->groupByCompanyToolStripMenuItem->Size = System::Drawing::Size(268, 34);
			this->groupByCompanyToolStripMenuItem->Text = L"Group by company";
			this->groupByCompanyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::groupByCompanyToolStripMenuItem_Click);
			// 
			// exiteAltF4ToolStripMenuItem
			// 
			this->exiteAltF4ToolStripMenuItem->Name = L"exiteAltF4ToolStripMenuItem";
			this->exiteAltF4ToolStripMenuItem->Size = System::Drawing::Size(268, 34);
			this->exiteAltF4ToolStripMenuItem->Text = L"Exite";
			this->exiteAltF4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exiteAltF4ToolStripMenuItem_Click);
			// 
			// tableToolStripMenuItem
			// 
			this->tableToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fillToolStripMenuItem,
					this->clearToolStripMenuItem, this->sortPricequickToolStripMenuItem, this->findSizeToolStripMenuItem
			});
			this->tableToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tableToolStripMenuItem.Image")));
			this->tableToolStripMenuItem->Name = L"tableToolStripMenuItem";
			this->tableToolStripMenuItem->Size = System::Drawing::Size(92, 29);
			this->tableToolStripMenuItem->Text = L"Table";
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(259, 34);
			this->fillToolStripMenuItem->Text = L"Fill";
			this->fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fillToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(259, 34);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			// 
			// sortPricequickToolStripMenuItem
			// 
			this->sortPricequickToolStripMenuItem->Name = L"sortPricequickToolStripMenuItem";
			this->sortPricequickToolStripMenuItem->Size = System::Drawing::Size(259, 34);
			this->sortPricequickToolStripMenuItem->Text = L"Sort price - (quick)";
			this->sortPricequickToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sortPricequickToolStripMenuItem_Click);
			// 
			// findSizeToolStripMenuItem
			// 
			this->findSizeToolStripMenuItem->Name = L"findSizeToolStripMenuItem";
			this->findSizeToolStripMenuItem->Size = System::Drawing::Size(259, 34);
			this->findSizeToolStripMenuItem->Text = L"Find size ";
			this->findSizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::findSizeToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(65, 29);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->sizey_inpt);
			this->groupBox1->Controls->Add(this->sizex_inpt);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->check_type_watch);
			this->groupBox1->Controls->Add(this->check_type_tablet);
			this->groupBox1->Controls->Add(this->check_type_phone);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->check_monitor);
			this->groupBox1->Controls->Add(this->check_gps);
			this->groupBox1->Controls->Add(this->check_camera);
			this->groupBox1->Controls->Add(label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->price_inpt);
			this->groupBox1->Controls->Add(this->comp_inpt);
			this->groupBox1->Controls->Add(this->capt_inpt);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(15, 57);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 465);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			// 
			// sizey_inpt
			// 
			this->sizey_inpt->Location = System::Drawing::Point(198, 293);
			this->sizey_inpt->Name = L"sizey_inpt";
			this->sizey_inpt->Size = System::Drawing::Size(65, 26);
			this->sizey_inpt->TabIndex = 29;
			// 
			// sizex_inpt
			// 
			this->sizex_inpt->Location = System::Drawing::Point(88, 293);
			this->sizex_inpt->Name = L"sizex_inpt";
			this->sizex_inpt->Size = System::Drawing::Size(63, 26);
			this->sizex_inpt->TabIndex = 28;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(234, 171);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 19);
			this->label10->TabIndex = 27;
			this->label10->Text = L"watch";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(158, 171);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 19);
			this->label9->TabIndex = 26;
			this->label9->Text = L"tablet";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(79, 171);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 19);
			this->label8->TabIndex = 25;
			this->label8->Text = L"phone";
			// 
			// check_type_watch
			// 
			this->check_type_watch->AutoSize = true;
			this->check_type_watch->Location = System::Drawing::Point(249, 198);
			this->check_type_watch->Name = L"check_type_watch";
			this->check_type_watch->Size = System::Drawing::Size(22, 21);
			this->check_type_watch->TabIndex = 24;
			this->check_type_watch->UseVisualStyleBackColor = true;
			this->check_type_watch->CheckedChanged += gcnew System::EventHandler(this, &MyForm::check_type_watch_CheckedChanged);
			// 
			// check_type_tablet
			// 
			this->check_type_tablet->AutoSize = true;
			this->check_type_tablet->Location = System::Drawing::Point(171, 198);
			this->check_type_tablet->Name = L"check_type_tablet";
			this->check_type_tablet->Size = System::Drawing::Size(22, 21);
			this->check_type_tablet->TabIndex = 23;
			this->check_type_tablet->UseVisualStyleBackColor = true;
			this->check_type_tablet->CheckedChanged += gcnew System::EventHandler(this, &MyForm::check_type_tablet_CheckedChanged);
			// 
			// check_type_phone
			// 
			this->check_type_phone->AutoSize = true;
			this->check_type_phone->Location = System::Drawing::Point(100, 198);
			this->check_type_phone->Name = L"check_type_phone";
			this->check_type_phone->Size = System::Drawing::Size(22, 21);
			this->check_type_phone->TabIndex = 22;
			this->check_type_phone->UseVisualStyleBackColor = true;
			this->check_type_phone->CheckedChanged += gcnew System::EventHandler(this, &MyForm::check_type_phone_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(33, 186);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(39, 19);
			this->label7->TabIndex = 19;
			this->label7->Text = L"type";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(167, 295);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 20);
			this->label6->TabIndex = 17;
			this->label6->Text = L"x";
			// 
			// check_monitor
			// 
			this->check_monitor->AutoSize = true;
			this->check_monitor->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->check_monitor->ForeColor = System::Drawing::Color::DarkOrchid;
			this->check_monitor->Location = System::Drawing::Point(82, 424);
			this->check_monitor->Name = L"check_monitor";
			this->check_monitor->Size = System::Drawing::Size(163, 23);
			this->check_monitor->TabIndex = 11;
			this->check_monitor->Text = L"Heart rate monitor";
			this->check_monitor->UseVisualStyleBackColor = true;
			// 
			// check_gps
			// 
			this->check_gps->AutoSize = true;
			this->check_gps->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->check_gps->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->check_gps->Location = System::Drawing::Point(82, 385);
			this->check_gps->Name = L"check_gps";
			this->check_gps->Size = System::Drawing::Size(66, 23);
			this->check_gps->TabIndex = 10;
			this->check_gps->Text = L"GPS";
			this->check_gps->UseVisualStyleBackColor = true;
			// 
			// check_camera
			// 
			this->check_camera->AutoSize = true;
			this->check_camera->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->check_camera->ForeColor = System::Drawing::Color::MediumSpringGreen;
			this->check_camera->Location = System::Drawing::Point(82, 346);
			this->check_camera->Name = L"check_camera";
			this->check_camera->Size = System::Drawing::Size(88, 23);
			this->check_camera->TabIndex = 9;
			this->check_camera->Text = L"camera";
			this->check_camera->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(29, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 19);
			this->label4->TabIndex = 7;
			this->label4->Text = L"price";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(-1, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 19);
			this->label3->TabIndex = 6;
			this->label3->Text = L"company";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(11, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 19);
			this->label2->TabIndex = 5;
			this->label2->Text = L"caption";
			// 
			// price_inpt
			// 
			this->price_inpt->Location = System::Drawing::Point(82, 240);
			this->price_inpt->Name = L"price_inpt";
			this->price_inpt->Size = System::Drawing::Size(189, 26);
			this->price_inpt->TabIndex = 3;
			// 
			// comp_inpt
			// 
			this->comp_inpt->Location = System::Drawing::Point(82, 128);
			this->comp_inpt->Name = L"comp_inpt";
			this->comp_inpt->Size = System::Drawing::Size(189, 26);
			this->comp_inpt->TabIndex = 2;
			// 
			// capt_inpt
			// 
			this->capt_inpt->Location = System::Drawing::Point(82, 78);
			this->capt_inpt->Name = L"capt_inpt";
			this->capt_inpt->Size = System::Drawing::Size(189, 26);
			this->capt_inpt->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(28, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(286, 27);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Properties of smartphone";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_delete);
			this->groupBox2->Controls->Add(this->button_modify);
			this->groupBox2->Controls->Add(this->button_find);
			this->groupBox2->Controls->Add(this->button_add);
			this->groupBox2->Location = System::Drawing::Point(15, 523);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1001, 120);
			this->groupBox2->TabIndex = 25;
			this->groupBox2->TabStop = false;
			// 
			// button_delete
			// 
			this->button_delete->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button_delete->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_delete->Font = (gcnew System::Drawing::Font(L"Orbitron SemiBold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_delete->ForeColor = System::Drawing::Color::White;
			this->button_delete->Location = System::Drawing::Point(309, 35);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(127, 60);
			this->button_delete->TabIndex = 15;
			this->button_delete->Text = L"Delete";
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click_1);
			// 
			// button_modify
			// 
			this->button_modify->BackColor = System::Drawing::Color::DarkOrchid;
			this->button_modify->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_modify->Font = (gcnew System::Drawing::Font(L"Orbitron SemiBold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_modify->ForeColor = System::Drawing::Color::White;
			this->button_modify->Location = System::Drawing::Point(543, 35);
			this->button_modify->Name = L"button_modify";
			this->button_modify->Size = System::Drawing::Size(127, 60);
			this->button_modify->TabIndex = 14;
			this->button_modify->Text = L"Modify";
			this->button_modify->UseVisualStyleBackColor = false;
			this->button_modify->Click += gcnew System::EventHandler(this, &MyForm::button_modify_Click_1);
			// 
			// button_find
			// 
			this->button_find->BackColor = System::Drawing::Color::Gold;
			this->button_find->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_find->Font = (gcnew System::Drawing::Font(L"Orbitron SemiBold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_find->ForeColor = System::Drawing::Color::White;
			this->button_find->Location = System::Drawing::Point(780, 35);
			this->button_find->Name = L"button_find";
			this->button_find->Size = System::Drawing::Size(132, 60);
			this->button_find->TabIndex = 13;
			this->button_find->Text = L"Find";
			this->button_find->UseVisualStyleBackColor = false;
			this->button_find->Click += gcnew System::EventHandler(this, &MyForm::button_find_Click_1);
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button_add->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_add->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_add->Font = (gcnew System::Drawing::Font(L"Orbitron SemiBold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_add->ForeColor = System::Drawing::Color::White;
			this->button_add->Location = System::Drawing::Point(70, 35);
			this->button_add->Margin = System::Windows::Forms::Padding(0);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(133, 60);
			this->button_add->TabIndex = 12;
			this->button_add->Text = L"Add";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9
			});
			this->dataGridView1->Location = System::Drawing::Point(360, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(656, 455);
			this->dataGridView1->TabIndex = 26;
			this->dataGridView1->ColumnHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::dataGridView1_ColumnHeaderMouseClick);
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &MyForm::dataGridView1_SelectionChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Caption";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Company";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Type";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 150;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Price";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 150;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Width";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 150;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Length";
			this->Column6->MinimumWidth = 8;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 150;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Camera";
			this->Column7->MinimumWidth = 8;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 150;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"GPS";
			this->Column8->MinimumWidth = 8;
			this->Column8->Name = L"Column8";
			this->Column8->Width = 150;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Monitor";
			this->Column9->MinimumWidth = 8;
			this->Column9->Name = L"Column9";
			this->Column9->Width = 150;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1028, 660);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizey_inpt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizex_inpt))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void refill() { // ця функція використовується для перезаповнення таблиці зі списку гаджетів (vector<Gadget> GadgetList)
			dataGridView1->RowCount = 1; 
			for (int i = 0; i < GadgetList.size(); i++) {
				dataGridView1->RowCount++;
				for (int j = 0; j < 9; j++) {
					dataGridView1->Rows[i]->Cells[j]->Value = GadgetList[i].GetProperty(j); // заповнення полів таблиці, отриманими за індексом значеннями змінних класу Gadget
				}
			}
		}

		void clear() { // функція, для очищення всіх полів вводу
			capt_inpt->Text = "";
			comp_inpt->Text = "";
			price_inpt->Text = "";

			check_type_phone->Checked = false;
			check_type_tablet->Checked = false;
			check_type_watch->Checked = false;

			check_camera->Checked = false;
			check_gps->Checked = false;
			check_monitor->Checked = false;
			
		}

		void QuickSort(std::vector<Project11::Gadget>& arr, int low, int high, int variable) { // метод Швидкого сортування (використовується для прядку елементів у std::vector<Gadget> GadgetList)
			if (low < high) { 
				int pivotIndex = Partition(arr, low, high, variable);

				QuickSort(arr, low, pivotIndex - 1, variable); // рекурсивний виклик
				QuickSort(arr, pivotIndex + 1, high, variable);
				if (high > GadgetList.size()) {
					throw CIndexException("Wrong index, out of range");
				}
			}
		}

		int Partition(std::vector<Project11::Gadget>& arr, int low, int high, int variable) { // основна частина сортування 
			Project11::Gadget pivot = arr[high]; 
			int i = (low - 1);

			for (int j = low; j <= high - 1; j++) {
				if (variable == 0) { // визначення за яким стовпцем сортувати вектор
					if (arr[j].GetCaption() <= pivot.GetCaption()) { // сортування по назві
						i++;
						Swap(arr[i], arr[j]);
					}
				}
				else if (variable == 1) {
					if (arr[j].GetCompany() <= pivot.GetCompany()) { // сортування по назві компанії
						i++;
						Swap(arr[i], arr[j]);
					}
				}
				else if (variable == 2) {
					if (arr[j].GetType() <= pivot.GetType()) { // сортування по типу 
						i++;
						Swap(arr[i], arr[j]);
					}
				}
				else if (variable == 3) {
					if (arr[j].GetPrice() <= pivot.GetPrice()) { // сортування по ціні
						i++;
						Swap(arr[i], arr[j]);
					}
				}
			}

			Swap(arr[i + 1], arr[high]);
			return (i + 1);
		}

		void Swap(Project11::Gadget& a, Project11::Gadget& b) { // обмін місцями двох елементів  std::vector<Gadget> GadgetList
			Project11::Gadget temp = a;
			a = b;
			b = temp;
		}
		
		std::string ConvertToString(String^ managedString) { // функція для переведення типу String^ у тип std::string
			pin_ptr<const wchar_t> wch = PtrToStringChars(managedString);
			const wchar_t* wstr = wch;

			// Convert wchar_t to char
			std::wstring wstring(wstr);
			std::string nativeString(wstring.begin(), wstring.end());

			return nativeString;
		}

		String^ convertEnumToString(GType value) { // функція для переведення типу гаджету(enum GType) у тип std::string
			switch (value) {
			case Phone:
				return "Phone";
			case Tablet:
				return "Tablet";
			case Watch:
				return "Watch";
			default:
				return "Unknown";
			}
		}

	private: System::Void readToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // функція для зчитування списку гаджетів з файлу, та запис їх до таблиці та у список всіх гаджетів (std::vector<Gadget> GadgetList)
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog(); // створення діалогового вікна пошуку файлу, та деякі його налаштування
		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		String^ FileName = "";
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) { // відкриття діалогового вікна
			FileName = openFileDialog1->FileName;
		}
		try {
			StreamReader^ file = File::OpenText(FileName); // відкриття файлу
			String^ line;
			int index = dataGridView1->RowCount-1;
			while (!file->EndOfStream) {
				GType type1;
				line = file->ReadLine();
				Gadget* gadget = new Gadget(); // створення об'єкту нового гаджету
				array<Char>^ delimiters = { ' ', '*'};
				array<String^>^ words = line->Split(delimiters, StringSplitOptions::RemoveEmptyEntries);
				
				gadget->SetProperties(ConvertToString(words[0]), ConvertToString(words[1]), Double::Parse(words[3]), Double::Parse(words[4]), Double::Parse(words[5])); // заповнення частини полів гаджету з файлу

				for (int j = 6; j < words->Length; j++) { // встановлення додаткових функцій гаджету
					std::string type_string = ConvertToString(words[j]);
					if (type_string == "camera") { 
						gadget->SetAddition("camera");
					}
					else if (type_string == "GPS") {
						gadget->SetAddition("GPS");
					}
					else if (type_string == "monitor") {
						gadget->SetAddition("monitor");
					}
				}

				if (words[2] == "phone") { // встановлення типу гаджету записаного у файлі
					type1 = Phone;
				}
				else if (words[2] == "tablet") {
					type1 = Tablet;
				}
				else if (words[2] == "watch") {
					type1 = Watch;
				}

				gadget->SetType(type1); // задання типу гаджету
				

				GadgetList.push_back(*gadget); // додання створеного гаджету до списку всіх гаджетів
				index++;
			}
			refill(); // оновлення таблиці
			file->Close(); // закриття файлу
		}
		catch (Exception^ exception) {
			MessageBox::Show(this, "File was not opened", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void writeCtrlWToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // виведення (збереження всього списку гаджетів до файлу)

		OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog(); // створення діалогового вікна пошуку файлу, та деякі його налаштування
		openFileDialog2->InitialDirectory = "c:\\";
		openFileDialog2->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog2->FilterIndex = 2;
		openFileDialog2->RestoreDirectory = true;
		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) { // відкриття діалогового вікна
			std::ofstream fout;
			fout.open(msclr::interop::marshal_as<std::string>(openFileDialog2->FileName)); // відкриття файлу
			fout.clear();
	
			for (int i = 0; i < GadgetList.size(); i++) {
				fout << GadgetList[i]; // виведення всіх гаджетів зі списку до файлу
			}
			fout.close(); // закриття файлу
		}
		
	}
	private: System::Void exiteAltF4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // фуекція для закриття форми
		this->Close();
	}


	private: System::Void fillToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // заповнення таблиці
		refill(); 
	}
	private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // очищення таблиці 
		dataGridView1->Rows->Clear();
	}


	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // функція, що виводить підказки для можливого вирішення проблеми
		MessageBox::Show(this, "1. If something wrong, try restart program. \n2. Try to clear and fill the table.\n3. Check whether your requested feature is written correctly. ", "Your help", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	 //наступні три функції використовуються для того щоб користувач не міг вибрати більше одного типу гаджету одночасно
	private: System::Void check_type_phone_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (check_type_phone->Checked) {
			check_type_tablet->Checked = false;
			check_type_watch->Checked = false;
		}

	}
	private: System::Void check_type_tablet_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (check_type_tablet->Checked) {
			check_type_phone->Checked = false;
			check_type_watch->Checked = false;
		}

	}
	private: System::Void check_type_watch_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (check_type_watch->Checked) {
			check_type_phone->Checked = false;
			check_type_tablet->Checked = false;
		}
	}


	private: System::Void button_add_Click_1(System::Object^ sender, System::EventArgs^ e) { // функція додавання до списку гаджетів нового гаджету

		//перевірка на введення всіх обов'язкових полів для створення нового об'єкту Gadget
		try {
			if (capt_inpt->Text == "") {
				throw CInputException("Didn`t manage to read the name of gadget");
			}
			if (comp_inpt->Text == "") {
				throw CInputException("Didn`t manage to read the company name of gadget");
			}
			if (check_type_phone->Checked == false && check_type_tablet->Checked == false && check_type_watch->Checked == false) {
				throw CInputException("Didn`t manage to check the type of gadget");
			}
			if (price_inpt->Text == "") {
				throw CInputException("Didn`t manage to read the price of gadget");
			}
			if (sizex_inpt->Value == 0) {
				throw CInputException("Didn`t manage to read the width of gadget");
			}
			if (sizey_inpt->Value == 0) {
				throw CInputException("Didn`t manage to read the length of gadget");
			}

			std::string price_str = msclr::interop::marshal_as<std::string>(price_inpt->Text);
			GType type1;
			double price = 0;
			Double::TryParse(gcnew String(price_str.c_str()), price); // перетворення ціни з типу вінформ (System::String ^System::Froms::TextBox::Text) до типу (double)

			if (check_type_phone->Checked) { // зчитування введеного типу гаджету
				type1 = Phone;
			}
			else if (check_type_tablet->Checked) {
				type1 = Tablet;
			}
			else if (check_type_watch->Checked) {
				type1 = Watch;
			}

			//заповнення полів нового об'єкту Gadget
			Gadget* gadget1 = new Gadget(marshal_as<std::string>(capt_inpt->Text), marshal_as<std::string>(comp_inpt->Text), type1, price, Decimal::ToDouble(sizex_inpt->Value), Decimal::ToDouble(sizey_inpt->Value), check_camera->Checked, check_gps->Checked, check_monitor->Checked);
			GadgetList.push_back(*gadget1); //додавання нового об'єкту Gadget до списку
			dataGridView1->Rows->Clear();
			refill();
		}
		catch (const CInputException& exception) {
			MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (const std::exception& exception)
		{
			MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (...)
		{
			MessageBox::Show(this, "Something went wrong", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	private: System::Void button_delete_Click_1(System::Object^ sender, System::EventArgs^ e) { //функція видалення вибраного елменту зі списку гаджетів
		if (dataGridView1->SelectedRows->Count > 0) { // перевірка, чи елемент вибрано
			int i = GadgetList.size() - 1;
			int selectedIndex = dataGridView1->SelectedRows[0]->Index; // знаходження вибраного елементу

			dataGridView1->RowCount--;
			for (int k = selectedIndex; k < dataGridView1->RowCount-1; k++) { // очищення таблиці від вибраного елементу
				for (int j = 0; j < 9; j++) {
					dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[k + 1].GetProperty(j);
				}
			}

			std::vector<Gadget> GadgetListbuffer;

			if (selectedIndex < GadgetList.size()) { // видалення вибраного елементу зі списку гаджетів
				while (i >= selectedIndex) {
					if (i == selectedIndex) {
						GadgetList.pop_back();
					}
					else {
						GadgetListbuffer.push_back(GadgetList[i]);
						GadgetList.pop_back();
					}
					i--;
				}
				i = GadgetListbuffer.size() - 1;
				while (i >= 0) {
					GadgetList.push_back(GadgetListbuffer[i]);
					GadgetListbuffer.pop_back();
					i--;
				}
			}

		}else {
			MessageBox::Show(this, "You have not chosen any element", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
	}
	private: System::Void button_modify_Click_1(System::Object^ sender, System::EventArgs^ e) { // функція редагування вибраного гаджету
		if (dataGridView1->SelectedRows->Count > 0) { // перевірка, чи елемент вибрано
			int selectedIndex = dataGridView1->SelectedRows[0]->Index;// знаходження вибраного елементу

			//зчитування всіх полів(змін які було введено)
			std::string price_str = msclr::interop::marshal_as<std::string>(price_inpt->Text);
			GType type1;
			double price = 0;
			Double::TryParse(gcnew String(price_str.c_str()), price); 

			if (check_type_phone->Checked) {
				type1 = Phone;
			}
			else if (check_type_tablet->Checked) {
				type1 = Tablet;
			}
			else if (check_type_watch->Checked) {
				type1 = Watch;
			}

			Gadget* gadget1 = new Gadget(marshal_as<std::string>(capt_inpt->Text), marshal_as<std::string>(comp_inpt->Text), type1, price, Decimal::ToDouble(sizex_inpt->Value), Decimal::ToDouble(sizey_inpt->Value), check_camera->Checked, check_gps->Checked, check_monitor->Checked);
			
			GadgetList[selectedIndex] = *gadget1; // додавання змін до вибраного елементу
			for (int j = 0; j < 9; j++) { // оновлення таблиці
				dataGridView1->Rows[selectedIndex]->Cells[j]->Value = GadgetList[selectedIndex].GetProperty(j);
			}

		}else {
			MessageBox::Show(this, "You have not chosen any element", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	private: System::Void button_find_Click_1(System::Object^ sender, System::EventArgs^ e) {

		int k = 0, type_check = 0;
		String^ type1;

		if (check_type_phone->Checked) { // зчитування введеного типу гаджету
			type1 = "phone";
			type_check++;
		}
		else if (check_type_tablet->Checked) {
			type1 = "tablet";
			type_check++;
		}
		else if (check_type_watch->Checked) {
			type1 = "watch";
			type_check++;
		}

		if (capt_inpt->Text == "" && comp_inpt->Text == "" && type_check == 0) { // перевірка, вивведено хочаб один критерій пошуку
			MessageBox::Show(this, "You have not entered any of arguments  (caption, company or type) ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		dataGridView1->Rows->Clear(); // очищення таблиці, перед виводом знайдених елементів
		
		String^ comp_text = comp_inpt->Text;
		String^ capt_text = capt_inpt->Text;

		dataGridView1->RowCount = 1;
		for (int i = 0; i < GadgetList.size(); i++) {// пошук елементів посписку
			if (capt_inpt->Text == "" && comp_inpt->Text == "") { // пошук лише за типом
				if (type1 == GadgetList[i].GetProperty(2)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else if (capt_inpt->Text == "" && type_check == 0) { // пошук лише за назвою компанії
				if (comp_text == GadgetList[i].GetProperty(1)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else if (comp_inpt->Text == "" && type_check == 0) { // пошук лише за назвою гаджету
				if (capt_text == GadgetList[i].GetProperty(0)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else if (capt_inpt->Text == "" ) { // пошук за назвою компанії та за типом
				if (comp_text == GadgetList[i].GetProperty(1) && type1 == GadgetList[i].GetProperty(2)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else if (comp_inpt->Text == "") { // пошук за назвою гаджету та за типом
				if (capt_text == GadgetList[i].GetProperty(0) && type1 == GadgetList[i].GetProperty(2)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else if (type_check == 0) { // пошук за назвою гаджету та за назвою компанії
				if (capt_text == GadgetList[i].GetProperty(0) && comp_text == GadgetList[i].GetProperty(1)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
			else { // пошук за назвою гаджету, за назвою компанії та за типом
				if (capt_text == GadgetList[i].GetProperty(0) && comp_text == GadgetList[i].GetProperty(1) && type1 == GadgetList[i].GetProperty(2)) {
					dataGridView1->RowCount++;
					for (int j = 0; j < 9; j++) {
						dataGridView1->Rows[k]->Cells[j]->Value = GadgetList[i].GetProperty(j);
					}
					k++;
				}
			}
		}
	}


	private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) { //функція для автоматичного заповнення полів вводу при воборі елементу
		if (dataGridView1->SelectedRows->Count > 0) { // перевірка, чи елемент вибрано

			int selectedIndex = dataGridView1->SelectedRows[0]->Index; // знаходження вибраного елементу
			clear();

			capt_inpt->Text += dataGridView1->Rows[selectedIndex]->Cells[0]->Value;  // заповнення всіх полів
			comp_inpt->Text += dataGridView1->Rows[selectedIndex]->Cells[1]->Value;

			if (dataGridView1->Rows[selectedIndex]->Cells[2]->Value->ToString() == "phone") {
				check_type_phone->Checked = true;
			}
			else if (dataGridView1->Rows[selectedIndex]->Cells[2]->Value->ToString() == "tablet") {
				check_type_tablet->Checked = true;
			}
			else if (dataGridView1->Rows[selectedIndex]->Cells[2]->Value->ToString() == "watch") {
				check_type_watch->Checked = true;
			}

			price_inpt->Text += dataGridView1->Rows[selectedIndex]->Cells[3]->Value;

			
			sizex_inpt->Value = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells[4]->Value);
			sizey_inpt->Value = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells[5]->Value);

			if (dataGridView1->Rows[selectedIndex]->Cells[6]->Value == "camera") {
				check_camera->Checked = true;
			}
			if (dataGridView1->Rows[selectedIndex]->Cells[7]->Value == "GPS") {
				check_gps->Checked = true;
			}
			if (dataGridView1->Rows[selectedIndex]->Cells[8]->Value == "monitor") {
				check_monitor->Checked = true;
			}
			
		}
	}
	private: System::Void dataGridView1_ColumnHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) { // функція сортування за вибраним параметром по кліку на назву параметру в таблиці
		
		if (e->ColumnIndex > -1 && e->ColumnIndex < 4) { // перевірка, чи вибраний назва відповідає можливим параметрам, за якими може бути посортовано список гаджетів
			try {
				int vectorSize = GadgetList.size();
				QuickSort(GadgetList, 0, vectorSize - 1, e->ColumnIndex); // запуск Швидкого сортування, аргументи : (перший, крайній елементи, вибраний параметр сортування)
			}
			catch (const CIndexException& exception) {
				MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			catch (const std::exception& exception)
			{
				MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			catch (...)
			{
				MessageBox::Show(this, "Something went wrong", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			
			
		}
	}
	private: System::Void sortPricequickToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Швидке сортування елементів у списку гаджетів за ціною

		try {
			int vectorSize = GadgetList.size();
			QuickSort(GadgetList, 0, vectorSize - 1, 3); // запуск Швидкого сортування, аргументи : (перший, крайній елементи, вибраний параметр сортування)
		}
		catch (const CIndexException& exception) {
			MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (const std::exception& exception)
		{
			MessageBox::Show(this, "The problem is: " + msclr::interop::marshal_as<String^>(exception.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (...)
		{
			MessageBox::Show(this, "Something went wrong", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
	}
	

	private: System::Void findSizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // функція для пошуку всіх елементів розміри яких відповідають заданим в новій створеній формі
		SizeForm obj;
		obj.ShowDialog(); // створення нової форми
		dataGridView1->RowCount = 1;
		int x_current = 0, y_current = 0;

		for (int i = 0; i < GadgetList.size(); i++) {
			Int32::TryParse(GadgetList[i].GetProperty(4), x_current); // приведення розмірів окремого елементу списку до int та запис у змінні ( x_current , y_current )
			Int32::TryParse(GadgetList[i].GetProperty(5), y_current);
			if ((obj.varieble->GetVariable(0) < x_current && x_current < obj.varieble->GetVariable(1)) && (obj.varieble->GetVariable(2) < y_current && y_current < obj.varieble->GetVariable(3))) { // перевірка відповідності елементу заданим розмірам
				dataGridView1->RowCount++;
				for (int j = 0; j < 9; j++) { //виведення знайденого елементу до таблиці
					dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[j]->Value = GadgetList[i].GetProperty(j);
				}

			}
			
		}
		
	}
	private: System::Void groupByCompanyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // функція для групування гаджетів певного типу за назвою та запис їх у окремий файл
		int k = 0, type_check = 0;
		std::string type1;

		if (check_type_phone->Checked) { // зчитування введеного типу гаджету
			type1 = "phone";
			type_check++;
		}
		else if (check_type_tablet->Checked) {
			type1 = "tablet";
			type_check++;
		}
		else if (check_type_watch->Checked) {
			type1 = "watch";
			type_check++;
		}

		if (comp_inpt->Text == "" || type_check == 0) { // перевірка, xb вивведено назву компанії та тип
			MessageBox::Show(this, "You have not entered enough arguments  (caption or type) ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog(); // створення діалогового вікна пошуку файлу, та деякі його налаштування
		openFileDialog2->InitialDirectory = "c:\\";
		openFileDialog2->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog2->FilterIndex = 2;
		openFileDialog2->RestoreDirectory = true;
		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) { // відкриття діалогового вікна
			std::ofstream fout;
			fout.open(msclr::interop::marshal_as<std::string>(openFileDialog2->FileName)); // відкриття файлу
			fout.clear();

			for (int i = 0; i < GadgetList.size(); i++) {
				if (GadgetList[i].GetCompany() == ConvertToString(comp_inpt->Text) && GadgetList[i].GetType() == type1) {
					fout << GadgetList[i]; // виведення всіх гаджетів зі списку до файлу
				}
			}
			fout.close(); // закриття файлу
		}

	}



};

}
