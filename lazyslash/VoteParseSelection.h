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
		int chosen_idx;

		VoteParseSelection(ArrayList^ voteplugin_results)
		{
			this->voteplugin_results = voteplugin_results;
			chosen_idx = 0;

			InitializeComponent();
			
			this->CancelButton = this->canButton;
			this->AcceptButton = this->okButton;

		}

	protected:
		ArrayList^ voteplugin_results;

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
	//private: System::Windows::Forms::RadioButton^  choiceButton;
	//private: System::Windows::Forms::ListView^  votesList;
	//private: System::Windows::Forms::Label^  voterLabel;


	private: System::Windows::Forms::Button^  canButton;
	private: System::Windows::Forms::Button^  okButton;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		ArrayList^ votelists;
		ArrayList^ radiobuttons;
		ArrayList^ voterlabels;

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
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// canButton
			// 
			this->canButton->Location = System::Drawing::Point(355, 209);
			this->canButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom)));
			this->canButton->Name = L"canButton";
			this->canButton->Size = System::Drawing::Size(75, 23);
			this->canButton->TabIndex = 1;
			this->canButton->Text = L"Cancel";
			this->canButton->UseVisualStyleBackColor = true;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(274, 209);
			this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom)));
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &VoteParseSelection::okButton_Click);
			// 
			// votesList
			// 

			votelists = gcnew ArrayList;
			radiobuttons = gcnew ArrayList;
			voterlabels = gcnew ArrayList;

			int next_loc = 0;

			this->chosen_idx = -1;
			
			int i=0, possibilities=0;

			for(i=0; i<this->voteplugin_results->Count; i++)
			{
				VotePlugin::IVotePlugin^ ivp = (VotePlugin::IVotePlugin^)( ((array<Object^>^)(this->voteplugin_results[i]))[0] );

				ArrayList^ vote_output;
				String^ errormsg;

				if (ivp == nullptr)
				{
					vote_output = nullptr;
					errormsg = (String^)( ((array<Object^>^)(this->voteplugin_results[i]))[1] );
				}
				else
				{
					// array of VotePlugin::Entry objects
					vote_output = (ArrayList^)( ((array<Object^>^)(this->voteplugin_results[i]))[1] );
					errormsg = nullptr;
				}

				System::Windows::Forms::RadioButton^ choiceButton = gcnew System::Windows::Forms::RadioButton();
				System::Windows::Forms::ListView^ votesList = gcnew System::Windows::Forms::ListView();
				System::Windows::Forms::Label^ voterLabel = gcnew System::Windows::Forms::Label();
				votelists->Add(votesList);
				radiobuttons->Add(choiceButton);
				voterlabels->Add(voterLabel);

				votesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
					| System::Windows::Forms::AnchorStyles::Left));
				votesList->Location = System::Drawing::Point(next_loc, 39);
				votesList->Name = L"votesList";
				votesList->Size = System::Drawing::Size(200, 149);
				votesList->TabIndex = 0;
				votesList->UseCompatibleStateImageBehavior = false;
				votesList->View = System::Windows::Forms::View::Details;
				votesList->FullRowSelect = true;

				// populate list
				if (ivp != nullptr)
				{
					if (this->chosen_idx == -1)
					{
						this->chosen_idx = i;
						choiceButton->Checked = true;
					}
					possibilities++;

					votesList->Columns->Add("Filename");
					votesList->Columns->Add("Title");

					for each (VotePlugin::Entry^ vpe in vote_output)
					{
						System::Windows::Forms::ListViewItem^ lvi = gcnew System::Windows::Forms::ListViewItem(gcnew array<String^>{vpe->filename, vpe->songtitle});
						votesList->Items->Add(lvi);
					}

					votesList->Columns[0]->Width = -2;
					votesList->Columns[1]->Width = -2;
				}
				else
				{
					votesList->Columns->Add("Error details");
					votesList->Items->Add(errormsg->Substring(errormsg->IndexOf(':') + 2));
					votesList->Columns[0]->Width = -2;
				}

				// 
				// choiceButton
				// 
				choiceButton->AutoSize = true;
				choiceButton->Location = System::Drawing::Point(next_loc+3, 3);
				choiceButton->Name = L"choiceButton";
				choiceButton->Size = System::Drawing::Size(85, 17);
				choiceButton->TabIndex = 1;
				choiceButton->TabStop = true;
				if (ivp != nullptr)
				{
					choiceButton->Text = ivp->vp_name + L" " + ivp->vp_version;
					choiceButton->Enabled = true;
				}
				else
				{
					choiceButton->Text = errormsg->Substring(0, errormsg->IndexOf(':'));
					choiceButton->Enabled = false;
					choiceButton->Checked = false;
				}
				choiceButton->UseVisualStyleBackColor = true;
				// 
				// voterLabel
				// 
				voterLabel->AutoSize = true;
				voterLabel->Location = System::Drawing::Point(next_loc+3, 23);
				voterLabel->Name = L"voterLabel";
				voterLabel->Size = System::Drawing::Size(35, 13);
				voterLabel->TabIndex = 2;
				if (ivp != nullptr)
				{
					if (ivp->voter != nullptr)
					{
						voterLabel->Text = L"Votes by: " + ivp->voter;
					}
					else
					{
						voterLabel->Text = L"Voter unknown.";
					}
				}
				else
				{
					voterLabel->Text = L"[parse error]";
				}

				next_loc += votesList->Width + votesList->Margin.Right;
			}

			if (possibilities == 0)
			{
				this->okButton->Enabled = false;
			}

			/*
			
			// these don't work, because the later call to ::Show() won't succeed
			// if the window is pre-closed.

			if (i == 0)
			{
				this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				this->Close();
				return;
			}
			if (i == 1 && possibilities == 1)
			{
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
				return;
			}
			*/
			

			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			
			for(int i=0; i < votelists->Count; i++)
			{
				this->panel1->Controls->Add((System::Windows::Forms::Label^)(voterlabels[i]));
				this->panel1->Controls->Add((System::Windows::Forms::RadioButton^)(radiobuttons[i]));
				this->panel1->Controls->Add((System::Windows::Forms::ListView^)(votelists[i]));
			}
			
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(418, 191);
			this->panel1->TabIndex = 0;
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
			this->Text = L"You may choose the results that you like the most";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->chosen_idx = 0;

		for each (System::Windows::Forms::RadioButton^ rb in this->radiobuttons)
		{
			if (rb->Enabled && rb->Checked)
			{
				break;
			}
			this->chosen_idx++;
		}
		if (this->chosen_idx == this->radiobuttons->Count)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		}
		else
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
		this->Close();
	}
};
}
