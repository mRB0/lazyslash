#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace lazyslash {

	/// <summary>
	/// Summary for CompoEntry
	/// </summary>
	public ref class CompoEntry
	{
	public:
		CompoEntry(void)
		{
			this->filespec = L"";
			this->filename = L"";
			this->songtitle = L"";
			this->composer = L"";
			this->voted = false;
			score = 0;
		}
		CompoEntry(String^ filespec, String^ songtitle)
		{
			this->filespec = filespec;
			this->filename = System::IO::Path::GetFileName(filespec);
			this->songtitle = songtitle;
			this->composer = L"";
			this->voted = false;
			score = 0;
		}

		String^ filespec;
		String^ filename;
		String^ songtitle;
		String^ composer;
		int score;
		bool voted;

	protected:

		~CompoEntry()
		{
		}

	private:
	};
}
