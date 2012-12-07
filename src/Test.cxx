/*
 * =====================================================================================
 *
 *       Filename:  Test.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2012 18:11:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ariel Hernán Curiale (A.H.C), ariel@lpi.tel.uva.es
 *   Organization:  Universidad de Valladolid, Spain
 *
 * =====================================================================================
 */


#include "lib/itkCommandLineArgumentParser.h"

int main( int argc, char *argv[] )
{



 /** Create a command line argument parser. **/
 itk::CommandLineArgumentParser::Pointer commandLineParser =
     itk::CommandLineArgumentParser::New();

 commandLineParser->SetCommandLineArguments(argc, argv);



 std::cout<<"Starting segmentation with the following arguments:"<<std::endl;
 commandLineParser->Print(std::cout);

 return EXIT_SUCCESS;
}
