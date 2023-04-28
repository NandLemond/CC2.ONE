#include <iostream>

using namespace std;

class ArrayDynamic{
   private:
    int *data;
    int size;
    int valor;
    int posicion;
   
   public:

      ArrayDynamic(){
         this->size=0;
         this->data = new int[0];
      }
      ArrayDynamic(int arr[],int size){
         this->size= size;
         this->data= new int [size];
         for(int i=0;i<size;i++)
            data[i]=arr[i];
         }
      ArrayDynamic(const ArrayDynamic &o){
         this->size = o.size;
         this->data = new int [o.size];
         for(int i=0; i< size;i++)
            data[i]=o.data[i];
      }

      int getSize() const {
         return size;
      }
      void mostrarData(){
         for(int i=0;i<size;i++)
         cout<<data[i]<<" ";
         cout<<endl;
      }
     

      void Insert(int val,int pos){
         size++;
         int *array_aux=new int[size];
         for(int i=0;i<size;i++)
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


         int *array_auxi=new int[size];
         for(int i=0;i<size;i++)
            array_auxi[i]=data[i];
         this->data=array_auxi;   
      }

      void Push_Back(int val){
         size++;
          int *array_auxi=new int[size];
         for(int i=0;i<size;i++)
            array_auxi[i]=data[i];
         array_auxi[size-1]=val;
         
         this->data=array_auxi;  
         
      }

    
    

      ~ArrayDynamic(){
         delete[] data;
        
      }




};

int main(){
  int arr[] = {1,2,4,5,6};
  ArrayDynamic ins1(arr,5);
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
 
 

  //ins1.mostrar(ins1.getData());
  //ArrayDynamic *ins2=&ins1;
  //ins2->Insert(5,4);

  
 
}
