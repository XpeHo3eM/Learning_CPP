#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


// Возможные варианты строений на участке
enum eBuildingsType
{
	GARAGE = 1,		// Гараж
	BARN,			// Сарай
	BATHHOUSE,		// Баня
	COUNT_BUILDING_TYPES = 3
};


// Возможные варианты комнат
enum eRoomsType
{
	BEDROOM = 1,	// Спальня
	KITCHEN,		// Кухня
	CHILDRENS_ROOM,	// Детская
	LIVING_ROOM,	// Гостинная
	BATHROOM,		// Ванная
	COUNT_ROOM_TYPES = 5
};


struct SRoom
{
	eRoomsType type;
	int square = 0;
};


struct SFloor
{
	int ceilingHeight = 0;
	std::vector <SRoom> room;
};


struct SPieceOfLand
{
	std::string uniqueNumber;

	struct SHouse
	{
		bool chimney = false;
		std::vector <SFloor> floor;
	} house;

	struct SGarage
	{
		bool enable = false;
		int square = 0;
	} garage;

	struct SBarn
	{
		bool enable = false;
		int square = 0;
	} barn;

	struct SBathhouse
	{
		bool enable = false;
		int square = 0;
		bool chimney = false;
	} bathhouse;
};


// Заполнение конкретного участка
SPieceOfLand fillPieceOfLand();

// Заполнение этажа
SFloor fillFloor();

// Заполнение дома на конкретном участке
void fillHouse(SPieceOfLand &piece);

// Заполнение гаража на конкретном участке
void fillGarage(SPieceOfLand &piece);

// Заполнение сарая на конкретном участке
void fillBarn(SPieceOfLand &piece);

// Заполнение бани на конкретном участке
void fillBathhouse(SPieceOfLand &piece);

// Принятие ввода площади с подсказкой названия строения
int fillSquare(const std::string &buildingName);

// Проверка вводимого числа на неотрицательные значения
bool isPositiveNumber(std::string &str);

// Ввод числа в строку и преобразование в корретный целочисленный тип
int enterInt();

// Ввод ответа и проверка на корректность ответу (y/n)
char enterYN();

// Задержка до ввода необходимого значения
void wait();

//Итоговый вывод необходимых данных
void outResult(std::vector <SPieceOfLand> &pieceOfLand);


// Количество участков
int totalPieceOfLand;


int main()
{
	std::cout << "Enter total piece of land: ";
	std::cin >> totalPieceOfLand;
	std::vector <SPieceOfLand> piecesOfLand;

	for (int i = 1; i <= totalPieceOfLand; ++i)
	{
		system("cls");
		std::cout << "~~ Fill " << i << " piece of land ~~" << std::endl << std::endl;
		piecesOfLand.push_back(fillPieceOfLand());
	}

	outResult(piecesOfLand);
}


int enterInt()
{
	std::string tmp;
	do
		std::cin >> tmp;
	while (!isPositiveNumber(tmp));
	return (std::stoi(tmp));
}


char enterYN()
{
	char answer;
	do
		std::cin >> answer;
	while (answer != 'y' && answer != 'n');

	return answer;
}


void wait()
{
	std::cout << std::endl << "Enter 0 to continue: ";
	std::string answer;
	do
		std::cin >> answer;
	while (answer != "0");
}


bool isPositiveNumber(std::string& str)
{
	bool error = false;
	for (int i = 0; (i < str.length()) && !error; ++i)
		if (str[i] < '0' || str[i] > '9') return false;

	return true;
}


int fillSquare(const std::string& buildingName)
{
	system("cls");
	std::cout << "Enter square of your " << buildingName << ": ";

	return (enterInt());
}


void fillHouse(SPieceOfLand& piece)
{
	system("cls");
	std::cout << "Does your house have chimney? (y/n): ";
	if (enterYN() == 'y')
		piece.house.chimney = true;

	std::system("cls");
	std::cout << "How many floors on your house? ";
	int floorCount = enterInt();

	for (int i = 1; i <= floorCount; ++i)
	{
		std::system("cls");
		std::cout << "~ Fill " << i << " floor of " << floorCount << " ~" << std::endl;
		piece.house.floor.push_back(fillFloor());
	}
}


SFloor fillFloor()
{
	SFloor floor;
	std::cout << "Enter ceiling height: ";
	floor.ceilingHeight = enterInt();

	std::cout << "Enter count of rooms: ";
	int roomCount = enterInt();
	for (int i = 1; i <= roomCount; ++i)
	{
		system("cls");
		std::cout << "~ Choose one of the types of rooms below for the " << i << " room ~" << std::endl;
		std::cout << BEDROOM << ". Bedroom;" << std::endl;
		std::cout << KITCHEN << ". Kitchen;" << std::endl;
		std::cout << CHILDRENS_ROOM << ". Childrens room;" << std::endl;
		std::cout << LIVING_ROOM << ". Living room;" << std::endl;
		std::cout << BATHROOM << ". Bathroom;" << std::endl;
		int roomType;
		do
			roomType = enterInt();
		while (roomType < 1 || roomType > COUNT_ROOM_TYPES);

		std::cout << "Enter square this room: ";
		SRoom currentRoom;
		currentRoom.square = enterInt();

		switch (roomType)
		{
		case BEDROOM:
			currentRoom.type = BEDROOM; break;
		case KITCHEN:
			currentRoom.type = KITCHEN;	break;
		case CHILDRENS_ROOM:
			currentRoom.type = CHILDRENS_ROOM; break;
		case LIVING_ROOM:
			currentRoom.type = LIVING_ROOM; break;
		case BATHROOM:
			currentRoom.type = BATHROOM; break;
		}
		floor.room.push_back(currentRoom);
	}

	return floor;
}


