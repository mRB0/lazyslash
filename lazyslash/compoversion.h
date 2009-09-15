#pragma once

/*
 * $Id$
 */

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
		static String^ version = L"0.1.1";
		static String^ svnrevision = L"$Rev$";
		static String^ svnid = L"$Id$";

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
