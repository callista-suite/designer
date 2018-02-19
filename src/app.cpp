
// Library includes
#include <stdio.h>

// Callista includes
#include <callista/app.hpp>

// App includes
#include "ui/designer_ui.hpp"


CallistaApp setup_app_struct() {

	CallistaApp app;

	app.setup_document_window_proc = setup_document_window;
	app.package_id = "com.callistasuite.designer";
	app.friendly_name = "Callista Designer";

	return app;
}

CALLISTA_MAIN(setup_app_struct);