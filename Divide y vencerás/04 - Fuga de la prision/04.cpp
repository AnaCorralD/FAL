// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	 Coste: O(log n)
  		T(n) = {
			c si n=0 		
 			T(n/2) + c 	En cualquier otro caso.
  		}
*/
// función que resuelve el problema
char resolver(std::vector<char> const &v, int ini, int fin, char const letraIni, char const letraFin) {


	if (ini >= (int)v.size()) return letraFin;

	int m = (ini + fin) / 2;
	if (ini > fin) return v[ini] - 1;
	
	else {
		if (v[m] - letraIni == m) //hacia la derecha
			return resolver(v, m + 1, fin, letraIni, letraFin);
		else return resolver(v, ini, m - 1, letraIni, letraFin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char ini, fin;
	std::cin >> ini >> fin;

	std::vector <char> v;

	char letra;
	for (int i = 0; i < fin - ini; i++) {
		std::cin >> letra;
		v.push_back(letra);
	}
		
	std::cout << resolver(v, 0, v.size() - 1, ini, fin) << "\n";


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}