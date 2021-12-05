#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Game {
	private:
		int score = 0;
		int currentQuestionNum = 0;
		vector< pair<string,string> > questions = {
			make_pair("What's the name of the US president?", "Joe Biden"),
			make_pair("What year was the Eiffel Tower built?(100 Points)", "1889"),
			make_pair("True or False? Douglas Lawrence Osowki voices Sheldon J Plankton on the show, Spongebob Squarepants. Use T and F for the answer.(100 Points)", "T"),
			make_pair("True or False? Darth Vader said to Luke, 'Luke I'm Your Father'. Use T and F for the answer.(100 Points)", "F"),
			make_pair("Last name of an artist, famous for her wax sculptures, who opened up a wax museum in 1835 London. Don't forget to capitalize the first letter.(100 Points)", "Tussaud"),
			make_pair("What rhymes with orange?(100 Points)", "Sporange"),
			make_pair("True or False? Youtube Rewind 2018 was the most disliked youtube video. Use T and F for the answer.(100 Points)", "T"),
			make_pair("True or False? Fast and The Furious 10 has a 47\% on Rotten Tomato. Use T and F for the answer.(100 Points)", "F"),
			make_pair("How many degrees does CSUF offer?(100 Points)", "103"),
			make_pair("Final Question: What's the name of the computer bug that allows attackers to send commands for Bash to execute? (100 Points)", "Shellshock")
		};

	public:
		string getQuestion() {
			if (currentQuestionNum < questions.size()) {
				return questions[currentQuestionNum].first;
			}
			return "You finished the game with " + to_string(score) + " points";
		}
		
		void nextQuestion() {
			currentQuestionNum++;
		}

		int getScore() {
			return score;
		}

		int gameDone() {
			return currentQuestionNum == questions.size();
		}
		bool checkAnswer(string userInput) { 
			bool correct = userInput == questions[currentQuestionNum].second;
			score = correct ? score + 100 : score - 100;
			
			return correct;
		}
		void playAgain() {
			currentQuestionNum = 0;
			score = 0;
		}
};
