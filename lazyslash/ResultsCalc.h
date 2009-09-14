#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;

#include "VoteData.h"
#include "CompoEntry.h"

namespace lazyslash {
	
	ref class ScoreComparer: public IComparer
	{
private:

		// Calls CaseInsensitiveComparer.Compare with the parameters reversed.
		virtual int Compare( Object^ x, Object^ y ) = IComparer::Compare
		{
			//return (gcnew Comparer)->Compare(((CompoEntry^)y)->score, ((CompoEntry^)x)->score);
			if ( ((CompoEntry^)y)->score < ((CompoEntry^)x)->score)
			{
				return -1;
			}
			if ( ((CompoEntry^)y)->score > ((CompoEntry^)x)->score)
			{
				return 1;
			}
			return 0;
		}

	};

	/// <summary>
	/// Summary for ResultsCalc
	/// </summary>
	public ref class ResultsCalc :  public System::ComponentModel::Component
	{
	public:
		ResultsCalc(ArrayList^ entries, ArrayList^ votes, String^ componame)
		{
			this->entries = entries;
			this->votes = votes;
			this->componame = componame;

			results = L"No results calculated!";
		}

		System::Void calculate(void)
		{
			for each (CompoEntry^ ce in this->entries)
			{
				ce->score = 0;
			}

			for each (VoteData^ vd in this->votes)
			{
				int score = this->entries->Count;

				for each (String^ vote in vd->votes)
				{
					for each (CompoEntry^ ce in this->entries)
					{
						if (ce->filename == vote)
						{
							ce->score += score;
							break;
						}
					}
					score--;
				}
			}

			this->generate_results_string();
		}

		System::Void generate_results_string(void)
		{
			results  = "** " + componame + " RESULTS!! **\n";
			results += "--\n";

			entries->Sort(gcnew ScoreComparer);
			
			int place = 0, lastscore = -1;

			for each (CompoEntry^ ce in entries)
			{
				if (ce->score != lastscore)
				{
					place++;
				}
				lastscore = ce->score;

				results += "[ PLACE " +
					place.ToString() + 
					" -=> " + 
					ce->filename + 
					" <=- Done by -=> " +
					ce->composer +
					" <=- with " +
					ce->score.ToString() +
					"pts ]\n";
			}
			results += "--\n";
			
			for each (VoteData^ vd in votes)
			{
				String^ votestr;
				if (vd->votingfor == L"")
				{
					votestr = vd->votingby + " (guest)";
				}
				else if (vd->votingby != vd->votingfor)
				{
					votestr = vd->votingby + " (voting for " + vd->votingfor + ")";
				}
				else
				{
					votestr = vd->votingby;
				}
				results += "--=> " +
					votestr +
					" <=- has voted as follows:\n";
				
				int i=0;
				for each (String^ vote in vd->votes)
				{
					i++;
					results += "[\\_Place -=> " +
						i.ToString() +
						" <=-=> " +
						vote +
						"_/]\n";
				}
			}

			results += "-----<O>-----\n";
			results += "These results were generated using lazyslash compomagoo. (c)2009 Mike Burke (mrb) - mrburke@gmail.com\n";

			// oops windows
			results = results->Replace("\n", "\r\n");
			
		}

		String^ results;
		String^ componame;


	protected:

		ArrayList^ entries;
		ArrayList^ votes;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ResultsCalc()
		{
		}

	private:
	};
}
