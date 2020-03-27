// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool resolver(std::vector<int> const &vector, int ini, int fin, int K) {

	if (fin - ini ==0) { // 1 elemento
		return true;
	}
	else {
		int m = (ini + fin) / 2;
		bool iz = resolver(vector, ini, m, K);
		bool der = resolver(vector, m + 1, fin, K);
		return (iz && der && K <= std::abs(vector[ini] - vector[fin]));
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int dim, K;
	std::cin >> dim >> K;

	if (!std::cin)
		return false;

	std::vector<int> vector(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> vector[i];

	if (resolver(vector, 0, dim - 1, K)) {
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}