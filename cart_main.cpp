#include<iostream>
#include<vector>
#include<unordered_map>
#include"datamodel.h"
using namespace std;


vector<Product> allProducts = {
    Product(1,"apple",26),
    Product(2,"mango",16),
    Product(3,"guava",36),
    Product(4,"banana",56),
    Product(5,"strawberry",29),
    Product(6,"pineapple",20)
};

Product* chooseProduct() {
    //Display the list of all products
    string productList;
    cout<<"Available Products "<<endl;
    for (auto product : allProducts) {
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;
    cout<<"--------------------------"<<endl;
    string choice;
    cin>>choice;
    for (int i = 0; i< allProducts.size();i++) {
         if (allProducts[i].getShortName() == choice) {
            return &allProducts[i];
         } 
    }
        cout<<"Product not found!"<<endl;
        return NULL;
}
bool checkout(Cart &cart) {
    if (cart.isEmpty()) {
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in Cash : ";

    int paid;
    cin>>paid;
    if (paid >= total) {
        cout<<"Your change is : "<<paid - total <<endl;
        cout<<"Your payment is successfull"<<endl;
        cout<<"Thank You for Shopping"<<endl;
        return true;
    }
    else {
        cout<<"Not enough cash!"<<endl;
        return false;
    }


}

int main () {

     unordered_map<char,int>mp{
            {'a',1},
            {'m',2},
            {'g',3},
            {'b',4},
            {'s',5},
            {'p',6}
        };

    char action;
    Cart cart;
    while (true) {
        cout<<"Select an action - (a)dd item,(r)emove item,(v)iew cart,(c)heckout"<<endl;
        cin>>action;

        if (action == 'a') {
            // Todo: Add to Cart
            // View all products+ Choose Products + Add to the cart
            Product* product = chooseProduct();
            if (product!=NULL) {
                cout<<"Added to the Cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'r') {
           
            cout<<"Enter the product you want to remove : "<<endl;
            char choice;
            cin>>choice;
            if (mp.count(choice) == 0) cout<<"You have entered the wrong choice \n";
            else cart.removeProduct(mp[choice]);
        }
        else if (action == 'v') {
            //View the cart
            cout<<"--------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"--------------------------"<<endl;

        }
        else {
            //Checkout
            cart.viewCart();
            if (checkout(cart)) {
                break;
            }
        }
    }
    
}