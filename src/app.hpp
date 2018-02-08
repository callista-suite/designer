#pragma once

#include <build_info.hpp>

#if SS_OS_GTK
	#include <gtkmm/application.h>
	extern Glib::RefPtr<Gtk::Application> sharedApp;
#endif