#pragma once

#include <gtkmm/window.h>
#include <types.hpp>

class DesignerWindow : Gtk::Window {
	
	
	DesignerWindow(dynarr open_files);
}

#if defined(SS_UI_IMPL) || defined(SS_CODE_EDITOR)

;

#endif