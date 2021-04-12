Class etudiant


etudiant etu

etudiant instproc show {} {

$self instvar nom prenom age cin cne note

puts "Nom :$nom"
puts "Prenom:$prenom"
puts "Age:$age"
puts "CIN:$cin"
puts "CNE:$cne"
puts "Note:$note"


}

etudiant instproc init { a b c d e f } {

$self instvar nom prenom age cin cne note

set nom $a
set prenom $b
set age $c
set cin $d
set cne $e
set note $f

}

etudiant instproc valide {  } { 

$self instvar nom prenom age cin cne note

  

	  if { $note ==20 } {

      	      puts "Majorant de la promotion"
      	      
	  } elseif { $note <0 } {
	   
	   puts "note erroné"
	  
	  } elseif { $note< 5 } {
	     
	    puts "Non validé"
	    
	  } elseif {  $note >=12   } {
	  
	      puts "Validé"
	      
	  }  else {
	  
	    puts "Rattrapage"
	  
	  }
  


}

puts "*********************Etudiant 1*************************************"
etudiant op1 LARHCHIM ISMAIL 21 AD35874 J13326042 12
op1 show
puts -nonewline "Etat Note:"
op1 valide
puts "**********************Etudiant 2************************************"
etudiant op2 BENREFAD MEHDI 21 AD35764 J177826042 7
op2 show
puts -nonewline "Etat Note:"
op2 valide
puts "**********************Etudiant 3************************************"
etudiant op3 CHIBANE YAHYA 21 AD76874 J133SDS42 4
op3 show
puts -nonewline "Etat Note:"
op3 valide
puts "********************Modification de l'etudiant 1*******************************"
op1 set nom "MESSI"
op1 set prenom "LIONEL"
op1 set age 33
op1 show 
puts -nonewline "Etat Note:"
op1 valide 
puts "*********************Modification de l'etudiant 2******************************"
op2 set note 15
op2 show 
puts -nonewline "Etat Note:"
op2 valide
puts "**********************Modification de l'etudiant 3*****************************"
op3 set note 20
op3 show 
puts -nonewline "Etat Note:"
op3 valide 
puts "**********************ReModification de l'etudiant 3******************************************************"
op3 set note -9
op3 show
puts -nonewline "Etat Note:"
op3 valide
