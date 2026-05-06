cmake_minimum_required(VERSION 4.1)
project(AT1Eletromag C)

set(CMAKE_C_STANDARD 11)

add_executable(AT1Eletromag main.c
        funcoes_math.c
        def.h
        mtwister.c
)
