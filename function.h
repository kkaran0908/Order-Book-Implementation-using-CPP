#include<iostream>
#include<string>
#include<queue>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;


struct OrderBookNode {
    
public:
    int orderId;
    float orderPriceLevel;
    int orderSize;
    OrderBookNode(int orderId,float orderPriceLevel, int orderSize)
    : orderPriceLevel(orderPriceLevel), orderSize(orderSize), orderId(orderId) {}
};

struct ComparePriceSell {
    bool operator()(OrderBookNode const& p1, OrderBookNode const& p2)
    {
        return p1.orderPriceLevel > p2.orderPriceLevel;
    }
};

struct ComparePriceBuy {
    bool operator()(OrderBookNode const& p1, OrderBookNode const& p2)
    {
        return p1.orderPriceLevel < p2.orderPriceLevel;
    }
};


class function1
{
    priority_queue<OrderBookNode, vector<OrderBookNode>, ComparePriceSell> orderBookSell;
    priority_queue<OrderBookNode, vector<OrderBookNode>, ComparePriceBuy> orderBookBuy;
    priority_queue<OrderBookNode, vector<OrderBookNode>, ComparePriceSell> tempOrderBookSell;
    priority_queue<OrderBookNode, vector<OrderBookNode>, ComparePriceBuy> tempOrderBookBuy;
public:
    void addOrderForSell(int,float,int);
    void tempAddOrderForSell(int, float, int);
    void printOrderBookStateSell();
    void deleteTheSellOrder(int);
    //for Buy Side Management
    void addOrderForBuy(int,float,int);
    void tempAddOrderForBuy(int, float, int);
    void printOrderBookStateBuy();
    void deleteTheBuyOrder(int);
    //modification of the orders
    void modifySell(int,float,int);
    void modifyBuy(int,float,int);
    
    //For Execution Side Management
    void executeOrder();
};
