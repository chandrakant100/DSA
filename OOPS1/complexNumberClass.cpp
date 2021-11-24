#include <iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    private:
    	int real;
    	int imaginary;
    public:
    	ComplexNumbers(){};
    	ComplexNumbers(int real,int imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }
    	void plus(ComplexNumbers obj)
        {
            this->real += obj.real;
            this->imaginary += obj.imaginary;
        }
    	void multiply(ComplexNumbers obj1)
        {
            int val = this->real;
            this->real = (this->real) * obj1.real + (-1)*(this->imaginary)*obj1.imaginary;
            this->imaginary = (val)*obj1.imaginary + (this->imaginary)*obj1.real;
        }
    	void print()
        {
            if (imaginary < 0)
            {
                cout<<real<<" - i"<<imaginary*(-1);
            }
            else
            {
                cout<<real<<" + i"<<imaginary;
            }
        }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}