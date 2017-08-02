echo "Hello Welcome to the automated Graphics file Building"
echo "This is using the OPENGL libraries!"

n=$#

for i in $*
do

g++ $i.cpp -lGL -lGLU -lglut -o $i
./$i

done
