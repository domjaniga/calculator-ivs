/**
 * @file input.c
 * @authors Šimon Ožvald xozvals00
 * @brief Functions for processing user input
 * @see input.h
 *
 * @todo Implement input processing
*/
#include <gtk-3.0/gtk/gtk.h>
#include <string.h>
#include "input.h"
#include "library.h"
#include <math.h>
#include "tinyexpr.h"

void symbol_key_cb(GtkButton* key, gpointer data){
    GtkTextView* textview = (GTK_TEXT_VIEW(data)); // Get textview
    const gchar* name = gtk_widget_get_name(GTK_WIDGET(key));
    char* symbol_str = alloca(strlen(name)); // String with symbol to be added to the input textview

    clear_warning();

    strcpy(symbol_str, name+2); // Copy name without first 2 characters (key names: n_0 s_+ s_^ ...)

    append_symbol_to_input(symbol_str, strlen(symbol_str), textview); // Add symbol to input

}// symbol_key_cb()

void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview){
    GtkTextBuffer* input_buffer = gtk_text_view_get_buffer(textview); // Get input buffer
    gtk_text_buffer_insert_at_cursor(input_buffer, symbol, len); // Insert symbol

}// append_symbol_to_input()

void clear_input_cb(GtkButton* clr_btn, gpointer data){
    GtkTextBuffer* input_buffer = GTK_TEXT_BUFFER(data); // Get input buffer

    clear_warning();

    GtkTextIter end_iter;
    GtkTextIter start_iter;
    gtk_text_buffer_get_end_iter(input_buffer, &end_iter);
    gtk_text_buffer_get_start_iter(input_buffer, &start_iter); // Get text bounds

    gtk_text_buffer_delete(input_buffer, &start_iter, &end_iter); // Delete from start to end (clear input)

}// clear_input_cb()

double evaluate_expression(char* expr, int* err) {
    double result = te_interp(expr, err);
    if (*err != 0) {
        fprintf(stderr, "Error evaluating expression at position %d\n", err);
        return NAN; // Not-a-Number to indicate error
    }
    return result;
}


void eval_cb(GtkButton* eval_btn, gpointer data){

    GtkTextBuffer* input_buffer = gtk_text_view_get_buffer(App.input_field); // Get input buffer
    GtkTextBuffer* hist_buffer = gtk_text_view_get_buffer(App.history_field); // Get history buffer

    clear_warning();

    GtkTextIter end_iter;
    GtkTextIter start_iter;
    gtk_text_buffer_get_end_iter(input_buffer, &end_iter);
    gtk_text_buffer_get_start_iter(input_buffer, &start_iter); // Get text bounds

    gchar* input_text = gtk_text_buffer_get_text(input_buffer, &start_iter, &end_iter, FALSE); // Get string from input buffer

    char* expr = alloca(strlen(input_text));
    strcpy(expr, input_text);

    double result = 42.0;
    int error = 0;

    result = evaluate_expression(expr, &error);

    /** @todo process input*/

    if(error != 0){
        set_warning(INVALID_INPUT_WARN);
        return;
    }

    char result_str[255];
    sprintf(result_str, "%lf", result); // Convert calculated result to a string

    clear_input_cb((GtkButton*)NULL, input_buffer); // Clear input buffer

    gtk_text_buffer_get_end_iter(input_buffer, &end_iter);
    gtk_text_buffer_insert(input_buffer, &end_iter, result_str, strlen(result_str)); // Write result to input buffer

    sprintf(result_str, "%s = %lf\n", input_text, result); // Create history entry

    gtk_text_buffer_get_end_iter(hist_buffer, &end_iter);
    gtk_text_buffer_insert(hist_buffer, &end_iter, result_str, strlen(result_str)); // Write an entry to the history buffer

}// eval_cb()

void set_warning(int code){
    switch (code) // code determines which warning to show
    {
    case MISSING_CSS_WARN:
        gtk_label_set_text(App.warning_label, "Failed to load CSS"); // Displayed if the app failed to load style from style.css
        break;

    case INVALID_INPUT_WARN:
        gtk_label_set_text(App.warning_label, "Invalid Input"); // Displayed if the expression in input cannot be calculated
        break;

    default:
        break;
    }
}// set_warning()

void clear_warning(void){
    gtk_label_set_text(App.warning_label, "");
}// clear_warning()

/*** End of input.c ***/
