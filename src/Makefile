# $Id: Makefile 15 2014-01-03 18:49:04Z wuthrich $
#
# This is the LabTk Makefile
#
# (c) Rolf Wuthrich
#     2015 -2020 Concordia University
#
# author:    Rolf Wuthrich
# email:     rolf.wuthrich@concordia.ca
# $Revision: 15 $
#
# This software is copyright under the BSD license
#
# ---------------------------------------------------------
# history:
# ---------------------------------------------------------
# Date       Modification                     Author
#----------------------------------------------------------
# 12.10.2015 Creation                         R. Wuthrich
# 16.11.2020 General update                   R. Wuthrich
#----------------------------------------------------------


CC = g++ -I /usr/include/tcl8.6 -I /usr/local/include/geco1.0


OBJS  = LabTkApp.o LabTk.o

all: $(OBJS)
#	$(CC) $(OBJS) -o labtk -lgeco1.0 -ltcl8.6 -ltk8.6 -lcomedi -lm
	$(CC) $(OBJS) -o labtk -lgeco1.0 -ltcl8.6 -ltk8.6 -lm

clean:
	rm -f *.o 
	rm -fr tmp
	rm -f labtk

install: labtk
	cp labtk /usr/local/bin

LabTkApp.o: LabTkApp.cc LabTkApp.h
	$(CC) -c LabTkApp.cc

LabTk.o: LabTk.cc LabTkApp.h
	$(CC) -c LabTk.cc
