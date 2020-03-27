// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct tDatos {
	std::string nombre;
	int altura;
	int piso;
};
std::vector<std::string> resolver(std::vector<tDatos> const& edificios) {
	int i = edificios.size() - 1;
	int max = edificios[edificios.size() - 1].altura;
	std::vector<std::string> sol;
	if (i == edificios.size() - 1) {
		if (edificios[i].piso != -1) {
			sol.push_back(edificios[i].nombre);
		}
	}
	i--;
	while (i >= 0) {
		if (edificios[i].piso > max)
			sol.push_back(edificios[i].nombre);
		
		if (edificios[i].altura > max)
			max = edificios[i].altura;
		i--;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	tDatos datos;
	int dim;
	std::cin >> dim;

	if (dim == 0)
		return false;
	std::vector<tDatos> edificios(dim);

	std::string aux1;
	int aux2, aux3;
	for (int i = 0; i < dim; i++) {
		std::cin >> aux1 >> aux2 >> aux3;
		edificios[i] = { aux1,aux2,aux3 };
	}
	std::vector<std::string> sol;
	sol = resolver(edificios);

	if (sol.size() > 0) {
		std::cout << sol.size() << "\n";
		std::cout << sol[0];
		for (int i = 1; i < sol.size(); i++) {
			std::cout << " " << sol[i];
		}
		std::cout << "\n";
	}
	else
		std::cout << "Ninguno\n";

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