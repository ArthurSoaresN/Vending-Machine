//Vending-Machine
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	float value;
	int stock;
} Product;

void add_money (float *money) {
  float banknotes[] = {1.0, 2.0, 5.0, 10.0};
  int length_banknotes = sizeof(banknotes)/sizeof(float);
  
  for (int i = 0; i < length_banknotes; i++) {
	  printf("%d. U$%.2f\n", i+1, banknotes[i]);
  }
  
  printf("Select an amount to add to your wallet (0 to exit) ");
  
  int choice;
  scanf("%d", &choice);
  
  if(choice == 0){
	  return;
  } else if ( (choice >= 1) && (choice <= length_banknotes) ) {
	  *money += banknotes[choice - 1];
  } else {
	printf ("invalid choice!\n");
  }
} //

void show_products (Product *machine[], int length, float money) {
	system("cls");
	printf("=== Vending Machine ===\n");
	printf("Wallet: U$%.2f\n\n", money);
	
	for (int i = 0; i < length; i++) {
	 printf("%d. %s - U$%.2f (in stock: %d)\n", 
		i + 1, 
		machine[i]->name, 
		machine[i]->value, 
		machine[i]->stock);	
	}
	
	printf("\n 0.Exit\n");
	
} //


void tosell (Product* product, float* money) {
	product->stock--;
	*money -= product->value;
	}//


int main() {
	
	Product itens[] = {
		{ "Soda", 3.0, 20 },
		{ "Chocolate Bar", 2.0, 15 },
		{ "Snack", 1.0, 10 },
		{ "Orange Juice", 2.0, 5 }
	};
	
	const int length_itens = sizeof(itens)/sizeof(Product);
	
	Product *machine[length_itens];
	for (int i = 0; i < length_itens; i++) {
		machine[i] = &itens[i];
	}
	
	float money = 0.0;
	
	int option = -1;
	while (option != 0) {
	system("cls");
	add_money(&money);
	
	show_products(machine, length_itens, money);
	
	printf("Select an option: ");
	
	scanf("%d", &option);
	
		if (option == 0) {break;}
		else if ( (option >= 1) && (option <= length_itens) ) {
		tosell(machine[option - 1], &money);
		}
	}
	
	printf("end of program!\n");
	return 0;
}

