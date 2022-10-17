// $Id: ECApp.cc 27 2014-03-16 17:58:36Z wuthrich $
// ---------------------------------------------------------------
//
// Definition of the class LabTkApp
//
// (c) Rolf Wuthrich
//     2015 - 2021 Concordia University
//
// author:  Rolf Wuthrich
// email:   rolf.wuthrich@concordia.ca
// version: v1 ($Revision: 27 $)
//
// This software is copyright under the BSD license
//  
// ---------------------------------------------------------------
// history:
// ---------------------------------------------------------------
// Date       Modification                     Author
// ---------------------------------------------------------------
// 12.10.2015 Creation                         R. Wuthrich
// 16.11.2020 General update                   R. Wuthrich
//
// ---------------------------------------------------------------

#define labTkVersion "1.2"

#include <tcl.h>
#include <cstring>
#include <iostream>
#include <tclreadline.h>
#include "LabTkApp.h"

using namespace std;

/**
 * @brief LabTk license
 */

static CONST char* labtk_license =
"   LabTk The Laboratory tool kit\n"
"   Copyright (c) 2015-2021, Rolf Wuthrich <rolf.wuthrich@concordia.ca>\n"
"   All rights reserved.\n "
"   \n"
"   Redistribution and use in source and binary forms, with or without\n"
"   modification, are permitted provided that the following conditions\n"
"   are met:\n"
"   \n"
"     * Redistributions of source code must retain the above copyright\n"
"       notice, this list of conditions and the following disclaimer.\n"
"     * Redistributions in binary form must reproduce the above copyright\n"
"       notice, this list of conditions and the following disclaimer in the\n"
"       documentation and/or other materials provided with the distribution.\n"
"     * Neither the name of Rolf Wuthrich nor the names of contributors\n"
"       to this software may be used to endorse or promote products derived\n"
"       from this software without specific prior written permission.\n"
"       \n"
"   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"
"   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n"
"   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n"
"   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR\n"
"   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,\n"
"   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,\n"
"   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR\n"
"   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF\n"
"   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING\n"
"   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS\n"
"   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";



/**
 * Use this function to perform cleanup operations
 * @brief Called on exit of Tcl
 * @param clientData pointer to the running LabTakApp
 */

void labTk_exitHandler(ClientData clientData)
{
  LabTkApp* app=(LabTkApp *)clientData;
  Tcl_Free(app->prompt);
  cout << "exiting LabTk ...\n";
}


// ----------------------------------------------------------------------
//
// class LABTKAPP : Main application of LabTk
//


/**
 * @brief Constructor
 * @param argc number of arguments passed from main
 * @param argv arguments passed from main
 */

LabTkApp::LabTkApp(int argc, char **argv) : gecoApp(argc,argv)
{
  if (argc == 1) {
    cout << "\n";
    cout << "\tL a b T k\n";
    cout <<"\tThe laboratory tool kit interface\n";
    cout << "\tVersion " << labTkVersion << "\n";
    cout << "\tlast modified August 2021\n";
    cout << "\n";
    cout << "\tCopyright (C) 2015-2021\n";
    cout << "\tRolf Wuthrich, Concordia University, Canada\n";
    cout << "\tThis is free software; type 'puts $::labtk::license' for more details.\n";
    cout << "\n";
    cout << "\tLabTk home: http://ege.encs.concordia.ca/ectk.html\n";
    cout << "\tFor help see the man pages.\n";
    cout << "\n";
    cout.flush();
  }

  prompt=Tcl_Alloc(9);
  strcpy(prompt, "LabTk > ");
  registerGlobalVars();
  Tcl_CreateExitHandler(labTk_exitHandler, this);

  //Tcl_EvalFile(interp,"//usr//local//share//labtk//labtklib.tcl");
  //Tcl_EvalFile(interp,"labtklib.tcl");
  //Tcl_EvalFile(interp,"//usr//local//etc//labtk//labtk.labtkrc.tcl");
  if (argc==2) Tcl_EvalFile(interp,argv[1]);
  sourceRcFile();
}


/**
 * Note: is never called at exit of Tcl.
 *       Cleanup operations must be done in labTk_exitHandler.
 * @brief Destructor
 */

LabTkApp::~LabTkApp()
{
}


/**
 * @brief Registers global Tcl variables specific to LabTk
 */

void LabTkApp::registerGlobalVars()
{
  Tcl_CreateNamespace(interp,"labtk", NULL, NULL);
  
  Tcl_LinkVar(interp,"::labtk::license",
              (char *)&labtk_license, TCL_LINK_STRING | TCL_LINK_READ_ONLY);

  Tcl_SetVar(interp,"::labtk::version",labTkVersion,0);
}


/**
 * @brief Sources the configuration files
 */

void LabTkApp::sourceRcFile()
{
  if (Tcl_EvalFile(interp,"~//.labtkrc.tcl")!=TCL_OK)
    {
      Tcl_Eval(interp,
	"file copy //usr//local//share//labtk//labtkrc.tcl ~//.labtkrc.tcl");
      Tcl_EvalFile(interp,"~//.labtkrc.tcl");
    }
}
