#include<iostream>
using namespace std;

class shape
{
   protected:
   double value1,value2;
   public:
  void get_data(double x,double y)
   {
       value1=x;
       value2=y;
   }
   virtual int display_area()
   {
   }
};

class triangle:public shape
{
   public:
  /* triangle()
   {
      value1=0;
      value2=0;
   }*/
   int display_area()
   {
      cout<<"The area of triangle is: "<<.5*value1*value2<<endl;
   }
};

class rectangle:public shape
{
   public:
  /* rectangle()
   {
       value1=0;
       value2=0;
   }*/
   int display_area()
   {
      cout<<"The area of rectangle is: "<<value1*value2<<endl;
   }
};

int main()
{
   int choice;
   double a,b;
   shape *ob;
   cout<<"Enter your choice:\n1.Rectangle\n2.Triangle\n";
   cin>>choice;

    if(choice==1){
       cout<<"Enter the sides of the rectangle: ";
              cin>>a>>b;
               ob=new rectangle;
             ob->get_data(a,b);
              ob->display_area();
            }
      else{ cout<<"Enter the base and height of the triangle: ";
              cin>>a>>b;
              ob=new triangle;
             ob->get_data(a,b);
              ob->display_area();

        }

   return 0;
}
