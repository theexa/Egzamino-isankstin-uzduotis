cmake_minimum_required(VERSION 3.10)
project(TextAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Šaltiniai
set(SOURCES
    main.cpp
    mylib.cpp
)

set(HEADERS
    mylib.h
)

# Tekstiniai failai
set(DATA_FILES
    tekstas.txt
    tlds-alpha-by-domain.txt
)

# Sukurti vykdomąjį failą
add_executable(TextAnalyzer ${SOURCES} ${HEADERS})

# Kopijuoti tekstinius failus į build katalogą
foreach(DATA_FILE ${DATA_FILES})
    add_custom_command(TARGET TextAnalyzer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/${DATA_FILE} $<TARGET_FILE_DIR:TextAnalyzer>/${DATA_FILE}
    )
endforeach()