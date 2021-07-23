#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>

using namespace std;

class Animal{
    public:
    string type;
    string name;
};

class Dog:public Animal{
    public:
    int id;
    float age;
    string breed;
    string color;
    Dog(int id, string name, float age, string breed, string color){
        type="dog";
        this->id=id;
        this->name=name;
        this->age=age;
        this->breed=breed;
        this->color=color;
    }
};

class Cat:public Animal{
    public:
    int id;
    float age;
    string breed;
    string color;
    Cat(int id, string name, float age, string breed, string color){
        type="cat";
        this->id=id;
        this->name=name;
        this->age=age;
        this->breed=breed;
        this->color=color;
    }
};

class adoption{
    private:
    vector<pair<int,pair<string,pair<float,pair<string,string>>>>> dogs;
    vector<pair<int,pair<string,pair<float,pair<string,string>>>>> cats;
    vector<pair<int,pair<string,pair<float,pair<string,string>>>>> a_dogs;
    vector<pair<int,pair<string,pair<float,pair<string,string>>>>> a_cats;
    public:

    void displayAnimals(){
        cout<<setw(20)<<"Dogs available for Adoption"<<endl;
        cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Breed"<<setw(10)<<"Color"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        for(int i=0; i<dogs.size(); i++){
            cout<<dogs[i].first<<setw(10)<<dogs[i].second.first<<setw(10)<<dogs[i].second.second.first<<setw(10)<<dogs[i].second.second.second.first<<setw(10)<<dogs[i].second.second.second.second<<endl;
        }
        cout<<setw(20)<<"Cats available for Adoption"<<endl;
        cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Breed"<<setw(10)<<"Color"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        for(int i=0; i<cats.size(); i++){
            cout<<cats[i].first<<setw(10)<<cats[i].second.first<<setw(10)<<cats[i].second.second.first<<setw(10)<<cats[i].second.second.second.first<<setw(10)<<cats[i].second.second.second.second<<endl;
        }
    }
    void viewAdopted(){
        cout<<setw(20)<<"Dogs adopted from shelter"<<endl;
        cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Breed"<<setw(10)<<"Color"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        for(int i=0; i<a_dogs.size(); i++){
            cout<<a_dogs[i].first<<setw(10)<<a_dogs[i].second.first<<setw(10)<<a_dogs[i].second.second.first<<setw(10)<<a_dogs[i].second.second.second.first<<setw(10)<<a_dogs[i].second.second.second.second<<endl;
        }
        cout<<setw(20)<<"Cats adopted from shelter"<<endl;
        cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Breed"<<setw(10)<<"Color"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        for(int i=0; i<a_cats.size(); i++){
            cout<<a_cats[i].first<<setw(10)<<a_cats[i].second.first<<setw(10)<<a_cats[i].second.second.first<<setw(10)<<a_cats[i].second.second.second.first<<setw(10)<<a_cats[i].second.second.second.second<<endl;
        }
    }
    void adopt(Dog d){
        int index=-1;
        for(int i=0; i<dogs.size(); i++){
            if(d.id==dogs[i].first){
                index=i;
                continue;
            }
        }
        if(index==-1){
                cout<<"Please enter the correct ID or type!"<<endl;
        }
        else{
                a_dogs.push_back({dogs[index].first,{dogs[index].second.first,{dogs[index].second.second.first,{dogs[index].second.second.second.first,dogs[index].second.second.second.second}}}});
                dogs.erase(dogs.begin()+index);
                cout<<"Congratulation on adopting a Dog!!"<<endl;
        }
    }
    void adopt(Cat c){
        int index=-1;
        for(int i=0; i<cats.size(); i++){
            if(c.id==cats[i].first){
                index=i;
                continue;
            }
        }
        if(index==-1){
            cout<<"Please enter the correct ID or type!"<<endl;
        }
        else{
            a_cats.push_back({cats[index].first,{cats[index].second.first,{cats[index].second.second.first,{cats[index].second.second.second.first,cats[index].second.second.second.second}}}});
            cats.erase(dogs.begin()+index);
            cout<<"Congratulation on adopting a Cat!!"<<endl;
        }
    }
    void addAnimal(Dog d){
        if(dogs.size()==0){
            d.id=1;
        }
        else{
            d.id=dogs[dogs.size()-1].first+1;
        }
        dogs.push_back({d.id,{d.name,{d.age,{d.breed,d.color}}}});
        cout<<"Record updated successfully"<<endl;
    }
    void addAnimal(Cat c){
        if(cats.size()==0){
            c.id=1;
        }
        else{
            c.id=cats[cats.size()-1].first+1;
        }
        cats.push_back({c.id,{c.name,{c.age,{c.breed,c.color}}}});
        cout<<"Record updated successfully"<<endl;
    }
};

