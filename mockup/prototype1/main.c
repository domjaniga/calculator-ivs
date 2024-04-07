#include<gtk-3.0/gtk/gtk.h>


static void load_style(){
    GtkCssProvider* css_provider = gtk_css_provider_new();
    GdkDisplay* display = gdk_display_get_default();
    GdkScreen* screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_path(css_provider, "style.css", NULL);

    g_object_unref(css_provider);
}

static void activate(GApplication* app, gpointer data){
    int v = gtk_get_major_version();
    printf("GTK%d\n", v);

    GtkBuilder* build;
    GObject* win;

    build = gtk_builder_new_from_file("mockup1.glade");

    win = G_OBJECT(gtk_builder_get_object(build, "MainWin"));
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);


    gtk_widget_show_all(GTK_WIDGET(win));
    gtk_main();

}

int main(int argc, char const *argv[])
{
    GtkApplication* app;
    int status;

    gtk_init(&argc, (char***)&argv);
    load_style();

    app = gtk_application_new("ivs.prototype.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, (char**)argv);
    g_object_unref(app);

    return status;
}
