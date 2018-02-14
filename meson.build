project('callista-designer', 'cpp', default_options : ['cpp_std=c++11'])

source_glob = ['src/', '-name', '*.cpp']

# Because of the globbing, we have to re-run meson every build.
find_result = run_command('find', source_glob)
sources = find_result.stdout().strip().split('\n')

if get_option('buildtype').startswith('debug')
	default_library_opt='default_library=shared'
else
	default_library_opt='default_library=static'
endif

suite_libs = subproject('libcallistashared', default_options: [default_library_opt])

executable('callista-designer', sources, dependencies: [
	suite_libs.get_variable('callista_dep')
], build_rpath: '$ORIGIN/../build/subprojects/libcallistashared')