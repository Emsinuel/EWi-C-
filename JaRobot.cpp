#include <iostream>

class Robot {
    private:
        double distance = 10;
        double degrees = 90;
        int edges = 4;
        void move()
        {
            std::cout << "Robot moved " << distance << " meters.\n";
        }
        void turn() 
        {
            std::cout << "Robot turned " << degrees << " degrees.\n";
        }
    public:
        void figure()
        {
            for(int i = 0; i < edges; i++)
            {
                move();
                turn();
            }
        }
};

class MobileRobot : public Robot {
    private:
        double distance = 0;
        double degrees = 0;
        int edges = 0;
    public:
        void details(int number)
        {
            if(number == 1)
            {
                std::cout<<"Enter the number of polygon edges: \n";
                std::cin>>edges;
                std::cout<<"Enter edge length: \n";
                std::cin>>distance;
                if(edges < 3)
                {
                    std::cout<<"The regular figure must have at least 3 edges!!!";
                }
                else
                {
                    degrees = (edges - 2) * 180 / edges;
                }
            }
            if(number == 2)
            {
                std::cout<<"Enter the number edges: \n";
                std::cin>>edges;
                std::cout<<"Enter edge length: \n";
                std::cin>>distance;
                std::cout<<"Enter degrees: \n";
                std::cin>>degrees;
            }
            if(number == 3)
            {
                std::cout<<"Enter the number edges: \n";
                std::cin>>edges;
            }
        }
        void move() 
        {
            std::cout << "Mobile robot moved " << distance << " meters.\n";
        }
        void turn() 
        {
            std::cout << "Mobile robot turned " << degrees << " degrees.\n";
        }
        void figure(int number)
        {
            if(number == 1 || number == 2)
            {
                for(int i = 0; i < edges; i++)
                {
                    move();
                    turn();
                }
            }
            if(number == 3)
            {
                for(int i = 0; i < edges; i++)
                {
                    std::cout<<"Enter edge length: \n";
                    std::cin>>distance;
                    std::cout<<"Enter degrees: \n";
                    std::cin>>degrees;
                    move();
                    turn();
                }
            }
        }
};

int select_shape();

int main() {
    //Starting the default robot from the Robot class:
    //Robot square;
    //square.figure();
    //Shape selection:
    MobileRobot MR1;
    int choice = select_shape();
    MR1.details(choice);
    MR1.figure(choice);

}

int select_shape()
{
    int number = 0;
    std::cout<<"If you want to get a regular polygon, type: 1\n";
    std::cout<<"If you want to create a figure whose sides are of the same length, angles of the same spacing and you have a fixed number of edges, type: 2\n";
    std::cout<<"If you want to get a other figure, type: 3\n";
    std::cin>>number;
    return number;
}