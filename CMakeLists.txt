CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(INVADERS)

INCLUDE_DIRECTORIES(include include/sdl include/tinyxml include/maploader)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)

ADD_EXECUTABLE(invaders src/CFont.cpp  src/CGame.cpp  src/CImage.cpp  src/CMultiImage.cpp  src/CSprite.cpp  src/main.cpp src/MenuState.cpp  src/PauseState.cpp  src/PlayState.cpp  src/TextureManager.cpp src/maploader/base64.cpp  src/maploader/TMXLoader.cpp src/tinyxml/tinystr.cpp  src/tinyxml/tinyxml.cpp  src/tinyxml/tinyxmlerror.cpp  src/tinyxml/tinyxmlparser.cpp)
TARGET_LINK_LIBRARIES(invaders SDL SDL_image GL GLU)
