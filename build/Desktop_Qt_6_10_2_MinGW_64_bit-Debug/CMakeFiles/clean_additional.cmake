# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TorneoPoder_DragonBall_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TorneoPoder_DragonBall_autogen.dir\\ParseCache.txt"
  "TorneoPoder_DragonBall_autogen"
  )
endif()
