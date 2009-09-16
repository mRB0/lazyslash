/*
 * $Id$
 */

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace lazyslash {

	/// <summary>
	/// Summary for VoteData
	/// </summary>
	public ref class VoteData
	{
	public:
		VoteData(void)
		{
			votingby = L"";
			votingfor = L"";
			votes = gcnew System::Collections::ArrayList;
		}
		
		String^ votingby;
		String^ votingfor;
		System::Collections::ArrayList^ votes;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VoteData()
		{
		}

	private:
	};
}
