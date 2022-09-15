make && ./bin/lab3_original.out && ./bin/lab3_modificado.out 
clear
sed -n '10050004,10050006p; 10050007q' ./bin/printsMod.txt
echo " "
sed -n '10050004,10050006p; 10050007q' ./bin/printsOrigin.txt