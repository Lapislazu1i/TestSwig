function(BuildCSharpLibrary LibraryName)
    file(GLOB SWIG_PYTHON_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/swig_csharp/*.cxx")

    
    add_library(${LibraryName} SHARED  ${NORMAL_SRCS} ${SWIG_PYTHON_SRCS})
    # set_target_properties(${LibraryName} PROPERTIES PREFIX "_")
    # set_target_properties(${LibraryName} PROPERTIES SUFFIX ".pyd")

    add_custom_command(TARGET ${LibraryName} PRE_BUILD
    
    COMMAND ${CMAKE_COMMAND} -E
    
    copy "${CMAKE_CURRENT_SOURCE_DIR}/interface/interface.i" "${CMAKE_CURRENT_SOURCE_DIR}/swig_csharp")

    add_custom_command(TARGET ${LibraryName} PRE_BUILD

    COMMAND swig -c++ -csharp -outdir "${CMAKE_CURRENT_SOURCE_DIR}/swig_csharp" -outfile TestSwig.cs "${CMAKE_CURRENT_SOURCE_DIR}/swig_csharp/interface.i")

    add_custom_command(TARGET ${LibraryName} POST_BUILD
    
    COMMAND ${CMAKE_COMMAND} -E
    
    copy $<TARGET_FILE:${LibraryName}> "${CMAKE_CURRENT_SOURCE_DIR}/swig_csharp")

    target_include_directories(${LibraryName} PRIVATE ${PYTHON_INCLUDE_DIR})
    target_link_directories(${LibraryName} PRIVATE ${PYTHON_LIBS_DIR})
endfunction()
