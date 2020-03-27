// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct nodo {
	int k;
	const std::vector<std::string>& colores;


	std::vector<std::string>& sol;
};

bool esSolucion(struct nodo& n, const int num) {
	return n.k == num - 1;
}
bool esValida(struct nodo& n) {
	if (n.sol[n.k] == "verde" && n.sol[n.k - 1] == "verde") return false;

	return true;
}
void resolver(struct nodo& n, const int num) {

	for (int i = 0; i < n.colores.size(); i++) {
		n.sol[n.k] = n.colores[i];
		if (esValida(n)) {
			if (esSolucion(n, num)) {
				for (auto c : n.sol)
					std::cout << c << " ";
				std::cout << "\n";
			}
			else {
				nodo siguiente{ n.k + 1, n.colores,n.sol };
				resolver(siguiente, num);
			}
		}
		n.sol[n.k] = "";
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num;
	std::cin >> num;
	if (num == 0)
		return false;

	std::vector<std::string> colores(3);
	colores[0] = "azul";
	colores[1] = "rojo";
	colores[2] = "verde";

	std::vector<std::string>sol(num, "");
	if (num == 1) std::cout << "rojo\n";
	else {
		sol[0] = "rojo";
		nodo inicio{ 1,colores,sol };
		resolver(inicio, num);
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