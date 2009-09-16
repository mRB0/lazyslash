#pragma once

/*
 * $Id$
 */

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;

#include "VoteData.h"
#include "CompoEntry.h"
#include "compoversion.h"

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
		ResultsCalc(ArrayList^ entries, ArrayList^ votes, String^ componame, bool penalize)
		{
			this->penalize = penalize;

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

			if (this->penalize)
			{
				
				for each (CompoEntry^ ce in this->entries)
				{
					ce->voted = false;

					for each (VoteData^ vd in this->votes)
					{
						if (vd->votingfor == ce->composer)
						{
							ce->voted = true;
							break;
						}
					}

					if (!ce->voted)
					{
						ce->score -= this->entries->Count;
					}
				}
			}

			this->generate_results_string();
		}

		String^ generate_compo_name(void)
		{
			String^ name = L"";
			Random rnd;
			int structure = rnd.Next(0, 3);
			
			if (structure == 0 || structure == 2)
			{
				name += this->adjectives[rnd.Next(0, this->adjectives->Length)];
			}
			if (structure == 2)
			{
				name += L" ";
			}
			if (structure == 1 || structure == 2)
			{
				name += this->nouns[rnd.Next(0, this->nouns->Length)];
			}

			name += " Compo";

			return name;
		}

		System::Void generate_results_string(void)
		{
			if (componame == L"")
			{
				componame = this->generate_compo_name();
			}

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

				String^ songname;
				if (ce->songtitle != L"")
				{
					songname = ce->songtitle + " (" + ce->filename + ")";
				}
				else
				{
					songname = ce->filename;
				}

				String^ scorestr;
				if (this->penalize && !ce->voted)
				{
					int sc_penalty = this->entries->Count;
					int sc_prepenalty = ce->score + sc_penalty;
					
					scorestr = ce->score.ToString() +
						" (" +
						sc_prepenalty.ToString() +
						"-" +
						sc_penalty.ToString() +
						")";
				}
				else
				{
					scorestr = ce->score.ToString();
				}

				results += "[ PLACE " +
					place.ToString() + 
					" -=> " + 
					songname + 
					" <=- done by -=> " +
					ce->composer +
					" <=- with " +
					scorestr +
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

					String^ songname;

					for each (CompoEntry ^ce in entries)
					{
						if (ce->filename == vote)
						{
							if (ce->songtitle != L"")
							{
								songname = ce->songtitle + " (" + ce->filename + ")";
							}
							else
							{
								songname = ce->filename;
							}
							break;
						}
					}

					results += "[\\_Place -=> " +
						i.ToString() +
						" <=-=> " +
						songname +
						"_/]\n";
				}
			}

			results += "-----<O>-----\n";
			results += "These results were generated using lazyslash compomagoo " + 
				compoversion::version + 
				" " +
				compoversion::svnrevision +
				" (c) 2009 Mike Burke (mrb) - mrburke@gmail.com\n";

			// oops windows
			results = results->Replace("\n", "\r\n");
			
		}

		String^ results;
		String^ componame;
		bool penalize;


	protected:

		ArrayList^ entries;
		ArrayList^ votes;

		static array<String^>^ adjectives = {
			"Perilous",
			"Mirthful",
			"Wild", 
			"Moist",
			"Deadly",
			"Strong",
			"Spherical",
			"Sucked",
			"Space",
			"Efficient",
			"Oily",
			"Sexist",
			"Racist",
			"Clockin'",
			"Cockin'",
			"Hot",
			"Deven Gallo"
		};
		static array<String^>^ nouns = {
			"Duck",
			"Dingle",
			"Bacon",
			"Moon",
			"Sphere",
			"Spacepond",
			"Pond",
			"Wolf",
			"Box",
			"Water",
			"Thrasher",
			"Tiger",
			"Squirrel",
			"Squirrel King",
			"Werehof",
			"Clock",
			"Cock",
			"Bajs",
			"Korv",
			"Sausage",
			"AINOR",
			"Deven Gallo"
		};

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ResultsCalc()
		{
		}

	private:
	};
}
