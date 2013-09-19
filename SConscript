Import ('env')

import subprocess as sp
proc = sp.Popen('gcc -dumpversion', shell=True, stdout=sp.PIPE)
version = proc.stdout.read()
version = version.strip()

if version == "4.6":
	env.Append(CXXFLAGS=['-I/usr/lib/gcc/x86_64-linux-gnu/4.6/plugin/include/'])
	deps = ['gcc_plugin_4.6']
else:
	env.Append(CXXFLAGS=['-I/usr/lib/gcc/x86_64-linux-gnu/4.7/plugin/include/'])	
	deps = ['gcc_plugin_4.7']

name = 'namecheck'
inc = env.Dir('./namecheck')
ext_inc = []
src = env.Glob('src/*.cpp')
	
deps += ['boost_regex', 'mili']
env.CreateSharedLibrary(name, inc, ext_inc, src, deps)