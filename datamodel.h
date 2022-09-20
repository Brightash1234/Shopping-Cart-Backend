#include<string>
#include<unordered_map>
using namespace std;
//Product, Item , Cart
class Item;
class Cart;
class Product {
	int id;
	string Name;
	int Price;
public:
	Product() {}

	Product (int u_id , string name , int price) : id(u_id),Name(name),Price(price) {
		
	}
	string getDisplayName() {
		return Name + " : Rs " + to_string(Price) + "\n";
	}
	string getShortName() {
        return Name.substr(1,1);
	}

	friend class Item;
	friend class Cart;

};

class Item {
	Product product;
	int quantity;
public:
	
	Item() {}

	Item (Product p , int q):product(p),quantity(q ) {
		
	}
	int getItemPrice() {
		return quantity*product.Price;
	}
	string getItemInfo() {
		return to_string(quantity) + " x " + product.Name + " Rs. " + to_string(quantity*product.Price) + "\n";
	}

   friend class Cart;

};

class Cart {
	unordered_map<int,Item> items;

public:
	void addProduct(Product product) {
		if (items.count(product.id) == 0) {
			Item newItem(product,1);
			items[product.id]=newItem;
		}
		else {
			items[product.id].quantity +=1;
		}
	}

	void removeProduct(int id , int q) {
		  if (items.empty()) {
               cout<<"Your cart is empty\n";
		  }
          else if (items.count(id) == 0) {
          	cout<<"Item not available in the cart \n";
          }
          else {
            
            q = min(q,items[id].quantity);	
            items[id].quantity-=q;
          	cout<<"\nSuccessfully removed from the cart !";
          	
          	cout<<"\n"<<q<<" X "<<items[id].product.Name<<" Rs: "<<items[id].product.Price*q<<endl;
   
          }
	}

	int getTotal() {
		//Todo
		int total = 0;
		for (auto itemPair : items) {
			auto item = itemPair.second;
			total+= item.getItemPrice();
		}
		return total;

	}

	string viewCart() {
		
		string itemizedList;
		int cartTotal = getTotal();

		for (auto itemPair : items) {
			auto item = itemPair.second;
			itemizedList.append(item.getItemInfo());
		}

		return itemizedList + "\nTotal amount : Rs: " + to_string(cartTotal) + '\n';
	}
		bool isEmpty() {
			return items.empty();
		}
};
