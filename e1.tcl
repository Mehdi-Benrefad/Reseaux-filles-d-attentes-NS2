puts "*****************************************begin of execution**********************************"




set file [open "ready.txt" r]

# $input will contain the contents of the file
set input [read $file]

# $lines will be an array containing each line of test.txt
set lines [split $input "\n"]

# Loop through each line
foreach line $lines {



    set T [split $line ":"]

    lassign $T nom age ville
    if { $nom != "" } { 
    
    puts " hello $nom  this is your age $age and this is your city $ville"
    
    }

    
}


# Clean up
close $file
