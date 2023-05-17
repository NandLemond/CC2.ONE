#include <iostream>
using namespace std;


template <typename T>

class Personaje{
    private:
     string nombre;
     int edad;
     T masa_corporal;
    public:
    Personaje(){
      this->nombre = " ";
      this->edad =  0;
      this->masa_corporal = 0;
    }
    void setDatos(string nombre,int edad,T masa_corporal){
      this->nombre= nombre;
      this->edad= edad;
      this->masa_corporal=masa_corporal;
      }
    string getNombre(){
      return nombre;
    }
    int getEdad(){
      return edad;
    }
    T getMasa(){
      return masa_corporal;
    }

    void setNombre(string nombre){
      this->nombre = nombre;}

    void setEdad(int edad){
      this->edad = edad;}

    void setMasa_corp(T masa_corporal){
      this->masa_corporal=masa_corporal;}
      
      
    

};




template <typename T>

class Array{
  private:
  Personaje<T> *arreglo;
  int size;
  int edad_A;
  string nom_A;
  T masa_cop;
  
  public:
    Array() {
        this->arreglo = nullptr;
        this->size = 0;
    }

  Array( int size){
    this->size=size;
    this->arreglo=new Personaje<T>[size];
  }


  void AgregarDatos_I(){
    for(int i=0;i<size;i++){
      cout<<"nombre , edad y masa corporal : ";cin>>nom_A>>edad_A>>masa_cop;
      arreglo[i].setDatos(nom_A,edad_A,masa_cop);
      

      }

  }

  void Insert(int pos){
    size++;
    Personaje<T> *array_aux=new Personaje<T>[size];
    for(int i=0;i<size-1;i++){
      array_aux[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad(),arreglo[i].getMasa());
       ;}
         delete[]arreglo;
    for(int i = size-1;i>pos;i--){
            array_aux[i].setDatos(array_aux[i-1].getNombre(),array_aux[i-1].getEdad(),array_aux[i-1].getMasa());}
    cout<<"nombre , edad y masa corporal : ";cin>>nom_A>>edad_A>>masa_cop;
    array_aux[pos].setDatos(nom_A,edad_A,masa_cop);
    this->arreglo=array_aux;
  
  }
  
  void remove(int pos){
    size--;
    for(int i=pos;i<size;i++)
      arreglo[i].setDatos(arreglo[i+1].getNombre(),arreglo[i+1].getEdad(),arreglo[i+1].getMasa());


    Personaje<T> *array_aux=new Personaje<T>[size];
    
         for(int i=0;i<size;i++)
            array_aux[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad(),arreglo[i].getMasa());
            delete[] arreglo; 
         arreglo=array_aux; 
         
      }
  void Push_Back(){
         size++;
          Personaje<T> *array_auxi=new Personaje<T>[size];
         for(int i=0;i<size-1;i++){
            array_auxi[i].setDatos(arreglo[i].getNombre(),arreglo[i].getEdad(),arreglo[i].getMasa());
         }
         delete[] arreglo;
         cout<<"nombre ,edad y masa corporal : ";cin>>nom_A>>edad_A>>masa_cop;    
         array_auxi[size-1].setDatos(nom_A,edad_A,masa_cop);
         
         arreglo=array_auxi;  
         
      }

  void mostrar(){
    //cout<<tam<<endl;2
    for(int i=0;i<size;i++){
        cout<<"posicion: "<<i<<endl;
    cout<<"nombre: "<<arreglo[i].getNombre()<<"; edad: " <<arreglo[i].getEdad()<<" ; masa corporal: "<<arreglo[i].getMasa()<<endl<<endl;

  }
  }

  ~Array(){
    delete []arreglo;
  }

};

int main(){
  
  int cant,pos;
  cout<<"¿cuantos Personajes desea agregar ? : ";cin>>cant;
  Array<int> p1(cant);


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

