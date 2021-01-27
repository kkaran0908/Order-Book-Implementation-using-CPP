#include "function.h"
int main()
{
    function1 f ;
    
    string myText;

    // Read from the text file
  //  ifstream MyReadFile("/Users/karankumar/Desktop/Divya/Divya/Divya/data.txt");
    char option;
    char side;
    int orderId;
    int orderSize;
    float priceLevel;
    // Use a while loop together with the getline() function to read the file line by line

    while (1)
    {
        cout<<"Choose your Options From the Given Below:"<<endl;
        cout<<"To add the New Order Press: A"<<endl;
        cout<<"To Delete the Existing Order From the Market Press: X"<<endl;
        cout<<"To modify the existing order, Please press: M"<<endl;
        cout<<"To Exit, press any button: "<<endl;
        cin>>option;
        if (option=='A')
        {   cout<<"Enter the Order-Id:\t";
            cin>>orderId;
            cout<<"Enter the Side eather 'S' or 'B': \t";
            cin>>side;
            cout<<"Enter the Order Size:\t";
            cin>>orderSize;
            cout<<"Enter the Price Level:\t";
            cin>>priceLevel;
            if (side=='S')
            {
                f.addOrderForSell(orderId,priceLevel,orderSize);
            }
            if (side=='B')
            {
                f.addOrderForBuy(orderId,priceLevel,orderSize);
            }
        }
        else if(option=='X')
        {
            
            cout<<"Current State of the Order BOOK:"<<endl;
            f.printOrderBookStateSell();
            f.printOrderBookStateBuy();
            cout<<"Enter the side of the Deleted order:\t";
            cin>>side;
            if (side=='B')
            {
                cout<<"Enter the OrderId from the Buy Order BOOK to Delete the Order:\t ";
                cin>>orderId;
                f.deleteTheBuyOrder(orderId);
            }
            if (side=='S')
            {
                cout<<"Enter the OrderId from the Sell Order BOOK to Delete the Order:\t ";
                cin>>orderId;
                f.deleteTheSellOrder(orderId);
            }
        }
        else if(option=='M')
        {
            cout<<"Current State of the Order BOOK:"<<endl;
            f.printOrderBookStateSell();
            f.printOrderBookStateBuy();
            cout<<"Enter the side of the Modifying order (S/B):\t";
            cin>>side;
            if (side=='B')
            {
                cout<<"Enter the OrderId from the Buy Order BOOK to Modify the Order:\t ";
                cin>>orderId;
                cout<<"Enter the New Order Size:\t";
                cin>>orderSize;
                cout<<"Enter the New Price Level:\t";
                cin>>priceLevel;
                f.modifyBuy(orderId,priceLevel,orderSize);
            }
            if (side=='S')
            {
                cout<<"Enter the OrderId from the Buy Order BOOK to Modify the Order:\t ";
                cin>>orderId;
                cout<<"Enter the New Order Size:\t";
                cin>>orderSize;
                cout<<"Enter the New Price Level:\t";
                cin>>priceLevel;
                f.modifySell(orderId,priceLevel,orderSize);
            }
        }
        else
        {
            break;
        }
      
        f.executeOrder();
        cout<<"*************************"<<endl;
        cout<<"Current State of the Order Book:\n"<<endl;
        f.printOrderBookStateSell();
        f.printOrderBookStateBuy();
        cout<<"*************************"<<endl;
        
    }
    cout<<"Current State of the Order Book:"<<endl;
    f.printOrderBookStateSell();
    f.printOrderBookStateBuy();
    
    return 0;
}
