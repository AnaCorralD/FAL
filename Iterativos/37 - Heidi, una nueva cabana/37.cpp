// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos{
	int longMax;
	std::vector<int> pos;
};

// función que resuelve el problema
tDatos resolver(std::vector<int> const &numeros, int const num) {
	tDatos datos{};
	int i = numeros.size() - 1;
	int auxMax = numeros[i];
	i--;
	int cont = 1;
	datos.longMax = 0;
	while (i >= 0) {
		if (auxMax < numeros[i]) {
			auxMax = numeros[i];
			cont = 1;
		}
		else if (auxMax == numeros[i]) {
			cont++;
			if (cont == num) {
				datos.pos.push_back(i + cont - 1);
			}
			if (cont > datos.longMax&& cont >= num)
				datos.longMax = cont;
		}
		else 
			cont = 0;
		i--;
	}

	return datos;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int dim, num;
	std::cin >> dim >> num;
	if (!std::cin)
		return false;

	std::vector<int> numeros(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> numeros[i];

	tDatos sol = resolver(numeros,num);

	std::cout << sol.longMax << " " << sol.pos.size();

	for (int i = 0; i < sol.pos.size(); i++) {
		std::cout << " " << sol.pos[i];
	}
	std::cout << "\n";
	


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