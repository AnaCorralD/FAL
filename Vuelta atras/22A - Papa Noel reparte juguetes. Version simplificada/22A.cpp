// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

/*
	k -> son los ninos
	i -> los tipo de regalo
*/

struct info{
	int juguetes;
	int ninos;
};

struct nodo{
	int k; 
	const struct info& info;
	const std::vector<std::string> &tipoJugues;

	int &cont; // me indica si ha llegado a una solucion valida
	std::vector<int>& contJuguestes; // en cada posicion de k tiene que haber tiene que tener al final 2 regalos
	std::vector<std::string>& sol; // voy guardando los tipo de juguete para comprobar los indicadores
	std::vector<int>& pos; // guerdo el indice del juguete correspondiente
};

bool esSolucionValida(struct nodo& n) {
	
	int ok = true;
	int i = 0;
	while (i < n.contJuguestes.size() && ok) {
		if (n.contJuguestes[i] != 2) ok = false;
		i++;
	}
	return ok;
}

bool esSolucion(struct nodo& n) {
	return n.k == n.sol.size()-1;
}

bool esValida(struct nodo& n) {
	if (n.contJuguestes[n.k/2] > 2) return false;
	if (n.k % 2 == 1) {
		if (n.sol[n.k] < n.sol[n.k - 1]) return false;
		if (n.sol[n.k] == n.sol[n.k - 1]) return false;
		else return true;
	}
	return true;
}

// función que resuelve el problema
void resolver(struct nodo &n) {

	for (int i = 0; i < n.info.juguetes; i++) {
		n.sol[n.k] = n.tipoJugues[i];
		n.contJuguestes[n.k/2]++;
		n.pos[n.k] = i;
		if (esValida(n)) {
			if (esSolucion(n)) {
				if (esSolucionValida(n)) {
					n.cont++;
					for (auto i : n.pos)
						std::cout << i << " ";
					std::cout << "\n";
				}
			}
			else {
				nodo siguiente{ n.k + 1, n.info,n.tipoJugues,n.cont, n.contJuguestes, n.sol, n.pos };
				resolver(siguiente);
			}
		}
		n.sol[n.k] = -1;
		n.contJuguestes[n.k/2]--;
		n.pos[n.k] = -1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	info info;
	std::cin >> info.juguetes >> info.ninos;
	if (!std::cin)
		return false;

	std::vector<std::string> tipoJugues(info.juguetes);
	for (int i = 0; i < tipoJugues.size(); i++)
		std::cin >> tipoJugues[i];

	std::vector<int> contJuguetes(info.ninos);
	std::vector<std::string> sol(info.ninos*2, "");
	std::vector<int> pos(info.ninos * 2, -1);
	int cont = 0;
	nodo inicio{ 0,info,tipoJugues,cont,contJuguetes,sol,pos };
	resolver(inicio);

	if (cont == 0) std::cout << "SIN SOLUCION\n";

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