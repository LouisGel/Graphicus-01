#
# Auteur: C.-A. Brunet
# Date: 08 janvier 2018
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-01: graphicus-01.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o
	g++ -o graphicus-01 graphicus-01.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o

plan_tests: plan_tests.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o
	g++ -o plan_tests plan_tests.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o

graphicus-01.o: graphicus-01.cpp tests.h
	g++ -c graphicus-01.cpp

plan_tests.o: plan_tests.cpp
	g++ -c plan_tests.cpp

tests.o: tests.cpp tests.h canevas.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h vecteur.hpp
	g++ -c couche.cpp

forme.o: forme.cpp forme.h coordonnee.h
	g++ -c forme.cpp

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ -c rectangle.cpp

carre.o: carre.cpp carre.h rectangle.h
	g++ -c carre.cpp

cercle.o: cercle.cpp cercle.h forme.h
	g++ -c cercle.cpp


clean:
	rm  -f *.o
