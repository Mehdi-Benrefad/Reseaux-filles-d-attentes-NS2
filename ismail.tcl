
for { set r 1 } { $r<80 } { incr r } {

set T($r) [expr $r+1]

puts $T($r)


}


proc ismail { a b } {

return [expr $a+$b]

}

set x [ismail 15 20]

puts -nonewline "this the result of sum "
puts $x


proc lis {} {

return [ list hello baby 15  10  1999]

}

set g [lis]

puts $g


puts "enter your value plz "
gets stdin var
puts "you entered $var"

