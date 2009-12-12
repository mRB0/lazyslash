#pragma once

/*
 * $Id$
 */

#include "TrackerMod.h"
#include "ListViewItemComparer.h"
#include "CompoEntry.h"
#include "EntryEditor.h"
#include "VoteEntry.h"
#include "VoteData.h"
#include "ResultsCalc.h"
#include "ResultsDisplay.h"
#include "compoversion.h"
#include "VoteParseSelection.h"

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

			this->open_new();

			//(gcnew VoteParseSelection)->ShowDialog();
		}


	protected:

		String^ zipfilePath;
		String^ txtfilePath;
		String^ savefilePath;

		System::Windows::Forms::ListViewItem^ _empty_item;
		bool sort_ascending;
	private: System::Windows::Forms::ContextMenuStrip^  entriesMenuStrip;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::Label^  zipErrorLabel;
	private: System::Windows::Forms::ContextMenuStrip^  votesMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  exportTxtLabel;
	private: System::Windows::Forms::ToolStripMenuItem^  addNewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;


			 int sort_col;

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
	private: System::Windows::Forms::TextBox^  txtCompoName1;

	private: System::Windows::Forms::ListView^  entriesList;
	private: System::Windows::Forms::Button^  createzipButton;
	private: System::Windows::Forms::MenuStrip^  mainMenuStrip;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ColumnHeader^  columnHeader0;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::TextBox^  txtCompoName2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::ListView^  voteList;
	private: System::Windows::Forms::Button^  exportButton;
	private: System::Windows::Forms::Button^  viewButton;
	private: System::ComponentModel::IContainer^  components;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CompoWindow::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->entriesTab = (gcnew System::Windows::Forms::TabPage());
			this->zipErrorLabel = (gcnew System::Windows::Forms::Label());
			this->createzipButton = (gcnew System::Windows::Forms::Button());
			this->entriesList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->entriesMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtCompoName1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->entriesLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->exportTxtLabel = (gcnew System::Windows::Forms::Label());
			this->exportButton = (gcnew System::Windows::Forms::Button());
			this->viewButton = (gcnew System::Windows::Forms::Button());
			this->voteList = (gcnew System::Windows::Forms::ListView());
			this->votesMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtCompoName2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1->SuspendLayout();
			this->entriesTab->SuspendLayout();
			this->entriesMenuStrip->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->votesMenuStrip->SuspendLayout();
			this->mainMenuStrip->SuspendLayout();
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
			this->tabControl1->Selecting += gcnew System::Windows::Forms::TabControlCancelEventHandler(this, &CompoWindow::tabControl1_Selecting);
			// 
			// entriesTab
			// 
			this->entriesTab->Controls->Add(this->zipErrorLabel);
			this->entriesTab->Controls->Add(this->createzipButton);
			this->entriesTab->Controls->Add(this->entriesList);
			this->entriesTab->Controls->Add(this->txtCompoName1);
			this->entriesTab->Controls->Add(this->label1);
			this->entriesTab->Controls->Add(this->entriesLabel);
			this->entriesTab->Location = System::Drawing::Point(4, 22);
			this->entriesTab->Name = L"entriesTab";
			this->entriesTab->Padding = System::Windows::Forms::Padding(3);
			this->entriesTab->Size = System::Drawing::Size(430, 288);
			this->entriesTab->TabIndex = 0;
			this->entriesTab->Text = L"Entries";
			this->entriesTab->UseVisualStyleBackColor = true;
			// 
			// zipErrorLabel
			// 
			this->zipErrorLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->zipErrorLabel->AutoSize = true;
			this->zipErrorLabel->Location = System::Drawing::Point(126, 262);
			this->zipErrorLabel->Name = L"zipErrorLabel";
			this->zipErrorLabel->Size = System::Drawing::Size(85, 13);
			this->zipErrorLabel->TabIndex = 5;
			this->zipErrorLabel->Text = L"duck duck duck";
			this->zipErrorLabel->Click += gcnew System::EventHandler(this, &CompoWindow::zipErrorLabel_Click);
			// 
			// createzipButton
			// 
			this->createzipButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->createzipButton->Location = System::Drawing::Point(6, 257);
			this->createzipButton->Name = L"createzipButton";
			this->createzipButton->Size = System::Drawing::Size(114, 23);
			this->createzipButton->TabIndex = 4;
			this->createzipButton->Text = L"Create &votepack";
			this->createzipButton->UseVisualStyleBackColor = true;
			this->createzipButton->Click += gcnew System::EventHandler(this, &CompoWindow::createzipButton_Click);
			// 
			// entriesList
			// 
			this->entriesList->AllowColumnReorder = true;
			this->entriesList->AllowDrop = true;
			this->entriesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->entriesList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader0, 
				this->columnHeader1, this->columnHeader2, this->columnHeader3});
			this->entriesList->ContextMenuStrip = this->entriesMenuStrip;
			this->entriesList->LabelWrap = false;
			this->entriesList->Location = System::Drawing::Point(6, 31);
			this->entriesList->Name = L"entriesList";
			this->entriesList->Size = System::Drawing::Size(416, 220);
			this->entriesList->TabIndex = 3;
			this->entriesList->UseCompatibleStateImageBehavior = false;
			this->entriesList->View = System::Windows::Forms::View::Details;
			this->entriesList->ItemActivate += gcnew System::EventHandler(this, &CompoWindow::entriesList_ItemActivate);
			this->entriesList->SelectedIndexChanged += gcnew System::EventHandler(this, &CompoWindow::entriesList_SelectedIndexChanged);
			this->entriesList->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &CompoWindow::entriesList_Drop);
			this->entriesList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &CompoWindow::entriesList_ColumnClick);
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
			// entriesMenuStrip
			// 
			this->entriesMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->addNewToolStripMenuItem, 
				this->removeToolStripMenuItem, this->copyToolStripMenuItem});
			this->entriesMenuStrip->Name = L"entriesMenuStrip";
			this->entriesMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->entriesMenuStrip->Size = System::Drawing::Size(219, 70);
			this->entriesMenuStrip->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &CompoWindow::entriesMenuStrip_Opening);
			// 
			// addNewToolStripMenuItem
			// 
			this->addNewToolStripMenuItem->Name = L"addNewToolStripMenuItem";
			this->addNewToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->addNewToolStripMenuItem->Size = System::Drawing::Size(218, 22);
			this->addNewToolStripMenuItem->Text = L"&Add new...";
			this->addNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::addNewToolStripMenuItem_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->removeToolStripMenuItem->Size = System::Drawing::Size(218, 22);
			this->removeToolStripMenuItem->Text = L"&Remove";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::removeToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(218, 22);
			this->copyToolStripMenuItem->Text = L"Copy filename/title";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::copyToolStripMenuItem_Click);
			// 
			// txtCompoName1
			// 
			this->txtCompoName1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtCompoName1->Location = System::Drawing::Point(188, 5);
			this->txtCompoName1->Name = L"txtCompoName1";
			this->txtCompoName1->Size = System::Drawing::Size(234, 20);
			this->txtCompoName1->TabIndex = 2;
			this->txtCompoName1->TextChanged += gcnew System::EventHandler(this, &CompoWindow::txtCompoName1_TextChanged);
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
			this->tabPage2->Controls->Add(this->exportTxtLabel);
			this->tabPage2->Controls->Add(this->exportButton);
			this->tabPage2->Controls->Add(this->viewButton);
			this->tabPage2->Controls->Add(this->voteList);
			this->tabPage2->Controls->Add(this->txtCompoName2);
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
			// exportTxtLabel
			// 
			this->exportTxtLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exportTxtLabel->AutoSize = true;
			this->exportTxtLabel->Enabled = false;
			this->exportTxtLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->exportTxtLabel->ForeColor = System::Drawing::Color::Blue;
			this->exportTxtLabel->Location = System::Drawing::Point(168, 262);
			this->exportTxtLabel->Name = L"exportTxtLabel";
			this->exportTxtLabel->Size = System::Drawing::Size(114, 13);
			this->exportTxtLabel->TabIndex = 10;
			this->exportTxtLabel->Text = L"Open containing folder";
			this->exportTxtLabel->Click += gcnew System::EventHandler(this, &CompoWindow::exportTxtLabel_Click);
			// 
			// exportButton
			// 
			this->exportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exportButton->Location = System::Drawing::Point(87, 257);
			this->exportButton->Name = L"exportButton";
			this->exportButton->Size = System::Drawing::Size(75, 23);
			this->exportButton->TabIndex = 9;
			this->exportButton->Text = L"E&xport TXT";
			this->exportButton->UseVisualStyleBackColor = true;
			this->exportButton->Click += gcnew System::EventHandler(this, &CompoWindow::exportButton_Click);
			// 
			// viewButton
			// 
			this->viewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->viewButton->Location = System::Drawing::Point(6, 257);
			this->viewButton->Name = L"viewButton";
			this->viewButton->Size = System::Drawing::Size(75, 23);
			this->viewButton->TabIndex = 8;
			this->viewButton->Text = L"View &results";
			this->viewButton->UseVisualStyleBackColor = true;
			this->viewButton->Click += gcnew System::EventHandler(this, &CompoWindow::viewButton_Click);
			// 
			// voteList
			// 
			this->voteList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->voteList->ContextMenuStrip = this->votesMenuStrip;
			this->voteList->LabelEdit = true;
			this->voteList->Location = System::Drawing::Point(6, 31);
			this->voteList->Name = L"voteList";
			this->voteList->Size = System::Drawing::Size(416, 220);
			this->voteList->TabIndex = 5;
			this->voteList->UseCompatibleStateImageBehavior = false;
			this->voteList->View = System::Windows::Forms::View::Details;
			this->voteList->DoubleClick += gcnew System::EventHandler(this, &CompoWindow::voteList_DoubleClick);
			this->voteList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &CompoWindow::voteList_ColumnClick);
			// 
			// votesMenuStrip
			// 
			this->votesMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem, 
				this->pasteToolStripMenuItem});
			this->votesMenuStrip->Name = L"votesMenuStrip";
			this->votesMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->votesMenuStrip->Size = System::Drawing::Size(173, 48);
			this->votesMenuStrip->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &CompoWindow::votesMenuStrip_Opening);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->addToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->addToolStripMenuItem->Text = L"&Add new...";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::addToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->pasteToolStripMenuItem->Text = L"&Paste...";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::pasteToolStripMenuItem_Click);
			// 
			// txtCompoName2
			// 
			this->txtCompoName2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtCompoName2->Location = System::Drawing::Point(188, 5);
			this->txtCompoName2->Name = L"txtCompoName2";
			this->txtCompoName2->Size = System::Drawing::Size(234, 20);
			this->txtCompoName2->TabIndex = 4;
			this->txtCompoName2->TextChanged += gcnew System::EventHandler(this, &CompoWindow::txtCompoName2_TextChanged);
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
			// mainMenuStrip
			// 
			this->mainMenuStrip->BackColor = System::Drawing::SystemColors::Control;
			this->mainMenuStrip->ImageScalingSize = System::Drawing::Size(0, 0);
			this->mainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mainMenuStrip->Name = L"mainMenuStrip";
			this->mainMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->mainMenuStrip->Size = System::Drawing::Size(438, 24);
			this->mainMenuStrip->TabIndex = 1;
			this->mainMenuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->newToolStripMenuItem, 
				this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator2, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->newToolStripMenuItem->Text = L"&New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveAsToolStripMenuItem->Text = L"Save &As...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::saveAsToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(143, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::exitToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::aboutToolStripMenuItem_Click);
			// 
			// CompoWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 341);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->mainMenuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mainMenuStrip;
			this->Name = L"CompoWindow";
			this->Text = L"lazyslash compomagoo";
			this->Load += gcnew System::EventHandler(this, &CompoWindow::CompoWindow_Load);
			this->tabControl1->ResumeLayout(false);
			this->entriesTab->ResumeLayout(false);
			this->entriesTab->PerformLayout();
			this->entriesMenuStrip->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->votesMenuStrip->ResumeLayout(false);
			this->mainMenuStrip->ResumeLayout(false);
			this->mainMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void match_entrylist_to_entry(System::Windows::Forms::ListViewItem^ edititem)
		{
			CompoEntry^ ce = (CompoEntry^)(edititem->Tag);
			edititem->SubItems[0]->Text = "";
			edititem->SubItems[1]->Text = ce->composer;
			edititem->SubItems[2]->Text = ce->filename;
			edititem->SubItems[3]->Text = ce->songtitle;
			//ce->songtitle
		}

		private: System::Void check_zip_button(void)
		{
			if (this->entriesList->Items->Count <= 1)
			{
				this->createzipButton->Enabled = false;
				this->zipErrorLabel->Text = L"Drag files into the list";
			}
			else
			{
				bool canzip = true;

				for each (System::Windows::Forms::ListViewItem^ lvi in this->entriesList->Items)
				{
					if (lvi != this->_empty_item)
					{
						if (((CompoEntry^)(lvi->Tag))->filespec == L"")
						{
							canzip = false;
						}
					}
				}
				if (canzip)
				{
					this->zipErrorLabel->Text = L"Boy! Eucalyptus!";
					this->createzipButton->Enabled = true;
				}
				else
				{
					this->zipErrorLabel->Text = L"All entries require a full path for zipping!";
					this->createzipButton->Enabled = false;
				}

			}

			if (this->zipfilePath != nullptr)
			{
				this->zipErrorLabel->Text = "Open containing folder";
				//this->zipErrorLabel->Enabled = true;
				this->zipErrorLabel->Cursor = System::Windows::Forms::Cursors::Hand;
				this->zipErrorLabel->ForeColor = System::Drawing::Color::Blue;
				this->zipErrorLabel->Font = gcnew System::Drawing::Font(
					this->zipErrorLabel->Font->Name,
					this->zipErrorLabel->Font->Size,
					System::Drawing::FontStyle::Underline,
					this->zipErrorLabel->Font->Unit);
				
			}
			else
			{
				//this->zipErrorLabel->Enabled = false;
				this->zipErrorLabel->Cursor = System::Windows::Forms::Cursors::Default;
				this->zipErrorLabel->ForeColor = System::Drawing::Color::Black;
			}
		}

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
			
			this->entriesList->Items->Remove(this->_empty_item);

			ListViewItem^ new_item;

			for each (String^ file in files)
			{
				String^ filename = System::IO::Path::GetFileName(file);

				String^ songtitle = TrackerMod::GetSongTitle(file)->TrimEnd(nullptr);
				//int songlen = songtitle->Length;
				
				new_item = gcnew ListViewItem(gcnew array<String^>{"", "", filename, songtitle});
				new_item->Tag = gcnew CompoEntry(file, songtitle);

				this->entriesList->Items->Add(new_item);
				this->match_entrylist_to_entry(new_item);
			}

			if (files->Length == 1)
			{
				// go directly to edit item if there is only one thing dropped

				ArrayList^ songs = gcnew ArrayList;
				ArrayList^ entrants = gcnew ArrayList;
				get_current_songs_entrants(songs, entrants);

				EntryEditor ee((CompoEntry^)(new_item->Tag), songs);
				ee.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				ee.ShowDialog();

				// make list entry match CompoEntry tag
				this->match_entrylist_to_entry(new_item);
				this->entriesList->Sort();

			}


			this->entriesList->Items->Add(_empty_item);
			this->entriesList->Sort();
			this->check_zip_button();

		}

		private: System::Void txtCompoName2_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			txtCompoName1->Text = txtCompoName2->Text;
		}

		private: System::Void txtCompoName1_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			txtCompoName2->Text = txtCompoName1->Text;
		}
		private: System::Void entriesList_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e)
		{
			
			//this->entriesList->Items->Remove(this->_empty_item);

			//this->entriesList->Sort();
			
			if (e->Column == sort_col)
			{
				sort_ascending = !sort_ascending;
			}
			else
			{
				sort_col = e->Column;
				sort_ascending = true;
			}
			this->entriesList->ListViewItemSorter = gcnew ListViewItemComparer(sort_col, sort_ascending, this->_empty_item);
			//this->entriesList->ListViewItemSorter = nullptr;


			//this->entriesList->Items->Add(this->_empty_item);
		}
		private: System::Void entriesMenuStrip_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
		{
			if ((this->entriesList->SelectedItems->Count > 0) &&
				!(this->entriesList->SelectedItems->Count == 1 &&
				this->entriesList->SelectedItems[0] == this->_empty_item))
			{
				this->entriesMenuStrip->Items[1]->Enabled = true;
				this->entriesMenuStrip->Items[2]->Enabled = true;
			}
			else
			{
				this->entriesMenuStrip->Items[1]->Enabled = false;
				this->entriesMenuStrip->Items[2]->Enabled = false;
			}
		}

		private: System::Void removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->tabControl1->SelectedTab != this->entriesTab)
			{
				return;
			}

			for each (System::Windows::Forms::ListViewItem^ killitem in this->entriesList->SelectedItems)
			{
				if (killitem != this->_empty_item)
				{
					this->entriesList->Items->Remove(killitem);
				}
			}
			this->check_zip_button();
		}

		private: System::Void createzipButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::SaveFileDialog^ sfd = gcnew System::Windows::Forms::SaveFileDialog;
			sfd->Filter = "7zip files (*.7z)|*.7z|zip files (*.zip)|*.zip|All files (*.*)|*.*";
			sfd->FilterIndex = 1;
			//sfd->RestoreDirectory = true;
			//sfd->AddExtension = true;

			DateTime^ now = DateTime::Now;
			sfd->FileName = now->ToString("yyyy-MM-dd\"_votepack\"");
			sfd->DefaultExt = "7z";

			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				
				/*
				Ionic::Zip::ZipFile^ zf = gcnew Ionic::Zip::ZipFile;
	
				
				for each (System::Windows::Forms::ListViewItem^ additem in this->entriesList->Items)
				{
					if (additem != this->_empty_item)
					{
						
						zf->AddFile(((CompoEntry^)additem->Tag)->filespec, L"");
						
					}
				}
				zf->Save(sfd->FileName);
	
				delete zf;
				*/

				String ^filespecs = L"";

				if (sfd->FilterIndex == 1)
				{
					filespecs += L"-t7z ";
				}
				else if (sfd->FilterIndex == 2)
				{
					filespecs += L"-tzip ";
				}

				for each (System::Windows::Forms::ListViewItem^ additem in this->entriesList->Items)
				{
					if (additem != this->_empty_item)
					{
						filespecs += L"\"" +
							((CompoEntry^)additem->Tag)->filespec->Replace('\\', '/') +
							L"\" ";
						
					}
				}

				try
				{
					System::IO::File::Delete(sfd->FileName);

					String^ exe7z = System::IO::Path::Combine(System::IO::Path::GetDirectoryName(Application::ExecutablePath), "7z.exe");

					Process^ zipproc = gcnew Process();
					zipproc->StartInfo->CreateNoWindow = true;
					zipproc->StartInfo->UseShellExecute = false;
					//zipproc->StandardOutput = gcnew System::IO::StreamWriter(L"C:\temp\7zout.txt");
					zipproc->StartInfo->RedirectStandardOutput = true;
					zipproc->StartInfo->FileName = exe7z;
					zipproc->StartInfo->Arguments = L"a \"" +
						sfd->FileName->Replace('\\', '/') +
						L"\" " +
						filespecs;

					zipproc->Start();

					String^ stdout = zipproc->StandardOutput->ReadToEnd();
					zipproc->WaitForExit();

					if (zipproc->ExitCode != 0)
					{
						ResultsDisplay rd(stdout, L"7zip output");
						rd.ShowDialog();
					}
					
					this->zipfilePath = sfd->FileName;
				}
				catch(System::ComponentModel::Win32Exception^ w32e)
				{
					System::Windows::Forms::MessageBox::Show(
						L"An error occurred executing 7z.exe, so compress your files manually.\n\n" +
						L"The error was: " +
						w32e->Message,
						L"Sorry :(",
						System::Windows::Forms::MessageBoxButtons::OK);
				}
				catch(System::Exception^ e)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Something weird happened. Compress your files manually.\n\n" +
						L"The error was: " +
						e->Message,
						L"Sorry :(",
						System::Windows::Forms::MessageBoxButtons::OK);
				}
