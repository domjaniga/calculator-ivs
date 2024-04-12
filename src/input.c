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

}// symbol_key_cb()

void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview){
    GtkTextBuffer* input_buffer = gtk_text_view_get_buffer(textview);
    gtk_text_buffer_insert_at_cursor(input_buffer, symbol, len);

}// append_symbol_to_input()

void clear_input_cb(GtkButton* clr_btn, gpointer data){
    GtkTextBuffer* input_buffer = GTK_TEXT_BUFFER(data); // Get input buffer

    GtkTextIter end_iter;
    GtkTextIter start_iter;
    gtk_text_buffer_get_end_iter(input_buffer, &end_iter);
    gtk_text_buffer_get_start_iter(input_buffer, &start_iter); // Get text bounds

    gtk_text_buffer_delete(input_buffer, &start_iter, &end_iter); // Delete from start to end (clear input)

}// clear_input_cb()


/*** End of input.c ***/
