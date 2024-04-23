add_library(ip_manager STATIC
    ip_manager.c
)

target_include_directories(ip_manager 
    PUBLIC .
)

target_link_libraries(ip_manager PUBLIC
    trie_data
)