int main(){
    adoption shelter;
    Dog d2(1,"Alex",4.0,"Pug","White");
    Dog d3(2,"Max",2.5,"Pitbull","Grey");
    Dog d4(3,"Tommy",1.5,"Pomereon","White");
    Dog d5(4,"Lena",6.0,"Husky","Black");
    Cat c2(1,"Kim",3.5,"Ragdoll","White");
    Cat c3(2,"Major",5.5,"Persian","Brown");
    Cat c4(3,"Rea",7.5,"Sphynx","Pink");
    shelter.addAnimal(d2);
    shelter.addAnimal(d3);
    shelter.addAnimal(d4);
    shelter.addAnimal(d5);
    shelter.addAnimal(c2);
    shelter.addAnimal(c3);
    shelter.addAnimal(c4);
    while(1){
        cout<<setw(5)<<"Welcome to the Dog and Cat adoption Center"<<endl<<endl;
        cout<<setw(10)<<"Please Enter yout Choice"<<endl;
        cout<<"*=========================================*"<<endl;
        cout<<"1: View Animals"<<endl;
        cout<<"2: Adopt Dog"<<endl;
        cout<<"3: Adopt Cat"<<endl;
        cout<<"4: Donate Rescued Animal"<<endl;
        cout<<"5: View Adopted Animal"<<endl;
        cout<<"6: Exit Shelter"<<endl;
        int choice;
        int id;
        float age;
        string type, name, breed, color;
        cin>>choice;
        switch(choice){
            case 1:{
                shelter.displayAnimals();
                break;
            }
            case 2:{
                cout<<"Enter Dog Details:"<<endl;
                cout<<"ID: ";
                cin>>id;
                cout<<"Name: ";
                cin>>name;
                cout<<"Age: ";
                cin>>age;
                cout<<"Breed: ";
                cin>>breed;
                cout<<"Color: ";
                cin>>color;
                Dog d1(id,name,age,breed,color);
                shelter.adopt(d1);
                break;
            }
            case 3:{
                cout<<"Enter Cat Details:"<<endl;
                cout<<"ID: ";
                cin>>id;
                cout<<"Name: ";
                cin>>name;
                cout<<"Age: ";
                cin>>age;
                cout<<"Breed: ";
                cin>>breed;
                cout<<"Color: ";
                cin>>color;
                Cat c1(id,name,age,breed,color);
                shelter.adopt(c1);
                break;
            }
            case 4:{
                cout<<"Enter Animal Details:"<<endl;
                cout<<"Type: ";
                cin>>type;
                cout<<"Name:";
                cin>>name;
                cout<<"Age:";
                cin>>age;
                cout<<"Breed: ";
                cin>>breed;
                cout<<"Color: ";
                cin>>color;
                if(type=="dog"|| type=="Dog" || type=="DOG"){
                    Dog d1(0,name,age,breed,color);
                    shelter.addAnimal(d1);
                }
                else{
                    Cat c1(0,name,age,breed,color);
                    shelter.addAnimal(c1);
                }
                break;
            }
            case 5:{
                shelter.viewAdopted();
                break;
            }
            case 6:{
                exit(0);
                break;
            }
            default:{
                cout<<"Please enter valid choice"<<endl;
            }
        }
    }
}