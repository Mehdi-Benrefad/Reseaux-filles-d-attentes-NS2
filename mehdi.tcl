

set r 75


while { $r>0 } {

puts $r

set r [expr $r-1]


}



for { set a 1 } { $a<99 } { incr a } {

if { [expr $a == 50]} {

puts "error mehdi"

}

puts -nonewline "I'm the "

puts -nonewline $a

puts " one"


}
