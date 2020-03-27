// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos{
	int coste;
	int superficie;
};


void resolver(int k, int const numObjetos, int const presupuesto, std::vector<tDatos> const &datos,
				int contPresupuesto, int contSuperficie,std::vector<bool> &marked,
				int &superTotal){

	marked[k] = true;
	contPresupuesto += datos[k].coste;
	contSuperficie += datos[k].superficie;
	if (contPresupuesto <= presupuesto) {
		if (k == numObjetos - 1) {
			if (contSuperficie > superTotal)
				superTotal = contSuperficie;
		}
		else {
			resolver(k + 1, numObjetos, presupuesto, datos,
				contPresupuesto, contSuperficie, marked,
				superTotal);
		}

	}
	contPresupuesto -= datos[k].coste;
	contSuperficie -= datos[k].superficie;
	marked[k] = false;

	if (k == numObjetos - 1) {
		if (contSuperficie > superTotal)
			superTotal = contSuperficie;
	}
	else {
		resolver(k + 1, numObjetos, presupuesto, datos,
			contPresupuesto, contSuperficie, marked,
			superTotal);
	}

	}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numObjetos, presupuesto;
	std::cin >> numObjetos >> presupuesto;
	if (!std::cin)
		return false;

	std::vector<tDatos> datos(numObjetos);
	std::vector<bool> marked(numObjetos);
	int aux1, aux2;
	for (int i = 0; i < numObjetos; i++) {
		std::cin >> aux1 >> aux2;
		datos[i] = { aux1,aux2 };
	}
	std::vector<int> sol;
	int superTotal = 0;
	resolver(0, numObjetos, presupuesto, datos,
		0, 0, marked,
		superTotal);
	std::cout << superTotal <<"\n";
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