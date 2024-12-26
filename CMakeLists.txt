cmake_minimum_required(VERSION 3.14)
project(dsaProject VERSION 1.0)

# google test required at least c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include_directories("./implementation")
file(GLOB sources "./implementation/*.c")
file(GLOB testSources "./test/*.cpp")

#
# Configuration de cmake et de C
#

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)

# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
# set(CMAKE_CXX_FLAGS_DEBUG
#     "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O2 -Werror -Wall -Wextra -Wpedantic -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wtrampolines -Walloca -Wvla -Warray-bounds=2 -Wimplicit-fallthrough=3 -Wtraditional-conversion -Wshift-overflow=2 -Wcast-qual -Wstringop-overflow=4 -Wconversion -Warith-conversion -Wlogical-op -Wduplicated-cond -Wduplicated-branches -Wformat-signedness -Wshadow -Wstrict-overflow=4 -Wundef -Wstrict-prototypes -Wswitch-default -Wswitch-enum -Wstack-usage=1000000 -Wcast-align=strict -D_FORTIFY_SOURCE=3 -fstack-protector-strong -fstack-clash-protection -fPIE -fsanitize=bounds -fsanitize-undefined-trap-on-error -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wl,-z,separate-code " )
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -fsanitize-address-use-after-scope ")

#
# Compilation standard avec googletest
#

include(FetchContent)
FetchContent_Declare(googletest
                     GIT_REPOSITORY https://github.com/google/googletest.git)

add_library(dsa SHARED ${sources})

#
# Construction du programme de tests unitaires
#
add_executable(dsaTest ${testSources})
target_link_libraries(dsaTest dsa gtest gtest_main)
#
# Ajout d'une cible pour lancer les tests de manière verbeuse
#
add_custom_target(check dsaTest)
#
# Construction du shell
#
add_executable(dsaRun "./implementation/dsa.c")
target_link_libraries(dsaRun dsa)
execute_process(COMMAND ctags -f "./implementation/" -R "./implementation/")

#
# Ajout d'une cible pour le project
#
add_custom_target(run dsaRun)

# Adding executable for testing add_executable(testDsa ${sources}
# ${testSources}) add_executable(${PROJECT_NAME} ${testSources})
# enable_testing()
