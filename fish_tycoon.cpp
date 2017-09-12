#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class FishbreadSeller
{
private:
	int Flour; //밀가루
	int Redbeen; //팥
	int Cream; //크림
	int Redbread; //팥 붕어빵
	int Creambread; //슈크림 붕어빵
	int Silver; //실버
	int Gold; //황금
	int numOfRedbread; //붕어빵 개수
	int numOfCreambread; //슈크림붕어빵 개수
	int myMoney; //나의 돈
	int GoldFish;//황금잉어빵
	int SilverFish;//실버붕어빵
	int SilverCream; //실버슈크림붕어빵

public:
	FishbreadSeller() //초기자본
	{
		int baseFlour=0;
		int baseRedbeen=0;
		int baseCream=0;
		int baseSilver=0;
		int baseGold=0;
		int basePrice=500;
		int basemyMoney=10000;
		int baseRednum=0;
		int baseCreamnum=0;
		int baseGoldFish=0;
		int baseSilverFish=0;
		int baseSilverCream=0;

		Flour=baseFlour;
		Redbeen=baseRedbeen;
		Cream=baseCream;
		Silver=baseSilver;
		Gold=baseGold;
		myMoney=basemyMoney;
		numOfRedbread=baseRednum;
		numOfCreambread=baseCreamnum;
		GoldFish=baseGoldFish;
		SilverFish=baseSilverFish;
		SilverCream=baseSilverCream;
	}


	int MakeRedbread(int num)
	{
		if(Flour<num*10 || Redbeen<num*5)
		{
			cout<<"밀가루 혹은 팥이 부족합니다."<<endl;
			return 0;
		}

		numOfRedbread+=num;
		Flour-=num*10;
		Redbeen-=num*5;
		cout<<"팥붕어빵 "<<numOfRedbread<<"개를 만들었습니다."<<endl;
		return numOfRedbread;
	}

	int MakeCreambread(int num)
	{
		if(Flour<num*10 || Cream<num*5)
		{
			cout<<"밀가루 혹은 크림이 부족합니다."<<endl;
			return 0;
		}
		
		numOfCreambread+=num;
		Flour-=num*10;
		Cream-=num*5;
		cout<<"슈크림붕어빵 "<<numOfCreambread<<"개를 만들었습니다."<<endl;
		return numOfCreambread;
	}

	int SellRedbread(int num)
	{
		if(numOfRedbread<num)
		{
			cout<<"보유한 팥 붕어빵 개수보다 많이 입력하셨습니다.";
			return 0;
		}
		numOfRedbread-=num;
		myMoney+=num*500;
		cout<<"남은 팥 붕어빵 ="<<numOfRedbread<<endl;
		return numOfRedbread;
	}

	int SellCreambread(int num)
	{
		if(numOfCreambread<num)
		{
			cout<<"보유한 슈크림붕어빵 개수보다 많이 입력하셨습니다.";
			return 0;
		}
		numOfCreambread-=num;
		myMoney+=num*500;
		cout<<"남은 슈크림붕어빵= "<<numOfCreambread<<endl;
		return numOfCreambread;
	}

	void BuyFlour(int num)
	{
		myMoney-=num*10;
		Flour+=num;
		cout<<"현재 밀가루 개수= "<<Flour<<endl;
	}

	int BuyRedbeen(int num)
	{
		myMoney-=num*5;
		Redbeen+=num;
		cout<<"현재 보유한 팥 개수="<<Redbeen<<endl;
		return Redbeen;
	}

	int BuyCream(int num)
	{
		myMoney-=num*5;
		Cream+=num;
		cout<<"현재 보유한 크림 개수= "<<Cream<<endl;
		return Cream;
	}
	
	int BuySilver(int num)
	{
		myMoney-=num*500;
		Silver+=num;
		cout<<"현재 보유한 실버 개수= "<<Silver<<endl;
		return Silver;
	}

	int BuyGold(int num)
	{
		myMoney-=num*1000;
		Gold+=num;
		cout<<"현재 보유한 황금 개수= "<<Gold<<endl;
		return Gold;
	}

	void Sum_silver_Redbread(void)
	{
		if(numOfRedbread<3 || Silver<0)
		{
			cout<<"팥 붕어빵 혹은 실버가 부족합니다.";
		}
		
		if(numOfRedbread>=3 && Silver>=1)
		{
			if(rand()%100+1<=60)
			{
				cout<<"실버붕어빵 만들기에 ☆성공☆했습니다!!"<<endl;
				numOfRedbread-=3;
				Silver-=1;
				SilverFish+=1;
			}
			else
				cout<<"조합에 실패하셨습니다."<<endl;
		}
	}

	void Sum_silver_Creambread(void)
	{
		if(numOfCreambread<3 || Silver<0)
		{
			cout<<"크림붕어빵 혹은 실버가 부족합니다.";
		}
		
		if(numOfCreambread>=3 && Silver>=1)
		{
			if(rand()%100+1<=60)
			{
				cout<<"실버슈크림붕어빵 만들기에 ☆성공☆했습니다!!"<<endl;
				numOfCreambread-=3;
				Silver-=1;
				SilverCream+=1;
			}
			else
				cout<<"조합에 실패하셨습니다."<<endl;
		}
	}

	void Sum_Gold_Fish(void)
	{
		if(SilverFish<3 || SilverCream<3 || Gold<0)
		{
			cout<<"실버붕어빵 혹은 실버크림붕어빵 혹은 골드가 부족합니다.";
		}
		
		if(SilverFish>=3 && SilverCream>=3)
		{

			if(rand()%100+1<=30)
			{
				cout<<"★황금★잉어빵 만들기에 ☆성공☆했습니다!!"<<endl;
				SilverFish-=3;
				SilverCream-=3;
				GoldFish+=1;
			}
			else
				cout<<"조합에 실패하셨습니다."<<endl;
		}
	}

	/**아래부터 보여지는 함수들**/


	void ShowSellerinfo(void)
	{
		cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"*****현재 정보*****"<<endl;
		cout<<"현재 밀가루의 양= "<<Flour<<endl;
		cout<<"현재 팥의 양= "<<Redbeen<<endl;
		cout<<"현재 크림의 양= "<<Cream<<endl;
		cout<<"현재 실버 개수= "<<Silver<<endl;
		cout<<"현재 황금 개수= "<<Gold<<endl;
		cout<<"********************"<<endl;
		cout<<"만든 붕어빵 개수= "<<numOfRedbread<<endl;
		cout<<"만든 슈크림붕어빵 개수= "<<numOfCreambread<<endl; 
		cout<<"만든 실버붕어빵 개수= "<<SilverFish<<endl;
		cout<<"만든 실버슈크림붕어빵 개수= "<<SilverCream<<endl;
		cout<<"만든 ★황금★잉어빵 개수= "<<GoldFish<<endl;
		cout<<endl;
		cout<<"현재 나의 돈="<<myMoney<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
		getchar();
	}

	void ShowSumlist(void)
	{
		cout<<"━━━━━━━━━조합List━━━━━━━━━━"<<endl;
		cout<<"실버붕어빵=붕어빵3+실버1"<<endl;
		cout<<"실버슈크림붕어빵=슈크림붕어빵3+실버1"<<endl;
		cout<<"황금잉어빵=실버붕어빵3+실버슈크림붕어빵3+황금1"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		getchar();
	}

	void ShowPro(void)
	{
		cout<<"━━━━━━조합 확률━━━━━━━━━"<<endl;
		cout<<"실버붕어빵= 60%"<<endl;
		cout<<"실버슈크림 붕어빵=60%"<<endl;
		cout<<"황금잉어빵=30%"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━"<<endl;
		getchar();
	}

	void ShowMenu(void)
	{
		system("cls");
		cout<<"***************붕어빵 만들기게임ver1.1//by KSM*******************"<<endl;
		cout<<"━━━━━━━━━메 뉴━━━━━━━━━━"<<endl;
		cout<<"1.팥붕어빵 만들기"<<endl;
		cout<<"2.슈크림붕어빵 만들기"<<endl;
		cout<<"3.붕어빵 팔기"<<endl;
		cout<<"4.재료상점"<<endl;
		cout<<"5.붕어빵 조합하기"<<endl;
		cout<<"6.현재 나의 정보"<<endl;
		cout<<"7.조합재료 보기"<<endl;
		cout<<"8.조합확률 보기"<<endl;
		cout<<"9.종료하기"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	}

	void makeredBread(void)
	{
		int make1;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"팥붕어빵을 만드는 데 필요한 재료는"<<endl;
		cout<<"밀가루10, 팥5 입니다."<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<endl;
		cout<<"몇개를 만드시겠습니까?";
		cin>>make1;
		MakeRedbread(make1);
		getchar();

		getchar();
	}
	void makecreamBread(void)
	{
		int make2;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"슈크림붕어빵을 만드는 데 필요한 재료는"<<endl;
		cout<<"밀가루10, 크림5 입니다."<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<endl;
		cout<<"몇개를 만드시겠습니까?";
		cin>>make2;
		MakeCreambread(make2);
		getchar();

		getchar();
	}

	void Store(void)
	{
		int buy;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"재료상점에 오신걸 환영합니다."<<endl;
		cout<<"1.밀가루"<<endl;
		cout<<"2.팥"<<endl;
		cout<<"3.크림"<<endl;
		cout<<"4.실버"<<endl;
		cout<<"5.황금"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"무엇을 사시겠습니까?";
		cin>>buy;

		switch(buy)
		{
		case 1:
			int flour;
			cout<<"밀가루는 1개당 10원입니다. 몇개나 사시겠습니까?";
			cin>>flour;
			BuyFlour(flour);
			break;
		case 2:
			int Redbeen;
			cout<<"팥은 1개당 5원입니다. 몇개나 사시겠습니까?";
			cin>>Redbeen;
			BuyRedbeen(Redbeen);
			break;
		case 3:
			int Cream;
			cout<<"크림은 1개당 5원입니다. 몇개나 사시겠습니까?";
			cin>>Cream;
			BuyCream(Cream);
			break;
		case 4:
			int Silver;
			cout<<"실버는 1개당 500원입니다. 몇개나 사시겠습니까?";
			cin>>Silver;
			BuySilver(Silver);
			break;
		case 5:
			int Gold;
			cout<<"황금은 1개당 1000원입니다. 몇개나 사시겠습니까?";
			cin>>Gold;
			BuyGold(Gold);
			break;
		}
		if(buy<0 || buy>5)
		{
			cout<<"잘못된 입력입니다. 다시입력하세요"<<endl;
		}
		getchar();
		
		getchar();
	}

	void ShowSell(void)
	{
		int sell;
		int sellredbread;
		int sellcreambread;
		cout<<"━━━━━━━━━팔기━━━━━━━━━━━"<<endl;
		cout<<"1.팥 붕어빵(500원)"<<endl;
		cout<<"2.슈크림 붕어빵(500원)"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"무엇을 파시겠습니까?";
		cin>>sell;

		if(sell==1)
		{
			cout<<"몇개나 파시겠습니까?";
			cin>>sellredbread;
			SellRedbread(sellredbread);
		}
		else if(sell==2)
		{
			cout<<"몇개나 파시겠습니까?";
			cin>>sellcreambread;
			SellCreambread(sellcreambread);
		}
		else
		{
			cout<<"잘못된 입력입니다."<<endl;
		}
		getchar();

		getchar();
	}

	void Sum(void)
	{
		int choice;
		cout<<"━━━━━━━━조 합 하 기━━━━━━━━━━"<<endl;
		cout<<"1.실버 붕어빵"<<endl;
		cout<<"2.실버 슈크림붕어빵"<<endl;
		cout<<"3.★황금★ 잉어빵"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"무엇을 조합하시겠습니까?";
		cin>>choice;

		switch(choice)
		{
		case 1:
			Sum_silver_Redbread();
			break;
		case 2:
			Sum_silver_Creambread();
			break;
		case 3:
			Sum_Gold_Fish();
			break;
		}

		if(choice<0 || choice>3)
		{
			cout<<"잘못된 선택입니다."<<endl;
		}
		getchar();

		getchar();
	}

};

int main(void)
{
	FishbreadSeller sell;
	srand((unsigned)time(NULL));
	enum{MAKE1=1,MAKE2,SELL,STORE,SUM,SHOW,SHOWSUM,SHOWPRO,QUIT};
	int inputnum=0;

	while(1)
	{
		sell.ShowMenu();
		cout<<"번호를 선택하시오>>";
		cin>>inputnum;
		while(getchar()!='\n');
		
		
		switch(inputnum)
		{
		case MAKE1:
			sell.makeredBread();
			break;
		case MAKE2:
			sell.makecreamBread();
			break;
		case SELL:
			sell.ShowSell();
			break;
		case STORE:
			sell.Store();
			break;
		case SUM:
			sell.Sum();
			break;
		case SHOW:
			sell.ShowSellerinfo();
			break;
		case SHOWSUM:
			sell.ShowSumlist();
			break;
		case SHOWPRO:
			sell.ShowPro();
			break;
		}

		if(inputnum==QUIT)
		{
			cout<<"황금잉어빵은 만들었는지요? 수고하셨습니다"<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}
