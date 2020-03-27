// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct info{
	int dim;
	int numColores;
	int consumo;
};

struct nodo{
	int k;
	const struct info& info;
	const std::vector<int> consumoPorBombilla;

	int consumo;
	std::vector<int>&contadorColores;
	std::vector<int>& sol;
	int& cont;
};

bool esValida(struct nodo& n) {
	if (n.consumo > n.info.consumo) return false;

	if (n.k > 2) {
		if (n.sol[n.k] == n.sol[n.k - 1] && n.sol[n.k - 1] == n.sol[n.k - 2]) return false;
	}

	int max = 0;
	for (int i = 0; i < n.contadorColores.size(); i++)
		max += n.contadorColores[i];

	int valor = 0;
	int demas = 0;
	for (int i = 0; i < n.contadorColores.size(); i++) {
		valor = n.contadorColores[i];
		demas = max - valor;
		if (valor - demas > 1) 
			return false;
	}

	return true;
}

bool esSolucion(struct nodo& n) {
	return n.k == n.sol.size() - 1;
}
// función que resuelve el problema
void resolver(struct nodo &n) {


	for (int i = 0; i < n.info.numColores; i++) {
		n.consumo += n.consumoPorBombilla[i];
		n.contadorColores[i]++;
		n.sol[n.k] = i;

		if (esValida(n)) {
			if (esSolucion(n)) {
				n.cont++;
			}
			else {
				nodo siguiente{ n.k + 1,n.info,n.consumoPorBombilla,n.consumo,n.contadorColores, n.sol,n.cont };
				resolver(siguiente);
			}
		}
		n.consumo -= n.consumoPorBombilla[i];
		n.contadorColores[i]--;
		n.sol[n.k] = -1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	info info;
	std::cin >> info.dim >> info.numColores >> info.consumo;
	if (!std::cin)
		return false;

	std::vector<int> consumoPorBombilla(info.numColores);

	for (int i = 0; i < consumoPorBombilla.size(); i++)
		std::cin >> consumoPorBombilla[i];

	std::vector<int> contadorColores(info.numColores);
	std::vector<int> sol(info.dim, -1);
	int cont = 0;

	nodo inicio{ 0,info,consumoPorBombilla,0,contadorColores,sol,cont };
	resolver(inicio);

	std::cout << cont << "\n";


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