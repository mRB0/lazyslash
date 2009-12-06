#pragma once

/*
 * $Id$
 */

#include "svnrev.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace lazyslash { 
	
	/// <summary>
	/// Summary for compoversion
	/// </summary>
	public ref class compoversion
	{
	public:
		static String^ version = L"1.0.0";
		static String^ svnrevision = SVN_REVSTR;
		static String^ svnrevdate = SVN_REVDATE;

		compoversion(void)
		{
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~compoversion()
		{
		}

	private:
	};
}
