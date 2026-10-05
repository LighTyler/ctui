cmake_minimum_required(VERSION 3.14)
project(tui_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Создаем статическую библиотеку. 
# Обязательно указываем файл заголовка, чтобы он отображался в IDE.
add_library(ctui STATIC src/ctui.cpp include/ctui)

# 2. ГЛАВНЫЙ ТРЮК: Говорим CMake, что файл без расширения — это заголовок, 
# и его НЕ НУЖНО пытаться компилировать как .cpp файл.
set_source_files_properties(include/ctui PROPERTIES HEADER_FILE_ONLY TRUE)

# 3. Подключаем папку include как системную (SYSTEM) и публичную (PUBLIC).
# SYSTEM уберет предупреждения из вашего кода, а PUBLIC позволит 
# подключать библиотеку через <ctui> в любом другом проекте.
target_include_directories(ctui SYSTEM PUBLIC include)