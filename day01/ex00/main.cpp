#include "position.hpp"
#include "statistic.hpp"
#include "worker.hpp"
#include "shovel.hpp"
#include "tool.hpp"
#include "hammer.hpp"
#include "workshop.hpp"

#define TITLE(X) std::cout << "\033[1;33m" << X << "\033[0m" << std::endl;

int main() {

	try {

		TITLE("Creating shovelA");
		Shovel shovel(10);

		std::cout << std::endl;
		TITLE("Assigning shovelA to workerA and using it")
		Worker workerA;

		workerA.addTool(&shovel);
		workerA.useTools();


		std::cout << std::endl;
		TITLE("Assigning shovelA to workerB inside a scope and using it")
		{
			Worker workerB;
			shovel.assign(&workerB);
			workerB.useTools();

			std::cout << std::endl;
			TITLE("End of scope for workerB")
		}


		std::cout << std::endl;
		TITLE("Trying workerA useTools() to see if shovelA is still assigned to it")
		workerA.useTools();


		std::cout << std::endl;
		TITLE("Assigning hammerA and shovelA to workerA and using them")
		Hammer hammer(5);

		workerA.addTool(&hammer);
		workerA.addTool(&shovel);
		workerA.useTools();

		std::cout << std::endl;
		TITLE("Creating workshopA and entering it with workerA")
		Workshop workshopA;

		workerA.enter(&workshopA);
		workerA.work();

		std::cout << std::endl;
		TITLE("End of scope for workerA, workshopA, hammerA and shovelA")

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}