#ifndef _M_CEE_SAFE
				catch(...)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Something REALLY weird happened.\n" +
						L"There's not even an exception handler to deal with it.",
						L"Sorry :(",
						System::Windows::Forms::MessageBoxButtons::OK);
				}
#endif

			}

			this->check_zip_button();
		}

		private: System::Void entriesList_ItemActivate(System::Object^  sender, System::EventArgs^  e)
		{
			for each (System::Windows::Forms::ListViewItem^ edititem in this->entriesList->SelectedItems)
			{
				ArrayList^ songs = gcnew ArrayList;
				ArrayList^ entrants = gcnew ArrayList;
				get_current_songs_entrants(songs, entrants);

				if (edititem != this->_empty_item)
				{
					CompoEntry^ ce = (CompoEntry^)(edititem->Tag);
					
					// edit item
					EntryEditor ee(ce, songs);
					ee.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
					ee.ShowDialog();

					// make list entry match CompoEntry tag
					this->match_entrylist_to_entry(edititem);
					this->entriesList->Sort();
				}
				else
				{
					CompoEntry ^ce = gcnew CompoEntry();

					EntryEditor ee(ce, songs);
					ee.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;

					if (ee.ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						ListViewItem^ new_item = gcnew ListViewItem(gcnew array<String^>{L"",L"",L"",L""});
						new_item->Tag = ce;

						this->entriesList->Items->Add(new_item);
						this->match_entrylist_to_entry(new_item);
					}
				}
			}
			this->entriesList->Sort();
			this->check_zip_button();
		}

		private: System::Void tabControl1_Selecting(System::Object^  sender, System::Windows::Forms::TabControlCancelEventArgs^  e)
		{
			if (e->TabPage == this->tabPage2)
			{
				for each (System::Windows::Forms::ListViewItem^ lvi in this->entriesList->Items)
				{
					if (lvi != this->_empty_item)
					{
						if ( ((CompoEntry^)(lvi->Tag))->composer == L"" )
						{
							System::Windows::Forms::MessageBox::Show(
								L"Fill in the Nick fields for\nentered songs before voting.",
								L"The jig's up, Chuckles",
								System::Windows::Forms::MessageBoxButtons::OK);
							e->Cancel = true;
							break;
						}
					}
				}
			}
			if ((e->TabPage == entriesTab) && (this->voteList->Columns->Count > 0))
			{
				System::Windows::Forms::DialogResult dr;
				

				dr = System::Windows::Forms::MessageBox::Show(
					L"Going back to the Entries tab\nwhile you have votes entered\nwill hose the list of votes!\n\nAre you okay with losing all the votes?",
					L"This program is too stupid",
					System::Windows::Forms::MessageBoxButtons::YesNo);

				if (dr != System::Windows::Forms::DialogResult::Yes)
				{
					e->Cancel = true;
				}
				else
				{
					this->voteList->Items->Clear();
					this->voteList->Columns->Clear();
				}
			}
		}
		private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->tabControl1->SelectedTab != this->tabPage2)
			{
				return;
			}

			/*
			 * figure out votes on clipboard data
			 */

			try
			{
				String^ pastedstr = ((String^)(System::Windows::Forms::Clipboard::GetData(System::Windows::Forms::DataFormats::Text)));
				if (pastedstr == nullptr)
				{
					/*
					System::Windows::Forms::MessageBox::Show(
						L"Whatever it is you're trying to paste,\nit ain't workin'.",
						L"Inappropriate stuff on clipboard",
						System::Windows::Forms::MessageBoxButtons::OK);
					*/
					return;
				}

				//array<String^>^ pastedata = pastedstr->Replace(L"\r", L"")->Split(L'\n');
				
				ArrayList^ vp_pastedata = gcnew ArrayList(pastedstr->Replace(L"\r", L"")->Split(L'\n'));

				// build entries list for VotePlugins
				ArrayList^ songs = gcnew ArrayList;
				ArrayList^ vp_not_voted = gcnew ArrayList;
				get_current_songs_entrants(songs, vp_not_voted);

				ArrayList^ vp_entries = gcnew ArrayList;
				
				for each (CompoEntry^ ce in songs)
				{
					VotePlugin::Entry^ vpe = gcnew VotePlugin::Entry(ce->composer, ce->filename, ce->songtitle);
					vp_entries->Add(vpe);
				}
				
				array<String^>^ plugins = System::IO::Directory::GetFiles(System::IO::Path::GetDirectoryName(Application::ExecutablePath), L"vp_*.dll");

				ArrayList^ vote_outputs = gcnew ArrayList;

				for each (String^ plugin_path in plugins)
				{
					VotePlugin::IVotePlugin^ ivp;
					try
					{
						// call each plugin

						String^ plugin_name = System::IO::Path::GetFileNameWithoutExtension(plugin_path);



						System::Reflection::Assembly^ assem = System::Reflection::Assembly::Load(plugin_name);
						System::Type^ voteplug = assem->GetType(plugin_name + "." + plugin_name);
						ivp = (VotePlugin::IVotePlugin^)(Activator::CreateInstance(voteplug));

						ivp->set_entries(vp_entries);
						ivp->set_not_voted(vp_not_voted);

						ArrayList^ vote_output = ivp->parse_votes(vp_pastedata);

						// post-plugin processing

						vote_outputs->Add(gcnew array<Object^> { ivp, vote_output } );
					}
					catch(VotePlugin::VoteParseException^ vpe)
					{
						vote_outputs->Add(gcnew array<Object^> { nullptr, ivp->vp_name + L" " + ivp->vp_version + ": " + vpe->Message } );
					}
					catch(System::Exception^ exc)
					{
						System::Windows::Forms::MessageBox::Show(
							L"Some bad thing happened while executing " +
							plugin_path +
							L":\n\n" +
							exc->ToString(),
							L"Slightly less lame error handler",
							System::Windows::Forms::MessageBoxButtons::OK);
					}
#ifndef _M_CEE_SAFE
					catch(...)
					{

					}
#endif
				}

				// ask user to select a parse result (if necessary)

				int voteparse_idx;

				if ((vote_outputs->Count == 1) && (((array<Object^>^)(vote_outputs[0]))[0] != nullptr))
				{
					voteparse_idx = 0;
				}
				else
				{
					bool allthesame = true;

					array<Object^>^ lhs_parse = nullptr;

					// check if all vote parser outputs match each other
					for each (array<Object^>^ rhs_parse in vote_outputs)
					{
						// parse failure
						if (rhs_parse[0] == nullptr)
						{
							allthesame = false;
							break;
						}
						if (lhs_parse == nullptr)
						{
							lhs_parse = rhs_parse;
							continue;
						}

						VotePlugin::IVotePlugin^ lhs_ivp = (VotePlugin::IVotePlugin^)( lhs_parse[0] );
						VotePlugin::IVotePlugin^ rhs_ivp = (VotePlugin::IVotePlugin^)( rhs_parse[0] );

						if (lhs_ivp->voter != rhs_ivp->voter)
						{
							allthesame = false;
							break;
						}

						ArrayList^ lhs_output = (ArrayList^)( lhs_parse[1] );
						ArrayList^ rhs_output = (ArrayList^)( rhs_parse[1] );
						
						if (lhs_output->Count != rhs_output->Count)
						{
							allthesame = false;
							break;
						}
						int i;
						for(i=0; i < lhs_output->Count; i++)
						{
							VotePlugin::Entry^ lhs_e = (VotePlugin::Entry^)(lhs_output[i]);
							VotePlugin::Entry^ rhs_e = (VotePlugin::Entry^)(rhs_output[i]);
							if (lhs_e->filename != rhs_e->filename)
							{
								allthesame = false;
								break;
							}
						}
						if (!allthesame)
						{
							break;
						}
					}

					
					if (allthesame)
					{
						voteparse_idx = 0;
					}
					else
					{
						VoteParseSelection^ vps = gcnew VoteParseSelection(vote_outputs);
						vps->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	
						System::Windows::Forms::DialogResult dr = vps->ShowDialog();
						if (dr != System::Windows::Forms::DialogResult::OK)
						{
							return;
						}
						voteparse_idx = vps->chosen_idx;
					}
				}

				VotePlugin::IVotePlugin^ ivp = (VotePlugin::IVotePlugin^)( ((array<Object^>^)(vote_outputs[voteparse_idx]))[0] );

				if (ivp == nullptr)
				{
					return;
				}

				ArrayList^ vote_output = (ArrayList^)( ((array<Object^>^)(vote_outputs[voteparse_idx]))[1] );

				CompoEntry ^author_entry = nullptr;
				VoteData^ vd = gcnew VoteData;

				for each (VotePlugin::Entry^ e in vote_output)
				{
					vd->votes->Add(e->filename);
				}


				// get author_entry using plugin->voter
				if (ivp->voter != nullptr)
				{
					vd->votingby = ivp->voter;

					for each (CompoEntry^ ce in songs)
					{
						if (ce->composer == ivp->voter)
						{
							if (vp_not_voted->Contains(ivp->voter) && (ce->composer == ivp->voter))
							{
								vd->votingfor = ivp->voter;
								author_entry = ce;
								break;
							}
						}
					}
				}

				// if there is only one entry left in songs that isn't in vd->votes,
				// and it belongs to the current author (CompoEntry^ author_entry when not
				// nullptr), then move it into the list.
				if ((author_entry != nullptr) && (vd->votes->Count+1 == songs->Count) && (!vd->votes->Contains(author_entry->filename)))
				{
					vd->votes->Add(author_entry->filename);
				}
	
				this->add_voter(vd);
			}
			catch(System::Exception^ exc)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Some bad thing happened.\n\n" +
					exc->ToString(),
					L"Lame error handler",
					System::Windows::Forms::MessageBoxButtons::OK);
			}
			
		}
		
		private: System::Void get_current_songs_entrants(ArrayList^ compoentries, ArrayList^ entrants)
		{

			ArrayList^ already_used_names = gcnew ArrayList;

			

			for each (System::Windows::Forms::ColumnHeader^ ch in this->voteList->Columns)
			{
				VoteData^ votes = (VoteData^)(ch->Tag);
				if (votes->votingfor != L"")
				{
					already_used_names->Add(votes->votingfor);
				}
			}

			for each (System::Windows::Forms::ListViewItem^ lvi in this->entriesList->Items)
			{
				if (lvi != this->_empty_item)
				{
					CompoEntry ^ce = (CompoEntry^)(lvi->Tag);
					compoentries->Add(ce);
					
					if (!already_used_names->Contains(ce->composer))
					{
						entrants->Add(ce->composer);
					}
				}
			}
		}

		private: System::Void add_voter(VoteData^ vd)
		{
			
			ArrayList^ entrants = gcnew ArrayList;
			ArrayList^ songs = gcnew ArrayList;

			get_current_songs_entrants(songs, entrants);

			VoteEntry ve(vd, entrants, songs);
			ve.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			

			System::Windows::Forms::DialogResult dr = ve.ShowDialog();

			if (dr == System::Windows::Forms::DialogResult::OK)
			{
				System::Windows::Forms::ColumnHeader ^newhead = this->voteList->Columns->Add(vd->votingby);
				newhead->Tag = vd;
				int idx = newhead->Index;

				int i=0;
				for each (System::Windows::Forms::ListViewItem^ lvi in this->voteList->Items)
				{
					while (lvi->SubItems->Count < idx+1)
					{
						lvi->SubItems->Add(L"");
					}

					System::Windows::Forms::ListViewItem::ListViewSubItem^ si = lvi->SubItems[idx];
					si->Text = (String^)(vd->votes[i]);
					
					i++;
				}
				while (i < vd->votes->Count)
				{
					System::Windows::Forms::ListViewItem^ nlvi = this->voteList->Items->Add(L"");
					
					while (nlvi->SubItems->Count < idx+1)
					{
						nlvi->SubItems->Add(L"");
					}
					System::Windows::Forms::ListViewItem::ListViewSubItem^ si = nlvi->SubItems[idx];
					si->Text = (String^)(vd->votes[i]);
					i++;
				}
			}

		}
		private: System::Void addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->add_voter(gcnew VoteData);
		}
		
		private: System::Void voteList_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e)
		{
			VoteData^ vd = (VoteData^)(this->voteList->Columns[e->Column]->Tag);
			ArrayList^ entrants = gcnew ArrayList;
			ArrayList^ songs = gcnew ArrayList;

			get_current_songs_entrants(songs, entrants);
			if (vd->votingfor != L"")
			{
				entrants->Add(vd->votingfor);
			}

			VoteEntry ve(vd, entrants, songs);
			ve.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;

			System::Windows::Forms::DialogResult dr = ve.ShowDialog();

			if (dr == System::Windows::Forms::DialogResult::OK)
			{
				int idx = e->Column;
				this->voteList->Columns[idx]->Text = vd->votingby;

				int i=0;
				for each (System::Windows::Forms::ListViewItem^ lvi in this->voteList->Items)
				{
					while (lvi->SubItems->Count < idx+1)
					{
						lvi->SubItems->Add(L"");
					}

					System::Windows::Forms::ListViewItem::ListViewSubItem^ si = lvi->SubItems[idx];
					si->Text = (String^)(vd->votes[i]);
					
					i++;
				}
				while (i < vd->votes->Count)
				{
					System::Windows::Forms::ListViewItem^ nlvi = this->voteList->Items->Add(L"");
					
					while (nlvi->SubItems->Count < idx+1)
					{
						nlvi->SubItems->Add(L"");
					}
					System::Windows::Forms::ListViewItem::ListViewSubItem^ si = nlvi->SubItems[idx];
					si->Text = (String^)(vd->votes[i]);
					i++;
				}
				
			}

		}

		private: System::Void voteList_DoubleClick(System::Object^  sender, System::EventArgs^  e)
		{
			this->add_voter(gcnew VoteData);
		}
		
		private: String^ calc_results(bool penalize)
		{
			ArrayList ^entries = gcnew ArrayList;
			ArrayList ^votes = gcnew ArrayList;

			for each (System::Windows::Forms::ListViewItem^ lvi in this->entriesList->Items)
			{
				if (lvi != this->_empty_item)
				{
					entries->Add((CompoEntry^)(lvi->Tag));
				}
			}
			for each (System::Windows::Forms::ColumnHeader^ ch in this->voteList->Columns)
			{
				votes->Add((VoteData^)(ch->Tag));
			}


			ResultsCalc rc(entries, votes, this->txtCompoName1->Text, penalize);

			rc.calculate();
			return rc.results;
		}

		private: System::Void viewButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::DialogResult dr = this->check_results();

			bool penalize;
			if (dr == System::Windows::Forms::DialogResult::Cancel)
			{
				return;
			}
			else if (dr == System::Windows::Forms::DialogResult::Yes)
			{
				penalize = true;
			}
			else
			{
				penalize = false;
			}
			ResultsDisplay rd(calc_results(penalize));
			rd.ShowDialog();
		}
		private: System::Void exportButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::DialogResult dr = this->check_results();

			bool penalize;
			if (dr == System::Windows::Forms::DialogResult::Cancel)
			{
				return;
			}
			else if (dr == System::Windows::Forms::DialogResult::Yes)
			{
				penalize = true;
			}
			else
			{
				penalize = false;
			}

			System::Windows::Forms::SaveFileDialog^ sfd = gcnew System::Windows::Forms::SaveFileDialog;
			sfd->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			sfd->FilterIndex = 0;
			DateTime^ now = DateTime::Now;
			sfd->FileName = now->ToString("yyyy-MM-dd\"_results.txt\"");

			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				System::IO::StreamWriter^ outf = gcnew System::IO::StreamWriter(sfd->FileName);

				outf->Write(calc_results(penalize));

				outf->Close();

				this->txtfilePath = sfd->FileName;
				this->exportTxtLabel->Enabled = true;
				this->exportTxtLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			}

		}
		private: System::Void zipErrorLabel_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->zipfilePath != nullptr)
			{
				Process::Start("explorer.exe", "/e,/select,"+this->zipfilePath);
			}
		}
		private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();
		}
		private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			array<String^>^ plugins = System::IO::Directory::GetFiles(System::IO::Path::GetDirectoryName(Application::ExecutablePath), L"vp_*.dll");
			String^ plugin_info = L"";

			for each (String^ plugin_path in plugins)
			{
				plugin_info += L"\n";
				try
				{
					String^ plugin_name = System::IO::Path::GetFileNameWithoutExtension(plugin_path);
		
					System::Reflection::Assembly^ assem = System::Reflection::Assembly::Load(plugin_name);
					System::Type^ voteplug = assem->GetType(plugin_name + "." + plugin_name);
					VotePlugin::IVotePlugin^ ivp = (VotePlugin::IVotePlugin^)(Activator::CreateInstance(voteplug));

					plugin_info += ivp->vp_name + L" " + ivp->vp_version + L" by " + ivp->vp_author;
				}
				catch(System::Exception^ e)
				{
					plugin_info += L"error loading info";
				}
#ifndef _M_CEE_SAFE
				catch(...)
				{
					plugin_info += L"error loading info";
				}
#endif

				plugin_info += L" (" + System::IO::Path::GetFileName(plugin_path) + L")";
			}

			System::Windows::Forms::MessageBox::Show(
				L"lazyslash compomagoo " + compoversion::version + "\ncompo management system\n\n" +
				L"svn rev " + compoversion::svnrevision +
				L" (" + compoversion::svnrevdate + L")" +
				L"\n\n(c) 2009 Mike Burke (mrb)\nmrburke@gmail.com\n\n" +
				L"Installed vote parser plugins:\n" +
				plugin_info,
				L"Aboot",
				System::Windows::Forms::MessageBoxButtons::OK);
		}
		private: System::Void exportTxtLabel_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->txtfilePath != nullptr)
			{
				Process::Start("explorer.exe", "/e,/select,"+this->txtfilePath);
			}
		}
		private: System::Void addNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->tabControl1->SelectedTab == this->entriesTab)
			{
				ArrayList^ songs = gcnew ArrayList;
				ArrayList^ entrants = gcnew ArrayList;
				get_current_songs_entrants(songs, entrants);

				CompoEntry ^ce = gcnew CompoEntry();

				EntryEditor ee(ce, songs);
				ee.StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				if (ee.ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					ListViewItem^ new_item = gcnew ListViewItem(gcnew array<String^>{L"",L"",L"",L""});
					new_item->Tag = ce;

					this->entriesList->Items->Add(new_item);
					this->match_entrylist_to_entry(new_item);
				}

			}
		}
		
		private: System::Void get_current_votes(ArrayList^ votes)
		{
			for each (System::Windows::Forms::ColumnHeader^ ch in this->voteList->Columns)
			{
				votes->Add((VoteData^)(ch->Tag));
			}
		}
		private: System::Windows::Forms::DialogResult check_results(void)
		{
			// check that all voters have submitted
			ArrayList^ songs = gcnew ArrayList;
			ArrayList^ entrants = gcnew ArrayList;

			get_current_songs_entrants(songs, entrants);

			if (entrants->Count > 0)
			{
				String^ slackers = L"";
				for each (String^ slacker in entrants)
				{
					slackers += "\n" + slacker;
				}
				
				System::Windows::Forms::DialogResult dr = System::Windows::Forms::MessageBox::Show(
					L"The following people have not yet voted:\n" +
					slackers +
					"\n\nDo you want to penalize them?",
					L"The Cockalizer",
					System::Windows::Forms::MessageBoxButtons::YesNoCancel);

				return dr;
			}
			else
			{
				return System::Windows::Forms::DialogResult::No;
			}
			
		}
		
		private: System::Void open_new(void)
		{
			zipfilePath = nullptr;
			txtfilePath = nullptr;
			savefilePath = nullptr;

			this->entriesList->Items->Clear();
			this->voteList->Clear();

			this->tabControl1->SelectedTab = this->entriesTab;

			this->entriesList->FullRowSelect = true;
			this->voteList->FullRowSelect = true;
			
			_empty_item = gcnew System::Windows::Forms::ListViewItem(gcnew array<String^>{L"", L"", L"(add new)", L""});

			this->entriesList->Items->Add(_empty_item);

			sort_ascending = true;
			sort_col = 2;

			this->entriesList->ListViewItemSorter = gcnew ListViewItemComparer(sort_col, sort_ascending, this->_empty_item);

			this->check_zip_button();
		}

		private: bool save(bool save_as)
		{
			String^ savefile = nullptr;

			if (save_as || this->savefilePath == nullptr)
			{
				System::Windows::Forms::SaveFileDialog^ sfd = gcnew System::Windows::Forms::SaveFileDialog;
				sfd->Filter = "compo files (*.compo)|*.compo|All files (*.*)|*.*";
				sfd->FilterIndex = 0;
				if (this->savefilePath != nullptr)
				{
					sfd->FileName = this->savefilePath;
				}
				if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					savefile = sfd->FileName;
				}
			}
			else
			{
				savefile = this->savefilePath;
			}

			if (savefile != nullptr)
			{
				try
				{
					ArrayList^ songs = gcnew ArrayList;
					ArrayList^ entrants = gcnew ArrayList;
					ArrayList^ votes = gcnew ArrayList;
					this->get_current_songs_entrants(songs, entrants);
					this->get_current_votes(votes);
					
					System::IO::StreamWriter^ outf = gcnew System::IO::StreamWriter(savefile);

					// write songs/entries
					outf->WriteLine(songs->Count.ToString());
					for each (CompoEntry^ ce in songs)
					{
						outf->WriteLine(ce->composer);
						outf->WriteLine(ce->filename);
						outf->WriteLine(ce->songtitle);
					}
					
					// write votes
					outf->WriteLine(votes->Count.ToString());
					for each (VoteData^ vd in votes)
					{
						outf->WriteLine(vd->votingfor);
						outf->WriteLine(vd->votingby);
						outf->WriteLine(vd->votes->Count.ToString());
						for each (String^ vote in vd->votes)
						{
							outf->WriteLine(vote);
						}
					}

					outf->Close();
					
					this->savefilePath = savefile;
					
					return true;
				}
				catch(System::Exception^ e)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Some (CLI/.NET) error occurred while saving.\nYour data probably wasn't saved.",
						L"Bzzt",
						System::Windows::Forms::MessageBoxButtons::OK);
					return false;
				}
