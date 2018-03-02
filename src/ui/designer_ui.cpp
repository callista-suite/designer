#include "designer_ui.hpp"
#include <callista/ui/document_window.hpp>
#include <callista/ui/button.hpp>


Button *b;
void destroy_button() {
	button_destroy(b);
}

void setup_document_window(DocumentWindow *window) {
	b = button_create(BUTTONKIND_LABEL);
	button_set_label(b, "Test!");
	button_set_parent(b, window);
	button_register_callback(b, destroy_button);
}