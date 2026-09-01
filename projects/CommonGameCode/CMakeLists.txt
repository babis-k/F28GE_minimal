add_library(CommonGameCode STATIC src/CommonGameCode.cpp src/SFMLApplication.cpp
        src/EntityId.h
        src/EntitySignals.h
        src/Component.h
        src/ManagerBase.cpp
        src/ManagerBase.h)
target_link_libraries(CommonGameCode PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System glm::glm rapidcsv::rapidcsv Pal::Sigslot)

target_include_directories(CommonGameCode PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)