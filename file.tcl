
#set fichier [open "ismail.txt" w+]

#puts $fichier "ismail:18:Rabat"
#puts $fichier "mehdi:20:kenitra"
#puts $fichier "yahya:21:casablanca"

#close $fichier
#


#set fichier [open "ismail.txt" r]

#for { set i 1 } { $i<4 } { incr i } {  

#gets $fichier res

#puts $res

#}


#close $fichier

set file [open "ismail.txt"]

# $input will contain the contents of the file
set input [read $file]

# $lines will be an array containing each line of test.txt
set lines [split $input "\n"]

# Loop through each line
foreach line $lines {


    set index 0
    set T [split $line ":"]
    puts "$T"
    lassign $T \ nom age ville
    puts "this is your age=$age"

    
}


# Clean up
close $file
