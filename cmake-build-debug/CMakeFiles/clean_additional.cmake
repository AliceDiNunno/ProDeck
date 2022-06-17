# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ProDeck_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ProDeck_autogen.dir/ParseCache.txt"
  "ProDeck_autogen"
  )
endif()
