/**
 * @file main.c
 * @brief Main file for the GUI calculator
 * @author Šimon Ožvald xozvals00
 * @todo handle user input, add math lib, expand documentation, add universal button handler
 *
*/

#include<gtk-3.0/gtk/gtk.h>
#include "input.h"

static void activate(GApplication* app, gpointer data);
static void load_style();
void symbol_key_cb(GtkButton* key, gpointer textview);

int main(int argc, char const *argv[])
{
    GtkApplication* app;
    int status;

    gtk_init(&argc, (char***)&argv);
    load_style();

    app = gtk_application_new("ivs.project.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, (char**)argv);
    g_object_unref(app);

    return status;

}// main()

static void activate(GApplication* app, gpointer data){
    GtkBuilder* build;
    GObject* win;

    build = gtk_builder_new_from_file("layout.glade");

    win = G_OBJECT(gtk_builder_get_object(build, "MainWin"));
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(build, NULL);

    gtk_widget_show_all(GTK_WIDGET(win));
    gtk_main();

}// activate()

static void load_style(){
    GtkCssProvider* css_provider = gtk_css_provider_new();
    GdkDisplay* display = gdk_display_get_default();
    GdkScreen* screen = gdk_display_get_default_screen(display);
    GError* err = NULL;

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_path(css_provider, "style.css", &err);

    if(err != NULL) g_printerr("Failed to load CSS!");

    g_object_unref(css_provider);

}// load_style()
