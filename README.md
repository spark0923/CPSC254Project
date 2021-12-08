# CPSC254Project
CPSC 254 Class Project: Trivia Game

Use of open source software: <br/>
GTK - used for the user interface of the program <br/>
https://www.gtk.org/docs/installations/windows/#using-gtk-from-msys2-packages

# To use:
In terminal: <br/>
```sudo apt-get install libgtk-3-dev```<br/>

If running on WSL (Ubuntu):<br/>
On Windows, download and install Xming X(https://sourceforge.net/projects/xming/).<br/>
Run Xming.<br/>
On Ubuntu, in terminal<br/>
```export DISPLAY=:0```<br/>

Clone the project directory: <br/>
```git clone git@github.com:spark0923/CPSC254Project.git```
Inside the project directory: <br/>
```./run.sh```


# How to Play:
A question will appear that you must answer correctly. If you get the right answer, you will earn 100 points to your score. Failure to do so will drop your score by 100 points. 
You need to answer 10 questions. After all of them are answered, your final score will appear. Make sure all your answers have their first letter capitalized.
Good Luck!

# Members:
Johnson Tong(jt28@csu.fullerton.edu) <br/> - Created base GUI of the game and implemented Randall's code to work with it. Made everything a bit more readable and reusable.

Scott SangHyuk Park(scottpark44@csu.fullerton.edu) - A lot of the things I did was add some functions that I thought would make the program practical for other users. Rather than having the questions embedded into the program, what if we allowed the user to bring their own questions, so that they can suit it to their needs? What if there was a question counter, telling us how many questions are left? Answering these questions in order to add practicality to the program was a large part of what I worked on.<br/>

Randall Frye(rcfrye18@csu.fullerton.edu)- I believe I was the one who came up with the idea of a quiz game though I might be wrong there. I helped designed how the quiz would play like. I also came up with many of the questions and answers. I had an original code that was the blueprint for the code of quiz game. The code was changed by Johnson to make it more convenient and less cluttered. I also worked on parts of the README file such as the how to play section, my part of the Members section, and the Development Experience section. <br/>


# Development Experience:
Planning- It took a while for us to decide what we should do for our project. We thought about making a funny music generator. However we decided not to because we felt that doing something more simple would be better for us instead of doing something that might result in potential complications. We have't tried it so we don't know for sure if that would've been the case. The open source we decided to use was GTK, which would be used for the UI. Because of this, we thought about having our project be an anonymous confession box. That seemed something incredibly simple. Johnson began to work on implementing the open source program to our project. <br/>

Change of Plans- 
The creation of the UI was successful. The base of the project had been completed. However, Johnson wasn't able to figure out how to store new messages for the chat box. Because of that, we had to change plans. Randall thought that we could work on a quiz game. We then designed how the game could play like as well as how it could be done through coding. We also thought about making it like a review for CPSC 254, but we went with trivia instead. We had planned to finish our project on November 28, but that didn't happen, partly because of our other college classes getting in the way. We then planned to finish up on December 4 as the deadline was near. Randall was also asked to work on a way to store the questions and answers, ideally before the 4th. <br/>

Coding-
Johnson's code had been uploaded on GitHub on the 3rd of December. We felt at the time that we were at least half way there. Randall uploaded his code called Questions.cpp on the 4th. The code contained a quiz game of ten questions with increasing point values(One question was 100 pts while another was 200 pts). It also had a bonus game, which was later removed. There was also specific correct and incorrect messages for each questions. Despite all this, the code was problematic. The problems with the code was that there was a lot of copy and pasting, making it cluttered and unnecessary, and that it's difficult to work with as it was not very compatible with the use of the open source and Johnson's code. Johnson decided to work on Randall's code and make it better. After a few hours, a code file called Questions.cc was uploaded. Randall's code was all made into one class. While the bonus game, the varied correct/incorrect messages, and the increasing values were removed, it made up for it with a much more organized and compatible code. Scott soon also added to the program that you could add your own questions to answer since the code now takes the input from a txt file. Eventually, Scott also added a tally for the questions. <br/>


# Sources for questions and answers:
President- https://www.usa.gov/presidents <br/>
Eiffel Tower- https://www.toureiffel.paris/en/the-monument/history <br/>
Douglas Lawrence Osowski- https://www.imdb.com/name/nm0492951/ <br/>
Darth Vader- https://www.verifythis.com/article/news/verify/pop-culture/star-wars-day-darth-vader-luke-father-line-misquoted/536-c6a3fcd3-41ce-4a50-b2ea-6a28b342a86d <br/>
Artist- https://www.wikiwand.com/en/Madame_Tussauds <br/>
Orange- https://www.merriam-webster.com/words-at-play/what-rhymes-with-orange <br/>
Youtube Rewind 2018- https://www.theverge.com/2018/12/13/18137894/youtube-rewind-2018-dislike-shane-dawson-logan-paul-pewdiepie-mkbhd-philip-defranco <br/>
Fast and the Furious- https://www.rottentomatoes.com/franchise/the_fast_and_the_furious <br/>
Cal State Fullerton- http://www.fullerton.edu/academics/ <br/>
Computer Bug- https://securityintelligence.com/articles/shellshock-vulnerability-in-depth/ <br/>
Other Questions - https://www.quizbreaker.com/trivia-questions <br/>







