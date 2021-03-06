#pragma once

/*
 * $Id$
 */

#include "VoteData.h"
#include "CompoEntry.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lazyslash {

	/// <summary>
	/// Summary for VoteEntry
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class VoteEntry : public System::Windows::Forms::Form
	{
	public:
		VoteEntry(VoteData^ vd, ArrayList^ entrants, ArrayList^ compoentries)
		{
			InitializeComponent();

			this->cb_dragging = nullptr;

			this->vd = vd;
			this->entrants = entrants;
			
			this->compoentries = compoentries;

			this->AcceptButton = this->okButton;
			this->CancelButton = this->canButton;

			this->availBox->FullRowSelect = true;
			this->chosenBox->FullRowSelect = true;
			this->chosenBox->InsertionMark->Color = Color::Green;
			
			this->voterCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			
			this->voterCombo->Items->Add(L"(guest vote)");
			for each (String^ entrant in entrants)
			{
				this->voterCombo->Items->Add(entrant);
			}
	
			if (vd->votingfor == L"")
			{
				this->voterCombo->SelectedIndex = 0;
			}
			else
			{
				this->voterCombo->SelectedItem = vd->votingfor;
			}

			this->voterText->Text = vd->votingby;

			for each (CompoEntry^ ce in compoentries)
			{
				if (!vd->votes->Contains(ce->filename))
				{
					System::Windows::Forms::ListViewItem^ nvi = gcnew System::Windows::Forms::ListViewItem(gcnew array<String^>{ce->filename,ce->songtitle});
					nvi->Tag = ce;
					this->availBox->Items->Add(nvi);
				}
			}
			for each (String^ song in vd->votes)
			{
				CompoEntry^ tce;
				for each (CompoEntry^ ce in compoentries)
				{
					if (song == ce->filename)
					{
						tce = ce;
						break;
					}
				}
				System::Windows::Forms::ListViewItem^ nvi = gcnew System::Windows::Forms::ListViewItem(gcnew array<String^>{tce->filename,tce->songtitle});
				nvi->Tag = tce;
				this->chosenBox->Items->Add(nvi);
			}
				

			this->check_completed();
		}

	protected:
		
		VoteData^ vd;
		ArrayList^ entrants;
		ArrayList^ compoentries;

	private: System::Windows::Forms::Button^  unVoteBtn;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	protected: 
		
		

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VoteEntry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  voterCombo;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  voterText;
	private: System::Windows::Forms::ListView^  availBox;

	private: System::Windows::Forms::Button^  addVoteBtn;
	private: System::Windows::Forms::ListView^  chosenBox;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  canButton;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VoteEntry::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->voterCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->voterText = (gcnew System::Windows::Forms::TextBox());
			this->availBox = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->addVoteBtn = (gcnew System::Windows::Forms::Button());
			this->chosenBox = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->canButton = (gcnew System::Windows::Forms::Button());
			this->unVoteBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Votes for";
			// 
			// voterCombo
			// 
			this->voterCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->voterCombo->FormattingEnabled = true;
			this->voterCombo->Location = System::Drawing::Point(67, 6);
			this->voterCombo->Name = L"voterCombo";
			this->voterCombo->Size = System::Drawing::Size(121, 21);
			this->voterCombo->TabIndex = 1;
			this->voterCombo->SelectionChangeCommitted += gcnew System::EventHandler(this, &VoteEntry::voterCombo_SelectionChangeCommitted);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(194, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"supplied by";
			// 
			// voterText
			// 
			this->voterText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->voterText->Location = System::Drawing::Point(260, 6);
			this->voterText->Name = L"voterText";
			this->voterText->Size = System::Drawing::Size(124, 20);
			this->voterText->TabIndex = 3;
			this->voterText->TextChanged += gcnew System::EventHandler(this, &VoteEntry::voterText_TextChanged);
			// 
			// availBox
			// 
			this->availBox->AllowDrop = true;
			this->availBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->availBox->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->columnHeader1, this->columnHeader2});
			this->availBox->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->availBox->Location = System::Drawing::Point(12, 33);
			this->availBox->MultiSelect = false;
			this->availBox->Name = L"availBox";
			this->availBox->Size = System::Drawing::Size(162, 173);
			this->availBox->TabIndex = 4;
			this->availBox->UseCompatibleStateImageBehavior = false;
			this->availBox->View = System::Windows::Forms::View::Details;
			this->availBox->DoubleClick += gcnew System::EventHandler(this, &VoteEntry::availBox_DoubleClick);
			this->availBox->Leave += gcnew System::EventHandler(this, &VoteEntry::availBox_Leave);
			this->availBox->Enter += gcnew System::EventHandler(this, &VoteEntry::availBox_Enter);
			this->availBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragDrop);
			this->availBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragEnter);
			this->availBox->DragLeave += gcnew System::EventHandler(this, &VoteEntry::votes_DragLeave);
			this->availBox->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &VoteEntry::votes_ItemDrag);
			this->availBox->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragOver);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Filename";
			this->columnHeader1->Width = 73;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Title";
			this->columnHeader2->Width = 84;
			// 
			// addVoteBtn
			// 
			this->addVoteBtn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->addVoteBtn->Location = System::Drawing::Point(180, 74);
			this->addVoteBtn->Name = L"addVoteBtn";
			this->addVoteBtn->Size = System::Drawing::Size(41, 41);
			this->addVoteBtn->TabIndex = 8;
			this->addVoteBtn->Text = L"=>";
			this->addVoteBtn->UseVisualStyleBackColor = true;
			this->addVoteBtn->Click += gcnew System::EventHandler(this, &VoteEntry::addVoteBtn_Click);
			// 
			// chosenBox
			// 
			this->chosenBox->AllowDrop = true;
			this->chosenBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->chosenBox->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->columnHeader3, this->columnHeader4});
			this->chosenBox->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->chosenBox->Location = System::Drawing::Point(227, 33);
			this->chosenBox->MultiSelect = false;
			this->chosenBox->Name = L"chosenBox";
			this->chosenBox->Size = System::Drawing::Size(157, 173);
			this->chosenBox->TabIndex = 5;
			this->chosenBox->UseCompatibleStateImageBehavior = false;
			this->chosenBox->View = System::Windows::Forms::View::Details;
			this->chosenBox->DoubleClick += gcnew System::EventHandler(this, &VoteEntry::chosenBox_DoubleClick);
			this->chosenBox->Leave += gcnew System::EventHandler(this, &VoteEntry::chosenBox_Leave);
			this->chosenBox->Enter += gcnew System::EventHandler(this, &VoteEntry::chosenBox_Enter);
			this->chosenBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragDrop);
			this->chosenBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragEnter);
			this->chosenBox->DragLeave += gcnew System::EventHandler(this, &VoteEntry::votes_DragLeave);
			this->chosenBox->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &VoteEntry::votes_ItemDrag);
			this->chosenBox->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &VoteEntry::votes_DragOver);
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Filename";
			this->columnHeader3->Width = 71;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Title";
			this->columnHeader4->Width = 79;
			// 
			// okButton
			// 
			this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->okButton->Location = System::Drawing::Point(228, 212);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 6;
			this->okButton->Text = L"&OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &VoteEntry::okButton_Click);
			// 
			// canButton
			// 
			this->canButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->canButton->Location = System::Drawing::Point(309, 212);
			this->canButton->Name = L"canButton";
			this->canButton->Size = System::Drawing::Size(75, 23);
			this->canButton->TabIndex = 7;
			this->canButton->Text = L"C&ancel";
			this->canButton->UseVisualStyleBackColor = true;
			// 
			// unVoteBtn
			// 
			this->unVoteBtn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->unVoteBtn->Location = System::Drawing::Point(180, 121);
			this->unVoteBtn->Name = L"unVoteBtn";
			this->unVoteBtn->Size = System::Drawing::Size(41, 41);
			this->unVoteBtn->TabIndex = 9;
			this->unVoteBtn->Text = L"<=";
			this->unVoteBtn->UseVisualStyleBackColor = true;
			this->unVoteBtn->Click += gcnew System::EventHandler(this, &VoteEntry::unVoteBtn_Click);
			// 
			// VoteEntry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(396, 241);
			this->Controls->Add(this->unVoteBtn);
			this->Controls->Add(this->canButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->chosenBox);
			this->Controls->Add(this->addVoteBtn);
			this->Controls->Add(this->availBox);
			this->Controls->Add(this->voterText);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->voterCombo);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"VoteEntry";
			this->Text = L"VoteEntry";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		private: System::Void check_completed(void)
		{
			if (this->chosenBox->Items->Count == 0)
			{
				this->unVoteBtn->Enabled = false;
				if (this->AcceptButton == this->unVoteBtn)
				{
					this->AcceptButton = this->okButton;
				}
			}
			else
			{
				this->unVoteBtn->Enabled = true;
			}

			if (this->availBox->Items->Count == 0)
			{
				this->addVoteBtn->Enabled = false;
				if (this->AcceptButton == this->addVoteBtn)
				{
					this->AcceptButton = this->okButton;
				}
			}
			else
			{
				this->addVoteBtn->Enabled = true;
			}

			if ((this->voterText->Text == L"") || (this->availBox->Items->Count > 0))
			{
				this->okButton->Enabled = false;
			}
			else
			{
				this->okButton->Enabled = true;
			}
		}

		
		private: System::Void voterText_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			check_completed();
		}
		
		private: System::Void voterCombo_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
		{
			if (
				(this->voterCombo->SelectedIndex > 0) &&
				(this->voterText->Text == L"")
			   )
			{
				this->voterText->Text = (String^)(this->voterCombo->SelectedItem);
			}
		}
		
		private: System::Void unmove_selection(void)
		{
			ArrayList al;

			for each (System::Windows::Forms::ListViewItem^ moving in this->chosenBox->SelectedItems)
			{
				al.Add(moving);
			}
			for each (System::Windows::Forms::ListViewItem^ removing in al)
			{
				this->chosenBox->Items->Remove(removing);
				this->availBox->Items->Add(removing);
			}

			check_completed();
		}
		private: System::Void move_selection(void)
		{
			ArrayList al;

			for each (System::Windows::Forms::ListViewItem^ moving in this->availBox->SelectedItems)
			{
				al.Add(moving);
			}
			for each (System::Windows::Forms::ListViewItem^ removing in al)
			{
				this->availBox->Items->Remove(removing);
				this->chosenBox->Items->Add(removing);
			}

			check_completed();
		}
		private: System::Void addVoteBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			move_selection();
		}
		private: System::Void availBox_DoubleClick(System::Object^  sender, System::EventArgs^  e)
		{
			move_selection();
		}
		
		private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e)
		{

			// ensure that voter's own entry is last
			if ((this->voterCombo->SelectedIndex != 0) &&
				(this->chosenBox->Items->Count > 0))
			{
				CompoEntry ^ce = (CompoEntry^)(this->chosenBox->Items[this->chosenBox->Items->Count-1]->Tag);
				if (ce->composer != (String^)(this->voterCombo->SelectedItem))
				{
					System::Windows::Forms::DialogResult dr;

					for each (CompoEntry ^ce in this->compoentries)
					{
						if (ce->composer == (String^)(this->voterCombo->SelectedItem))
						{
							dr = System::Windows::Forms::MessageBox::Show(
								ce->filename + L" was created by " + ce->composer +
								L"\nand should be in last place.\n\n" +
								L"Do you want to accept these votes anyway?",
								L"EPECULIARORDERING",
								System::Windows::Forms::MessageBoxButtons::YesNo);
	
							if (dr != System::Windows::Forms::DialogResult::Yes)
							{
								return;
							}
							break;
						}
					}
				}
			}

			if (this->voterCombo->SelectedIndex == 0)
			{
				this->vd->votingfor = L"";
			}
			else
			{
				this->vd->votingfor = (String^)(this->voterCombo->SelectedItem);
			}

			if (this->vd->votingfor != L"")
			{
				for each (CompoEntry^ ce in this->compoentries)
				{
					if (ce->composer == this->vd->votingfor)
					{
						ce->voted = true;
						break;
					}
				}
			}

			this->vd->votingby = this->voterText->Text;

			this->vd->votes = gcnew ArrayList;
			for each (System::Windows::Forms::ListViewItem^ lvi in this->chosenBox->Items)
			{
				this->vd->votes->Add(((CompoEntry^)(lvi->Tag))->filename);
			}

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		private: System::Void chosenBox_DoubleClick(System::Object^  sender, System::EventArgs^  e)
		{
			this->unmove_selection();
		}
		private: System::Void unVoteBtn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->unmove_selection();
		}
		private: System::Void availBox_Enter(System::Object^  sender, System::EventArgs^  e)
		{
			this->AcceptButton = this->addVoteBtn;
			check_completed();
		}
		private: System::Void availBox_Leave(System::Object^  sender, System::EventArgs^  e)
		{
			this->AcceptButton = this->okButton;
		}
		private: System::Void chosenBox_Enter(System::Object^  sender, System::EventArgs^  e)
		{
			this->AcceptButton = this->unVoteBtn;
			this->check_completed();
		}
		private: System::Void chosenBox_Leave(System::Object^  sender, System::EventArgs^  e) 
		{
			this->AcceptButton = this->okButton;
		}

		System::Windows::Forms::ListViewItem^ cb_dragging;
		System::Windows::Forms::ListView^ cb_dragfrom;
		int cb_draginsertindex;

		private: System::Void votes_ItemDrag(System::Object^  sender, System::Windows::Forms::ItemDragEventArgs^  e)
		{
			System::Windows::Forms::ListView^ box = (System::Windows::Forms::ListView^)sender;

			cb_dragfrom = box;

			cb_draginsertindex = -1;
			cb_dragging = (System::Windows::Forms::ListViewItem^)(e->Item);
			this->DoDragDrop(L"chosenbox_drag", DragDropEffects::Move);
		}
		private: System::Void votes_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
		{
			System::Windows::Forms::ListView^ box = (System::Windows::Forms::ListView^)sender;

			if ((e->Data->GetDataPresent(DataFormats::Text) && e->Data->GetData(DataFormats::Text) == L"chosenbox_drag" && cb_dragging != nullptr))
			{
				e->Effect = DragDropEffects::Move;
				//e->Effect = e->AllowedEffect;
			}
			else
			{
				e->Effect = DragDropEffects::None;
			}			
			
		}
		private: System::Void votes_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
		{
			System::Windows::Forms::ListView^ box = (System::Windows::Forms::ListView^)sender;

			if (e->Data->GetDataPresent(DataFormats::Text) && e->Data->GetData(DataFormats::Text) == L"chosenbox_drag" && cb_dragging != nullptr)
			{
				//String^ ploble = this->cb_dragging->SubItems[0]->Text;
				// Retrieve the index of the insertion mark;
				//int targetIndex = chosenBox->InsertionMark->Index;

				// If it is not on an index, assume it is inserting after the last element
				// (or empty list)
				if ( cb_draginsertindex == -1 )
				{
					cb_draginsertindex = box->Items->Count;
				}

				box->Items->Insert( cb_draginsertindex, (System::Windows::Forms::ListViewItem^)(cb_dragging->Clone()) );

				// Remove the original copy of the dragged item.
				cb_dragfrom->Items->Remove( cb_dragging );
				cb_dragging = nullptr;

				this->check_completed();
			}
		}
		private: System::Void votes_DragOver(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
		{
			System::Windows::Forms::ListView^ box = (System::Windows::Forms::ListView^)sender;

			if (e->Data->GetDataPresent(DataFormats::Text) && e->Data->GetData(DataFormats::Text) == L"chosenbox_drag" && cb_dragging != nullptr)
			{
				// Retrieve the client coordinates of the mouse pointer.
				Point targetPoint = box->PointToClient( Point(e->X,e->Y) );

				// Retrieve the index of the item closest to the mouse pointer.
				//cb_draginsertindex = chosenBox->GetItemAt(e->X, e->Y)->Index;
				System::Windows::Forms::ListViewItem^ lvi = box->GetItemAt(targetPoint.X, targetPoint.Y);
				if (lvi != nullptr)
				{
					lvi->EnsureVisible();
					cb_draginsertindex = lvi->Index;
				}
				else
				{
					cb_draginsertindex = -1;
				}

				if ( cb_draginsertindex > -1 )
				{
					// Determine whether the mouse pointer is to the left or
					// the right of the midpoint of the closest item and set
					// the InsertionMark.AppearsAfterItem property accordingly.
					Rectangle^ itemBounds = box->GetItemRect( cb_draginsertindex );
					if ( targetPoint.Y > itemBounds->Top + (itemBounds->Height / 2) )
					{
						cb_draginsertindex++;
						// after
						//chosenBox->InsertionMark->AppearsAfterItem = true;
					}
					else
					{
						// before
						//chosenBox->InsertionMark->AppearsAfterItem = false;
					}
				}

				//cb_draginsertindex = targetIndex;

			}
		}
		private: System::Void votes_DragLeave(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::ListView^ box = (System::Windows::Forms::ListView^)sender;

			//chosenBox->InsertionMark->Index = -1;
		}
};
}
