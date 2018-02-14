#pragma once

#include <callista/build_info.hpp>

#if CS_OS_GTK
	#include <gtkmm/application.h>
	extern Glib::RefPtr<Gtk::Application> sharedApp;
#endif