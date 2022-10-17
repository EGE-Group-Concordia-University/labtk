# -----------------------------------------------------------------------------
#
# LabTk script reading potential measurements from
# the MP730027 bench-top multimeter using USBTMC
# and writes them to a file
#
# (c) 2022 Rolf Wuthrich
#          Concordia University
#
# ------------------------------------------------------------------------------
# History
# Date       What                          Who
# ------------------------------------------------------------------------------
# 17.10.2022 Creation                      Rolf Wuthrich
# ------------------------------------------------------------------------------

# The MP730027 bench-top multimeter can be programmed using USBTMC
# This example demonstrates how LabTk can communicate with the MP730027

# Usage:
# =====
#
# In LabTk source this file like so:
#  labtk>  source MP730027.tcl
#
# Start data gathering with the command:
#  labtk> start
#
# Gathering will stop after $endTime seconds or after the
# following command is issued in LabTk:
#  labtk> stop

# Note:
# =====
#
# The user running LabTk must have the required privileges to read/write
# on the usbtmc files

# To give access to a none-root user to the usbtmc files:
#
# 1) create a group usbtmc:
#    sudo groupadd usbtmc
#
# 2) add members to this group with:
#    sudo usermod -aG usbtmc <user>
#
# 3) create udev rule in file /etc/udev/rules.d/51-usbtmc.rules
#    with the following content:
#
#    KERNEL=="usbtmc/*", MODE="0660", GROUP="usbtmc"
#    KERNEL=="usbtmc[0-9]", MODE="0660", GROUP="usbtmc"


# -------------------------------------------------------------------------------
# USBTMC communication with the MP730027 bench-top multimeter
# Read the manufacturer manual for details on the USBTMC commands
# the MP730027 bench-top multimeter understands

# opens communication socket
set usbtmc [open "/dev/usbtmc0" r+];
iosocket -open $usbtmc mp730027

# sets measurement range (units are volts)
mp730027 -write {"SENSE:VOLT:DC:RANGE 60"}

# sets measurement speed (F = fast; M = middle; L = low)
mp730027 -write {"RATE F"}

# links the measurement to the Tcl variable E
mp730027 -linkTclVariable E read {"MEAS?"}


# -------------------------------------------------------------------------------
# GECO process loop

# Time (in seconds) after which data gathering is stopped
set endTime 10

# Sets clock time to 50 ms
clk -tick 50

# Links the MP730027 instrument to the GECO process loop
io -linkModule mp730027

# trigger to turn off data gathering once end time is reached
trigger -trigger {if {$t>$endTime} {return STOP} else {return CONTINUE}} \
        -action {stop}

# Stream data to a file 'data.csv' every 2 seconds (-dtRecord 2)
set data_file data.csv
filestream -file $data_file \
           -header "# Collected data from [clock format [clock seconds] -format %D]\nt\tE" \
           -data {$t\t$E} \
           -dtRecord 2

# end of GECO process loop
end
