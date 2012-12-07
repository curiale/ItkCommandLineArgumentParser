# Generate the ItkCommandLineArgumentParserConfig.cmake file in the build tree.
# The file tells external projects how to use ItkCommandLineArgumentParser.

# Settings specific to build trees
#
#
set(ItkCommandLineArgumentParser_USE_FILE_CONFIG ${ItkCommandLineArgumentParser_BINARY_DIR}/UseItkCommandLineArgumentParser.cmake)
set(ItkCommandLineArgumentParser_INCLUDE_DIRS_CONFIG
  ${ItkCommandLineArgumentParser_BINARY_DIR}
  ${ItkCommandLineArgumentParser_SOURCE_DIR}/lib
  )
set(ItkCommandLineArgumentParser_LIBRARY_DIRS_CONFIG
  ${ItkCommandLineArgumentParser_BINARY_DIR}
  )
set(ItkCommandLineArgumentParser_BINARY_DIR_CONFIG
  ${ItkCommandLineArgumentParser_BINARY_DIR}
  )

configure_file(
  ${ItkCommandLineArgumentParser_SOURCE_DIR}/ItkCommandLineArgumentParserConfig.cmake.in
  ${ItkCommandLineArgumentParser_BINARY_DIR}/ItkCommandLineArgumentParserConfig.cmake
  @ONLY IMMEDIATE
  )

configure_file(
  ${ItkCommandLineArgumentParser_SOURCE_DIR}/UseItkCommandLineArgumentParser.cmake.in
  ${ItkCommandLineArgumentParser_USE_FILE_CONFIG}
  @ONLY IMMEDIATE
  )

