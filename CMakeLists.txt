cmake_minimum_required(VERSION 3.2)

#project(bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
project(bulk)

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#configure_file(version.h.in version.h)

set(HEADERS commands_storage.h solver.h solvers.h)
set(SOURCES commands_storage.cpp solver.cpp solvers.cpp)

add_executable(bulk ${HEADERS} ${SOURCES} main.cpp)

#set (TEST test_bulk)
#add_executable (${TEST} test_bulk.cpp)

set_target_properties (bulk PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#set_target_properties (print_ip ${TEST} PROPERTIES
#        CXX_STANDARD 14
#        CXX_STANDARD_REQUIRED ON
#        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
#)

#set_target_properties (${TEST} PROPERTIES
#        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

#target_link_libraries(${TEST}
#        ${Boost_LIBRARIES}
#)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT tima_mamedxp@mail.ru)

#include(CPack)

#enable_testing()

#add_test (${TEST} ${TEST})
