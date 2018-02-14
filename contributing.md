# Contributing to ShapeSplash

Feel free to submit pull requests to fix open issues - please make an issue *before* fixing something so that we can see if the behavior needs to be "fixed" though.

Here's a couple of things to know about this codebase:
  * For *nix, you need to have Gtk3 and Gtkmm installed.
  * A couple of macros exist; most of them are defined in src/build_info.cpp
    `CS_CODE_EDITOR` is meant to be defined by any code-completion plugins so that it parses implementation code in headers.