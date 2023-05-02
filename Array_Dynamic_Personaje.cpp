#include <iostream>
using namespace std;


class Personaje{
    private:
     string nombre;
     int edad;
    public:
    Personaje();
    void setDatos(string,int);
    string getNombre();
    int getEdad();
    void setNombre(string nombre){
      this->nombre = nombre;}
    void setEdad(int edad){
      this->edad = edad;}
      
      
    

};
//constructo de la clase Personaje --------------------------------
 Personaje::Personaje(){
    this->nombre = " ";
    this->edad = 0;
}
//set para resivir y guardar atributos de la clase Personaje --------------------------------
void Personaje::setDatos(string nombre,int edad){
      this->nombre= nombre;
      this->edad= edad;
}
//get nombre --------------------------------
string Personaje::getNombre(){
  return nombre;
}
//get edad --------------------------------
int Personaje::getEdad(){
  return edad;
}

//**

class Array{
  private:
  Personaje *arreglo;
  int size;
  int edad_A;
  string nom_A;
  
  public:
  Array(){
    this->arreglo=new Personaje[1];
    this->size=0;
  }

  Array( int size){
    this->size=size;
    this->arreglo=new Personaje[size];
  }


  void AgregarDatos_I(){
    for(int i=0;i<size;i++){
      cout<<"nombre y edad: ";cin>>nom_A>>edad_A;
      arreglo[i].setDatos(nom_A,edad_A);
      

      }

  }

  void Insert(int pos){
    size++;
    Personaje *array_aux=new Personaje[size];
    for(int i=0;i<size-1;i++){
      array_aux[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad());
       ;}
         delete[]arreglo;
    for(int i = size-1;i>pos;i--){
            array_aux[i].setDatos(array_aux[i-1].getNombre(),array_aux[i-1].getEdad());}
    cout<<"nombre y edad : ";cin>>nom_A>>edad_A;
    array_aux[pos].setDatos(nom_A,edad_A);
    this->arreglo=array_aux;
  
  }
  
  void remove(int pos){
    size--;
    for(int i=pos;i<size;i++)
      arreglo[i].setDatos(arreglo[i+1].getNombre(),arreglo[i+1].getEdad());


    Personaje *array_aux=new Personaje[size];
    
         for(int i=0;i<size;i++)
            array_aux[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad());
            delete[] arreglo; 
         arreglo=array_aux; 
         
      }
  void Push_Back(){
         size++;
          Personaje *array_auxi=new Personaje[size];
         for(int i=0;i<size-1;i++)
            array_auxi[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad());
         delete[] arreglo;
         cout<<"nombre y edad : ";cin>>nom_A>>edad_A;    
         array_auxi[size-1].setDatos(nom_A,edad_A);
         
         arreglo=array_auxi;  
         
      }

  void mostrar(){
    //cout<<tam<<endl;2
    for(int i=0;i<size;i++){
        cout<<"posicion: "<<i<<endl;
    cout<<"nombre: "<<arreglo[i].getNombre()<<"; edad: " <<arreglo[i].getEdad()<<endl<<endl;

  }
  }

  ~Array(){
    delete []arreglo;
  }

};

int main(){
  int cant,pos;
  cout<<"¿cuantos Personajes desea agregar ? : ";cin>>cant;
  Array p1(cant);
  cout<<"----Agregando Personaje --->>>"<<endl;
  p1.AgregarDatos_I();
  cout<<endl;
  cout<<"-- datos de los Personajes: --"<<endl;
  p1.mostrar();
  //cout<<"¿en que posición se va insertar el personaje?";cin>>pos;
  cout<<"-- --------------------------- --"<<endl;
   cout<<"---- > INTERCAMBIO < ----"<<endl;
  cout<<" Posición para intercambiar : "<<endl;cin>>pos; 
  p1.Insert(pos);
 
  cout<<"-- datos de los Personajes: --"<<endl;
  p1.mostrar();
  cout<<"-- --------------------------- --"<<endl;

  cout<<"---- > REMOVER < ---- "<<endl;
  cout<<" Posición para remover : "<<endl;cin>>pos;
  p1.remove(pos);
  cout<<"-- datos de los Personajes: --"<<endl; 
  p1.mostrar();
  cout<<"-- --------------------------- --"<<endl;

  cout<<"---- > PUSH BACK < ----"<<endl;
  p1.Push_Back();
  cout<<"-- datos de los Personajes: --"<<endl;
  p1.mostrar();
  cout<<"-- --------------------------- --"<<endl;

}

