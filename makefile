#
# Auteur: C.-A. Brunet
# Date: 08 janvier 2018
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-01: graphicus-01.o tests.o canevas.o couche.o forme.o vecteur.o rectangle.o carre.o cercle.o
	g++ -o graphicus-01 graphicus-01.o tests.o canevas.o couche.o forme.o vecteur.o rectangle.o carre.o cercle.o

graphicus-01.o: graphicus-01.cpp canevas.h couche.h forme.h
	g++ -c graphicus-01.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h
	g++ -c couche.cpp

forme.o: forme.cpp forme.h
	g++ -c forme.cpp

vecteur.o: vecteur.cpp vecteur.h
	g++ -c vecteur.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -c rectangle.cpp

carre.o: carre.cpp carre.h
	g++ -c carre.cpp

cercle.o: cercle.cpp cercle.h
	g++ -c cercle.cpp

clean:
	rm  -f *.o
