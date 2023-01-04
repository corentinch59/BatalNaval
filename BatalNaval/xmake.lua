add_rules("mode.debug", "mode.release")

add_requires("sfml")

set_project("BatalNaval")

target("BatalNaval")
    set_kind("binary")
    set_languages("cxx17")
    add_files("src/*.cpp")
    add_headerfiles("headers/*.h")
    add_includedirs("headers")
    add_packages("sfml")