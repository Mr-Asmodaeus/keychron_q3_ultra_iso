# Swap out upstream kscan_gpio_matrix.c for the shield's custom version
if(TARGET drivers__kscan)
    # Read the current source list from ZMK's kscan driver target
    get_target_property(KSCAN_SRCS drivers__kscan SOURCES)

    # Strip out the default upstream file path
    list(FILTER KSCAN_SRCS EXCLUDE REGEX ".*kscan_gpio_matrix\\.c$")

    # Update the target source list
    set_property(TARGET drivers__kscan PROPERTY SOURCES "${KSCAN_SRCS}")

    # Inject your shield-local driver replacement
    target_sources(drivers__kscan PRIVATE "${CMAKE_CURRENT_LIST_DIR}/drivers/kscan/kscan_gpio_matrix.c")

    message(STATUS "Shield Override: Replaced kscan_gpio_matrix.c with local shield driver.")
endif()