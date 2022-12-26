#cmake_minimum_required(VERSION 3.22)
cmake_minimum_required(VERSION 3.8.2)
 
project(client)

set (CMAKE_CXX_STANDARD 17)


# Проверим версию компилятора
# Нужна поддержка C++17
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "6")
        message(FATAL_ERROR "GCC with version higher than or equals 6 is needed.")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4")
        message(FATAL_ERROR "Clang with version higher than or equals 4 is needed.")
    endif()
else()
    message(FATAL_ERROR "No supported compiler found.")
endif()

# Дополнительные опции для свежих версий Boost
# The practice of declaring the Bind placeholders (_1, _2, ...)
# in the global namespace is deprecated. Please use
# <boost/bind/bind.hpp> + using namespace boost::placeholders,
# or define BOOST_BIND_GLOBAL_PLACEHOLDERS to retain the current behavior.
add_definitions("-DBOOST_BIND_GLOBAL_PLACEHOLDERS")

find_package(Boost 1.36.0)
if(Boost_FOUND)
find_package(Boost REQUIRED filesystem program_options regex timer thread)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES} )

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

endif()