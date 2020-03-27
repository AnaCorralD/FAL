// Ana Laura Corral Descargue
// TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector<std::vector<int>>;

struct info{	
	int tareas; //entrada
	int alumnos; //entrada
	int maxTereasPorAlumno; //entrada
	tmatriz& matriz; //entrada de la matriz de satisfacion
};

struct marcas{
	int actual; //valor actual de satifacion
	std::vector<int> &contTareas; //vector para contar el numero de tareas que lleva actualmente
	std::vector<int> &contAlumnos; // vector para contar el numero de tareas que lleva un almuno actualmente
};

bool esValida(const int &k, const marcas& n, const info& info, const int i) {

	if (n.contAlumnos[i] > info.maxTereasPorAlumno) return false;
	if (k % 2 == 1) {
		if (n.contTareas[k] == n.contTareas[k - 1]) return false;
	}

	return true;
}

void resolver(const int& k, marcas& n, const info& info, int& max) {

	for (int i = 0; i < info.alumnos; i++) {
		n.actual += info.matriz[i][k/2];
		n.contAlumnos[i]++;
		n.contTareas[k] = i;

		if (esValida(k,n,info,i)) {
			if (k == n.contTareas.size() - 1) {
				if (n.actual > max)
					max = n.actual;
			}
			else {
				resolver(k+1,n,info, max);
			}
		}

		n.actual -= info.matriz[i][k/2];
		n.contAlumnos[i]--;
		//n.contTareas[k] = -1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int tareas, alumnos, maxTereasPorAlumno;
	std::cin >> tareas >> alumnos >> maxTereasPorAlumno;

	if (tareas == 0 && alumnos == 0 && maxTereasPorAlumno == 0)
		return false;

	tmatriz matriz(alumnos, std::vector<int>(tareas));
	for (int i = 0; i < alumnos; i++) {
		for (int j = 0; j < tareas; j++)
			std::cin >> matriz[i][j];
	}
	info info{ tareas,alumnos,maxTereasPorAlumno, matriz};
	
	std::vector<int> contTareas(tareas * 2);
	std::vector<int> contAlumnos(alumnos);
	
	int max = 0;
	marcas inicio{0,contTareas,contAlumnos};
	resolver(0,inicio, info, max);
	std::cout << max << "\n";

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