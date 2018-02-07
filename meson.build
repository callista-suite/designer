project('shapesplash', 'cpp', default_options : ['cpp_std=c++11'])

gtk_dep = dependency('gtk+-3.0')
thread_dep = dependency('threads')

# Because of this, we have to re-run meson every build.
find_result = run_command('find', ['src/', '-name', '*.cpp'])
sources = find_result.stdout().strip().split('\n')

executable('shapesplash', sources, dependencies: [gtk_dep, thread_dep])