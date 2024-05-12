OPT = -Wall -std=c++11

escape: main.o Hero.o EscapeeBehaviour.o Ninja.o random.o RescuedBehaviour.o RescuerBehvaiour.o Snorc.o VillainBehaviour.o List.o Escape.o
	g++ $(OPT) -o escape main.o Hero.o EscapeeBehaviour.o Ninja.o random.o RescuedBehaviour.o RescuerBehvaiour.o Snorc.o VillainBehaviour.o List.o Escape.o

main.o: main.cc Escape.h
	g++ $(OPT) -c main.cc

Hero.o: Hero.cc Hero.h
	g++ $(OPT) -c Hero.cc

EscapeeBehaviour.o: EscapeeBehaviour.cc EscapeeBehaviour.h
	g++ $(OPT) -c EscapeeBehaviour.cc

Ninja.o: Ninja.cc Ninja.h
	g++ $(OPT) -c Ninja.cc

random.o: random.cc 
	g++ $(OPT) -c random.cc

RescuedBehaviour.o: RescuedBehaviour.cc RescuedBehaviour.h
	g++ $(OPT) -c RescuedBehaviour.cc

RescuerBehvaiour.o: RescuerBehvaiour.cc RescuerBehvaiour.h
	g++ $(OPT) -c RescuerBehvaiour.cc

Snorc.o: Snorc.cc Snorc.h
	g++ $(OPT) -c Snorc.cc

VillainBehaviour.o: VillainBehaviour.cc VillainBehaviour.h
	g++ $(OPT) -c VillainBehaviour.cc

List.o: List.cc List.h
	g++ $(OPT) -c List.cc

Escape.o: Escape.cc Escape.h defs.h
	g++ $(OPT) -c Escape.cc

clean:
	rm -f *.o escape
