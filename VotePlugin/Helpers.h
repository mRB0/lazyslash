#pragma once

using namespace System;

namespace VotePlugin {
	
	public ref class EntryFilenameComparer : public System::Collections::IComparer
	{
	public:
		virtual int Compare(Object^ left, Object^ right)
		{
			return String::Compare( ((VotePlugin::Entry^)left)->filename, ((VotePlugin::Entry^)right)->filename );
		}
	};
	
	public ref class EntryAuthorComparer : public System::Collections::IComparer
	{
	public:
		virtual int Compare(Object^ left, Object^ right)
		{
			return String::Compare( ((VotePlugin::Entry^)left)->author, ((VotePlugin::Entry^)right)->author );
		}
	};

	public ref class EntryTitleComparer : public System::Collections::IComparer
	{
	public:
		virtual int Compare(Object^ left, Object^ right)
		{
			return String::Compare( ((VotePlugin::Entry^)left)->songtitle, ((VotePlugin::Entry^)right)->songtitle );
		}
	};

	public ref class Helpers
	{
	public:
		/*
		 * votes: In-order ArrayList^ of String^ items (voted filenames)
		 * entry_list: ArrayList^ of all Entry^ items
		 *
		 * Return: In-order ArrayList^ of voted-for Entry^ items
		 */
		static System::Collections::ArrayList^ votestrings_to_entries(System::Collections::ArrayList^ votes, System::Collections::ArrayList^ entry_list)
		{
			System::Collections::ArrayList^ vote_entries = gcnew System::Collections::ArrayList;
			
			// for each String^ in votes,
			// find an entry_list[...]->Entry with a matching filename,
			// and stuff it into vote_entries
			entry_list->Sort(gcnew EntryFilenameComparer);

			for each(String^ vote in votes)
			{
				VotePlugin::Entry ve(L"", vote, L"");
				int idx = entry_list->BinarySearch(%ve, gcnew EntryFilenameComparer);

				if (idx < 0)
				{
					throw gcnew System::IndexOutOfRangeException(L"Entry not in entry_list");
				}

				vote_entries->Add(entry_list[idx]);
			}
			
			return vote_entries;
		}

		static int levenshtein(String^ s, String^ t)
		{
			s = s->ToLower();
			t = t->ToLower();

			// d is a table with m+1 rows and n+1 columns
			array<int,2>^ d = gcnew array<int,2>(s->Length+1, t->Length+1);

			int i, j;

			for (i=0; i < s->Length+1; i++)
			{
				d[i, 0] = i; // deletion
			}
			for (j=0; j < t->Length+1; j++)
			{
				d[0, j] = j; // insertion
			}

			for (j=1; j < t->Length+1; j++)
			{
				for (i=1; i < s->Length+1; i++)
				{
					
					if (s[i-1] == t[j-1])
					{
						d[i, j] = d[i-1, j-1];
					}
					else
					{
						int del = d[i-1, j] + 1;   // deletion
						int ins = d[i, j-1] + 1;   // insertion
						int sub = d[i-1, j-1] + 1; // substitution

						if (del < ins && del < sub)
						{
							d[i, j] = del;
						}
						else if (ins < sub)
						{
							d[i, j] = ins;
						}
						else
						{
							d[i, j] = sub;
						}
					}
				
				}
			}

			return d[s->Length, t->Length];
		}

	};
}
