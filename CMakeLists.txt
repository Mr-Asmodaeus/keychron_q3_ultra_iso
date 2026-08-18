function(swap_kscan_matrix_driver)
    if(NOT TARGET drivers__kscan)
        message(FATAL_ERROR "drivers__kscan target does not exist")
    endif()

    get_target_property(KSCAN_SRCS drivers__kscan SOURCES)

    list(
        FILTER KSCAN_SRCS
        EXCLUDE REGEX
        "/kscan_gpio_matrix\\.c$"
    )

    set(LOCAL_DRIVER
        "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/drivers/kscan/kscan_gpio_matrix.c"
    )

    if(NOT EXISTS "${LOCAL_DRIVER}")
        message(FATAL_ERROR
            "Custom KSCAN driver not found: ${LOCAL_DRIVER}"
        )
    endif()

    list(APPEND KSCAN_SRCS "${LOCAL_DRIVER}")

    set_property(
        TARGET drivers__kscan
        PROPERTY SOURCES "${KSCAN_SRCS}"
    )

    target_include_directories(
        drivers__kscan
        PRIVATE
        "${ZEPHYR_BASE}/../zmk/app/module/drivers/kscan"
    )

    message(STATUS
        "KSCAN matrix driver replaced with: ${LOCAL_DRIVER}"
    )
endfunction()

cmake_language(
    DEFER
    DIRECTORY "${ZEPHYR_BASE}/../zmk/app"
    CALL swap_kscan_matrix_driver
)