#pragma once

#include "CompoEntry.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lazyslash {
	
	/// <summary>
	/// Summary for EntryEditor
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class EntryEditor : public System::Windows::Forms::Form
	{
	public:
		EntryEditor(CompoEntry^ ce, ArrayList ^compoentries)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//this->okButton->IsDefault::set(true);
			this->CancelButton = this->canButton;
			this->AcceptButton = this->okButton;
			
			this->ce = ce;
			this->compoentries = compoentries;
			
			this->fullpathBox->Text = this->ce->filespec;
			this->titleField->Text = this->ce->songtitle;
			this->filenameField->Text = this->ce->filename;
			this->nickField->Text = this->ce->composer;
		}

	protected:
		CompoEntry ^ce;
		ArrayList ^compoentries;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EntryEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  nickField;
	private: System::Windows::Forms::TextBox^  filenameField;
	private: System::Windows::Forms::TextBox^  titleField;



	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  canButton;
	private: System::Windows::Forms::TextBox^  fullpathBox;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nickField = (gcnew System::Windows::Forms::TextBox());
			this->filenameField = (gcnew System::Windows::Forms::TextBox());
			this->titleField = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->canButton = (gcnew System::Windows::Forms::Button());
			this->fullpathBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nick";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(121, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Filename";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(227, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Song title";
			// 
			// nickField
			// 
			this->nickField->AcceptsReturn = true;
			this->nickField->Location = System::Drawing::Point(15, 25);
			this->nickField->Name = L"nickField";
			this->nickField->Size = System::Drawing::Size(103, 20);
			this->nickField->TabIndex = 3;
			// 
			// filenameField
			// 
			this->filenameField->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->filenameField->Location = System::Drawing::Point(124, 25);
			this->filenameField->Name = L"filenameField";
			this->filenameField->Size = System::Drawing::Size(100, 20);
			this->filenameField->TabIndex = 4;
			// 
			// titleField
			// 
			this->titleField->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->titleField->Location = System::Drawing::Point(230, 25);
			this->titleField->Name = L"titleField";
			this->titleField->Size = System::Drawing::Size(139, 20);
			this->titleField->TabIndex = 5;
			// 
			// okButton
			// 
			this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->okButton->Location = System::Drawing::Point(213, 51);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 6;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &EntryEditor::okButton_Click);
			// 
			// canButton
			// 
			this->canButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->canButton->Location = System::Drawing::Point(294, 51);
			this->canButton->Name = L"canButton";
			this->canButton->Size = System::Drawing::Size(75, 23);
			this->canButton->TabIndex = 7;
			this->canButton->Text = L"Cancel";
			this->canButton->UseVisualStyleBackColor = true;
			// 
			// fullpathBox
			// 
			this->fullpathBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->fullpathBox->Location = System::Drawing::Point(15, 53);
			this->fullpathBox->Name = L"fullpathBox";
			this->fullpathBox->ReadOnly = true;
			this->fullpathBox->Size = System::Drawing::Size(192, 20);
			this->fullpathBox->TabIndex = 8;
			// 
			// EntryEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(381, 86);
			this->Controls->Add(this->fullpathBox);
			this->Controls->Add(this->canButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->titleField);
			this->Controls->Add(this->filenameField);
			this->Controls->Add(this->nickField);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EntryEditor";
			this->Text = L"EntryEditor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

		private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->nickField->Text == L"")
			{
				System::Windows::Forms::MessageBox::Show(
					L"Nick can't be left blank.",
					L"Blast it all!",
					System::Windows::Forms::MessageBoxButtons::OK);
				return;
			}

			for each (CompoEntry ^other in this->compoentries)
			{
				if (this->ce == other)
				{
					continue;
				}

				if (this->filenameField->Text == other->filename)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Filename matches another entry.",
						L"Malarky!",
						System::Windows::Forms::MessageBoxButtons::OK);
					return;
				}
				if (this->nickField->Text == other->composer)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Nick matches another entry.",
						L"Hogwash!",
						System::Windows::Forms::MessageBoxButtons::OK);
					return;
				}
			}

			this->ce->filespec = this->fullpathBox->Text;
			this->ce->songtitle = this->titleField->Text;
			this->ce->filename = this->filenameField->Text;
			this->ce->composer = this->nickField->Text;

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}
