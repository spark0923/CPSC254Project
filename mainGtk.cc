#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Questions.cc"
#include <memory>
#include <utility>

// Globally defined user interface pieces for easy reference
GtkWidget* score;
GtkWidget* enter_msg;
GtkWidget* skip_question;
GtkWidget* announcement;
GtkWidget* question;
GtkWidget* questionNum;

// The Game class is used to abstract the game from the user interface
std::shared_ptr<Game> g = std::make_shared<Game>();

// Button handler for submitting an answer
void onCLickSubmit(GtkWidget* submitBtn, gpointer data) {
    // The button shouldn't do anything when the game is finished
    if (g->gameDone()) {
        return;
    }
    
    const gchar *c = gtk_entry_get_text(GTK_ENTRY(enter_msg));

    // check if input is empty, exit immediately
    if ((c != NULL) && (c[0] == '\0')) {
        gtk_label_set_text(GTK_LABEL(announcement), "Please enter a message!");
        return;
    }

    gtk_label_set_text(GTK_LABEL(announcement), "");
    if (g->checkAnswer(std::string(c))) {
        gtk_label_set_text(GTK_LABEL(announcement), "Correct!");
        g->nextQuestion();
        gtk_label_set_text(GTK_LABEL(question), g->getQuestion().c_str());
    }
    else {
        gtk_label_set_text(GTK_LABEL(announcement), "WRONG!!!");
    }

    // update the score
    std::string scoreMsg = "Score: " + to_string(g->getScore());
    const char* scoreMsgC = scoreMsg.c_str();
    
    gtk_label_set_text(GTK_LABEL(score), scoreMsgC);

    gtk_entry_set_text(GTK_ENTRY(enter_msg), "");

    //  update the current question label
    std::string currentQuestion = g->currentOutOf();
    const char* currentQuestionC = currentQuestion.c_str();

    gtk_label_set_text(GTK_LABEL(questionNum), currentQuestionC);
}

//Button Handler for the "SKIP" Button
void onClickSkip(GtkWidget* skipBtn){
    // The button shouldn't do anything when the game is finished
    if (g->gameDone()) {
        return;
    }
    // Next Question
    g->skipQuestion();
    gtk_label_set_text(GTK_LABEL(question), g->getQuestion().c_str());

    // Update the Score
    std::string scoreMsg = "Score: " + to_string(g->getScore());
    const char* scoreMsgC = scoreMsg.c_str();
    gtk_label_set_text(GTK_LABEL(score), scoreMsgC);

    // Update the Current Question Count
    std::string currentQuestion = g->currentOutOf();
    const char* currentQuestionC = currentQuestion.c_str();
    gtk_label_set_text(GTK_LABEL(questionNum), currentQuestionC);
}

static void activate(GtkApplication *app, gpointer user_data) {
    g->questionFromTxt();

    //window meta data
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Dumb Trivia");
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // importing css file
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(cssProvider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Form to enter message
    score = gtk_label_new("Score: 0");
    questionNum = gtk_label_new (g->currentOutOf().c_str());
    GtkWidget* enter_msg_label = gtk_label_new("Your answer: ");
    enter_msg = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(enter_msg), "You're probably wrong");
    GtkWidget* submitBtn = gtk_button_new_with_label("Submit");
    GtkWidget* skipBtn = gtk_button_new_with_label("Skip");
    announcement = gtk_label_new("");
    g_signal_connect(submitBtn,"clicked",G_CALLBACK(onCLickSubmit), enter_msg);
    g_signal_connect(skipBtn, "clicked", G_CALLBACK(onClickSkip), skip_question);

    // packing all of the message form into a single box
    GtkWidget* msgForm = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_box_pack_start(GTK_BOX(msgForm), score, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), questionNum, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), enter_msg_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), enter_msg, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), submitBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), skipBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), announcement, FALSE, FALSE, 0);
    //styling the message box
    GtkStyleContext* context = gtk_widget_get_style_context(msgForm);
    gtk_style_context_add_class(context, "enterMsgForm");

    // confessions box container
    question = gtk_label_new(g->getQuestion().c_str());
    // styling
    GtkStyleContext* msgContainerContext = gtk_widget_get_style_context(GTK_WIDGET(question));
    gtk_style_context_add_class(msgContainerContext, "msgContainer");

    // want all components to flow vertically
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_box_pack_start(GTK_BOX(box), msgForm, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(question), FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
}
int main(int argc, char** argv) {
    GtkApplication *app;
    int ret;

    app = gtk_application_new("in.cpsc254", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    ret = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return ret;
}