add_rules("mode.debug", "mode.release")
add_includedirs("src")
add_requires("sfml", "cxxopts")
set_rundir(".")

target("main")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("sfml", "cxxopts")
