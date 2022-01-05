CU_SET_PATH("CMAKE_PHASING_SYSTEM_DIR" "${CMAKE_CURRENT_LIST_DIR}")

AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Phase_Aura.cpp")

AC_ADD_SCRIPT_LOADER("Phase_Aura"      "${CMAKE_CURRENT_LIST_DIR}/src/Phase_Aura_loader.h")

message("-- Phasing System configured --")
