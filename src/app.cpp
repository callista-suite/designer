
#include <stdio.h>
#include <callista/build_info.hpp>

#if CS_OS_WIN32

#error "Not implemented."

// Apple's stuff has to be written in Swift or ObjC.
// I'm not sure how to approach this yet.
#elif !CS_OS_APPLE
	#if CS_OS_GTK

		#include <gtkmm/application.h>

		Glib::RefPtr<Gtk::Application> sharedApp;

		int main(int argc, char** argv) {
			
			sharedApp = Gtk::Application::create(argc, argv, "com.zacpierson.shapesplash");

			return 0;
		}

	#else
		#error "Only GTK building is supported on *nix."
	#endif
#endif