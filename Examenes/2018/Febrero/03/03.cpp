// Ana Laura Corral Descargue
// TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(int const k, int const i, int const punMin, tMatriz const& punPapelActor, int const presupuesto, int const preActual,
			 std::vector<bool> marked){

	if (punPapelActor[k][i] < punMin) return false;
	if (preActual > presupuesto) return false;
	if (marked[i]) return false;
	return true;
}

void resolver(int k, int const numPapales, int const numActores, int const presupuesto, int const punMin,
			  std::vector<int> const& costePorActor, tMatriz const& punPapelActor,
			  int &preActual, int punActual, std::vector<bool> &marked, std::vector<int> auxSol,
			  int &punMax, std::vector<int>&sol, int &pre) {

	for (int i = 0; i < numActores; i++) {
		preActual += costePorActor[i];
		punActual += punPapelActor[k][i];
		if (esValida(k,i,punMin,punPapelActor,presupuesto,preActual, marked)) {
			auxSol[k] = i;
			marked[i] = true;
			if (k == numPapales - 1) { //esSolucion
				if (punActual > punMax && preActual < pre) {
					punMax = punActual;
					pre = preActual;
					sol = auxSol;
				}
			}
			else {
				resolver(k + 1, numPapales, numActores, presupuesto, punMin,
					costePorActor, punPapelActor,
					preActual, punActual,marked,auxSol,
					punMax, sol, pre);
			}
			marked[i] = false;
		}
		preActual -= costePorActor[i];
		punActual -= punPapelActor[k][i];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int numPapales, numActores, presupuesto, punMin;
	std::cin >> numPapales >> numActores >> presupuesto >> punMin;

	if (numPapales == 0 && numActores == 0 && presupuesto == 0 && punMin==0)
		return false;

	/*Lectura*/

	std::vector<int> costePorActor(numActores);
	for (int i = 0; i < numActores; i++)
		std::cin >> costePorActor[i];

	tMatriz punPapelActor(numPapales, std::vector<int>(numActores));
	for (int i = 0; i < numPapales; i++) {
		for (int j = 0; j < numActores; j++)
			std::cin >> punPapelActor[i][j];
	}

	/*---------*/
	int punMax = 0;

	for (int i = 0; i < numPapales; i++) //diagonal
		punMax += punPapelActor[i][i];
	
	int preActual = 0;
	int pre = 1000000000;
	std::vector<bool>marked(numActores);
	std::vector<int> sol(numPapales);
	std::vector<int> auxSol(numPapales);
	resolver(0, numPapales, numActores, presupuesto, punMin, costePorActor, punPapelActor, preActual, 0, marked, auxSol,punMax, sol, pre);

	std::cout << punMax << " " << pre << "\n";
	for (int i = 0; i < numPapales; i++)
		std::cout << i << " " << sol[i] << "\n";

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