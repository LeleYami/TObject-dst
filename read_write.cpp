#include "../../include/TFile.h"
#include "Sclass.h"

void write_it(){
    //write f1
    std::cout<<"write f1..."<<std::endl;
    TFile *f1=TFile::Open("test1.root","recreate");

    Sclass* obj1=new Sclass();
    obj1->SetX(32.1);
    obj1->SetY(1.23);
    obj1->Write("anObject1");

    f1->Close();
    std::cout<<"write it done."<<std::endl;

    //write f2
    std::cout<<"write f2..."<<std::endl;
    TFile *f2=TFile::Open("test2.root","recreate");

    Sclass* obj2=new Sclass();
    obj2->SetX(45.6);
    obj2->SetY(6.45);
    obj2->Write("anObject2");

    f2->Close();
    std::cout<<"write it done."<<std::endl;

    //write f3
    std::cout<<"write f3..."<<std::endl;
    TFile *f3=TFile::Open("test3.root","recreate");

    Sclass* obj3=new Sclass();
    obj3->SetX(78.9);
    obj3->SetY(9.87);
    obj3->Write("anObject3");

    f3->Close();
    std::cout<<"write it done."<<std::endl;
}

void read_it(){
   //read f1
   std::cout<<"read f1..."<<std::endl;
   TFile* f1=TFile::Open("test1.root");
   if(!f1){
      std::cerr<<"Can't open file test1.root."<<std::endl;
      return;
   }

   Sclass* obj1=dynamic_cast<Sclass*>(f1->Get("anObject1"));
   if(!obj1){
      std::cerr<<"Can't find the object anObject1."<<std::endl;
      return;
   }
   obj1->Print();
   std::cout<<"read it done."<<std::endl;
   
   //read f2
   std::cout<<"read f2..."<<std::endl;
   TFile* f2=TFile::Open("test2.root");
   if(!f2){
      std::cerr<<"Can't open file test2.root."<<std::endl;
      return;
   }

   Sclass* obj2=dynamic_cast<Sclass*>(f2->Get("anObject2"));
   if(!obj2){
      std::cerr<<"Can't find the object anObject2."<<std::endl;
      return;
   }
   obj2->Print();
   std::cout<<"read it done."<<std::endl;
   
   //read f3
   std::cout<<"read f3..."<<std::endl;
   TFile* f3=TFile::Open("test3.root");
   if(!f3){
      std::cerr<<"Can't open file test3.root."<<std::endl;
      return;
   }

   Sclass* obj3=dynamic_cast<Sclass*>(f3->Get("anObject3"));
   if(!obj3){
      std::cerr<<"Can't find the object anObject3."<<std::endl;
      return;
   }
   obj3->Print();
   std::cout<<"read it done."<<std::endl;
}

void read_write(){
    write_it();
    read_it();
}

int main(){
    read_write();
}
