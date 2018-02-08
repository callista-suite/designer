project('shapesplash', 'cpp', default_options : ['cpp_std=c++11'])

# macOS and iOS UIs can only really be written with Swift, so we have to play ball
# with Apple's trash language.
if host_machine.system() == 'darwin'
	add_languages('swift')
	source_glob = ['src/', '-name', '*.cpp', '-o', '-name', '*.swift']
else
	source_glob = ['src/', '-name', '*.cpp']
endif

thread_dep = dependency('threads')

# Because of the globbing, we have to re-run meson every build.
find_result = run_command('find', source_glob)
sources = find_result.stdout().strip().split('\n')


gtk_dep=[]
gtkmm_dep=[]

if host_machine.system() == 'linux'
	gtk_dep = dependency('gtk+-3.0')
	gtkmm_dep = dependency('gtkmm-3.0')
endif


executable('shapesplash', sources, dependencies: [gtk_dep, thread_dep])