SPieceOfLand fillPieceOfLand()
{
	SPieceOfLand pieceOfLand;
	std::cout << "Enter unique number of your piece of land: ";
	std::cin >> pieceOfLand.uniqueNumber;

	fillHouse(pieceOfLand);

	bool next = false;
	do
	{
		system("cls");
		std::cout << "Do you have some buildings? (y/n): ";
		
		if (enterYN() == 'y')
		{
			int answer;
			do
			{
				system("cls");
				std::cout << "Choose one of this:" << std::endl;
				std::cout << GARAGE		<< ". Garage;" << std::endl;
				std::cout << BARN		<< ". Barn;" << std::endl;
				std::cout << BATHHOUSE	<< ". Bathhouse." << std::endl;
				std::cout << "0. Exit from this piece of land" << std::endl;
				answer = enterInt();
			} while (answer < 0 || answer > COUNT_BUILDING_TYPES);

			switch (answer)
			{
			case GARAGE: 
				fillGarage(pieceOfLand); break;
			case BARN: 
				fillBarn(pieceOfLand); break;
			case BATHHOUSE: 
				fillBathhouse(pieceOfLand); break;
			case 0: next = true; break;
			}
		}
		else next = true;
	} 
	while (!next);

	return pieceOfLand;
}


void fillGarage(SPieceOfLand &piece)
{
	piece.garage.enable = true;
	piece.garage.square = fillSquare("garage");

	system("cls");

	// При вводе площади равной 0 считаем, что гаража на участке нет
	if (piece.garage.square == 0)
	{
		piece.garage.enable = false;
		std::cout << "~ Garage wasn't added ~" << std::endl;
	}
	else
		std::cout << "~ Square of your garage was added ~" << std::endl;

	wait();
}


void fillBarn(SPieceOfLand &piece)
{
	piece.barn.enable = true;
	piece.barn.square = fillSquare("barn");

	system("cls");

	// При вводе площади равной 0 считаем, что амбара на участке нет
	if (piece.barn.square == 0)
	{
		piece.barn.enable = false;
		std::cout << "~ Barn wasn't added ~" << std::endl;
	}
	else
		std::cout << "~ Square of your barn was added ~" << std::endl;

	wait();
}


void fillBathhouse(SPieceOfLand &piece)
{
	piece.bathhouse.enable = true;
	piece.bathhouse.square = fillSquare("bathhouse");

	system("cls");

	// При вводе площади равной 0 считаем, что гаража на участке нет
	if (piece.bathhouse.square == 0)
	{
		piece.bathhouse.enable = false;
		std::cout << "~ Bathhouse wasn't added ~" << std::endl;
	}
	else
	{
		std::cout << "~ Square of your bathhouse was added ~" << std::endl << std::endl;		
		std::cout << "Does you bathhouse has chimney? (y/n): ";
		if (enterYN() == 'y')
			piece.bathhouse.chimney = true;
	}
		
	wait();
}


void outResult(std::vector <SPieceOfLand>& piecesOfLand)
{
	int totalSquare = 0;
	// Т.к. на каждом участке должен быть хотя бы дом
	int totalBuildings = totalPieceOfLand;
	int totalRooms = 0;
	int totalBedrooms = 0;
	int totalKitchens = 0;
	int totalChildrenRooms = 0;
	int totalLivingRooms = 0;
	int totalBathrooms = 0;


	for (int p = 0; p < totalPieceOfLand; ++p)
	{
		if (piecesOfLand[p].barn.enable)
		{
			totalSquare += piecesOfLand[p].barn.square;
			++totalBuildings;
		}
		if (piecesOfLand[p].bathhouse.enable)
		{
			totalSquare += piecesOfLand[p].bathhouse.square;
			++totalBuildings;
		}
		if (piecesOfLand[p].garage.enable)
		{
			totalSquare += piecesOfLand[p].garage.square;
			++totalBuildings;
		}

		for (int f = 0; f < piecesOfLand[p].house.floor.size(); ++f)
		{
			totalRooms += piecesOfLand[p].house.floor[f].room.size();
			for (int r = 0; r < piecesOfLand[p].house.floor[f].room.size(); ++r)
				switch (piecesOfLand[p].house.floor[f].room[r].type)
				{
				case BEDROOM:
					++totalBedrooms; break;
				case KITCHEN:
					++totalKitchens; break;
				case CHILDRENS_ROOM:
					++totalChildrenRooms; break;
				case LIVING_ROOM:
					++totalLivingRooms; break;
				case BATHROOM:
					++totalBathrooms; break;
				}
		}

	}

	system("cls");
	std::cout << "Total count of buildings is  " << totalBuildings << std::endl;
	std::cout << "Total square of buildings is " << totalSquare << std::endl;
	std::cout << "Total count of rooms is " << totalRooms << std::endl;
	std::cout.width(20);
	std::cout << "bedrooms: " << totalBedrooms << std::endl;
	std::cout.width(20);
	std::cout << "kitchens: " << totalKitchens << std::endl;
	std::cout.width(20);
	std::cout << "children rooms: " << totalChildrenRooms << std::endl;
	std::cout.width(20);
	std::cout << "living rooms: " << totalLivingRooms << std::endl;
	std::cout.width(20);
	std::cout << "bathrooms: " << totalBathrooms << std::endl;
}