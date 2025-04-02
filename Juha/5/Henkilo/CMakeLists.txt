cmake_minimum_required(VERSION 3.10)
project(Ensimmainen)
set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp Henkilo.cpp Osoite.cpp Osoite.h Opettaja.cpp Opettaja.h Opiskelija.cpp Opiskelija.h)
