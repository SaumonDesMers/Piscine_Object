#include "position.hpp"
#include "statistic.hpp"
#include "worker.hpp"
#include "shovel.hpp"

int main() {

	/* Test Agrregation */
	try {
		Shovel shovel(10);
		Worker workerA;

		workerA.addShovel(&shovel);
		workerA.dig();

		int nbUses = shovel.getNumberOfUses();
		std::cout << "Number of uses: " << nbUses << std::endl;

		{
			Worker workerB;
			shovel.assign(&workerB);
			workerB.dig();
		}

		nbUses = shovel.getNumberOfUses();
		std::cout << "Number of uses: " << nbUses << std::endl;

		workerA.addShovel(&shovel);
		workerA.dig();

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}