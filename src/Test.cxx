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
 itk::CommandLineArgumentParser::Pointer parser =
     itk::CommandLineArgumentParser::New();

 parser->SetCommandLineArguments(argc, argv);



 std::cout<<"Starting segmentation with the following arguments:"<<std::endl;
 parser->Print(std::cout);
  
  
  std::string volumeFilePath = "";
  bool ret_parser = parser->GetCommandLineArgument("--volume",volumeFilePath);
  
  std::vector<double> newDirection(9,0.0);
  ret_parser = parser->GetCommandLineArgument("--newDirection",newDirection);
  
  
  double direction[3][3];
  
  for(unsigned int i=0; i<3; i++)
    for(unsigned int j=0; j<3; j++)
      direction[i][j] = newDirection[3*i+j];
  
  
  
  

    for(unsigned int i=0; i<3; i++)
      {
      std::cout<<"["<<std::endl;
      for(unsigned int j=0; j<3; j++)
        std::cout<<direction[i][j]<<",";
      
      std::cout<<"]"<<std::endl;
      
      
      std::cout<<"["<<std::endl;
      for(unsigned int j=0; j<3; j++)
        std::cout<<newDirection[3*i+j]<<",";
      
      std::cout<<"]"<<std::endl;
      }

  return EXIT_SUCCESS;
}
