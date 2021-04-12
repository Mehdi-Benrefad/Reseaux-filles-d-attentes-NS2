set fichier [open "ff.txt" a]

puts $fichier "IMRANE:18:Rabat"
puts $fichier "KHALID:20:kenitra"
puts $fichier "BADR:21:casablanca"

close $fichier

set fichier [open "ff.txt" r]

for { set i 1 } { $i<4 } { incr i } {  

gets $fichier res

puts $res

}

