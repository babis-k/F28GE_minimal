add_executable(SFMLTemplate src/SFMLTemplate.cpp)
target_link_libraries(SFMLTemplate PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System glm::glm rapidcsv::rapidcsv Pal::Sigslot CommonGameCode)
copy_media(SFMLTemplate)