#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

GtkWidget* enter_msg;
GtkWidget* pleaseEnterMsg;
std::vector<GtkWidget*> messagesVector;

void onCLickSubmit(GtkWidget* submitBtn, gpointer data) {
    const gchar *c = gtk_entry_get_text(GTK_ENTRY(enter_msg));
    if ((c != NULL) && (c[0] == '\0')) {
        gtk_label_set_text(GTK_LABEL(pleaseEnterMsg), "Please enter a message!");
        return;
    }
    std::string s;
    s.assign(c);
    std::cout << s << std::endl;
    gtk_entry_set_text(GTK_ENTRY(enter_msg), "");
    gtk_label_set_text(GTK_LABEL(pleaseEnterMsg), "");

}
static void activate(GtkApplication *app, gpointer user_data) {
    //window meta data
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Anonymous Confessions");
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // importing css file
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(cssProvider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Form to enter message
    GtkWidget* enter_msg_label = gtk_label_new("Your confession: ");
    enter_msg = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(enter_msg), "Last week I ate a ****!!");
    GtkWidget* submitBtn = gtk_button_new_with_label("Submit");
    pleaseEnterMsg = gtk_label_new("");
    g_signal_connect(submitBtn,"clicked",G_CALLBACK(onCLickSubmit), enter_msg);

    // packing all of the message form into a single box
    GtkWidget* msgForm = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_box_pack_start(GTK_BOX(msgForm), enter_msg_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), enter_msg, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), submitBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(msgForm), pleaseEnterMsg, FALSE, FALSE, 0);
    //styling the message box
    GtkStyleContext* context = gtk_widget_get_style_context(msgForm);
    gtk_style_context_add_class(context, "enterMsgForm");

    // confessions box container
    GtkFrame* frame = GTK_FRAME(gtk_frame_new(NULL));
    // styling
    GtkStyleContext* msgContainerContext = gtk_widget_get_style_context(GTK_WIDGET(frame));
    gtk_style_context_add_class(msgContainerContext, "msgContainer");

    // want all components to flow vertically
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_box_pack_start(GTK_BOX(box), msgForm, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(frame), FALSE, FALSE, 0);

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