#ifndef _M_CEE_SAFE
				catch(...)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Some (CRT) error occurred while saving.\nYour data probably wasn't saved.",
						L"Bzzt",
						System::Windows::Forms::MessageBoxButtons::OK);
					return false;
				}
#endif
			}
			else
			{
				return false;
			}
		}

		private: bool open_file(void)
		{
			String^ openfile = nullptr;

			System::Windows::Forms::OpenFileDialog^ ofd = gcnew System::Windows::Forms::OpenFileDialog;
			ofd->Filter = "compo files (*.compo)|*.compo|All files (*.*)|*.*";
			ofd->FilterIndex = 0;
			if (this->savefilePath != nullptr)
			{
				ofd->FileName = this->savefilePath;
			}
			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				try
				{
					ArrayList^ songs = gcnew ArrayList;
					ArrayList^ votes = gcnew ArrayList;
					
					System::IO::StreamReader^ inf = gcnew System::IO::StreamReader(ofd->FileName);
					String^ line = L"lol";

					// load songs/entries
					line = inf->ReadLine();
					int count = System::Int32::Parse(line);
					int i;

					for(i=0; i < count; i++)
					{
						CompoEntry^ ce = gcnew CompoEntry;
						ce->composer = inf->ReadLine();
						ce->filename = inf->ReadLine();
						ce->songtitle = inf->ReadLine();
						songs->Add(ce);
					}
					
					// load votes
					line = inf->ReadLine();
					count = System::Int32::Parse(line);

					for(i=0; i < count; i++)
					{
						VoteData^ vd = gcnew VoteData;

						vd->votingfor = inf->ReadLine();
						vd->votingby = inf->ReadLine();
						int votecount = System::Int32::Parse(inf->ReadLine());
						for(int j=0; j < votecount; j++)
						{
							vd->votes->Add(inf->ReadLine());
						}
						votes->Add(vd);
					}

					inf->Close();
					
					this->savefilePath = ofd->FileName;

					// fill in data
					this->open_new();

					this->tabControl1->SelectedTab = this->entriesTab;

					this->entriesList->Items->Clear();
					for each (CompoEntry^ ce in songs)
					{
						ListViewItem^ new_item = gcnew ListViewItem(gcnew array<String^>{"", "", "", ""});
						new_item->Tag = ce;
						this->entriesList->Items->Add(new_item);
						this->match_entrylist_to_entry(new_item);
					}
					this->entriesList->Items->Add(_empty_item);
					this->entriesList->Sort();

					// fill in votes
					if (votes->Count > 0)
					{
						this->tabControl1->SelectedTab = this->tabPage2;
					}

					for each (VoteData^ vd in votes)
					{
						System::Windows::Forms::ColumnHeader ^newhead = this->voteList->Columns->Add(vd->votingby);
						newhead->Tag = vd;
						int idx = newhead->Index;
	
						i=0;
						for each (System::Windows::Forms::ListViewItem^ lvi in this->voteList->Items)
						{
							while (lvi->SubItems->Count < idx+1)
							{
								lvi->SubItems->Add(L"");
							}
	
							System::Windows::Forms::ListViewItem::ListViewSubItem^ si = lvi->SubItems[idx];
							si->Text = (String^)(vd->votes[i]);
							
							i++;
						}
						while (i < vd->votes->Count)
						{
							System::Windows::Forms::ListViewItem^ nlvi = this->voteList->Items->Add(L"");
							
							while (nlvi->SubItems->Count < idx+1)
							{
								nlvi->SubItems->Add(L"");
							}
							System::Windows::Forms::ListViewItem::ListViewSubItem^ si = nlvi->SubItems[idx];
							si->Text = (String^)(vd->votes[i]);
							i++;
						}
		
					}

					return true;
				}
				catch(System::Exception^ e)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Some (CLI/.NET) error occurred while loading.\nYou should probably exit the program to\nreturn to a consistent state.",
						L"Bzzt",
						System::Windows::Forms::MessageBoxButtons::OK);
					return false;
				}
