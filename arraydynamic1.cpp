#include <iostream>

using namespace std;

template<typename T>

class ArrayDynamic{
   private:
    T *data,valor;
    int size,posicion;
   public:

      ArrayDynamic(){
         this->size=0;
         this->data = new T[0];
      }
      ArrayDynamic(T arr[],int size){
         this->size= size;
         this->data= new T [size];
         for(int i=0;i<size;i++)
            data[i]=arr[i];
         }
     

      int getSize() const {
         return size;
      }
      void mostrarData(){
         for(int i=0;i<size;i++)
         cout<<data[i]<<" ";
         cout<<endl;
      }
     

      void Insert(T val,int pos){
         size++;
         T *array_aux=new T[size];
         for(int i=0;i<size-1;i++)
            array_aux[i]=data[i];
         delete[]data;   
         for(int i = size-1;i>=pos;i--){
            array_aux[i]=array_aux[i-1];}
         
         
         array_aux[pos]=val; 
        this->data=array_aux;
      


      }

      void Remove(int pos){
         size--;
         for(int i=pos;i<size;i++)
            data[i]=data[i+1];


         T *array_auxi=new T[size];
         for(int i=0;i<size;i++)
            array_auxi[i]=data[i];
            delete[] data; 
         this->data=array_auxi; 
         
      }

      void Push_Back(T val){
         size++;
          T *array_auxi=new T[size];
         for(int i=0;i<size-1;i++)
            array_auxi[i]=data[i];
         delete[] data;    
        array_auxi[size-1]=val;
         
         this->data=array_auxi;  
         
      }

    
    

      ~ArrayDynamic(){
         delete[] data;
        
      }




};



int main(){

//probando con char
 /* 
  char arr[] = {'a','b','c','d','e'};
  ArrayDynamic<char> ins1(arr,5);
  //cout<<ins1.getSize()<<endl;
  cout<<"array inicial"<<endl;
  ins1.mostrarData();
  ins1.Insert('X',2);
  //cout<<"\n";
  ins1.Insert('Y',6);
  //ins1.Remove(2);

  //ins1.Push_Back(7);
  cout<<"array final"<<endl;
  ins1.mostrarData();
*/
/* ---probando con elementos de tipo float ---
  
  float arr[] = {1.5,1.3,4.5,5.2,6};
  ArrayDynamic<float> ins1(arr,5);
  //cout<<ins1.getSize()<<endl;
  cout<<"array inicial"<<endl;
  ins1.mostrarData();
  ins1.Insert(3,2);
  //cout<<"\n";
ins1.Insert(7,6);
  ins1.Remove(2);

  //ins1.Push_Back(7);
  cout<<"array final"<<endl;
  ins1.mostrarData();
 */
 
/*
 string arr[] = {"Luis","Jose","Paul","Ana","Lulu"};
  ArrayDynamic<string> ins1(arr,5);
  //cout<<ins1.getSize()<<endl;
  cout<<"--- array inicial---"<<endl;
  ins1.mostrarData();
  ins1.Insert("Carol",2);
  //cout<<"\n";
  ins1.Insert("Maria",6);
  //ins1.Remove(2);

  ins1.Push_Back("Fernando");
  cout<<endl;
  cout<<"--- array final --- "<<endl;
  ins1.mostrarData();
  */

// elementos del tipo int 
 int arr[] = {1,2,3,4,5};
  ArrayDynamic<int> ins1(arr,5);
  //cout<<ins1.getSize()<<endl;
  cout<<"--- array inicial---"<<endl;
  ins1.mostrarData();
  ins1.Insert(3,2);
  //cout<<"\n";
  ins1.Insert(5,6);
  //ins1.Remove(2);

  ins1.Push_Back(6);
  cout<<endl;
  cout<<"--- array final --- "<<endl;
  ins1.mostrarData();
  
 
}