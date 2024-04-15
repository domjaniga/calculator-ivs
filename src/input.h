
typedef struct app_data_s
{
    GtkApplication*     app;
    GtkWindow*          main_window;
    GtkTextView*        input_field;
    GtkTextView*        history_field;
    int status;
} app_data;

extern app_data App;

/**
 * @file input.h
 * @authors Šimon Ožvald xozvals00
 * @brief Function declarations for processing user input
 * @see input.h
*/

/**
 * @fn symbol_key_cb(GtkButton* key, gpointer data)
 * @brief Called when a symbol key is clicked. Adds the symbol to the input textview.
 * @param key The key that has been clicked.
 * @param textview GtkTextView that stores user input
*/
void symbol_key_cb(GtkButton* key, gpointer data);

/**
 * @fn void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview)
 * @brief Adds a symbol (string describing an operation) to the input textview.
 * @param symbol String representing the operation to be added to input.
 * @param len Length of symbol
 * @param textview Input textview.
*/
void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview);

/**
 * @fn void clear_input_cb(GtkButton* clr_btn, gpointer data)
 * @brief Callback for the clear button (CE)
 * @param clr_btn Button that has been clicked.
 * @param data pointer to the input buffer
*/
void clear_input_cb(GtkButton* clr_btn, gpointer data);


/**
 * @fn void eval_cb(GtkButton* eval_btn, gpointer data)
 * @brief Callback for evaluating the expression from the input buffer
 * @param eval_btn Evaluate (equals) button
 * @param buff Pointer to the buffer from which to read the expression.
*/
void eval_cb(GtkButton* eval_btn, gpointer data);

/*** End of input.h ***/
