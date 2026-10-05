# ctui — C++ Console TUI Library

Легкая и переиспользуемая библиотека для создания консольных меню (TUI) на C++. Поддерживает два режима работы: интерактивное меню с действиями и меню-выбор, возвращающее индекс выбранного пункта.

## Возможности

- Два режима работы: меню с действиями и меню-выбор (возвращает `int`).
- Автоматическое определение режима по типу переданных данных.
- Поддержка вложенных подменю без дополнительного кода.
- Автоматическая очистка экрана и обработка ошибок ввода.
- Опциональный заголовок меню.
- Подключение через `#include <ctui>` как системной библиотеки.
- Сборка в виде статической библиотеки через CMake.

## Требования

- **C++**: стандарт C++20 или выше.
- **CMake**: версия 3.14 или выше.
- **Компилятор**: GCC, Clang или MSVC с полной поддержкой C++20.

## Установка и подключение

### Через локальную папку

1. Клонируйте библиотеку в удобное место:
   ```bash
   git clone https://github.com/ВАШ_НИК/ctui.git ~/Projects/libs/ctui

2. В CMakeLists.txt вашего проекта добавьте:
   ```cmake
   add_subdirectory(~/Projects/libs/ctui ${CMAKE_BINARY_DIR}/ctui_build)
   target_link_libraries(ваш_проект PRIVATE ctui)
3. Используйте в коде:
   ```cpp
   #include <ctui>

### Через FetchContent
   ```cmake
   include(FetchContent)

   FetchContent_Declare(
      ctui
      GIT_REPOSITORY https://github.com/ВАШ_НИК/ctui.git
      GIT_TAG main
   )

   FetchContent_MakeAvailable(ctui)
   target_link_libraries(ваш_проект PRIVATE ctui)