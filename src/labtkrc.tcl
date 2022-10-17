# CVS ID : $Id: ectkrc.tcl 39 2015-01-09 13:09:42Z wuthrich $
# ----------------------------------------------------------------
#
# This is the LabTk user rc file
#
# This file is sourced by LabTk at startup
#
# (c) Rolf Wuthrich
#     2012-2020 Concordia University
#
# version: v3 ($Revision: 39 $)
#
# ----------------------------------------------------------------


# ----------------------------------------------------------------
# 
# User specific configuration
# 
# Add here any commands you want to have executed at LabTk startup


# ----------------------------------------------------------------


# ----------------------------------------------------------------
# setups and launches tclreadline

if {$tcl_interactive} {

    package require tclreadline

    # store maximal this much lines in the history file:
    set tclreadline::historyLength 200

    # defines a command prompt
    namespace eval tclreadline {
  	proc prompt1 {} {
  	    return "LabTk> "
  	}
    }

    # go to tclrealdine's main loop.
    tclreadline::Loop
}

# ----------------------------------------------------------------
