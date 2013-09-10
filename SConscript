Import ('env')

#env.Append(CXXFLAGS=['-I/usr/lib/gcc/x86_64-linux-gnu/4.6/plugin/include'])
env.Append(CXXFLAGS=['-I/usr/lib/gcc/x86_64-linux-gnu/4.7.3/plugin/include'])

name = 'namecheck'
inc = env.Dir('./namecheck')
ext_inc = []
src = env.Glob('src/*.cpp')
	
deps = ['gcc_plugin', 'boost_regex']
env.CreateSharedLibrary(name, inc, ext_inc, src, deps)