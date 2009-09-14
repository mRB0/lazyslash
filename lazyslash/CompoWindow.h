#pragma once

#include "TrackerMod.h"
#include "ListViewItemComparer.h"
#include "CompoEntry.h"
#include "EntryEditor.h"
#include "VoteEntry.h"
#include "VoteData.h"
#include "ResultsCalc.h"
#include "ResultsDisplay.h"

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

			zipfilePath = nullptr;

			this->entriesList->FullRowSelect = true;
			this->voteList->FullRowSelect = true;
			
			_empty_item = gcnew System::Windows::Forms::ListViewItem(gcnew array<String^>{L"", L"", L"(add new)", L""});

			this->entriesList->Items->Add(_empty_item);

			sort_ascending = true;
			sort_col = 2;

			this->entriesList->ListViewItemSorter = gcnew ListViewItemComparer(sort_col, sort_ascending, this->_empty_item);

			this->check_zip_button();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:

		String^ zipfilePath;

		System::Windows::Forms::ListViewItem^ _empty_item;
		bool sort_ascending;
	private: System::Windows::Forms::ContextMenuStrip^  entriesMenuStrip;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::Label^  zipErrorLabel;
	private: System::Windows::Forms::ContextMenuStrip^  votesMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
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
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtCompoName1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->entriesLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
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
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->zipErrorLabel->Location = System::Drawing::Point(155, 262);
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
			this->createzipButton->Size = System::Drawing::Size(143, 23);
			this->createzipButton->TabIndex = 4;
			this->createzipButton->Text = L"Create votepack .ZIP";
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
			this->entriesMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->removeToolStripMenuItem});
			this->entriesMenuStrip->Name = L"entriesMenuStrip";
			this->entriesMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->entriesMenuStrip->Size = System::Drawing::Size(136, 26);
			this->entriesMenuStrip->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &CompoWindow::entriesMenuStrip_Opening);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->removeToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->removeToolStripMenuItem->Text = L"Remove";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::removeToolStripMenuItem_Click);
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
			// exportButton
			// 
			this->exportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exportButton->Location = System::Drawing::Point(87, 257);
			this->exportButton->Name = L"exportButton";
			this->exportButton->Size = System::Drawing::Size(75, 23);
			this->exportButton->TabIndex = 9;
			this->exportButton->Text = L"Export TXT";
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
			this->viewButton->Text = L"View results";
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
			this->votesMenuStrip->Size = System::Drawing::Size(169, 48);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->addToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->addToolStripMenuItem->Text = L"Add New...";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::addToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->pasteToolStripMenuItem->Text = L"Paste...";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompoWindow::pasteToolStripMenuItem_Click);
			// 
			// txtCompoName2
			// 
			this->txtCompoName2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtCompoName2->Location = System::Drawing::Point(188, 5);
			this->txtCompoName2->Name = L"txtCompoName2";
			this->txtCompoName2->Size = System::Drawing::Size(236, 20);
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
			this->mainMenuStrip->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->mainMenuStrip->ImageScalingSize = System::Drawing::Size(0, 0);
			this->mainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mainMenuStrip->Name = L"mainMenuStrip";
			this->mainMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->mainMenuStrip->Size = System::Drawing::Size(438, 24);
			this->mainMenuStrip->TabIndex = 1;
			this->mainMenuStrip->Text = L"menuStrip1";
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
			this->Controls->Add(this->mainMenuStrip);
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
			edititem->SubItems[0]->Text = (ce->voted ? L"yes" : L"NO");
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

			for each (String^ file in files)
			{
				String^ filename = System::IO::Path::GetFileName(file);

				String^ songtitle = TrackerMod::GetSongTitle(file)->TrimEnd(0);
				//int songlen = songtitle->Length;
				
				ListViewItem^ new_item = gcnew ListViewItem(gcnew array<String^>{"", "", filename, songtitle});
				new_item->Tag = gcnew CompoEntry(file, songtitle);

				this->entriesList->Items->Add(new_item);
				this->match_entrylist_to_entry(new_item);
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
				this->entriesMenuStrip->Items[0]->Enabled = true;
			}
			else
			{
				this->entriesMenuStrip->Items[0]->Enabled = false;
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
			sfd->Filter = "zip files (*.zip)|*.zip|All files (*.*)|*.*";
			sfd->FilterIndex = 0;
			//sfd->RestoreDirectory = true;

			DateTime^ now = DateTime::Now;
			sfd->FileName = now->ToString("yyyy-MM-dd \"votepack.zip\"");

			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				
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

				this->zipfilePath = sfd->FileName;
			}

			this->check_zip_button();
		}

		private: System::Void entriesList_ItemActivate(System::Object^  sender, System::EventArgs^  e)
		{
			for each (System::Windows::Forms::ListViewItem^ edititem in this->entriesList->SelectedItems)
			{
				if (edititem != this->_empty_item)
				{
					CompoEntry^ ce = (CompoEntry^)(edititem->Tag);

					// edit item
					EntryEditor ee(ce);
					ee.ShowDialog();

					// make list entry match CompoEntry tag
					this->match_entrylist_to_entry(edititem);
					this->entriesList->Sort();
				}
				else
				{
					CompoEntry ^ce = gcnew CompoEntry();

					EntryEditor ee(ce);
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

			// TODO: accept pastes
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

		private: System::Void add_voter(void)
		{
			VoteData^ vd = gcnew VoteData;
			ArrayList^ entrants = gcnew ArrayList;
			ArrayList^ songs = gcnew ArrayList;

			get_current_songs_entrants(songs, entrants);

			VoteEntry ve(vd, entrants, songs);
			

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
			this->add_voter();
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
			this->add_voter();
		}
		
		private: String^ calc_results(void)
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


			ResultsCalc rc(entries, votes, this->txtCompoName1->Text);

			rc.calculate();
			return rc.results;
		}

		private: System::Void viewButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ResultsDisplay rd(calc_results());
			rd.ShowDialog();
		}
		private: System::Void exportButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::SaveFileDialog^ sfd = gcnew System::Windows::Forms::SaveFileDialog;
			sfd->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			sfd->FilterIndex = 0;
			DateTime^ now = DateTime::Now;
			sfd->FileName = now->ToString("yyyy-MM-dd \"results.txt\"");

			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				System::IO::StreamWriter^ outf = gcnew System::IO::StreamWriter(sfd->FileName);

				outf->Write(calc_results());

				outf->Close();
			}

		}
		private: System::Void zipErrorLabel_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->zipfilePath != nullptr)
			{
				Process::Start("explorer.exe", "/e,/select,"+this->zipfilePath);
			}
		}
};


}

