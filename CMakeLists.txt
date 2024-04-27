cmake_minimum_required(VERSION 3.21)
project(CA2_BugsLife_Ema_Eiliakas_D00255056)

set(CMAKE_CXX_STANDARD 11)

add_executable(CA2_BugsLife_Ema_Eiliakas_D00255056 main.cpp
        Bug.cpp
        Bug.h
        Board.cpp
        Board.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Beatle.cpp
        Beatle.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(CA2_BugsLife_Ema_Eiliakas_D00255056 sfml-system sfml-window sfml-graphics sfml-audio)



