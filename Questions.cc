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
		
		vector< pair<string,string>> questions;

	public:
		void questionFromTxt(){
		    string line, test, question, answer;
			int findPos1, findPos2, findPos3, findPos4;

			ifstream myfile ("input.txt");
			if (myfile.is_open())
			{
				while (getline(myfile,line))
				{
					cout << line << '\n';
					test = line;
					findPos1 = test.find("\"");
					findPos2 = test.find("\"", findPos1 + 1);
					findPos3 = test.find("\"", findPos2 + 1);
					findPos4 = test.find("\"", findPos3 + 1);
					question = test.substr(findPos1 + 1, findPos2 - findPos1 - 1);
					if(question == "Question"){
						;
					}
            		else{
						answer = test.substr(findPos3 + 1, findPos4 - findPos3 - 1);
						questions.push_back(make_pair(question,answer));
					}
				}
				myfile.close();
			}
			else cout << "Unable to open file"; 
		}

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
