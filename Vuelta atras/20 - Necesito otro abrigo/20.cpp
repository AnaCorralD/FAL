// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
	k -> numero de dias
	i -> abrigos
*/
struct info {
	int dias;
	int numAbrigos;
};
struct nodo {
	int k;
	const std::vector<int> &estimacion;
	const std::vector<int> &soportarMaximoAbrigo;
	const struct info& info;

	std::vector<int> &marked;

	std::vector<int> &sol;
	int& cont;
};

bool esValida(struct nodo& n, int i) {

	if (n.estimacion[n.k] > n.soportarMaximoAbrigo[i]) return false;
	if (n.k > 0 && n.sol[n.k] == n.sol[n.k - 1])return false;
	if (n.marked[i] > n.k / 3 + 2) return false;
	return true;
}

bool esSolucion(struct nodo& n, int i) {
	return n.k == n.info.dias - 1;

}
bool esSolucionValida(struct nodo& n) {
	if (n.sol[0] == n.sol[n.k]) return false;
	
	return true;
}
// función que resuelve el problema
void resolver(struct nodo &n) {

	for (int i = 0; i < n.info.numAbrigos; i++) {
		n.sol[n.k] = i;
		n.marked[i]++;
		if (esValida(n, i)) {
			if (esSolucion(n, i)) {
				if (esSolucionValida(n)) {
					n.cont++;
				}
			}
			else {
				nodo siguiente{ n.k + 1, n.estimacion,n.soportarMaximoAbrigo, n.info, n.marked,n.sol, n.cont };
				resolver(siguiente);
			}
		}
		n.marked[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	info i;
	std::cin >> i.dias >> i.numAbrigos;
	if (i.dias == 0 && i.numAbrigos == 0)
		return false;

	std::vector<int> estimacion(i.dias);

	for (int i = 0; i < estimacion.size(); i++)
		std::cin >> estimacion[i];

	std::vector<int> soportarMaximoAbrigo(i.numAbrigos);
	for (int i = 0; i < soportarMaximoAbrigo.size(); i++)
		std::cin >> soportarMaximoAbrigo[i];

	std::vector<int> sol(i.dias);
	std::vector<int> marked(i.numAbrigos);

	int cont = 0;
	nodo inicio{ 0,estimacion ,soportarMaximoAbrigo,i,marked,sol,cont };
	resolver(inicio);

	if (cont > 0) std::cout << cont << "\n";
	else std::cout << "Lo puedes comprar\n";
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