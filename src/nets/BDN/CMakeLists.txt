add_subdirectory(realisations)
link_directories(realisations)

add_library(BDN
    BDN.cpp
    BDNTrainer.cpp
    LogicalArchitecture.cpp)

target_link_libraries(BDN BDN-realisations)
