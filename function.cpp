#include "function.h"

//sell side management
void function1::tempAddOrderForSell(int orderId, float priceLevel, int size)
    {
        tempOrderBookSell.push(OrderBookNode(orderId, priceLevel, size));
    }
void function1::addOrderForSell(int orderId, float priceLevel, int size)
    {
        orderBookSell.push(OrderBookNode(orderId, priceLevel, size));
    }

void function1::printOrderBookStateSell()
{
    cout<<"SELL SIDE ORDER BOOK"<<endl;
    cout<<"OrderId || Price Level\t"<<"|| Order Size\t"<<endl;
    while (!orderBookSell.empty())
        {
            OrderBookNode node = orderBookSell.top();
            tempAddOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
            orderBookSell.pop();
            cout <<"    "<<node.orderId<<"\t\t"<<node.orderPriceLevel << "\t\t||\t  " << node.orderSize << "\n";
        }
    while (!tempOrderBookSell.empty())
        {
            OrderBookNode node = tempOrderBookSell.top();
            addOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookSell.pop();
        }
    cout<<"\n";
}

void function1::modifySell(int orderId, float priceLevel, int orderSize)
{
    int flag =1;
    if(orderBookSell.empty())
    {
        cout<<"Order-Id does not exist, modification not possible!"<<endl;
        return;
    }
    cout<<"Sell SIDE: Modifying the Node with Order-id:\t"<<orderId<<endl;
    while (!orderBookSell.empty())
        {
            OrderBookNode node = orderBookSell.top();
            
            if(node.orderId==orderId)
            {
                flag=0;
                orderBookSell.pop();
                tempAddOrderForSell(orderId,priceLevel,orderSize);
                continue;
            }
            orderBookSell.pop();
            tempAddOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
        }
    while (!tempOrderBookSell.empty())
        {
            OrderBookNode node = tempOrderBookSell.top();
            addOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookSell.pop();
        }
    if(flag==1)
    {
        cout<<"OrderId does not exist in the OrderBook, Please try Again with Correct Id!"<<endl;
        return;
    }

    return;
}

void function1::deleteTheSellOrder(int orderId)
{
    int flag = 1;
    if(orderBookSell.empty())
    {
        cout<<"Sell Side Order Book is Empty, Deletion Not Possible!"<<endl;
        return;
    }
    cout<<"SELL SIDE: Deleting the Node with Order-id:\t"<<orderId<<endl;
    while (!orderBookSell.empty())
        {
            OrderBookNode node = orderBookSell.top();
            
            if(node.orderId==orderId)
            {
                flag = 0;
                orderBookSell.pop();
                continue;
            }
            orderBookSell.pop();
            tempAddOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
        }
    while (!tempOrderBookSell.empty())
        {
            OrderBookNode node = tempOrderBookSell.top();
            addOrderForSell(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookSell.pop();
        }
    if(flag==1)
    {
        cout<<"Order Id does not exist in the Order Book, Please try again with Correct id"<<endl;
        return;
    }
    return;
}

//Logic to the Buy side:

void function1::tempAddOrderForBuy(int orderId, float priceLevel, int size)
    {
        tempOrderBookBuy.push(OrderBookNode(orderId, priceLevel, size));
    }
void function1::addOrderForBuy(int orderId, float priceLevel, int size)
    {
        orderBookBuy.push(OrderBookNode(orderId, priceLevel, size));
    }

void function1::printOrderBookStateBuy()
{
    cout<<"BUY ORDER BOOK:"<<endl;
    cout<<"OrderId || Price Level\t"<<"|| Order Size\t"<<endl;
    while (!orderBookBuy.empty())
        {
            OrderBookNode node = orderBookBuy.top();
            tempAddOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
            orderBookBuy.pop();
            cout <<"    "<<node.orderId<<"\t\t"<<node.orderPriceLevel << "\t\t||\t  " << node.orderSize << "\n";
        }
    
    while (!tempOrderBookBuy.empty())
        {
            OrderBookNode node = tempOrderBookBuy.top();
            addOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookBuy.pop();
        }
    cout<<"\n";
}

void function1::modifyBuy(int orderId, float priceLevel, int orderSize)
{
    int flag =1;
    if(orderBookBuy.empty())
    {
        cout<<"Order-Id does not exist, modification not possible!"<<endl;
        return;
    }
    cout<<"BUY SIDE: Modifying the Node with Order-id:\t"<<orderId<<endl;
    while (!orderBookBuy.empty())
        {
            OrderBookNode node = orderBookBuy.top();
            
            if(node.orderId==orderId)
            {
                flag=0;
                orderBookBuy.pop();
                tempAddOrderForBuy(orderId,priceLevel,orderSize);
                continue;
            }
            orderBookBuy.pop();
            tempAddOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
        }
    while (!tempOrderBookBuy.empty())
        {
            OrderBookNode node = tempOrderBookBuy.top();
            addOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookBuy.pop();
        }
    if(flag==1)
    {
        cout<<"OrderId does not exist in the OrderBook, Please try Again with Correct Id!"<<endl;
        return;
    }

    return;
}
void function1::deleteTheBuyOrder(int orderId)
{
    int flag =1;
    if(orderBookBuy.empty())
    {
        cout<<"Buy Order Book is Empty, Deletion is Not Possible"<<endl;
        return;
    }
    cout<<"BUY SIDE: Deleting the Node with Order-id:\t"<<orderId<<endl;
    while (!orderBookBuy.empty())
        {
            OrderBookNode node = orderBookBuy.top();
            
            if(node.orderId==orderId)
            {
                flag=0;
                orderBookBuy.pop();
                continue;
            }
            orderBookBuy.pop();
            tempAddOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
        }
    while (!tempOrderBookBuy.empty())
        {
            OrderBookNode node = tempOrderBookBuy.top();
            addOrderForBuy(node.orderId,node.orderPriceLevel,node.orderSize);
            tempOrderBookBuy.pop();
        }
    if(flag==1)
    {
        cout<<"OrderId does not exist in the OrderBook, Please try Again with Correct Id!"<<endl;
        return;
    }

    return;
}

//logic to execute the order

void function1::executeOrder()
{
    if(orderBookBuy.empty() || orderBookSell.empty())
    {
        return;
    }
    while(1)
    {
        if(orderBookBuy.empty() || orderBookSell.empty())
            return;
        
        OrderBookNode temp1 = orderBookBuy.top();
        OrderBookNode temp2 = orderBookSell.top();
        //check if the price level of buy side is greater as compared to sell side
        if (temp1.orderPriceLevel>=temp2.orderPriceLevel)
        {
            if (temp1.orderSize == temp2.orderSize)
            {
                deleteTheBuyOrder(temp1.orderId);
                deleteTheSellOrder(temp2.orderId);
                continue;
            }
            else if (temp1.orderSize > temp2.orderSize)
            {
                deleteTheSellOrder(temp2.orderId);
                int t1 = temp1.orderId;
                float t2 = temp1.orderPriceLevel;
                int t3 = temp1.orderSize - temp2.orderSize;
                deleteTheBuyOrder(t1);
                addOrderForBuy(t1,t2,t3);
                continue;
            }
            else if (temp1.orderSize < temp2.orderSize)
            {
                deleteTheBuyOrder(temp1.orderId);
                int t1 = temp2.orderId;
                float t2 = temp2.orderPriceLevel;
                int t3 = temp2.orderSize - temp1.orderSize;
                deleteTheSellOrder(t1);
                addOrderForSell(t1,t2,t3);
                continue;
            }
            else
                break;
            
        }
        else
        {
            return;
        }
    }
}
