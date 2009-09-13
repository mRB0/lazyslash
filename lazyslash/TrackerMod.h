#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace lazyslash {

	/// <summary>
	/// Summary for TrackerMod
	/// </summary>
	public ref class TrackerMod :  public System::ComponentModel::Component
	{
	public:
		TrackerMod(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		TrackerMod(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

		static String^ TrackerMod::GetITTitle(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			bool is_it = true;
			for each (unsigned char cmp in "IMPM")
			{
				if (breader->ReadByte() != cmp)
				{
					is_it = false;
				}
			}
			if (is_it)
			{
				array<unsigned char>^ namedata = breader->ReadBytes(26);

				int titlelen = System::Array::IndexOf((array<unsigned char>^)namedata, (unsigned char)0);
				
				Console::WriteLine("titlelen is " + titlelen.ToString());

				if (titlelen == -1)
				{
					titlelen = 26;
				}
				
				System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();

				songtitle = ae->GetString(namedata, 0, titlelen);
				
				
			}
			
			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::Get669Title(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			// support 669 and extended 669, two different file markers
			bool is_669 = true;
			for each (unsigned char cmp in "if")
			{
				if (breader->ReadByte() != cmp)
				{
					is_669 = false;
				}
			}
			if (!is_669)
			{
				is_669 = true;
				for each (unsigned char cmp in "JN")
				{
					if (breader->ReadByte() != cmp)
					{
						is_669 = false;
					}
				}
			}

			if (is_669)
			{
				// I think the 669 titles are space-padded, but anyway...

				array<unsigned char>^ namedata = breader->ReadBytes(108);

				int titlelen = System::Array::IndexOf((array<unsigned char>^)namedata, (unsigned char)0);
				
				if (titlelen == -1)
				{
					titlelen = 108;
				}
				
				System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();

				songtitle = ae->GetString(namedata, 0, titlelen);
				
				
			}
			
			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::GetMTMTitle(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			bool is_mtm = true;
			for each (unsigned char cmp in "MTM\x10")
			{
				if (breader->ReadByte() != cmp)
				{
					is_mtm = false;
				}
			}
			if (is_mtm)
			{
				array<unsigned char>^ namedata = breader->ReadBytes(20);

				int titlelen = System::Array::IndexOf((array<unsigned char>^)namedata, (unsigned char)0);
				
				if (titlelen == -1)
				{
					titlelen = 20;
				}
				
				System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();

				songtitle = ae->GetString(namedata, 0, titlelen);
				
				
			}
			
			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::GetXMTitle(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			bool is_xm = true;
			for each (unsigned char cmp in "Extended Module: ")
			{
				if (breader->ReadByte() != cmp)
				{
					songtitle = L"Failed";
					is_xm = false;
				}
			}
			if (is_xm)
			{
				array<unsigned char>^ namedata = breader->ReadBytes(20);
				int titlelen = 20; // always space-padded

				System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();

				songtitle = ae->GetString(namedata, 0, titlelen);
			}
			
			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::GetS3MTitle(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			// s3m stores song name first, so let's read it first...
			array<unsigned char>^ namedata = breader->ReadBytes(28);

			int titlelen = System::Array::IndexOf((array<unsigned char>^)namedata, (unsigned char)0);
			
			if (titlelen == -1)
			{
				titlelen = 28;
			}
				
			bool is_s3m = true;
			for each (unsigned char cmp in "\x1A\x10")
			{
				if (breader->ReadByte() != cmp)
				{
					is_s3m = false;
				}
			}

			if (is_s3m)
			{
				System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();
	
				songtitle = ae->GetString(namedata, 0, titlelen);
			}
			
			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::GetMODTitle(String^ filespec)
		{
			String ^songtitle = gcnew String(L"");

			System::IO::FileStream^ inf;
			
			inf = System::IO::File::Open(filespec, System::IO::FileMode::Open, System::IO::FileAccess::Read);
			
			System::IO::BinaryReader^ breader = gcnew System::IO::BinaryReader(inf);
			
			// mod stores the name (20 characters, nulls) and that is all.
			array<unsigned char>^ namedata = breader->ReadBytes(20);

			int titlelen = System::Array::IndexOf((array<unsigned char>^)namedata, (unsigned char)0);
			
			if (titlelen == -1)
			{
				titlelen = 20;
			}
				
			System::Text::ASCIIEncoding^ ae = gcnew System::Text::ASCIIEncoding();
	
			songtitle = ae->GetString(namedata, 0, titlelen);

			inf->Close();

			return songtitle;
		}

		static String^ TrackerMod::GetSongTitle(String ^filespec)
		{
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".it")
			{
				return TrackerMod::GetITTitle(filespec);
			}
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".xm")
			{
				return TrackerMod::GetXMTitle(filespec);
			}
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".s3m")
			{
				return TrackerMod::GetS3MTitle(filespec);
			}
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".mtm")
			{
				return TrackerMod::GetMTMTitle(filespec);
			}
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".mod")
			{
				return TrackerMod::GetMODTitle(filespec);
			}
			if (System::IO::Path::GetExtension(filespec)->ToLowerInvariant() == ".669")
			{
				return TrackerMod::Get669Title(filespec);
			}

			return L"";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrackerMod()
		{
			if (components)
			{
				delete components;
			}
		}

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
			components = gcnew System::ComponentModel::Container();
		}
#pragma endregion
	};
}
