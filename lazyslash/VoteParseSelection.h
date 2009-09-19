#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lazyslash {

	/// <summary>
	/// Summary for VoteParseSelection
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class VoteParseSelection : public System::Windows::Forms::Form
	{
	public:
		VoteParseSelection(void)
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
		~VoteParseSelection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  choiceButton;
	private: System::Windows::Forms::ListView^  votesList;


	private: System::Windows::Forms::Button^  canButton;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Label^  voterLabel;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VoteParseSelection::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->canButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->votesList = (gcnew System::Windows::Forms::ListView());
			this->choiceButton = (gcnew System::Windows::Forms::RadioButton());
			this->voterLabel = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->voterLabel);
			this->panel1->Controls->Add(this->choiceButton);
			this->panel1->Controls->Add(this->votesList);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(418, 191);
			this->panel1->TabIndex = 0;
			// 
			// canButton
			// 
			this->canButton->Location = System::Drawing::Point(355, 209);
			this->canButton->Name = L"canButton";
			this->canButton->Size = System::Drawing::Size(75, 23);
			this->canButton->TabIndex = 1;
			this->canButton->Text = L"Cancel";
			this->canButton->UseVisualStyleBackColor = true;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(274, 209);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &VoteParseSelection::okButton_Click);
			// 
			// votesList
			// 
			this->votesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->votesList->Location = System::Drawing::Point(0, 39);
			this->votesList->Name = L"votesList";
			this->votesList->Size = System::Drawing::Size(121, 149);
			this->votesList->TabIndex = 0;
			this->votesList->UseCompatibleStateImageBehavior = false;
			// 
			// choiceButton
			// 
			this->choiceButton->AutoSize = true;
			this->choiceButton->Location = System::Drawing::Point(3, 3);
			this->choiceButton->Name = L"choiceButton";
			this->choiceButton->Size = System::Drawing::Size(85, 17);
			this->choiceButton->TabIndex = 1;
			this->choiceButton->TabStop = true;
			this->choiceButton->Text = L"radioButton1";
			this->choiceButton->UseVisualStyleBackColor = true;
			// 
			// voterLabel
			// 
			this->voterLabel->AutoSize = true;
			this->voterLabel->Location = System::Drawing::Point(3, 23);
			this->voterLabel->Name = L"voterLabel";
			this->voterLabel->Size = System::Drawing::Size(35, 13);
			this->voterLabel->TabIndex = 2;
			this->voterLabel->Text = L"label1";
			// 
			// VoteParseSelection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 244);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->canButton);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"VoteParseSelection";
			this->Text = L"VoteParseSelection";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
