/* grafos tortuga */
/* David Ruiz García*/

#include <iostream>
#define TAM 20
using namespace std;

int mat[TAM][TAM];
int pluma = 0;
int dir = 0;
int posicion[]={0,0};
/*Prototipos*/

void inicializar_piso(){
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      mat[i][j] = 0;
    }
  }
}

void gderecha(){
  if(dir==0)
    dir=3;
  else
    dir--;
  return;
}

void gizquierda(){
  if(dir==3)
    dir=0;
  else
    dir++;
  return;
}

int avanza(int n){
  switch (dir) {
    case 0:
      for(int i=0; i<n; i++){
        posicion[1]++;
        if(!(posicion[1]<TAM)){
          posicion[1]--;
          return -1;
        }
        if(pluma)
          mat[posicion[0]][posicion[1]] = 1;
      }
    break;
    case 1:
      for(int i=0; i<n; i++){
        posicion[0]--;
        if(!(posicion[0]>=0) ){
          posicion[0]++;
          return -1;
        }
        if(pluma)
          mat[posicion[0]][posicion[1]] = 1;
      }
    break;
    case 2:
      for(int i=0; i<n; i++){
        posicion[1]--;
        if(!(posicion[1]>=0)){
          posicion[1]++;
          return -1;
        }
        if(pluma)
          mat[posicion[0]][posicion[1]] = 1;
      }
    break;
    case 3:
    for(int i=0; i<n; i++){
      posicion[0]++;
      if(!(posicion[1]<TAM)){
        posicion[0]--;
        return -1;
      }
      if(pluma)
        mat[posicion[0]][posicion[1]] = 1;
    }
    break;
    default:
      break;
  }
  return 0;
}

void imprimir(){
  cout << "Tamaño: " << TAM << " Posicion: " << posicion[0] << "," << posicion[1] << " Pluma: ";
  if(pluma)
    cout << "arriba" << endl << endl;
  else
    cout << "abajo" << endl << endl;
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      if(mat[i][j])
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
}

int ejecutar(int cmd){
  switch(cmd){
    case 1:
      pluma = 0;
      cout<< endl<< "Pluma arriba" << endl;
    break;
    case 2:
      pluma = 1;
      cout<< endl<< "Pluma abajo" << endl;
    break;
    case 3:
      gderecha();
      cout << endl << "Giro a la derecha" <<endl;
    break;
    case 4:
      gizquierda();
      cout << endl << "Giro a la izquierda" << endl;
    break;
    case 5:
      cout << "espacios: ";
      int aux;
      cin >> aux;
      if(!avanza(aux)){
        cout << endl << "Avanzando " << aux << " espacios."<< endl;
      }
      else{
        cout << endl << "No hay espacio suficiente para realizar el movimiento." << endl;
        return 1;
      }
      break;
    case 6:
      imprimir();
      break;
    case 9:
      cout << endl << "Adios..." << endl;
      break;
    default:
      return -1;
      break;
  }
  return 0;
}

int main(){
  inicializar_piso();
  cout << "Graficos tortuga" << endl << endl;
  int cmd;
  do{
    cout << "$: ";
    cin >> cmd;
    if(ejecutar(cmd) == -1){
      cout << "comando no admitido" << endl;
      cmd = -1;
    }
  }while(cmd != 9);
  return 0;
}
