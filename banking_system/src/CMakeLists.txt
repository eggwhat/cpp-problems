

file(GLOB HEADER_EXCEPTIONS_LIST CONFIGURE_DEPENDS "${BankingSystem_SOURCE_DIR}/include/exceptions/*.h")
file(GLOB HEADER_INTERFACES_LIST CONFIGURE_DEPENDS "${BankingSystem_SOURCE_DIR}/include/interfaces/*.h")
file(GLOB HEADER_PROJECT_LIST CONFIGURE_DEPENDS "${BankingSystem_SOURCE_DIR}/include/project/*.h")

add_library(exceptions_library exception.cpp ${HEADER_EXCEPTIONS_LIST})
add_library(interfaces_library ${HEADER_INTERFACES_LIST})
add_library(project_library account.cpp command_line_interface.cpp funds.cpp funds_eur.cpp funds_pln.cpp funds_usd.cpp
maintenance.cpp person.cpp premium_account.cpp premium_account_manager.cpp premium_account_manager_factory.cpp
standard_account.cpp standard_account_manager.cpp standard_account_manager_factory.cpp)

target_include_directories(exceptions_library PUBLIC ../include)
target_include_directories(interfaces_library PUBLIC ../include)
target_include_directories(project_library PUBLIC ../include)

target_compile_features(exceptions_library PUBLIC cxx_std_14)
target_compile_features(interfaces_library PUBLIC cxx_std_14)
target_compile_features(project_library PUBLIC cxx_std_14)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})

