#include<iostream>
#include<vector>
#include<unordered_map>
#include"datamodel.h"
using namespace std;


vector<Product> allProducts = {
    Product(1,"(a)pple",26),
    Product(2,"(m)ango",16),
    Product(3,"(g)uava",36),
    Product(4,"(b)anana",56),
    Product(5,"(s)trawberry",29),
    Product(6,"(p)ineapple",20)
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
    cout<<"Enter your choice : "<<endl;
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
        char choice ; 
        cout<<"Do you want to continue shopping(y/n) : \n";
        cin>>choice;
        if (choice == 'n') return true;
        else return false;
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
            if (cart.isEmpty()) {
                cout<<"Your cart is empty\n";
            }
            else {
            cout<<cart.viewCart();
            cout<<"Enter the product you want to remove : "<<endl;
            char choice;
            cin>>choice;
            cout<<"Enter the quantity you want to remove :"<<endl;
            int q;
            cin>>q;
            if (mp.count(choice) == 0) cout<<"You have entered the wrong choice \n";
            else cart.removeProduct(mp[choice],q);
               }
        }
        else if (action == 'v') {
            //View the cart
            cout<<"--------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"--------------------------"<<endl;

        }
        else if (action == 'c') {
            //Checkout
            cout<<cart.viewCart();
            if (checkout(cart)) {
                break;
            }
        }
        else {
            cout<<"Invalid Choice \n";
        }
    }
    return 0;
    
}
