/**
 * @file input.c
 * @authors Šimon Ožvald xozvals00
 * @brief Functions for processing user input
 * @see input.h
*/
#include<gtk-3.0/gtk/gtk.h>
#include<string.h>
#include "input.h"

void symbol_key_cb(GtkButton* key, gpointer data){
    GtkTextView* textview = (GTK_TEXT_VIEW(data));
    const gchar* name;
    char* symbol_str = alloca(strlen(name));

    name = gtk_widget_get_name(GTK_WIDGET(key));
    strcpy(symbol_str, name+2);

    g_print("%s", symbol_str);

    append_symbol_to_input(symbol_str, strlen(symbol_str), textview);
}

void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview){
    GtkTextBuffer* input_buffer = gtk_text_view_get_buffer(textview);
    gtk_text_buffer_insert_at_cursor(input_buffer, symbol, len);
}

/*** End of input.c ***/
