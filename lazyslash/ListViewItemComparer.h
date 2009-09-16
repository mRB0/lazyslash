/*
 * $Id$
 */

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace lazyslash {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class ListViewItemComparer: public IComparer
	{
	private:
		int col;
		bool ascending;
		System::Windows::Forms::ListViewItem^ ignoreditem;

	public:
		ListViewItemComparer()
		{
			col = 0;
		}

		ListViewItemComparer( int column, bool ascending, System::Windows::Forms::ListViewItem^ ignoreditem )
		{
			col = column;
			this->ascending = ascending;
			this->ignoreditem = ignoreditem;
		}

		virtual int Compare( Object^ x, Object^ y )
		{
			if (ignoreditem == (dynamic_cast<ListViewItem^>(x)))
			{
				return 1;
			}
			if (ignoreditem == (dynamic_cast<ListViewItem^>(y)))
			{
				return -1;
			}

			int reverse = 1;

			if (!ascending)
			{
				reverse = -1;
			}

			return reverse * String::Compare( (dynamic_cast<ListViewItem^>(x))->SubItems[ col ]->Text,
								       (dynamic_cast<ListViewItem^>(y))->SubItems[ col ]->Text );
		}
	};

}
