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
		}
		CompoEntry(String^ filespec, String^ songtitle)
		{
			this->filespec = filespec;
			this->songtitle = songtitle;
			this->composer = L"";
			this->voted = false;
		}

		String^ filespec;
		String^ songtitle;
		String^ composer;
		bool voted;

	protected:

		~CompoEntry()
		{
		}

	private:
	};
}
