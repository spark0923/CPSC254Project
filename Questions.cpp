#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int answerNum; 
string answerWord;
int score;

void bonus_game()
{
	int answer = score + 877;
	cout << "BONUS GAME! What's your score plus 877?(259 pts)(NO PENALTY)" << endl;
	cin >> answerNum;
	if (answerNum == answer)
	{
		score += 259;
		cout << "GOOD JOB! 259 points won!" << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		cout << "FAILURE! Good luck next time!" << endl;
	}
}

void questions()
{


	//First Question
	cout << "What year was the Eiffel Tower built?(100 Points)" << endl;
	cin >> answerNum; 
	if (answerNum == 1889)
	{
		score += 100; 
		cout << "GOOD JOB! 100 Points to you!" << endl;
		cout << "Score: " << score << endl;
	} else
	{
		score -= 100;
		cout << "FAILURE! 100 Points lost! Off with a rough start" << endl;
		cout << "Score: " << score << endl;
	}



	//Second Question
	cout << "True or False? Douglas Lawrence Osowki voices Sheldon J Plankton on the show, Spongebob Squarepants. Use T and F for the answer.(100 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "T")
	{
		score += 100;
		cout << "GOOD JOB! Victory Screech!" << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 100;
		cout << "FAILURE! My Leg!"  << endl;
		cout << "Score: " << score << endl;
	}



	//Third Question
	cout << "True or False? Darth Vader said to Luke, 'Luke I'm Your Father'. Use T and F for the answer.(100 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "F")
	{
		score += 100;
		cout << "GOOD JOB! You're a Star Wars geek!" << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 100;
		cout << "FAILURE! That was misquoted" << endl;
		cout << "Score: " << score << endl;
	}



	//Bonus Question Check
	if (score >= 200)
	{
		bonus_game();
	} 
	if (score >= 300)
	{
		cout << "Perfect Score!(Not counting bonus points)" << endl;
	}
	else if (score < 0)
	{
		cout << "You're in the negative zone. Climb back up, you can do this!" << endl;
	}



	//Fourth Question
	cout << "Last name of an artist, famous for her wax sculptures, who opened up a wax museum in 1835 London. Don't forget to capitalize the first letter.(200 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "Tussaud")
	{
		score += 200;
		cout << "GOOD JOB! Yeah these questions will continue to increase in value.....even if the questions are easy." << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 200;
		cout << "FAILURE! Her name is Marie Tussaud. Also these questions, no matter the difficulty, will have bigger value, so watch out!" << endl;
		cout << "Score: " << score << endl;
	}



	//Fifth Question
	cout << "What rhymes with orange?(200 Points)" << endl;
	cin >> answerWord;
	if (answerWord ==  "sporange" || answerWord == "Sporange")
	{
		score += 200;
		cout << "GOOD JOB! See, there is a word that rhymes." << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 200;
		cout << "FAILURE! There is one spore producing structure that does rhyme with orange." << endl;
		cout << "Score: " << score << endl;
	}
	

	//Sixth Question
	cout << "2 + 2 = (200 points)" << endl;
	cin >> answerNum;
	if (answerNum == 4)
	{
		score += 200;
		cout << "GOOD JOB! Yay!" << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 200;
		cout << "FAILURE! Um what happened? " << endl;
		cout << "Score: " << score << endl;
	}


	//Bonus game check
	if (score >= 600)
	{
		bonus_game();
	}
	else if (score < 0)
	{
		cout << "Oh and seriously? " << score << " ?" << endl;
	}



	//Seventh Question
	cout <<"True or False? Youtube Rewind 2018 was the most disliked youtube video. Use T and F for the answer.(300 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "T")
	{
		score += 300;
		cout << "GOOD JOB! That's a lot of points!" << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 300;
		cout << "FAILURE! That's a lot of damage!" << endl;
		cout << "Score: " << score << endl;
	}


	//Eighth Question
	cout << "True or False? Fast and The Furious 10 has a 47% on Rotten Tomato. Use T and F for the answer.(300 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "F")
	{
		score += 300;
		cout << "GOOD JOB! You didn't get fooled! Also never seen these movies." << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 300;
		cout << "FAILURE! The sequel that has yet to even exist." << endl;
		cout << "Score: " << score << endl;
	}


	//Ninth Question
	cout << "How many degrees does CSUF offer?(300 Points)" << endl;
	cin >> answerNum;
	if (answerNum == 103)
	{
		score += 300;
		cout << "GOOD JOB! You almost there, but first..." << endl;
		cout << "Score: " << score << endl;
	}
	else
	{
		score -= 300;
		cout << "FAILURE! One last question left, but first...." << endl;
		cout << "Score: " << score << endl;
	}


	//Bonus game check
	if (score >= 1000)
	{
		bonus_game();
	}
	else if (score < 0)
	{
		cout << "Oh nevermind, no bonus game. Your not very good at this lol" << endl;
	}
	else
	{
		cout << "Oh nevermind, no bonus game. But hey, at least your not in the negative!" << endl;
	}

	//Tenth Question 
	cout << "Final Question: What's the name of the computer bug that allows attackers to send commands for Bash to execute? (400 Points)" << endl;
	cin >> answerWord;
	if (answerWord == "Shellshock" || "shellshock")
	{
		score += 400;
		cout << "GOOD JOB! 400 points for you!" << endl;
	}
	else
	{
		score -= 400;
		cout << "FAILURE! Oof! Hopefully that doesn't hurt much." << endl;
	}


}

void check_score()
{
	cout << "You got " << score << endl;
	if (score == 2977)
	{
		cout << "You got every question right, even the bonus games. Congrats! You get NOTHING!";
	}
	else if (score < 0)
	{
		cout << "Wow! You need to read more books or something lol.";
	}
	else
	{
		cout << "Good Job!";
	}
}

int main()
{
	cout << "Welcome to the our dumb trivia game! *Audience Applause*" << endl;
	cout << "Bonus Game Milestone(Reach after every three questions)" << endl;
	cout << "200" << endl;
	cout << "600" << endl;
	cout << "1000" << endl;
	questions();
	check_score();
}

