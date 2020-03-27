// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct datos{
	bool presentado;
	int ronda;
};

// función que resuelve el problema
datos resolver(const std::vector<std::string> &v, int ini, int fin, const int numRondas, int &actual ) {

	
	if (ini + 1 == fin){
		actual = 1;
		if (v[ini] != "NP" && v[fin] != "NP") return { true,1 }; // dos jugadores
		else if (v[ini] != "NP" || v[fin] != "NP") return { true, 0 }; //un jugadore
		else return { false, 0 };
	}
	else {
		int m = (ini + fin) / 2;


		datos iz = resolver(v, ini, m, numRondas, actual);
		datos der = resolver(v, m + 1, fin, numRondas, actual);

		
		if (iz.presentado && der.presentado && actual < numRondas) { // dos jugadores
			actual++;
			return { true, iz.ronda + der.ronda + 1 };
		}
		else if (iz.presentado || der.presentado) { // un jugador
			actual++;
			return { true, iz.ronda + der.ronda};
		}
		else { // ningun jugador
			actual++;
			return { false, iz.ronda + der.ronda };
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int dim, numRondas;
	std::cin >> dim;

	if (!std::cin)
		return false;

	std::cin >> numRondas;

	std::vector<std::string> v(dim);

	std::string leyendo;
	for (int i = 0; i < dim; i++) {
		std::cin >> leyendo;
		v[i] = leyendo;
	}

	int actual = 0;
	datos sol = resolver(v, 0, dim - 1, numRondas, actual);
	std::cout << sol.ronda  << "\n";

	// escribir sol


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