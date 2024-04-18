#include <iostream>
#include <string>
#include <random>

void FindTheTreasure(int row, int col);

int main()
{
    FindTheTreasure(3, 5);
}

void FindTheTreasure(int row, int col)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 5);
    int treasureMap[5][5];
    int first_rand = dist(rd);
    int second_rand = dist(rd);
    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            treasureMap[row][col] = 0;
        }
    }
    treasureMap[first_rand][second_rand] = 1;
    while (found != true)
    {
        if (treasureMap[row][col] == 1)
        {
            std::cout << "Ati gasit comoara! Felicitari!" << std::endl;
            found = true;
            return;
        }
        else
        {
            std::cout << "Incercati din nou!\n" << "Comoara era la: [" << first_rand << "] [" << second_rand << "] " << std::endl;
            std::cout << "Introduceti rand: " << std::endl;
            std::cin >> row;
            std::cout << "Introduceti coloana: " << std::endl;
            std::cin >> col;
            if ((row < 0 || row > 5) || (col < 0 || col > 5))
            {
                std::cout << "DON'T TRY TRICKING THE SYSTEM" << std::endl;
                std::cout << "Introduceti rand: " << std::endl;
                std::cin >> row;
                std::cout << "Introduceti coloana: " << std::endl;
                std::cin >> col;
            }
            FindTheTreasure(row, col);
            break;
        }
    }
}