#ifndef _M_CEE_SAFE
				catch(...)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Some (CRT) error occurred while loading.\nYou should probably exit the program to\nreturn to a consistent state.",
						L"Bzzt",
						System::Windows::Forms::MessageBoxButtons::OK);
					return false;
				}
#endif
			}
			else
			{
				return false;
			}
		}

		private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::DialogResult dr = System::Windows::Forms::MessageBox::Show(
				L"You'll lose unsaved work. Save first?",
				L"Which is chosen?",
				System::Windows::Forms::MessageBoxButtons::YesNoCancel);
			if (dr == System::Windows::Forms::DialogResult::Cancel)
			{
				return;
			}
			else if (dr == System::Windows::Forms::DialogResult::Yes)
			{
				if (this->save(false))
				{
					this->open_new();
				}
				// not saved: don't clear data
			}
			else
			{
				this->open_new();
			}
		}

		private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->save(false);
		}
		private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->save(true);
		}

		private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::DialogResult dr = System::Windows::Forms::MessageBox::Show(
				L"You'll lose unsaved work. Save first?",
				L"Which is chosen?",
				System::Windows::Forms::MessageBoxButtons::YesNoCancel);
			if (dr == System::Windows::Forms::DialogResult::Cancel)
			{
				return;
			}
			else if (dr == System::Windows::Forms::DialogResult::Yes)
			{
				if (this->save(false))
				{
					this->open_file();
				}
				// not saved: don't clear data
			}
			else
			{
				this->open_file();
			}
		}
		private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->tabControl1->SelectedTab != this->entriesTab)
			{
				return;
			}

			String^ newclipdata = L"";

			for each (System::Windows::Forms::ListViewItem^ copyitem in this->entriesList->SelectedItems)
			{
				if (copyitem != this->_empty_item)
				{
					if (newclipdata != L"")
					{
						newclipdata += "\n";
					}

					CompoEntry^ ce = (CompoEntry^)(copyitem->Tag);

					newclipdata += ce->filename;
					if (ce->songtitle != L"")
					{
						newclipdata += " (" + ce->songtitle + ")";
					}

				}
			}
			if (newclipdata != L"")
			{
				System::Windows::Forms::Clipboard::SetData(System::Windows::Forms::DataFormats::Text, newclipdata);
			}

		}
		private: System::Void votesMenuStrip_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
		{
			this->votesMenuStrip->Items[1]->Enabled = System::Windows::Forms::Clipboard::ContainsText();
		}
};


}

