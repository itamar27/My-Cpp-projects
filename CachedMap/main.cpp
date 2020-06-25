//#include "cached_map.h"

#include    "cached_map2.h"
#include "employee2.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    ifstream in("emps.bin", ios::binary|ios::in);
    in.seekg(0);
    int count = 10;
    employee e;
    CachedMap<string, employee> mp;
    long long int cnt = 1;
    int i = 10;
   while( i-- > 0)//!in.eof())              
   {   
       try
       {    
            std:: cout<< cnt++<< ". ";
            e.load(in);
            mp.add(e.get_id() , e);
            
            
       }
       catch(...)
       {
           std::cout<< "Error!" << std::endl;;
       }
        
        mp.get(e.get_id())->printEmployee(); 
        
   }      

   mp.erase(e.get_id());
 
     if(!(mp.get("462502120600352")))
        std::cout <<"error handling here!" <<std::endl;
    else
    {
        std::cout << "462502120600352 ---> exist in map!" << std::endl;
    }
    
 

 

    in.close();

    


    // CachedMap<int, string> cm;
    // std::string x = "Nice day";
    // int y = 6;

    // cm.add(y,x);
    // cm.add(1,"Nice day two");
    // try
    // {
    //     cm.erase(y);
    //     cm.erase(y);
    // }
    // catch(CachedMap<int, string>::ObjectNotExistException)
    // {
    //     cout<< "Object not exist!" << endl;
    // }

    // if(!cm.get(y))
    //     std::cout<<"Y is not existed any more in cached map"<<endl;
    // else
    // {
    //     std::cout<<*cm.get(1)<<endl;
    // }
    
    

    //  try
    //  {
    //     cm.add('a', 1);
    //     cm.add('b', 5);
    //     cm.add('c', 4);
    //     cm.add('t',y);
    //     cm.add('a', 20);
    //  }
    //  catch(CachedMap<int, int>::ObjectNotExistException)
    // {         
    //     cout<<"Obj not exist!"<<endl;
    // }
    // catch(CachedMap<int, int>::DuplicateKeyExecption)
    // {         
    //     cout<<"Duplicate key!"<<endl;
    // }

    // cout<<cm.getValue('b')<<endl;
    // cout<<cm.getValue('c')<<endl;
    // cout<<cm.getValue('t')<<endl;
}