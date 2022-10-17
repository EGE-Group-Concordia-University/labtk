# $Id: ectklib.tcl 15 2014-01-03 18:49:04Z wuthrich $
# ---------------------------------------------------------
#
# This is the LabTk library
#
# This file is sourced by LabTk at start-up
#
# (c) Rolf Wuthrich
#     2015 Concordia University
#
# author:  Rolf Wuthrich
# email:   rolf.wuthrich@concordia.ca
# version: v1 ($Revision: 15 $)
#
# This software is copyright under the BSD license
#
# ---------------------------------------------------------
# history:
# ---------------------------------------------------------
# Date       Modification                     Author
#----------------------------------------------------------
# 10.12.2015 Creation                         R. Wuthrich
#----------------------------------------------------------

fconfigure stdin -blocking 0

# hide the main window of the tk application
wm state . withdrawn

# standard colour palette to be used
tk_setPalette white

# number of significant digits to be used in display operations
set tcl_precision 4

# load additional modules


# -----------------------------------------------------------------------
#
# defines global variables of LabTk
#
# -----------------------------------------------------------------------



# -----------------------------------------------------------------------
#
# notes - manipulates notes to be added to an experiment
#
# usage : notes option ?arg?
#
# valid options are:
#
#  -add          : adds a note
#  -clear        : removes all notes
#  -insert index : inset a note before the line index
#  -print        : returns the notes
#  -remove index : remove the note on the line index
#
# -----------------------------------------------------------------------

proc notes {{subCmd ""} args} {
    global ::labtk::note
    set ret ""

    if {$subCmd==""} {
        if {[info exists note]!=0} {
            for {set i 0} {$i<[llength $note]} {incr i} {
                append ret "$i:\t[subst [join [lindex $note $i]]]\n"
            }
        }
        return $ret
    }

    switch -exact -- $subCmd {
        
        -add {
            lappend note $args
	    return
	}
	-clear {
	    if {[info exists note]!=0} {unset note} }
	-insert {
	    if {[info exists note]==0} {return}
	    set i [lindex $args 0]
	    set note [linsert $note $i [lrange $args 1 end]]
	    return
	}
	-print {
	    if {[info exists note]==0} {return}
	    for {set i 0} {$i<[llength $note]} {incr i} {
		append ret "[subst [join [lindex $note $i]]]\n"
	    }
	    return $ret
	}
	-remove {
	    if {[info exists note]==0} {return}
	    set i [lindex $args 0]
	    set note [lreplace $note $i $i]
	    return
	}
	default {
	    error "bad option \"$subCmd\": \
                       must be -add, -clear, -insert, -print or -remove"}
    }
}

