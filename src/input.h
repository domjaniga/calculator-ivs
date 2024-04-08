/**
 * @file input.h
 * @authors Šimon Ožvald xozvals00
 * @brief Function declarations for processing user input
 * @see input.h
*/

/**
 * @brief Called when a symbol key is clicked. Adds the symbol to the input textview.
 * @param key The key that has been clicked.
 * @param textview GtkTextView that stores user input
*/
void symbol_key_cb(GtkButton* key, gpointer data);

/**
 * @brief Adds a symbol (string describing an operation) to the input textview.
 * @param symbol String representing the operation to be added to input.
 * @param len Length of symbol
 * @param textview Input textview.
*/
void append_symbol_to_input(char* symbol, size_t len, GtkTextView* textview);

/*** End of input.h ***/
