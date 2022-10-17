// This may look like C code, but it is really -*- C++ -*-
// $Id: ECApp.h 15 2014-01-03 18:49:04Z wuthrich $
// ---------------------------------------------------------------- 
//                                                                  
// Header file for the class LabTkApp
//
// (c) Rolf Wuthrich
//     2015 - 2020 Concordia University
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
// ---------------------------------------------------------------

#ifndef LabTkApp_SEEN_
#define LabTkApp_SEEN_

#include <tcl.h>
#include <tk.h>
#include <geco.h>

using namespace std;


/**
 * @brief Main class of LabTk
 * \author Rolf Wuthrich
 * \date 2015-2021
 */

class LabTkApp : public gecoApp
{

  friend void labTk_exitHandler(ClientData clientData);

public:

  LabTkApp(int argc, char **argv);
  ~LabTkApp();

  virtual void registerGlobalVars();
  void sourceRcFile();

};

#endif /* LabTkApp_SEEN_ */
