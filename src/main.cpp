#include "../include/dni_t.hpp"
#include "../include/nodo_t.hpp"
#include "../include/arbol_t.hpp"
#include <iomanip>
using namespace std;

int main (void) {

    cout << endl;
    cout << "___|PRÁCTICA 6: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADOS|___" << endl;
    cout << "___|	      Implementación de un ABB 	        |___" << endl;
    
    ABB_t<dni_t> arbol_;
    int opcion;
    int opcion2;
    int aux;
    
    do {
        cout << "PULSE 1 PARA ACCEDER AL MENÚ" << endl;
        cin >> aux;
        
        if (aux == 1) {
            cout << endl;
            cout << "1. Modo Demostración" << endl;
	        cout << "2. Modo Estadística" << endl;
	        cout << "0. Salir" << endl;
	        cout << endl;
	        cout << ">>> Introduzca una opción: ";
	        cin >> opcion;
	        cout << endl;
	        
	        switch(opcion) {
            
                case 1: do {
        					cout << "Bienvenido al Modo Demostración" << endl;
        					cout << "1. Insertar CLAVE" << endl;
						    cout << "2. Eliminar CLAVE" << endl;
						    cout << "0. Salir" << endl;
						    cout << endl;
						    cout << ">>> Introduzca una opción: ";
						    cin >> opcion2;
						    cout << endl;
						    
						    switch(opcion2) {
				                case 1: { dni_t A;
				                    int v;
				                    cout << "Introduzca un valor: " << endl;
				                    cin >> v;
				                    A.set_dni(v);
				                    arbol_.insertar(A);
				                    arbol_.mostrar();
				                    break;
				                }
						        case 2: { dni_t A;
				                    int v;
				                    cout << "Introduzca el valor que desea eliminar: " << endl;
				                    cin >> v;
				                    A.set_dni(v);
				                    arbol_.eliminar(A);
				                    arbol_.mostrar();
				                    break;
						        }
				                case 0: opcion = 0;
				        			break;
				        		default: cout << "¡OPCIÓN INCORRECTA!" << endl << "Introduzca una opción válida." << endl;
				    	    }
			    	} while (opcion2 != 0);
			    	cout << "¡HASTA LUEGO!" << endl;
					return 0;
                    break;
                case 2:	{ cout << "Bienvenido al Modo Estadística" << endl;
                    ABB_t<dni_t> valores_;
                    int N, num_prueba;
                    cout << "Introduzca el tamaño del árbol: " << endl;
                    cin >> N;
                    cout << "Introduzca el número de pruebas: " << endl;
                    cin >> num_prueba;
                    cout <<setw(52)<< "Número de comparaciones" << endl;
                    
                    dni_t* banco = new dni_t[2*N];
                    dni_t DNI;
                    dni_t* aux;
                    aux = DNI.secuencia_demo(2*N);
                    
                    for (int i = 0; i < 2*N; i++) {
                        banco[i] =  aux[i];
                    }
                    for(int i = 0; i < N ; i++) {
                        valores_.insertar(banco[i]);
                    }
                    
                    // Búsqueda //
                    
                    valores_.inicializar_contadores();
            
                    for(int i = 0; i < num_prueba; i++) {
                        int pos = rand()%N;
                        DNI.iniciar_contador();
                        // busqueda uno de los elementos de los primos N elementos del banco de pruebas
                        valores_.buscar(banco[pos]);
                        if(DNI.get_cont() > valores_.cont_max) valores_.cont_max = DNI.get_cont();
    		            if(DNI.get_cont() < valores_.cont_min) valores_.cont_min = DNI.get_cont();
                        valores_.suma = valores_.suma + DNI.get_cont();
                    }
                    float media1 =  valores_.resultado(num_prueba); 
                    cout<<setw(30)<<"Nº Pruebas"<<setw(10)<<"Mínimo"<<setw(10)<<"Medio"<<setw(12)<<"Máximo"<< endl;
                    cout << "Búsqueda" <<setw(18) << num_prueba << setw(10)<< valores_.cont_min << setw(10) << media1 << setw(10) << valores_.cont_max << endl;
                    valores_.podar_arbol();
                    
                    // Inserción //
                    
                    // insertar N primeros elementos en el árbol
                    for(int i = N; i < 2*N ; i++) {
                                valores_.insertar(banco[i]);
                    }
                    //valores_.mostrar();
                
                    valores_.inicializar_contadores();
                    
                    for(int i = 0; i < num_prueba; i++){
                        int pos = (rand()%N)+N;
                        DNI.iniciar_contador();
                        // insertar(buscar) N ultimos elementos en el árbol
                        valores_.buscar(banco[i]);
                        if(DNI.get_cont() > valores_.cont_max) valores_.cont_max = DNI.get_cont();
        		        if(DNI.get_cont() < valores_.cont_min) valores_.cont_min = DNI.get_cont();
                        valores_.suma = valores_.suma + DNI.get_cont();
                    }
                    float media2 =  valores_.resultado(num_prueba);   
            	    cout << "Inserción" <<setw(17) << num_prueba << setw(10)<< valores_.cont_min << setw(10) << media2 << setw(10) << valores_.cont_max << endl;
                }
                case 0: opcion = 0;
        			break;
        		default: cout << "¡OPCIÓN INCORRECTA!" << endl << "Introduzca una opción válida." << endl;
    	    }
	    }
	    else {
	        cout << "¿SEGURO QUE QUIERE SALIR DE LA PRÁCTICA?" << endl;
		    cout << "PULSE 0 PARA SALIR ó 1 PARA VOLVER: ";
		    int aux2 = 0;
		    cin >> aux2;
		    cout << endl;
		    if (aux2 == 0) {
			    cout << "¡HASTA LUEGO!" << endl;
			    return 0;
		    }
	    }
	    
    } while (opcion != 0);
    cout << "¡HASTA LUEGO!" << endl;
	return 0;
   
}