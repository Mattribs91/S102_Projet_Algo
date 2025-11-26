# CMakeLists.txt
# ----------------------------------------------------------------------
# Ce fichier est destiné à remplacer le fichier .cbp pour la compilation
# sur macOS (via CLion et Homebrew).
# ----------------------------------------------------------------------

# Spécifie la version minimale de CMake requise
cmake_minimum_required(VERSION 3.10)

# Définit le nom de votre projet
project(Projet_Algo C CXX)

# Spécifie le standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- ÉTAPE 1 : Trouver les bibliothèques SDL ---
# Trouve manuellement SDL2 et SDL2_image installés via Homebrew
find_library(SDL2_LIBRARY SDL2 PATHS /opt/homebrew/lib REQUIRED)
find_library(SDL2_IMAGE_LIBRARY SDL2_image PATHS /opt/homebrew/lib REQUIRED)
find_path(SDL2_INCLUDE_DIR SDL.h PATH_SUFFIXES SDL2 PATHS /opt/homebrew/include REQUIRED)
find_path(SDL2_IMAGE_INCLUDE_DIR SDL_image.h PATH_SUFFIXES SDL2 PATHS /opt/homebrew/include REQUIRED)

# --- ÉTAPE 2 : Définir l'exécutable ---
# Crée l'exécutable final "Projet_Algo"
add_executable(Projet_Algo
        src/main.cpp
        src/Moteur.cpp
        src/Image.cpp
)

# --- ÉTAPE 3 : Spécifier les chemins d'en-tête ---
target_include_directories(Projet_Algo PRIVATE
        include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
)

# --- ÉTAPE 4 : Lier les bibliothèques ---
target_link_libraries(Projet_Algo PRIVATE
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
)