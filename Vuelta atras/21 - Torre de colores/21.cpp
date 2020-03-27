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

	std::vector<int> &contPiezas;

	std::vector<std::string>& sol;
	int &cont;
};
bool esSolucionValida(struct nodo& n) {
	
	if (n.contPiezas[1] <= (n.contPiezas[0] + n.contPiezas[2])) return false;
	return true;
}

bool esSolucion(struct nodo& n, const int num) {
	return n.k == num - 1;
}
bool esValida(struct nodo& n, const int azul, const int verde,const int rojo) {
	if (n.sol[n.k] == "verde" && n.sol[n.k - 1] == "verde") return false;
	if (n.contPiezas[2] > n.contPiezas[0]) return false;
	
	if (n.contPiezas[0] > azul) return false;
	if (n.contPiezas[1] > rojo) return false;
	if (n.contPiezas[2] > verde) return false;

	return true;
}
void resolver(struct nodo& n, const int num, const int azul, const int verde, const int rojo) {

	for (int i = 0; i < n.colores.size(); i++) {
		n.sol[n.k] = n.colores[i];
		n.contPiezas[i]++;
		if (esValida(n,azul,verde,rojo)) {
			if (esSolucion(n, num)) {
				if (esSolucionValida(n)) {
					n.cont++;
					for (auto c : n.sol)
						std::cout << c << " ";
					std::cout << "\n";
				}
			}
			else {
				nodo siguiente{ n.k + 1, n.colores,n.contPiezas,n.sol,n.cont };
				resolver(siguiente, num,azul,verde,rojo);
			}
		}
		n.sol[n.k] = "";
		n.contPiezas[i]--;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num, azul, verde, rojo;
	std::cin >> num >> azul >> rojo >> verde;
	if (num == 0 && azul == 0 && verde == 0 && rojo==0)
		return false;

	std::vector<std::string> colores(3);
	colores[0] = "azul";
	colores[1] = "rojo";
	colores[2] = "verde";

	std::vector<int>contPiezas(3);

	std::vector<std::string>sol(num, "");
	
	if (num == 1) std::cout << "rojo\n";
	else {
		int cont = 0;
		sol[0] = "rojo";
		contPiezas[1]++;
		nodo inicio{ 1,colores,contPiezas,sol,cont };
		resolver(inicio, num,azul,verde,rojo);
		if (cont == 0) std::cout << "SIN SOLUCION\n";
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