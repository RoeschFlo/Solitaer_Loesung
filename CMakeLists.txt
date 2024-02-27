cmake_minimum_required(VERSION 3.0.0)
project(solitear)

# Setze den Pfad zu den Header-Dateien
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Setze den Pfad zur statischen Bibliotheksdatei
set(LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/libraylib.a)

# Füge den Include-Pfad für die Header-Dateien hinzu
include_directories(${INCLUDE_PATH})

# Füge die statische Bibliotheksdatei hinzu
add_library(libraylib STATIC IMPORTED)
set_target_properties(libraylib PROPERTIES IMPORTED_LOCATION ${LIBRARY_PATH})

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/spielfeld.cpp
    src/buttons.cpp
                            )

# Verlinke das Ziel mit der importierten Bibliothek
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    libraylib
    winmm)
