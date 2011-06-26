add_subdirectory(BDN)
link_directories(BDN)

add_library(nets NetsFactory.cpp)

target_link_libraries(nets BDN)
