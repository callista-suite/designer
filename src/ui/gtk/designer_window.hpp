#pragma once



#if defined(SS_UI_IMPL) || defined(SS_CODE_EDITOR)

#include <gtkmm/applicationwindow.h>

typedef Gtk::ApplicationWindow Window;

Window *create_window() {

	auto window = new Window();
	return window;

}

#endif