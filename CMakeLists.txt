CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(INVADERS)

IF(UNIX)
	SET(CMAKE_BUILD_TYPE ${CMAKE_C_FLAGS_DEBUG})
ENDIF(UNIX)

INCLUDE_DIRECTORIES(include include/sdl include/tinyxml include/maploader)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)

ADD_EXECUTABLE(invaders src/CFont.cpp src/CSound.cpp  src/CGame.cpp  src/CImage.cpp  src/CMultiImage.cpp  src/CSprite.cpp  src/main.cpp src/MenuState.cpp  src/PauseState.cpp  src/PlayState.cpp  src/TextureManager.cpp src/maploader/base64.cpp  src/maploader/TMXLoader.cpp src/tinyxml/tinystr.cpp  src/tinyxml/tinyxml.cpp  src/tinyxml/tinyxmlerror.cpp  src/tinyxml/tinyxmlparser.cpp)
TARGET_LINK_LIBRARIES(invaders ${CMAKE_BUILD_TYPE} SDL SDL_image SDL_mixer GL GLU)
