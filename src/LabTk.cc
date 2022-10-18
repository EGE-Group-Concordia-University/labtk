// $Id: ECTk.cc 15 2014-01-03 18:49:04Z wuthrich $
// ---------------------------------------------------------------- 
//                                                                  
// LabTk - Laboratory Tool Kit
//
// (c) Rolf Wuthrich
//     2015 - 2022 Concordia University
//
// author:  Rolf Wuthrich
// email:   rolf.wuthrich@concordia.ca
// version: v1 ($Revision: 15 $)
//
// This software is copyright under the BSD license
//
// ---------------------------------------------------------------
// history:
// ---------------------------------------------------------------
// Date       Modification                     Author
// ---------------------------------------------------------------
// 12.10.2015 Creation                         R. Wuthrich
// 20.11.2020 General update                   R. Wuthrich
//                                                                  
// ---------------------------------------------------------------

#include "LabTkApp.h"

using namespace std;

/*! \mainpage LabTk - The laboratory tool kit
 *
 * \tableofcontents
 *
 * \section intro_sec Introduction
 *
 * LabTk is a command line shell type application to interface the geCo library.
 *
 * \section install_sec Installation
 *
 * \subsection Prerequisites 
 * Tcl/Tk development package version 8.6 
 *
 * \subsection Step1 
 * Build the latest version of the geCo library
 * \subsection Step2 
 * Build the LabTk with 'make'
 * \subsection Step3 
 * Install LabTk with 'sudo make install'
 */


/**
 * @brief Main program of LabtTk
 * @param argc number of arguments passed in the command line
 * @param argv Arguments passed on the command line
 */

int main(int argc, char **argv)
{
  LabTkApp* LabTk;
  LabTk = new LabTkApp(argc, argv);
  LabTk->runCLI();
  delete LabTk;
  return 0;
}
