#pragma once

#include "TrackerMod.h"

namespace lazyslash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CompoWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CompoWindow : public System::Windows::Forms::Form
	{
	public:
		CompoWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CompoWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  entriesTab;

	protected: 

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  entriesLabel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListView^  entriesList;
	private: System::Windows::Forms::Button^  createzipButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ColumnHeader^  columnHeader0;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  pasteButton;
	private: System::Windows::Forms::Button^  addVoterButton;
	private: System::Windows::Forms::ListView^  voteList;
	private: System::Windows::Forms::Button^  exportButton;
	private: System::Windows::Forms::Button^  viewButton;


	protected: 

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->entriesTab = (gcnew System::Windows::Forms::TabPage());
			this->createzipButton = (gcnew System::Windows::Forms::Button());
			this->entriesList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->entriesLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->exportButton = (gcnew System::Windows::Forms::Button());
			this->viewButton = (gcnew System::Windows::Forms::Button());
			this->pasteButton = (gcnew System::Windows::Forms::Button());
			this->addVoterButton = (gcnew System::Windows::Forms::Button());
			this->voteList = (gcnew System::Windows::Forms::ListView());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1->SuspendLayout();
			this->entriesTab->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->entriesTab);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(438, 314);
			this->tabControl1->TabIndex = 0;
			// 
			// entriesTab
			// 
			this->entriesTab->Controls->Add(this->createzipButton);
			this->entriesTab->Controls->Add(this->entriesList);
			this->entriesTab->Controls->Add(this->textBox1);
			this->entriesTab->Controls->Add(this->label1);
			this->entriesTab->Controls->Add(this->entriesLabel);
			this->entriesTab->Location = System::Drawing::Point(4, 22);
			this->entriesTab->Name = L"entriesTab";
			this->entriesTab->Padding = System::Windows::Forms::Padding(3);
			this->entriesTab->Size = System::Drawing::Size(406, 276);
			this->entriesTab->TabIndex = 0;
			this->entriesTab->Text = L"Entries";
			this->entriesTab->UseVisualStyleBackColor = true;
			// 
			// createzipButton
			// 
			this->createzipButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->createzipButton->Location = System::Drawing::Point(7, 247);
			this->createzipButton->Name = L"createzipButton";
			this->createzipButton->Size = System::Drawing::Size(143, 23);
			this->createzipButton->TabIndex = 4;
			this->createzipButton->Text = L"Create votepack .ZIP";
			this->createzipButton->UseVisualStyleBackColor = true;
			// 
			// entriesList
			// 
			this->entriesList->AllowDrop = true;
			this->entriesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->entriesList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader0, 
				this->columnHeader1, this->columnHeader2, this->columnHeader3});
			this->entriesList->Location = System::Drawing::Point(6, 31);
			this->entriesList->Name = L"entriesList";
			this->entriesList->Size = System::Drawing::Size(394, 210);
			this->entriesList->TabIndex = 3;
			this->entriesList->UseCompatibleStateImageBehavior = false;
			this->entriesList->View = System::Windows::Forms::View::Details;
			this->entriesList->SelectedIndexChanged += gcnew System::EventHandler(this, &CompoWindow::entriesList_SelectedIndexChanged);
			this->entriesList->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &CompoWindow::entriesList_Drop);
			this->entriesList->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &CompoWindow::entriesList_DragEnter);
			// 
			// columnHeader0
			// 
			this->columnHeader0->Text = L"Voted";
			this->columnHeader0->Width = 41;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Nick";
			this->columnHeader1->Width = 73;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Filename";
			this->columnHeader2->Width = 95;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Song name";
			this->columnHeader3->Width = 184;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(188, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(212, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(110, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Compo name:";
			// 
			// entriesLabel
			// 
			this->entriesLabel->AutoSize = true;
			this->entriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->entriesLabel->Location = System::Drawing::Point(3, 3);
			this->entriesLabel->Name = L"entriesLabel";
			this->entriesLabel->Size = System::Drawing::Size(66, 20);
			this->entriesLabel->TabIndex = 0;
			this->entriesLabel->Text = L"Entries";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->exportButton);
			this->tabPage2->Controls->Add(this->viewButton);
			this->tabPage2->Controls->Add(this->pasteButton);
			this->tabPage2->Controls->Add(this->addVoterButton);
			this->tabPage2->Controls->Add(this->voteList);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(430, 288);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Voters";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// exportButton
			// 
			this->exportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exportButton->Location = System::Drawing::Point(88, 259);
			this->exportButton->Name = L"exportButton";
			this->exportButton->Size = System::Drawing::Size(75, 23);
			this->exportButton->TabIndex = 9;
			this->exportButton->Text = L"Export TXT";
			this->exportButton->UseVisualStyleBackColor = true;
			// 
			// viewButton
			// 
			this->viewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->viewButton->Location = System::Drawing::Point(7, 259);
			this->viewButton->Name = L"viewButton";
			this->viewButton->Size = System::Drawing::Size(75, 23);
			this->viewButton->TabIndex = 8;
			this->viewButton->Text = L"View results";
			this->viewButton->UseVisualStyleBackColor = true;
			// 
			// pasteButton
			// 
			this->pasteButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->pasteButton->Location = System::Drawing::Point(349, 144);
			this->pasteButton->Margin = System::Windows::Forms::Padding(3, 50, 3, 60);
			this->pasteButton->Name = L"pasteButton";
			this->pasteButton->Size = System::Drawing::Size(75, 23);
			this->pasteButton->TabIndex = 7;
			this->pasteButton->Text = L"Paste";
			this->pasteButton->UseVisualStyleBackColor = true;
			this->pasteButton->Click += gcnew System::EventHandler(this, &CompoWindow::pasteButton_Click);
			// 
			// addVoterButton
			// 
			this->addVoterButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->addVoterButton->Location = System::Drawing::Point(349, 115);
			this->addVoterButton->Margin = System::Windows::Forms::Padding(3, 50, 3, 60);
			this->addVoterButton->Name = L"addVoterButton";
			this->addVoterButton->Size = System::Drawing::Size(75, 23);
			this->addVoterButton->TabIndex = 6;
			this->addVoterButton->Text = L"Add";
			this->addVoterButton->UseVisualStyleBackColor = true;
			this->addVoterButton->Click += gcnew System::EventHandler(this, &CompoWindow::addVoterButton_Click);
			// 
			// voteList
			// 
			this->voteList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->voteList->Location = System::Drawing::Point(6, 31);
			this->voteList->Name = L"voteList";
			this->voteList->Size = System::Drawing::Size(337, 222);
			this->voteList->TabIndex = 5;
			this->voteList->UseCompatibleStateImageBehavior = false;
			this->voteList->View = System::Windows::Forms::View::Details;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(188, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(110, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Compo name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Voters";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(438, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newToolStripMenuItem, 
				this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->newToolStripMenuItem->Text = L"&New";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->saveAsToolStripMenuItem->Text = L"Save &As...";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			// 
			// CompoWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 341);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CompoWindow";
			this->Text = L"CompoWindow";
			this->Load += gcnew System::EventHandler(this, &CompoWindow::CompoWindow_Load);
			this->tabControl1->ResumeLayout(false);
			this->entriesTab->ResumeLayout(false);
			this->entriesTab->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void CompoWindow_Load(System::Object^  sender, System::EventArgs^  e)
		{
		}

		private: System::Void entriesList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
		}

		private: System::Void entriesList_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
		{
			if (e->Data->GetDataPresent(DataFormats::FileDrop))
			{
				e->Effect = DragDropEffects::Copy;
			}
			else
			{
				e->Effect = DragDropEffects::None;
			}			
		}

		private: System::Void entriesList_Drop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
		{
			array<String^>^ files;

			if (!e->Data->GetDataPresent(System::Windows::Forms::DataFormats::FileDrop))
			{
				return;
			}

			files = (array<String^>^)(e->Data->GetData(System::Windows::Forms::DataFormats::FileDrop));

			for each (String^ file in files)
			{
				String^ filename = System::IO::Path::GetFileName(file);

				String^ songtitle = TrackerMod::GetSongTitle(file)->TrimEnd(nullptr);
				
				this->entriesList->Items->Add(gcnew ListViewItem(gcnew array<String^>{"", "", filename, songtitle}));
			}
		}

		private: System::Void addVoterButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
		}

		private: System::Void pasteButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
		}

	};
}

