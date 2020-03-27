// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct datos{
	std::string nombre;
	int numCanicas;
};


// función que resuelve el problema
datos resolver(const std::vector<datos> &v, int ini, int fin) {

	if (ini + 1 == fin) {
		if (v[ini].numCanicas < v[fin].numCanicas) {
			int mitad = v[ini].numCanicas / 2;
			return { v[fin].nombre, v[fin].numCanicas + mitad };
		}
		else {
			int mitad = v[fin].numCanicas / 2;
			return { v[ini].nombre, v[ini].numCanicas + mitad };
		}
	}
	else {
		int m = (ini + fin) / 2;

		datos iz = resolver(v, ini, m);
		datos der = resolver(v, m + 1, fin);

		if (iz.numCanicas < der.numCanicas) {
			int mitad = iz.numCanicas / 2;
			return { der.nombre, der.numCanicas + mitad };
		}
		else {
			int mitad = der.numCanicas / 2;
			return { iz.nombre, iz.numCanicas + mitad };
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int dim;
	std::cin >> dim;

	if (!std::cin)
		return false;

	std::vector<datos> v;
	std::string nino = "";
	int num = 0;
	for (int i = 0; i < dim; i++) {
		std::cin >> nino >> num;
		v.push_back({ nino,num });
	}

	datos sol = resolver(v,0,dim-1);

	std::cout << sol.nombre << " " << sol.numCanicas << "\n";


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