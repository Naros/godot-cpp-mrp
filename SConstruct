#!/usr/bin/env python

VariantDir("build/godot-cpp", "extern/godot-cpp", duplicate=False)
env = SConscript("build/godot-cpp/SConstruct")

env.VariantDir("build/src", "src", duplicate=False)
sources = Glob("build/src/*.cpp") + Glob("build/src/editor/*.cpp")

library = env.SharedLibrary(
    "project/addons/mrp/libmrp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)
