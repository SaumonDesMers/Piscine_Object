#include "position.hpp"
#include "statistic.hpp"
#include "workshop.hpp"
#include "worker.hpp"
#include "shovel.hpp"
#include "tool.hpp"
#include "hammer.hpp"

#define TITLE(X) std::cout << "\033[1;32m" << X << "\033[0m\n" << std::endl;
#define SUBTITLE(X) std::cout << "\033[1;33m" << X << "\033[0m" << std::endl;

int main() {

	TITLE("MANDATORY PART")
	try {

		SUBTITLE("Creating worker A, B and C, Shovel, Hammer, Workshop A and B")
		Worker workerA, workerB, workerC;
		Shovel shovel(10);
		Hammer hammer(5);
		Workshop workshopA, workshopB;

		std::cout << std::endl;
		SUBTITLE("Assigning shovel to workerA and using it")
		workerA.grabTool(&shovel);
		workerA.useTools();


		std::cout << std::endl;
		SUBTITLE("Creating workerD inside a scope, assigning shovel to it and using it")
		{
			Worker workerD;
			workerD.grabTool(&shovel);
			workerD.useTools();

			std::cout << std::endl;
			SUBTITLE("End of scope for workerD")
		}

		std::cout << std::endl;
		SUBTITLE("Trying workerA useTools() to see if shovel is still assigned to it")
		workerA.useTools();


		std::cout << std::endl;
		SUBTITLE("Assigning hammer and shovel to workerA and using them")
		workerA.grabTool(&hammer);
		workerA.grabTool(&shovel);
		workerA.useTools();

		std::cout << std::endl;
		SUBTITLE("Registering workerA to workshopA and working")
		workerA.enter(&workshopA);
		workerA.work();

		std::cout << std::endl;
		SUBTITLE("End of scope")

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	TITLE("BONUS PART")
	try {

		SUBTITLE("Creating worker A, B and C, Shovel, Hammer, Workshop A and B")
		Worker workerA, workerB, workerC;
		Shovel shovel(10);
		Hammer hammer(5);
		Workshop workshopA, workshopB;

		std::cout << std::endl;
		SUBTITLE("Assigning shovel and hammer to workerA, getting shovel and using it")
		workerA.grabTool(&hammer);
		workerA.grabTool(&shovel);
		Tool *tool = workerA.getTool<Hammer>();
		tool->use();

		std::cout << std::endl;
		SUBTITLE("Restricting workshopA to Shovel and trying to register workerB to it")
		workshopA.setRestrictedTool<Shovel>();
		try {
			workerB.enter(&workshopA);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;
		SUBTITLE("Registering workerA to workshopA and working")
		workerA.enter(&workshopA);
		workerA.work();

		std::cout << std::endl;
		SUBTITLE("Set workshopA restricted tool to Hammer and working")
		workshopA.setRestrictedTool<Hammer>();
		workshopA.executeWorkDay();

		std::cout << std::endl;
		SUBTITLE("WorkerA drops shovel")
		workerA.dropTool(&shovel);

		std::cout << std::endl;
		SUBTITLE("WorkerA drops hammer, should leave workshopA")
		workerA.dropTool(&hammer);

		std::cout << std::endl;
		SUBTITLE("End of scope")

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}