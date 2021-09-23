
#include <iostream>
#include "rectangle.cpp"
#include "rectangle.h"
#include "Figure.h"
#include "tvector.h"
//#include "rhombus.cpp"
//#include "trapezoid.h"
int main()
{
    bool cont_exist=false;
    int choice=1;
    rectangle temp_rec;
    TVector container;
    while(choice!=7){
        std::cout<<"Menu\n1.Create container\n2.Add to container\n3.Delete from container\n4.Resize\n5.Pop back\n6.Print container\n7.Exit\nYour choice:";
        std::cin>>choice;
        switch(choice){

        case 1:{
            int length;
            char c;
            std::cout<<"Insert ammount of container el-nt:";
            std::cin>>length;
            container.resize(length);
            std::cout<<"Do you want to fill container?\ty or n:";
            std::cin>>c;
            if(c=='y')
                std::cin>>container;
            cont_exist=true;
            continue;
        }

        case 2:{
            if(cont_exist) {
                std::cout<<"Insert new rectangle coords:";
                std::cin>>temp_rec;
                std::cout<<temp_rec;
                container.push_back(temp_rec);
            }
            else std::cout<<"Create container first\n"<<std::endl;
            continue;
        }

        case 3:{
            if(cont_exist){
                int deletindex;
                std::cout<<"Choose number of element, which has to be deleted (if the entered number is greater than the number,container will be deleted):";
                std::cin>>deletindex;
                if(deletindex>0 && deletindex<=container.size()){
                    container.erase(deletindex);
                }
                else {
                    container.clear();
                }
            }
            else std::cout<<"Create container first\n"<<std::endl;
            continue;
        }

        case 4:{
            if(cont_exist){
                int length;
                std::cout<<"Insert new ammount of container el-nt:";
                std::cin>>length;
                container.resize(length);
            }
            else std::cout<<"Create container first\n"<<std::endl;
            continue;
        }

        case 5:{
            if(cont_exist)
                std::cout<<"Last "<< container.pop_back()<<std::endl;
            else std::cout<<"Create container first\n"<<std::endl;
        }

        case 6:{
            if(cont_exist)
                std::cout<<container;
            else std::cout<<"Create container first\n"<<std::endl;
            continue;
        }
        case 7:{
            continue;
        }
        default:{
            std::cout<<"Wrong answer\n"<<std::endl;
            continue;
        }
        }
    }
    return 0;
}
