#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lazyslash {

	/// <summary>
	/// Summary for ResultsDisplay
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ResultsDisplay : public System::Windows::Forms::Form
	{
	public:
		ResultsDisplay(String^ resultsText)
		{
			InitializeComponent();
			
			this->resultsBox->Text = resultsText;
			this->CancelButton = this->closeButton;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ResultsDisplay()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::TextBox^  resultsBox;
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
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->resultsBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// closeButton
			// 
			this->closeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->closeButton->Location = System::Drawing::Point(475, 293);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(75, 23);
			this->closeButton->TabIndex = 0;
			this->closeButton->Text = L"Close";
			this->closeButton->UseVisualStyleBackColor = true;
			// 
			// resultsBox
			// 
			this->resultsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->resultsBox->BackColor = System::Drawing::Color::Black;
			this->resultsBox->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->resultsBox->ForeColor = System::Drawing::Color::DarkOrange;
			this->resultsBox->Location = System::Drawing::Point(12, 12);
			this->resultsBox->Multiline = true;
			this->resultsBox->Name = L"resultsBox";
			this->resultsBox->ReadOnly = true;
			this->resultsBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->resultsBox->Size = System::Drawing::Size(538, 275);
			this->resultsBox->TabIndex = 1;
			// 
			// ResultsDisplay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 328);
			this->Controls->Add(this->resultsBox);
			this->Controls->Add(this->closeButton);
			this->Name = L"ResultsDisplay";
			this->Text = L"Results!";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
