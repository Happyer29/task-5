// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>


//баг с union
struct business
{
	std::string name;
	bool isProfitTaken = false;
	struct
	{
		int turnover; // monthly turnover
		int costs; // costs
	} money;
	struct
	{
		int postcode;
	} location;

	union
	{
		struct
		{
			int profit;
		} take_profit;

		struct
		{
			int profit;
		} not_take_profit;
	};
	business()
	{
		name = "";
		money.turnover = 0;
		take_profit.profit = 0;
		not_take_profit.profit = 0;
		money.costs = 0;

		location.postcode = 0;
	}
};




void insert_business(business* arr, const int* size, int i = 0)
{
	for (; i < *size; i++)
	{
		std::cout << "Iteration #" << i << std::endl;
		std::cout << "Business name: "; std::cin >> arr[i].name;
		std::cout << "Turnover: "; std::cin >> arr[i].money.turnover;
		std::cout << "Costs: "; std::cin >> arr[i].money.costs; std::cout << std::endl;

		char tmp = 'N';
		std::cout << "Take profit? Y/N: "; std::cin >> tmp;
		if(tmp == 'Y')
		{
			arr[i].isProfitTaken = true;
			arr[i].take_profit.profit = arr[i].money.turnover - arr[i].money.costs;
		}

		std::cout << "Postcode: "; std::cin >> arr[i].location.postcode; std::cout << std::endl;
	}

	//std::cout << arr[0].name << std::endl;
	
}


void show_db(business* arr, const int* size)
{
	for (int i = 0; i < *size; i++)
	{
		std::cout << "Iteration #" << i << std::endl;
		std::cout << "Business name: " << arr[i].name << std::endl;
		std::cout << "Turnover: " << arr[i].money.turnover << std::endl;
		std::cout << "Costs: " << arr[i].money.costs << std::endl;
		if(arr[i].isProfitTaken) std::cout << "Profit: " << arr[i].take_profit.profit << std::endl;
		else std::cout << "Profit not taken " << std::endl;		
		std::cout << "Postcode: " << arr[i].location.postcode << std::endl << std::endl;
	}
}

void add_business(business* arr, int* size)
{
	*size += 1;
	insert_business(arr, size, *size - 1);
}


int main()
{
	business* arr = new business[30];

	int arr_size = 2, * parr_size = &arr_size;

	insert_business(arr, parr_size);

	std::cout << "0 - finish, 1 - show base, 2 - add new, 3 - delete" << std::endl;
    std::cout << std::endl;
    int a = -1;
    while (a != 0)
    {
        std::cout << "What you want to do?" << std::endl;
        std::cin >> a;
        std::cout << std::endl;
        switch (a)
        {
        case 0: {
            break;
        }
        case 1: {
			show_db(arr, parr_size);
            break;
        }
        case 2: {
            add_business(arr, parr_size);
            break;
        }
        case 3: {
            //int num;
            //std::cout << "Enter the number:  ";
            //std::cin >> num;
            //size--;
            //deleteCharacter(arr, num, size);
            //std::cout << std::endl;
            //break;
        }
        default:
            break;
        }
    }
	
	//std::cin >> arr.staff_count;

	//std::cout << arr.staff_count;

	delete[] arr;
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
