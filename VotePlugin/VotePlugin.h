// VotePlugin.h

#pragma once

using namespace System;

namespace VotePlugin {
	
	public ref class Entry
	{
	public:
		Entry()
		{
			author = L"";
			filename = L"";
			songtitle = L"";
		}

		Entry(String^ author, String^ filename, String^ songtitle)
		{
			this->author = author;
			this->filename = filename;
			this->songtitle = songtitle;
		}

		String^ author;
		String^ filename;
		String^ songtitle;
	};

	public ref class VoteParseException : System::Exception
	{
	public:
		VoteParseException(String^ message) : System::Exception(message) { }
	};

	public interface class IVotePlugin
	{
	public:
		//IVotePlugin(System::Collections::ArrayList^ entries, System::Collections::ArrayList^ not_voted);

		/*
		 * entries: ArrayList^ of Entry^ objects.
		 *          List of entered songs.
		 */
		void set_entries(System::Collections::ArrayList^ entries);
		/*
		 * not_voted: ArrayList^ of String^s.
		 *            List of entrants (from entries) who have not yet voted.
		 */
		void set_not_voted(System::Collections::ArrayList^ not_voted);
		
		/*
		 * Parse vote text, returning the list of votes.
		 * Any entries missing in the returned list will be assumed to be
		 * missing in the vote text, and the compo host will be able to sort
		 * them manually.
		 *
		 * irctext: ArrayList^ of vote text, one element per IRC line.
		 *
		 * Returns: ArrayList^ of Entry^ objects, from highest-voted to lowest.
		 */
		System::Collections::ArrayList^ parse_votes(System::Collections::ArrayList^ irctext);

		/*
		 * name of the author who submitted the votes, or nullptr if unknown
		 */
		property String^ voter { virtual String^ get(); }

		/*
		 * vp_name: Name of vote plugin.
		 * vp_author: Author of vote plugin.
		 * vp_version: Version of vote plugin.
		 */
		property String^ vp_name { virtual String^ get(); }
		property String^ vp_author { virtual String^ get(); }
		property String^ vp_version { virtual String^ get(); }

	};
}
