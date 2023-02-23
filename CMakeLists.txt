cmake_minimum_required(VERSION 3.24)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

#file(чё-то там чтоб все файлы в папке ARRAY)
#
#for (FILE IN ARRAY)
#add_executable(${FILE} ${FILE})
#endfor()

add_executable(agro src/1/agro.cpp)
add_executable(zoo src/1/zoo.cpp)
add_executable(config src/1/config.cpp)
add_executable(chaos src/1/chaos.cpp)
add_executable(fighting src/1/fighting.cpp)
add_executable(trouble src/1/trouble.cpp)

add_executable(number src/2/number.cpp)
add_executable(cows src/2/cows.cpp)
add_executable(castle src/2/castle.cpp)
add_executable(shop src/2/shop.cpp)
add_executable(elephpotamus src/2/elephpotamus.cpp)
add_executable(spy src/2/spy.cpp)
