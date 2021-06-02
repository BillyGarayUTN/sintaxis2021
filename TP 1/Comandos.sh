#!/bin/bash


# punto a

sed "s/\./\.\n/g" breve_historia.txt   >  nuevoArchivo.txt


# punto b

grep -v '^\s*$' breve_historia.txt   


# punto c

sed "s/\./\.\n/g" breve_historia.txt  | grep -v '^\s*$' > breve_historia_2.txt


# punto d

sed "s/\./\.\n/g" breve_historia.txt |  grep -i '.\bguerra\b'


# punto e

egrep  '^A.*s\b|s\.\b$' breve_historia.txt > nuevoArchivo3.txt 


# punto f

egrep  '\bperonismo\b' 


# punto g

sed "s/\./\.\n/g" breve_historia.txt|  egrep  'Sarmiento.*Rosas|Rosas.*Sarmiento'  


# punto h

sed "s/\./\.\n/g" breve_prueba.txt | egrep  '1990|18[0-9][0-9]' 


# punto i

ls Escritorio | grep '\.txt$'

