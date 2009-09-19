// vp_lazyslash.h

#pragma once

using namespace System;

namespace vp_lazyslash {

	public ref class vp_lazyslash : VotePlugin::IVotePlugin
	{
		System::Collections::ArrayList^ entries;
		System::Collections::ArrayList^ not_voted;

	public:

		static int leven_threshold = 4;

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

		property String^ voter
		{
			virtual String^ get() { return this->_voter; }
		}

		// * //

		vp_lazyslash(void)
		{
			this->_voter = nullptr;
		}

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
			System::Collections::ArrayList^ parsed = gcnew System::Collections::ArrayList;
			
			System::Collections::ArrayList^ votetokens = gcnew System::Collections::ArrayList;
			String^ voter = nullptr;
			
			for each (String^ line in irctext)
			{

				System::Text::RegularExpressions::Regex re_nick(L"[^<]*<([^>]+)>");
				System::Text::RegularExpressions::Match^ m_nick = re_nick.Match(line);
				int start_votelook = 0;

				if (m_nick->Success)
				{
					voter = m_nick->Groups[1]->Value;
					start_votelook = m_nick->Index+m_nick->Length;
				}
				System::Text::RegularExpressions::Regex re_songs(L"[^a-zA-Z0-9_]*([0-9][0-9]?[\.:,;\-]?[<>:\"/\\\|\?\* ]*)?([^<>:\"/\\\|\?\* ]+)", System::Text::RegularExpressions::RegexOptions::IgnoreCase);
				System::Text::RegularExpressions::Match^ m_songs = re_songs.Match(line, start_votelook);

				while (m_songs->Success)
				{
					votetokens->Add(System::IO::Path::GetFileNameWithoutExtension(m_songs->Groups[2]->Value));
					m_songs = m_songs->NextMatch();
				}
			}
			if (votetokens->Count == 0)
			{
				throw gcnew VotePlugin::VoteParseException(L"Couldn't parse any entries");
			}
			
			this->_voter = voter;

			// check votetokens for real entries
			for each (String^ vote in votetokens)
			{
				int lowestlscore = -1;
				String^ result = nullptr;

				for each (VotePlugin::Entry^ e in this->entries)
				{
					if (parsed->Contains(e->filename))
					{
						// already-found results are not eligible to be found again!
						continue;
					}

					int lscore = VotePlugin::Helpers::levenshtein(System::IO::Path::GetFileNameWithoutExtension(e->filename), vote);
					if (lscore < this->leven_threshold && (lowestlscore == -1 || lscore < lowestlscore))
					{
						lowestlscore = lscore;
						result = e->filename;
					}
				}

				if (result != nullptr)
				{
					parsed->Add(result);
				}

			}

			return VotePlugin::Helpers::votestrings_to_entries(parsed, this->entries);
		}

	protected:
		String^ _voter;

	};
}
