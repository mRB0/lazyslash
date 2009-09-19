// vp_lazyslash.h

#pragma once

using namespace System;

namespace vp_lazyslash {

	public ref class vp_lazyslash : VotePlugin::IVotePlugin
	{
		System::Collections::ArrayList^ entries;
		System::Collections::ArrayList^ not_voted;

	public:

		virtual void set_entries(System::Collections::ArrayList^ entries)
		{
			this->entries = entries;
		}

		virtual void set_not_voted(System::Collections::ArrayList^ not_voted)
		{
			this->not_voted = not_voted;
		}

		virtual System::Collections::ArrayList^ parse_votes(System::Collections::ArrayList^ irctext)
		{
			return gcnew System::Collections::ArrayList;
		}


		property String^ vp_name 
		{
			virtual String^ get() { return L"lazyslash"; }
		}

		property String^ vp_author
		{
			virtual String^ get() { return L"mrb"; }
		}

		property String^ vp_version
		{
			virtual String^ get() { return L"banana"; }
		}

	};
}
