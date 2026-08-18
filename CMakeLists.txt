if(TARGET drivers__kscan)
    # Give compiler access to original zmk kscan header files
    target_include_directories(drivers__kscan PRIVATE 
        "${ZEPHYR_BASE}/../zmk/app/module/drivers/kscan"
    )
    
    get_target_property(KSCAN_SRCS drivers__kscan SOURCES)
    list(FILTER KSCAN_SRCS EXCLUDE REGEX ".*kscan_gpio_matrix\\.c$")
    set_property(TARGET drivers__kscan PROPERTY SOURCES "${KSCAN_SRCS}")
    target_sources(drivers__kscan PRIVATE "${CMAKE_CURRENT_LIST_DIR}/drivers/kscan/kscan_gpio_matrix.c")
    
    message(STATUS "Shield Override: Replaced kscan_gpio_matrix.c with local shield driver.")
endif()