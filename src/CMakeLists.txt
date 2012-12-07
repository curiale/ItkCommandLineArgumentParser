#Requerimiento de la versión de cmake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release CACHE STRING
		        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
				        FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)



INCLUDE(${CMAKE_SOURCE_DIR}/CCMacros.txt)  

# Defino el nombre del proyecto
PROJECT(ItkCommandLineArgumentParser)



#Declare any external dependencies that your project may have here.
#examples include: ITK, VTK, JPEG, PNG, OpenGL, ZLIB, Perl, Java
#If you're not sure what name to use, look in the Modules directory of your
#cmake install and check that a file named Find(Package).cmake exists
SET(Required_Packages
	 ITK
	 )

#this foreach loads all of the packages that you specified as required.
#It shouldn't need to be modified.
FOREACH(Package ${Required_Packages})
  LOADPACKAGE(${Package})
ENDFOREACH(Package)


include(GenerateItkCommandLineArgumentParserConfig.cmake)
#-----------------------------------------------------------------------------
# Configure ItkCommandLineArgumentParserConfig.cmake for the build tree.
configure_file(${ItkCommandLineArgumentParser_SOURCE_DIR}/ItkCommandLineArgumentParserConfig.cmake.in
               ${ItkCommandLineArgumentParser_BINARY_DIR}/ItkCommandLineArgumentParserConfig.cmake @ONLY IMMEDIATE)
# Copy the UseItkVtk.cmake file to the binary tree
configure_file(${ItkCommandLineArgumentParser_SOURCE_DIR}/UseItkCommandLineArgumentParser.cmake.in
               ${ItkCommandLineArgumentParser_BINARY_DIR}/UseItkCommandLineArgumentParser.cmake @ONLY IMMEDIATE)






# Seteamos algunas variables en cmake
#SET (MI MyItkCommandLineArgumentParser)
#SET (${MI}_SOURCE ${MI}.cxx)

# add_executable -> crea un ejecutable stand-alone para ser corrido desde consola
#ADD_EXECUTABLE(${MI} ${${MI}_SOURCE})


# Incluimos el directorio lib/ que esta dentro de nuestro proyecto con librerias nuestras particulares del plugin
# Ademas agregamos las librerías que haya que compilar de nuetro propio plugin. 
INCLUDE_DIRECTORIES(./lib/)  

# Para cada una de las librerías las agregamos indicando cual es el cxx y el nombre del archivo




# ----- Lib itkUSSTImageToImageMetric-----
ADD_LIBRARY(ItkCommandLineArgumentParser lib/itkCommandLineArgumentParser.h lib/itkCommandLineArgumentParser.cxx)
TARGET_LINK_LIBRARIES(ItkCommandLineArgumentParser
	 ${ITK_LIBRARIES} 
	 ) 



ADD_EXECUTABLE(Test Test.cxx)

# Seteamos los flags de compilacion  
#Desabilitamos todos los flags 
SET_TARGET_PROPERTIES(ItkCommandLineArgumentParser  Test PROPERTIES COMPILE_FLAGS "-Wno-deprecated" LINK_FLAGS "")
#SET_TARGET_PROPERTIES(${MI}  PROPERTIES COMPILE_FLAGS "-Wno-deprecated" LINK_FLAGS "")


TARGET_LINK_LIBRARIES(Test 
    ItkCommandLineArgumentParser
	 ${ITK_LIBRARIES} 
	 ) 





#the following line is an example of how to add a test to your project.
#Testname is the title for this particular test.  ExecutableToRun is the
#program which will be running this test.  It can either be a part of this
#project or an external executable.  After that list any args that are needed
#for this test.  Include as many tests as you like.  If your project doesn't have
#any tests you can comment out or delete the following line.


#SET(MY_EXE_DIR ${CMAKE_BINARY_DIR})
#IF(RUNTIME_OUTPUT_DIRECTORY)
#   SET(MY_EXE_DIR ${RUNTIME_OUTPUT_DIRECTORY})
#ENDIF(RUNTIME_OUTPUT_DIRECTORY)

# Also do a unit test that checks whether the registration result is the same
# whether we use pixel spacing and image direction or not
#ADD_TEST(RegisterImages ${MY_EXE_DIR}/DemonsRegistration
#  -f ${CMAKE_SOURCE_DIR}/RatLungSlice1.mhd
#  -m ${CMAKE_SOURCE_DIR}/RatLungSlice2.mhd
# -o ${PROJECT_BINARY_DIR}/output.mha
#  -d -s 2 -g 1 -i 3x5 -e)

#ADD_TEST(RegisterImagesS ${MY_EXE_DIR}/DemonsRegistration
#  -f ${CMAKE_SOURCE_DIR}/RatLungSlice1s.mhd
# -m ${CMAKE_SOURCE_DIR}/RatLungSlice2s.mhd
# -o ${PROJECT_BINARY_DIR}/output-s.mha
# -d -s 2 -g 1 -i 3x5 -e)

#ADD_TEST(CompareImages ${MY_EXE_DIR}/ImageCompare 
#  ${PROJECT_BINARY_DIR}/output.mha ${PROJECT_BINARY_DIR}/output-s.mha)



