cmake_minimum_required(VERSION 3.30)
project(SnakeInterfaceTerminal)

set(CMAKE_C_STANDARD 99)

# Adicione o caminho para os arquivos de inclusão (cabeçalhos)
include_directories("C:/MinGW/PDCurses-3.8/PDCurses-3.8")

# Adicione o caminho para as bibliotecas do PDCurses
link_directories("C:/MinGW/PDCurses-3.8/PDCurses-3.8/wincon")

# Adicione o executável principal do projeto
add_executable(SnakeInterfaceTerminal main.c)

# Vincule a biblioteca PDCurses ao projeto
target_link_libraries(SnakeInterfaceTerminal pdcurses)
