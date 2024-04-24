/**
 * @file main.c
 * @brief Main file for the GUI calculator
 * @author Šimon Ožvald xozvals00
 * @todo handle user input, add math lib, expand documentation
 *
*/

#include<gtk-3.0/gtk/gtk.h>
#include<unistd.h>
#include "input.h"

#define INSTALLER_VERSION

static void activate(GApplication* app, gpointer data);
static void load_style();
void symbol_key_cb(GtkButton* key, gpointer textview);

app_data App = {};

int main(int argc, char const *argv[])
{

    gtk_init(&argc, (char***)&argv); // Initialize GTK

    load_style(); // Load CSS from style.css

    App.app = gtk_application_new("ivs.project.app", 0); // Create application
    g_signal_connect(G_APPLICATION(App.app), "activate", G_CALLBACK(activate), NULL);

    App.status = g_application_run(G_APPLICATION(App.app), argc, (char**)argv); // run application (calls activate() )
    g_object_unref(App.app);

    return App.status;

}// main()

static void activate(GApplication* app, gpointer data){
    GtkBuilder* build;

    if(access("assets/layout.glade", F_OK)) build = gtk_builder_new_from_file("assets/layout.glade");
    else build = gtk_builder_new_from_file("/usr/share/calculator/assets/layout.glade");

    App.main_window = GTK_WINDOW(gtk_builder_get_object(build, "MainWin"));
    g_signal_connect(App.main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    App.input_field = GTK_TEXT_VIEW(gtk_builder_get_object(build, "input_field"));
    App.history_field = GTK_TEXT_VIEW(gtk_builder_get_object(build, "result_field"));
    App.warning_label = GTK_LABEL(gtk_builder_get_object(build, "warning_label"));

    gtk_builder_connect_signals(build, NULL);

    gtk_widget_show_all(GTK_WIDGET(App.main_window));
    gtk_main();

}// activate()

static void load_style(){
    GtkCssProvider* css_provider = gtk_css_provider_new();
    GdkDisplay* display = gdk_display_get_default();
    GdkScreen* screen = gdk_display_get_default_screen(display);
    GError* err = NULL;

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_path(css_provider, "assets/style.css", &err);

    if(err != NULL){
        err = NULL;
        gtk_css_provider_load_from_path(css_provider, "/usr/share/calculator/assets/style.css", &err);
        if(err != NULL) set_warning(MISSING_CSS_WARN);
    }

    g_object_unref(css_provider);

}// load_style()

